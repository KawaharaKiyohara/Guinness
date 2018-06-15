#include "stdafx.h"
#include "AppCameraNormalMove.h"
#include "mikyan.h"

AppCameraNormalMove::AppCameraNormalMove(AppCamera* camera ) :
	IAppCameraMove(camera)
{
	//みきゃんを検索する。
	m_mikyan = FindGO<Mikyan>("みきゃん");

	Move();
	
}


AppCameraNormalMove::~AppCameraNormalMove()
{
}
void AppCameraNormalMove::Move()
{
	//みきゃんに追従。
	CVector3 target = m_mikyan->position;
	target.y += 150.0f;
	m_appCamera->m_springCamera.SetTarget(target);
	CVector3 pos = target;
	pos.y += 100.0f;
	pos.z += 700.0f;
	m_appCamera->m_springCamera.SetPosition(pos);
}
