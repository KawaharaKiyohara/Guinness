#include "stdafx.h"
#include "GoalCamera.h"
#include "Mikyan.h"


GoalCamera::GoalCamera(AppCamera* camera) :
	IAppCameraMove(camera)
{
	//みきゃんを検索する。
	m_mikyan = FindGO<Mikyan>("みきゃん");

}

GoalCamera::~GoalCamera()
{
}

void GoalCamera::Move()
{
	if (m_state == 0) {
		//ステート変数が１のときは真後ろに移動。
		cameraX = -600;
		cameraY = 400;
		cameraZ = -1000;

		CVector3 cameraTarget = m_mikyan->position;
		cameraTarget.y = m_mikyan->position.y + 200.0f; //プレイヤーのちょっと上にする。 
		m_appCamera->m_springCamera.SetTarget(cameraTarget);

		CVector3 cameraPos = m_mikyan->position;
		cameraPos.x -= cameraX;
		cameraPos.y += cameraY;
		cameraPos.z += cameraZ; //視点をカメラに伝える。 
		m_appCamera->m_springCamera.SetPosition(cameraPos);
		m_appCamera->m_springCamera.Refresh();
		m_appCamera->m_springCamera.Update();
		//カメラ移動
		cameraPos = m_mikyan->position;
		cameraPos.y += 400;
		cameraPos.z -= 1000;
		m_appCamera->m_springCamera.SetPosition(cameraPos);

		m_state = 1;
	}
	else if (m_state == 1) {
		//ステートが１のときはみきゃんの真横に移動する。
		//実際の視点の座標を取得するのは下記のコード
		CVector3 realPos = m_appCamera->m_springCamera.GetRealPosition();
		//目標視点は下記
		CVector3 tarPos = m_appCamera->m_springCamera.GetPosition();
		//この二つを使って、２点間の距離を計算して、それが10以下になったら
		//前に移動する視点を設定して、ステートを2にする。
		CVector3 diff = realPos - tarPos;
		float len = diff.Length();// sqrt(diff.x * diff.x + diff.y * diff.y + diff.z * diff.z);
		if (len<=300) {
			m_state = 2;
		}		
	}
	else if (m_state == 2) {
		//カメラ移動
		CVector3 cameraPos = m_mikyan->position;
		cameraPos.z += 200;
		cameraPos.y += 400;
		cameraPos.x -= 600;
		m_appCamera->m_springCamera.SetPosition(cameraPos);

		m_state = 3;

	}



}


