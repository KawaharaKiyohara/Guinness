#include "stdafx.h"
#include "AppCamera.h"
#include "IAppCameraMove.h"
#include "AppCameraNormalMove.h"
#include "GoalCamera.h"

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
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(30000.0f);
		
	//�ʏ�̃J�����̈ړ������̃C���X�^���X���쐬�B
	m_move = new AppCameraNormalMove(this);
	m_springCamera.Init(MainCamera(), 1200, false, false);
	m_springCamera.SetDampingRate(1.8f);
	return true;
}

void AppCamera::ChangeGoalCamera()
{
	delete m_move;
	m_move = new GoalCamera(this);
	ChangeGoalflag = true;

}

void AppCamera::Update()
{
	if (m_move != nullptr) {
		m_move->Move();
	}
	//�o�l�J�������X�V�B
	m_springCamera.Update();

	/*if (ChangeGoalflag == true) {
		CVector3 cameraPos;
		cameraPos.z += 10;
		MainCamera().SetPosition(cameraPos);
	}*/

}