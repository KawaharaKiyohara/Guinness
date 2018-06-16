#include "stdafx.h"
#include "Mikyan.h"
#include "Game.h"
#include "Npc.h"

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
void Mikyan::Update()
{
	const auto csMoveSpeed = 6.0f;
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