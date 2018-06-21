#include "stdafx.h"
#include "Game.h"
#include "Mikyan.h"
#include "AppCamera.h"
#include "Ground.h"
#include "Sky.h"
#include "Npc.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Counter.h"
#include "NpcRender.h"
#include "EffectManager.h"
Game::Game()
{
}


Game::~Game()
{
	DeleteGO(m_mikyan);
	DeleteGO(m_camera);
	for (auto lig : m_lights) {
		DeleteGO(lig);
	}
	for (auto npc : m_npc) {
		DeleteGO(npc);
	}
	DeleteGO(m_counter);
	DeleteGO(m_bgm);
	for (auto& npcRender : m_npcRenderList) {
		DeleteGO(npcRender);
	}
}
//���C�g�̏������B
void Game::InitLight()
{
	auto lig = NewGO<prefab::CDirectionLight>(0);
	auto lightDir = CVector3(1, -1, -1);
	lightDir.Normalize();
	lig->SetDirection(lightDir);
	lig->SetColor({ 10.2f, 10.2f, 10.2f, 1.0f });
	m_lights.push_back(lig);

	lig = NewGO<prefab::CDirectionLight>(0);
	lig->SetColor({ 1.2f, 1.2f, 1.2f, 1.0f });
	lig->SetDirection({ -1.0f, 0.0f, 0.0f });
	m_lights.push_back(lig);

	lig = NewGO<prefab::CDirectionLight>(0);
	lig->SetColor({ 1.2f, 1.2f, 1.2f, 1.0f });
	lightDir.Set(1.0f, -1.0f, -1.0f);
	lightDir.Normalize();
	lig->SetDirection(lightDir);
	m_lights.push_back(lig);

	GraphicsEngine().GetShadowMap().SetLightDirection(lightDir);

	m_bgm = NewGO<prefab::CSoundSource>(0);
	m_bgm->Init("sound/bgm.wav");
	m_bgm->Play(true);
}
//NPC���������B
void Game::InitNpc()
{
	//NPC�̔z�u�������[�h�B
	CLocData locData;
	locData.Load(L"locData/npcLoc.tks");
	//�z�u����Ă���I�u�W�F�N�g�ɑ΂��ăN�G�����s���B
	using NpcRenderPair = std::pair<NpcRender*, int>;
	std::map<std::wstring, NpcRenderPair> npcMap;
	locData.QueryLocObject([&](const auto& objData) {
		auto npc = NewGO<Npc>(0, "Npc");
		npc->Init(objData);
		m_npc.push_back(npc);
		wchar_t modelName[256], normalActionName[256];
		swscanf(objData.name, L"%ls %ls", modelName, normalActionName);
		wchar_t modelFullPath[256];
		swprintf(modelFullPath, L"modelData/%ls.cmo", modelName);
		auto it = npcMap.find(modelFullPath);
		if (it == npcMap.end()) {
			//�V�K
			NpcRender* npcRender = NewGO<NpcRender>(0);
			npc->m_npcRender = npcRender;
			npcMap.insert({ modelFullPath, { npcRender, 1 } });
		}
		else {
			//�d���B
			it->second.second++;
			npc->m_npcRender = it->second.first;
		}
	});
	//NPC�����_���[������������B
	for (auto npcRenderPair : npcMap) {
		const std::wstring& modelPath = npcRenderPair.first;
		auto numInstance = npcRenderPair.second.second;
		
		npcRenderPair.second.first->Init(numInstance, modelPath.c_str());
	}
	
}
bool Game::Start()
{
	m_mikyan = NewGO<Mikyan>(0, "�݂����");
	m_camera = NewGO<AppCamera>(0, "AppCamera");
	m_ground = NewGO<Ground>(0);
	m_sky = NewGO<Sky>(0);
	m_EffectManager = NewGO<EffectManager>(0);
	m_counter = NewGO<Counter>(0);

	//���C�g�̏������B
	InitLight();
	//NPC�̏������B
	InitNpc();
	return true;
}
void Game::Update()
{
#if BUILD_LEVEL != BUILD_LEVEL_MASTER
	if (Pad(0).IsPress(enButtonRight) == true) {
#else
	//�}�X�^�[�r���h�ł́A�L�[�������ςȂ��ł̓J�E���g�ł��Ȃ��悤�ɂ���B
	if (Pad(0).IsTrigger(enButtonRight) == true) {
#endif
		for (auto& listener : m_countUpListener) {
			listener(m_counter->GetCount() + 1);
		}
	}
}
