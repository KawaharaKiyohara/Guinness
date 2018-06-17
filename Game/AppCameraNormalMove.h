#pragma once
#include "IAppCameraMove.h"


class Mikyan;

class AppCameraNormalMove : public IAppCameraMove
{
public:
	AppCameraNormalMove(AppCamera* camera);
	~AppCameraNormalMove();
	//IAppCameraMove��Move�֐����I�[�o�[���C�h����B
	void Move() ;
	//�J�E���g�A�b�v�̃R�[���o�b�N�B
	void OnCountUp(int count);
	Mikyan* m_mikyan = nullptr;		//�݂����
	CVector3 m_cameraTargetToPos;	//�J�����̒����_���王�_�Ɍ������ĐL�т�x�N�g���B
};

