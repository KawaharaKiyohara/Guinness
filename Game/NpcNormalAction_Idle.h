#pragma once
#include "INpcNormalAction.h"

//�ҋ@�A�N�V�����B�˂������Ă��邾���B
class NpcNormalAction_Idle : public INpcNormalAction
{
public:
	NpcNormalAction_Idle( Npc* npc );
	~NpcNormalAction_Idle();
	void Action();
};

