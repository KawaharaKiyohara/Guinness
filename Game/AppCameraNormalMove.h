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
	Mikyan* m_mikyan = nullptr;		//�݂����
	
};

