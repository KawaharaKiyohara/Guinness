#pragma once
#include "INpcNormalAction.h"

class NpcNormalAction_Urouro : public INpcNormalAction
{
public:
	NpcNormalAction_Urouro( Npc* npc );
	~NpcNormalAction_Urouro();
	void Action();
	//ˆÚ“®•ûŒü‚ğXV‚·‚éB
	void UpdateMoveDirection();
	CVector3 m_InitPosition;
	CVector3 m_moveDir = CVector3::Zero;
	int m_count = 0;
};

