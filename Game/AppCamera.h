#pragma once
#include "tkEngine/camera/tkSpringCamera.h"

class IAppCameraMove;
class move;

//アプリケーションカメラ。
class AppCamera : public IGameObject
{
public:
	AppCamera();
	~AppCamera();
	bool Start();
	void Update();
	void ChangeGoalCamera();
	bool ChangeGoalflag = false;
	IAppCameraMove*		m_move = nullptr;		//カメラの移動処理。
	CSpringCamera		m_springCamera;		//バネカメラ。

};

