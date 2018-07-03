#include "stdafx.h"
#include "EffectManager.h"
#include "EffectPlay.h"
#include "Game.h"
#include "Mikyan.h"
#include "AppCamera.h"

EffectManager::EffectManager()
{
	//�݂�������������B
	m_mikyan = FindGO<Mikyan>("�݂����");
	Game* game = FindGO<Game>("Game");
	game->AddCountUpListener([&](int count) {
		OnCountUp(count);
	});
}


EffectManager::~EffectManager()
{
}

void EffectManager::Update()
{
	if (m_isNewRecordFlag == true) {
	
		m_isNewRecordCount--;

		if (m_isNewRecordCount == 0) {
			m_isNewRecordFlag = false;
		}

	}

	if (m_finalCount >30) {

		m_finalCount--;
		MainCamera().SetViewAngle(CMath::DegToRad(m_finalCount));

	}

}

void EffectManager::OnCountUp(int count)
{
	if (count == 100) {
		//�ԉ΍Đ�
		EffectPlay* p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 300.0f,300.0f,300.0f };
		//�݂�����X���W���Ăяo���ĉ���
		CVector3 target = m_mikyan->position;
		target.x += 0.0f;
		target.y += 100.0f;
		target.z -= 1400.0f;
		p->position = { target };
	}
	if (count == 200) {
		//�ԉ΍Đ�
		EffectPlay* p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 200.0f,200.0f,200.0f };
		//�݂�����X���W���Ăяo���ĉ���
		CVector3 target = m_mikyan->position;
		target.x += 1600.0f;
		target.y += 200.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 200.0f,200.0f,200.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1400.0f;
		target.y += 280.0f;
		target.z -= 1400.0f;
		p->position = { target };
	}
	if (count == 300) {
		//�ԉ΍Đ�
		EffectPlay* p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 200.0f,200.0f,200.0f };
		//�݂�����X���W���Ăяo���ĉ���
		CVector3 target = m_mikyan->position;
		target.x += 1400.0f;
		target.y += 150.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 200.0f,200.0f,200.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1000.0f;
		target.y += 240.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 100.0f,100.0f,100.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1800.0f;
		target.y += 100.0f;
		target.z -= 1400.0f;
		p->position = { target };
	}
	if (count == 400) {
		//�ԉ΍Đ�
		EffectPlay* p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 200.0f,200.0f,200.0f };
		//�݂�����X���W���Ăяo���ĉ���
		CVector3 target = m_mikyan->position;
		target.x += 1600.0f;
		target.y += 250.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 100.0f,100.0f,100.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x += 1600.0f;
		target.y += 200.0f;
		target.z -= 1400.0f;
		p->position = { target };

		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 200.0f,200.0f,200.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1600.0f;
		target.y += 250.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 100.0f,100.0f,100.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1600.0f;
		target.y += 200.0f;
		target.z -= 1400.0f;
		p->position = { target };
	}
	if (count == 500) {
		//�ԉ΍Đ�
		EffectPlay* p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 400.0f,400.0f,400.0f };
		//�݂�����X���W���Ăяo���ĉ���
		CVector3 target = m_mikyan->position;
		target.x += 0.0f;
		target.y += 100.0f;
		target.z -= 1600.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 100.0f,100.0f,100.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1800.0f;
		target.y += 150.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabi.efk" };
		p->scale = { 100.0f,100.0f,100.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x += 1700.0f;
		target.y += 200.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiUp.efk" };
		p->scale = { 150.0f,150.0f,150.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x += 400.0f;
		target.y -= 200.0f;
		target.z += 700.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiUp.efk" };
		p->scale = { 150.0f,150.0f,150.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 400.0f;
		target.y -= 200.0f;
		target.z += 700.0f;
		p->position = { target };

	}
	if (count == Game::GUINESS_RECORD) {
		m_isNewRecordCount = 75;
		m_isNewRecordFlag = true;

		//�ԉ΍Đ�
		EffectPlay* p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiStar.efk" };
		p->scale = { 200.0f,200.0f,200.0f };
		//�݂�����X���W���Ăяo���ĉ���
		CVector3 target = m_mikyan->position;
		target.x += 1200.0f;
		target.y += 1000.0f;
		target.z -= 1600.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiStar.efk" };
		p->scale = { 100.0f,100.0f,100.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1200.0f;
		target.y += 1000.0f;
		target.z -= 1600.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiStar.efk" };
		p->scale = { 80.0f,80.0f,80.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 1800.0f;
		target.y += 400.0f;
		target.z -= 1600.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiDown.efk" };
		p->scale = { 300.0f,300.0f,300.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x += 0.0f;
		target.y += 100.0f;
		target.z -= 1400.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiUp.efk" };
		p->scale = { 150.0f,150.0f,150.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x -= 400.0f;
		target.y -= 200.0f;
		target.z += 700.0f;
		p->position = { target };

		//�ԉ΍Đ�
		p = NewGO<EffectPlay>(0);
		p->animation = { L"effect/hanabiUp.efk" };
		p->scale = { 150.0f,150.0f,150.0f };
		//�݂�����X���W���Ăяo���ĉ���
		target = m_mikyan->position;
		target.x += 400.0f;
		target.y -= 200.0f;
		target.z += 700.0f;
		p->position = { target };

	}
	if (count == Game::KAWAHARA_TARGET) {
		m_finalCount = 100;
		//�J�������o�Ăяo��
		m_camera = FindGO<AppCamera>("AppCamera");
		m_camera->ChangeGoalCamera();
		m_mikyan = FindGO<Mikyan>("�݂����");
		m_mikyan->Stopflag = true;

	}
}

void EffectManager::PostRender(CRenderContext& rc)
{
	if (m_isNewRecordFlag == true) {
		m_font.Begin(rc);
		wchar_t text[256];
		swprintf(text, L"New Record!!");
		m_font.Draw(text, { 0.0f, -50.0f }, CVector4::Yellow, 0.0f, 0.8f);
		m_font.End(rc);
	}

}