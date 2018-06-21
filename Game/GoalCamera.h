#pragma once
#include "IAppCameraMove.h"


class Mikyan;

class GoalCamera : public IAppCameraMove
{
public:
	GoalCamera(AppCamera* camera);
	~GoalCamera();
	//IAppCameraMove��Move�֐����I�[�o�[���C�h����B
	void Move();

	//�ϐ��w��
	int cameraX, cameraY, cameraZ = 0;
	int m_state = 0;
	Mikyan* m_mikyan = nullptr;		//�݂����
	CVector3 m_cameraTargetToPos;	//�J�����̒����_���王�_�Ɍ������ĐL�т�x�N�g���B

};


