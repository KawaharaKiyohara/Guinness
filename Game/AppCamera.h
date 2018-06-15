#pragma once

#include "tkEngine/camera/tkSpringCamera.h"

class IAppCameraMove;

//�A�v���P�[�V�����J�����B
class AppCamera : public IGameObject
{
public:
	AppCamera();
	~AppCamera();
	bool Start();
	void Update();
	IAppCameraMove*		m_move = nullptr;		//�J�����̈ړ������B
	CSpringCamera		m_springCamera;		//�o�l�J�����B
};

