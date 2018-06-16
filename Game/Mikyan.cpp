#include "stdafx.h"
#include "Mikyan.h"
#include "Game.h"
#include "Npc.h"

namespace {
	const float MIKYAN_RADIUS = 40.0f;	//�݂����̔��a�B
}
Mikyan::Mikyan()
{
}


Mikyan::~Mikyan()
{
	DeleteGO(skinModelRender);
}
bool Mikyan::Start()
{
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/mikyan.cmo");
	skinModelRender->SetShadowCasterFlag(true);
	skinModelRender->SetShadowReceiverFlag(true);
	Game* game = FindGO<Game>("Game");
	game->m_countUpListener.push_back([&]() {
		OnCountUp();
	});

	
	return true;
}
void Mikyan::OnCountUp()
{
	prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
	
	ss->Init("sound/touch_00.wav");
	ss->Play(false);

	m_moveTargetPosition.x -= 200.0f;
	//�݂����Ɉ�ԋ߂�NPC���݂����̌��Ɉړ�������B
	Npc* nearNpc = nullptr;
	float dist = FLT_MAX;
	QueryGOs<Npc>("Npc", [&](auto npc)->bool {
		if (npc->IsPossibleChangeStateFollow()) {
			//�ǔ���ԂɑJ�ڂł���H
			//npc�Ƃ̋����𑪒肷��B
			CVector3 vDist = npc->m_position - position;
			float tmp = vDist.Length();
			if (tmp < dist) {
				//������̕����߂��B
				dist = tmp;
				nearNpc = npc;
			}
		}
		return true;
	});

	if (nearNpc != nullptr) {
		nearNpc->ChangeStateFollow();
	}
}
bool Mikyan::InnerAddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, FollowData& followData, Npc* npc)
{
	//�ǔ��\�f�[�^�����݂��邩���ׂ�B
	for (int i = 0; i < FollowData::MAX_FOLLOW; i++) {

		if (followData.m_npc[i] == nullptr) {
			//�ǔ��\�B
			followData.m_npc[i] = npc;
			offsetPos += followData.offsetPos[i];
			return true;
		}
	}
	//������Ȃ������ꍇ�͍ċA�I�ɒ��ׂĂ����B
	int t = rand() % 3;
	
	CVector3 offsetPosLocal = offsetPos + followData.offsetPos[t];
	if (InnerAddFolloNpcListAndGetPositionInMikyan(offsetPosLocal, followData.m_npc[t]->m_followData, npc) == true) {
		offsetPos = offsetPosLocal;
		return true;
	}
	
	return false;
}
//�ǔ�����NPC�����X�g�ɓo�^���āANPC���ǔ�����ڕW�ƂȂ�݂������W�n�̍��W���擾����B
void Mikyan::AddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, Npc* npc)
{
	offsetPos = CVector3::Zero;
	InnerAddFolloNpcListAndGetPositionInMikyan(offsetPos, m_followData, npc);	
}
void Mikyan::Update()
{
	const auto csMoveSpeed = 300.0f * GameTime().GetFrameDeltaTime();
	CVector3 moveSpeed = m_moveTargetPosition - position;
	if (moveSpeed.Length() > csMoveSpeed) {
		//�ړ�����B
		moveSpeed.Normalize();
		position += moveSpeed * csMoveSpeed;
		rotation.SetRotation(CVector3::AxisY, atan2f(moveSpeed.z, moveSpeed.x) + CMath::PI * 0.5f);
	}
	else {
		position = m_moveTargetPosition;
	}
	
#if BUILD_LEVEL != BUILD_LEVEL_MASTER
	// �f�o�b�O�@�\�I�I�I
	auto stick = CVector2(Pad(0).GetLStickXF(), Pad(0).GetLStickYF());
	position.x += stick.x * -10.0f;
	position.z += stick.y * -10.0f;
	
	
#endif
	skinModelRender->SetPosition(position);
	skinModelRender->SetRotation(rotation);
}