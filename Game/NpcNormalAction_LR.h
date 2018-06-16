#pragma once
#include "INpcNormalAction.h"

class NpcNormalAction_LR : public INpcNormalAction
{
public:
	NpcNormalAction_LR(Npc* npc);
	~NpcNormalAction_LR();
	void Action();
	CVector3 m_initPosition;
	CVector3 m_position = CVector3::Zero;
	int m_moveDir = 1;
};

