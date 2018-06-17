#include "stdafx.h"
#include "AppCameraNormalMove.h"
#include "mikyan.h"
#include "Game.h"
AppCameraNormalMove::AppCameraNormalMove(AppCamera* camera ) :
	IAppCameraMove(camera)
{
	//‚İ‚«‚á‚ñ‚ğŒŸõ‚·‚éB
	m_mikyan = FindGO<Mikyan>("‚İ‚«‚á‚ñ");
	Game* game = FindGO<Game>("Game");
	m_cameraTargetToPos = { 0.0f, 30.0f, 800.0f };
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
	if (count == 50) {
		m_targetOffset = 550.0f;
		m_cameraTargetToPos.y = 100.0f;
		m_cameraTargetToPos.z = 1200.0f;
	}
	if (count == 100) {
		m_targetOffset = 700.0f;
		m_cameraTargetToPos.y = 100.0f;
		m_cameraTargetToPos.z = 1400.0f;
	}
	if (count == 250) {
		m_targetOffset = 800.0f;
		m_cameraTargetToPos.z = 1600.0f;
	}
	if (count == 400) {
		m_targetOffset = 900.0f;
		m_cameraTargetToPos.z = 2000.0f;
	}
	if (count == 600) {
		m_targetOffset = 1000.0f;
		m_cameraTargetToPos.z = 2400.0f;
	}
	if (count == 800) {
		m_targetOffset = 1300.0f;
		m_cameraTargetToPos.z = 2800.0f;
		GraphicsEngine().GetShadowMap().SetLightHeight(UnitM(20.0f));
		GraphicsEngine().GetShadowMap().SetFar(4000.0f);
	}
}
void AppCameraNormalMove::Move()
{
	//‚İ‚«‚á‚ñ‚É’Ç]B
	CVector3 target = m_mikyan->position;
	target.y += m_targetOffset;
	m_appCamera->m_springCamera.SetTarget(target);
	CVector3 pos = target;
	pos += m_cameraTargetToPos;
	
	m_appCamera->m_springCamera.SetPosition(pos);
}
