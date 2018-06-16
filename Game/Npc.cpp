#include "stdafx.h"
#include "Npc.h"
#include "INpcNormalAction.h"
#include "NpcNormalAction_Idle.h"
#include "NpcNormalAction_Guruguru.h"
#include "NpcNomalActionManzi.h"
#include "NpcNormalAction_Urouro.h"

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
	wchar_t modelFullPath[256];
	swprintf(modelFullPath, L"modelData/%ls.cmo", modelName);
	//スキンモデルレンダラーを作成。
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(modelFullPath);
	
	m_position = locObjData.position;
	m_rotation = locObjData.rotation;
	//セルフシャドウをオンにする。
	m_skinModelRender->SetShadowCasterFlag(true);
	m_skinModelRender->SetShadowReceiverFlag(true);

	InitNormalAction(normalActionName);
}
void Npc::InitNormalAction(const wchar_t* normalActionName)
{
	//アクションの名前を解析して、対応するアクションを作成する。
	if (wcsncmp(normalActionName, L"idle", 4) == 0) {
		//待機アクション。
		m_normalAction = new NpcNormalAction_Idle(this);
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
	//for 中村君、佐伯君、平野君。待機アクションの作成の仕方を参考に
	//    各種アクションを作っていってください。
	//仕様は
}
void Npc::Update()
{
	if (m_normalAction != nullptr) {
		m_normalAction->Action();
	}
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}
bool Npc::Start()
{
	return true;
}
