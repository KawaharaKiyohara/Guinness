#pragma once

#include "AppCamera.h"

class AppCamera;
//カメラの移動処理のインターフェースクラス。
class IAppCameraMove
{
public:
	IAppCameraMove( AppCamera* camera );
	~IAppCameraMove();
	
	virtual void Move() = 0;
	AppCamera* m_appCamera = nullptr;
};

