#pragma once
#include "INpcNormalAction.h"

class NpcNormalAction_Guruguru : public INpcNormalAction
{
public:
	NpcNormalAction_Guruguru( Npc* npc );
	~NpcNormalAction_Guruguru();
	void Action();
	CQuaternion m_rotation = CQuaternion::Identity;
	float Angle = 0;
};

