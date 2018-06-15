#pragma once
#include "INpcNormalAction.h"

//待機アクション。突っ立っているだけ。
class NpcNormalAction_Idle : public INpcNormalAction
{
public:
	NpcNormalAction_Idle( Npc* npc );
	~NpcNormalAction_Idle();
	void Action();
};

