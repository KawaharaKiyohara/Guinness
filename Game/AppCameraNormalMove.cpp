#include "stdafx.h"
#include "AppCameraNormalMove.h"
#include "mikyan.h"
#include "Game.h"
AppCameraNormalMove::AppCameraNormalMove(AppCamera* camera ) :
	IAppCameraMove(camera)
{
	//みきゃんを検索する。
	m_mikyan = FindGO<Mikyan>("みきゃん");
	Game* game = FindGO<Game>("Game");
	m_cameraTargetToPos = { 0.0f, 100.0f, 700.0f };
	game->AddCountUpListener([&](int count) {
		OnCountUp(count);
	});
	Move();
	
}


AppCameraNormalMove::~AppCameraNormalMove()
{
}
void AppCameraNormalMove::OnCountUp(int count)
{
	if (count == 100) {
		m_cameraTargetToPos.y = 200.0f;
		m_cameraTargetToPos.z = 850.0f;
	}
	if (count == 250) {
		m_cameraTargetToPos.y = 350.0f;
		m_cameraTargetToPos.z = 1000.0f;
	}
	if (count == 400) {
		m_cameraTargetToPos.y = 400.0f;
		m_cameraTargetToPos.z = 1200.0f;
	}
}
void AppCameraNormalMove::Move()
{
	//みきゃんに追従。
	CVector3 target = m_mikyan->position;
	target.y += 250.0f;
	m_appCamera->m_springCamera.SetTarget(target);
	CVector3 pos = target;
	pos += m_cameraTargetToPos;
	
	m_appCamera->m_springCamera.SetPosition(pos);
}
