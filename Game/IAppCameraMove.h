#pragma once

#include "AppCamera.h"

class AppCamera;
//�J�����̈ړ������̃C���^�[�t�F�[�X�N���X�B
class IAppCameraMove
{
public:
	IAppCameraMove( AppCamera* camera );
	~IAppCameraMove();
	
	virtual void Move() = 0;
	AppCamera* m_appCamera = nullptr;
};

