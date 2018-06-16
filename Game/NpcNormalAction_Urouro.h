#pragma once
#include "INpcNormalAction.h"

class NpcNormalAction_Urouro : public INpcNormalAction
{
public:
	NpcNormalAction_Urouro( Npc* npc );
	~NpcNormalAction_Urouro();
	void Action();
};

