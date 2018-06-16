#include "stdafx.h"
#include "NpcNormalAction_Urouro.h"


NpcNormalAction_Urouro::NpcNormalAction_Urouro( Npc* npc ) : INpcNormalAction(npc)
{
	m_InitPosition = m_npc->m_position;
	UpdateMoveDirection();
}


NpcNormalAction_Urouro::~NpcNormalAction_Urouro()
{
}
void NpcNormalAction_Urouro::UpdateMoveDirection()
{
	m_moveDir.x = 0.0f;
	m_moveDir.y = 0.0f;
	m_moveDir.z = 1.0f;
	//Y軸周りに回転するクォータニオンを乱数を使って作成。
	CQuaternion qRot;
	int t = rand() % 360;
	qRot.SetRotationDeg(CVector3::AxisY, (float)t);
	qRot.Multiply(m_moveDir);
}
void NpcNormalAction_Urouro::Action()
{    
	m_count++;
	if (m_count == 30) {
		//移動方向を更新する。
		if ((rand() % 2) == 0) {
			UpdateMoveDirection();
		}
		m_count = 0;
	}
	//移動前の座標をバックアップ。
	CVector3 posOld = m_npc->m_position;
	m_npc->m_position += m_moveDir * 2.0f;
	//範囲外移動チェック。
	CVector3 vInitPosToPos = m_npc->m_position - m_InitPosition;
	if (vInitPosToPos.Length() > 100.0f) {
		m_moveDir *= -1.0f;
		//範囲外に出たので、戻す。
		m_npc->m_position = posOld;
	}
}