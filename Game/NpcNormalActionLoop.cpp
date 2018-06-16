#include "stdafx.h"
#include "NpcNormalActionLoop.h"

NpcNormalActionLoop::NpcNormalActionLoop(Npc* npc) :
	INpcNormalAction(npc)
{
	m_origin = m_npc->m_position;
	m_origin.z -= 500;
}


NpcNormalActionLoop::~NpcNormalActionLoop()
{
}

void NpcNormalActionLoop::Action()
{
	//①m_originからm_positionに向かって伸びるベクトルVを求める。
	CVector3 v = m_npc->m_position - m_origin;
	//②Y軸回りに1度の回転を表すクォータニオンを作成する。
	// CQuaternion rot;を作って、CQuaternionのメンバ変数のSetRotationDegを使って
	// 作成する。
	CQuaternion qRot;
	qRot.SetRotationDeg({ 0.0f, 1.0f, 0.0f }, 1.0f);
	 //③ ②で作ったクォータニオンと①で求めたベクトルを乗算して、回転後のベクトルv1を求める。
	qRot.Multiply(v);
	//④ m_originにv1を加算して、それをm_positionに代入する。
	m_npc->m_position = m_origin + v;

}