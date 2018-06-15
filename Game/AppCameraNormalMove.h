#pragma once
#include "IAppCameraMove.h"


class Mikyan;

class AppCameraNormalMove : public IAppCameraMove
{
public:
	AppCameraNormalMove(AppCamera* camera);
	~AppCameraNormalMove();
	//IAppCameraMoveのMove関数をオーバーライドする。
	void Move() ;
	Mikyan* m_mikyan = nullptr;		//みきゃん
	
};

