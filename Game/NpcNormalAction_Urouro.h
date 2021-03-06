#pragma once
#include "INpcNormalAction.h"

class NpcNormalAction_Urouro : public INpcNormalAction
{
public:
	NpcNormalAction_Urouro( Npc* npc );
	~NpcNormalAction_Urouro();
	void Action();
	//移動方向を更新する。
	void UpdateMoveDirection();
	CVector3 m_InitPosition;
	CVector3 m_moveDir = CVector3::Zero;
	int m_count = 0;
};

