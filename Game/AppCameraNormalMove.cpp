#include "stdafx.h"
#include "AppCameraNormalMove.h"
#include "mikyan.h"

AppCameraNormalMove::AppCameraNormalMove(AppCamera* camera ) :
	IAppCameraMove(camera)
{
	//�݂�������������B
	m_mikyan = FindGO<Mikyan>("�݂����");

	Move();
	
}


AppCameraNormalMove::~AppCameraNormalMove()
{
}
void AppCameraNormalMove::Move()
{
	//�݂����ɒǏ]�B
	CVector3 target = m_mikyan->position;
	target.y += 150.0f;
	m_appCamera->m_springCamera.SetTarget(target);
	CVector3 pos = target;
	pos.y += 100.0f;
	pos.z += 700.0f;
	m_appCamera->m_springCamera.SetPosition(pos);
}
