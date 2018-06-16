#pragma once
#include "INpcNormalAction.h"


class NpcNomalActionManzi : public INpcNormalAction

{
public:
	NpcNomalActionManzi(Npc* npc);
	~NpcNomalActionManzi();
	void Action();
	CVector3 m_InitPosition ;
	int m_moveDir = -1;
};

