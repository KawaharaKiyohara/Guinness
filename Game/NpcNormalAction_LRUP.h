#pragma once
#include "INpcNormalAction.h"

class NpcNormalAction_LRUP : public INpcNormalAction
{
public:
	NpcNormalAction_LRUP(Npc* npc);
	~NpcNormalAction_LRUP();
	void Action();
	CVector3 m_initPosition;
	CVector3 m_position = CVector3::Zero;
	int m_moveDir = 1;
	float m_moveSpeed = 0.0f;
	int m_jump = 0;
};

