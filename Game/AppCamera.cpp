#include "stdafx.h"
#include "AppCamera.h"
#include "IAppCameraMove.h"
#include "AppCameraNormalMove.h"

AppCamera::AppCamera()
{

}


AppCamera::~AppCamera()
{
	//移動処理を削除。
	delete m_move;
}
bool AppCamera::Start()
{
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(50000.0f);
		
	//通常のカメラの移動処理のインスタンスを作成。
	m_move = new AppCameraNormalMove(this);
	m_springCamera.Init(MainCamera(), 1200, false, false);
	m_springCamera.SetDampingRate(1.8f);
	return true;
}
void AppCamera::Update()
{
	if (m_move != nullptr) {
		m_move->Move();
	}
	//バネカメラを更新。
	m_springCamera.Update();
}