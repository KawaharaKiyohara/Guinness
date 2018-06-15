#include "stdafx.h"
#include "AppCamera.h"
#include "IAppCameraMove.h"
#include "AppCameraNormalMove.h"

AppCamera::AppCamera()
{

}


AppCamera::~AppCamera()
{
	//�ړ��������폜�B
	delete m_move;
}
bool AppCamera::Start()
{
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(50000.0f);
		
	//�ʏ�̃J�����̈ړ������̃C���X�^���X���쐬�B
	m_move = new AppCameraNormalMove(this);
	m_springCamera.Init(MainCamera(), 1200, false, false);
	m_springCamera.SetDampingRate(1.8f);
	return true;
}
void AppCamera::Update()
{
	if (m_move != nullptr) {
		m_move->Move();
	}
	//�o�l�J�������X�V�B
	m_springCamera.Update();
}