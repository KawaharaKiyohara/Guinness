#include "stdafx.h"
#include "AppCamera.h"
#include "IAppCameraMove.h"
#include "AppCameraNormalMove.h"
#include "GoalCamera.h"

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
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(30000.0f);
		
	//通常のカメラの移動処理のインスタンスを作成。
	m_move = new AppCameraNormalMove(this);
	m_springCamera.Init(MainCamera(), 1200, false, false);
	m_springCamera.SetDampingRate(1.8f);
	return true;
}

void AppCamera::ChangeGoalCamera()
{
	delete m_move;
	m_move = new GoalCamera(this);
	ChangeGoalflag = true;

}

void AppCamera::Update()
{
	if (m_move != nullptr) {
		m_move->Move();
	}
	//バネカメラを更新。
	m_springCamera.Update();

	/*if (ChangeGoalflag == true) {
		CVector3 cameraPos;
		cameraPos.z += 10;
		MainCamera().SetPosition(cameraPos);
	}*/

}