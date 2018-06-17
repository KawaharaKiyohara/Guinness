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
	//カウントアップのコールバック。
	void OnCountUp(int count);
	Mikyan* m_mikyan = nullptr;		//みきゃん
	CVector3 m_cameraTargetToPos;	//カメラの注視点から視点に向かって伸びるベクトル。
};

