#include "stdafx.h"
#include "Npc.h"
#include "INpcNormalAction.h"
#include "NpcNormalAction_Idle.h"
#include "NpcNormalAction_LR.h"
#include "NpcNormalAction_Guruguru.h"
#include "NpcNomalActionManzi.h"
#include "Mikyan.h"
#include "NpcNormalAction_Urouro.h"
#include "NpcNomalAction_JP.h"
#include"NpcNormalActionLoop.h"
#include "NpcRender.h"
#include "NpcNormalAction_LRUP.h"


Npc::Npc()
{
}


Npc::~Npc()
{
	delete m_normalAction;
}
void Npc::Init(const CLocData::SObjectData& locObjData)
{
	//配置されているオブジェクト名からロードするモデル名を抽出
	wchar_t modelName[256], normalActionName[256];
	swscanf(locObjData.name, L"%ls %ls", modelName, normalActionName);

	m_position = locObjData.position;
	m_rotation = locObjData.rotation;
	

	InitNormalAction(normalActionName);
}
void Npc::InitNormalAction(const wchar_t* normalActionName)
{
	//アクションの名前を解析して、対応するアクションを作成する。
	if (wcsncmp(normalActionName, L"idle", 4) == 0) {
		//待機アクション。
		m_normalAction = new NpcNormalAction_Idle(this);
	}
	else if (wcsncmp(normalActionName, L"LR", 2) == 0) {

		m_normalAction = new NpcNormalAction_LR(this);
	}
	else if (wcsncmp(normalActionName, L"GR", 2) == 0) {
		m_normalAction = new NpcNormalAction_Guruguru(this);
	}
	else if (wcsncmp(normalActionName, L"Manzi", 5) == 0) {
		//待機アクション。
		m_normalAction = new NpcNomalActionManzi(this);
	}
	else if (wcsncmp(normalActionName, L"UR", 2) == 0) {
		m_normalAction = new NpcNormalAction_Urouro(this);
	}
	else if (wcsncmp(normalActionName, L"JP", 2) == 0) {

		m_normalAction = new NpcNomalAction_JP(this);
	}
	else if (wcsncmp(normalActionName, L"Loop", 4) == 0) {
		//待機アクション。
		m_normalAction = new NpcNormalActionLoop(this);
	}
	else if (wcsncmp(normalActionName, L"LRUP", 4) == 0) {
		m_normalAction = new NpcNormalAction_LRUP(this);
	}

	//for 中村君、佐伯君、平野君。待機アクションの作成の仕方を参考に
	//    各種アクションを作っていってください。
	//仕様は
}
void Npc::ChangeStateFollow()
{
	//みきゃんに追尾する状態に遷移する。
	//追尾座標を取得。
	m_mikyan = FindGO<Mikyan>("みきゃん");
	m_mikyan->AddFolloNpcListAndGetPositionInMikyan(m_offsetPos, this);
	m_state = enState_Follow;
}
void Npc::Update()
{
	switch (m_state) {
	case enState_Normal:
		//通常状態。
		if (m_normalAction != nullptr) {
			m_normalAction->Action();
		}
		break;
	case enState_Follow:
		//追尾状態。
		OnStateFollow();
		break;
	}
	m_npcRender->UpdateWorldMatrix(m_position, m_rotation);
}
void Npc::OnStateFollow()
{
	CVector3 targetPos = m_mikyan->position + m_offsetPos;
//	if (m_position.x > targetPos.x) {
		//追尾。
		CVector3 moveDir = targetPos - m_position;
		moveDir.Normalize();
		//距離に比例して移動速を上げる。
		CVector3 moveSpeed = moveDir * 250.0f * min( 2.0f, pow(fabsf(targetPos.x - m_position.x) * 0.005f, 2.0f) * GameTime().GetFrameDeltaTime() );
		m_position += moveSpeed;
		m_count++;
		if (m_count % 10 == 0) {
			m_yspeed = m_yspeed * -1.0f;
		}

		m_position.y += m_yspeed;
		if (m_position.y <= 0) {
			m_position.y = 0.0f;
		}
		
		
		
//	}
	CVector3 dir = m_mikyan->position - m_position;
	m_rotation.SetRotation(CVector3::AxisY, -atan2f(dir.z, dir.x) - CMath::PI * 0.5f);
}
bool Npc::Start()
{
	return true;
}
