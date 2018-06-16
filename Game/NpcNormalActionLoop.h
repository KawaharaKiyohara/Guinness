#pragma once

#include "INpcNormalAction.h"

class NpcNormalActionLoop : public INpcNormalAction

{
public:
	NpcNormalActionLoop(Npc* npc);
	~NpcNormalActionLoop();
	void Action();
	CQuaternion m_rotation = CQuaternion::Identity;		//âÒì]ÅB
	CVector3 m_origin;
	
};

