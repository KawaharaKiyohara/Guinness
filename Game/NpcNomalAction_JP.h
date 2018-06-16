#pragma once
#include "INpcNormalAction.h"

class NpcNomalAction_JP : public INpcNormalAction
{
public:
	NpcNomalAction_JP(Npc* npc);
	~NpcNomalAction_JP();
	void Action();
	CVector3 m_initPosition;
	CVector3 m_position = CVector3::Zero;
	float m_moveSpeed = 0.0f;
};

