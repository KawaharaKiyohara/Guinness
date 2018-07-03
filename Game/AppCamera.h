#pragma once
#include "tkEngine/camera/tkSpringCamera.h"

class IAppCameraMove;
class move;

//�A�v���P�[�V�����J�����B
class AppCamera : public IGameObject
{
public:
	AppCamera();
	~AppCamera();
	bool Start();
	void Update();
	void ChangeGoalCamera();
	bool ChangeGoalflag = false;
	IAppCameraMove*		m_move = nullptr;		//�J�����̈ړ������B
	CSpringCamera		m_springCamera;		//�o�l�J�����B

};

