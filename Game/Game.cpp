#include "stdafx.h"
#include "Game.h"
#include "Mikyan.h"
#include "AppCamera.h"
#include "Ground.h"
#include "Sky.h"
#include "Npc.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Counter.h"

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
}
//NPC���������B
void Game::InitNpc()
{
	//NPC�̔z�u�������[�h�B
	CLocData locData;
	locData.Load(L"locData/npcLoc.tks");
	//�z�u����Ă���I�u�W�F�N�g�ɑ΂��ăN�G�����s���B
	locData.QueryLocObject([&](const auto& objData) {
		auto npc = NewGO<Npc>(0);
		npc->Init(objData);
	});
	
}
bool Game::Start()
{
	m_mikyan = NewGO<Mikyan>(0, "�݂����");
	m_camera = NewGO<AppCamera>(0);
	m_ground = NewGO<Ground>(0);
	m_sky = NewGO<Sky>(0);
	m_counter = NewGO<Counter>(0);

	//���C�g�̏������B
	InitLight();
	//NPC�̏������B
	InitNpc();
	return true;
}
void Game::Update()
{
	if (Pad(0).IsTrigger(enButtonRight) == true) {
		for (auto& listener : m_countUpListener) {
			listener();
		}
	}
}
