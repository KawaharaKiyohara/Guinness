#include "stdafx.h"
#include "Mikyan.h"
#include "Game.h"
#include "Npc.h"

namespace {
	const float MIKYAN_RADIUS = 40.0f;	//みきゃんの半径。
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
	game->m_countUpListener.push_back([&]( int count ) {
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
	//みきゃんに一番近いNPCをみきゃんの後ろに移動させる。
	Npc* nearNpc = nullptr;
	float dist = FLT_MAX;
	QueryGOs<Npc>("Npc", [&](auto npc)->bool {
		if (npc->IsPossibleChangeStateFollow()) {
			//追尾状態に遷移できる？
			//npcとの距離を測定する。
			CVector3 vDist = npc->m_position - position;
			float tmp = vDist.Length();
			if (tmp < dist) {
				//こちらの方が近い。
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
bool Mikyan::InnerAddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, FollowData& followData, Npc* npc, int depth)
{
	int npcNo = 0;
	//追尾可能データが存在するか調べる。
	CVector3 asobiOffset;
	//5列目以降は真後ろに続いていく。
	asobiOffset.x = CMath::Lerp(Random().GetRandDouble(), -40.0f, 40.0f);
	asobiOffset.y = 0.0f;
	asobiOffset.z = CMath::Lerp(Random().GetRandDouble(), -40.0f, 40.0f);
	if (depth > 3) {
		
		if (followData.m_npc[0] == nullptr) {
			
			followData.m_npc[0] = npc;
			offsetPos += followData.offsetPos[0] + asobiOffset;
			return true;
		}
	}
	else {
		for (int i = 0; i < FollowData::MAX_FOLLOW; i++) {

			if (followData.m_npc[i] == nullptr) {
				//追尾可能。
				followData.m_npc[i] = npc;
				offsetPos += followData.offsetPos[i] + asobiOffset;
				return true;
			}
		}
		npcNo = rand() % FollowData::MAX_FOLLOW;
	}
	
	CVector3 offsetPosLocal = offsetPos + followData.offsetPos[npcNo] + asobiOffset;
	if (InnerAddFolloNpcListAndGetPositionInMikyan(offsetPosLocal, followData.m_npc[npcNo]->m_followData, npc, depth+1) == true) {
		offsetPos = offsetPosLocal;
		return true;
	}
	
	return false;
}
//追尾するNPCをリストに登録して、NPCが追尾する目標となるみきゃん座標系の座標を取得する。
void Mikyan::AddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, Npc* npc)
{
	offsetPos = CVector3::Zero;
	InnerAddFolloNpcListAndGetPositionInMikyan(offsetPos, m_followData, npc, 0);	
}
void Mikyan::Update()
{
	const auto csMoveSpeed = 300.0f * GameTime().GetFrameDeltaTime();
	CVector3 moveSpeed = m_moveTargetPosition - position;
	if (moveSpeed.Length() > csMoveSpeed) {
		//移動しろ。
		moveSpeed.Normalize();
		position += moveSpeed * csMoveSpeed;
		rotation.SetRotation(CVector3::AxisY, atan2f(moveSpeed.z, moveSpeed.x) + CMath::PI * 0.5f);
	}
	else {
		position = m_moveTargetPosition;
	}
	
#if BUILD_LEVEL != BUILD_LEVEL_MASTER
	// デバッグ機能！！！
	auto stick = CVector2(Pad(0).GetLStickXF(), Pad(0).GetLStickYF());
	position.x += stick.x * -10.0f;
	position.z += stick.y * -10.0f;
	
	
#endif
	skinModelRender->SetPosition(position);
	skinModelRender->SetRotation(rotation);
}