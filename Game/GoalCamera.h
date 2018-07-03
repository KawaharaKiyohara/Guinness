#pragma once
#include "IAppCameraMove.h"


class Mikyan;

class GoalCamera : public IAppCameraMove
{
public:
	GoalCamera(AppCamera* camera);
	~GoalCamera();
	//IAppCameraMoveのMove関数をオーバーライドする。
	void Move();

	//変数指定
	int cameraX, cameraY, cameraZ = 0;
	int m_state = 0;
	Mikyan* m_mikyan = nullptr;		//みきゃん
	CVector3 m_cameraTargetToPos;	//カメラの注視点から視点に向かって伸びるベクトル。

};


