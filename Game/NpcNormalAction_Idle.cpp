#include "stdafx.h"
#include "NpcNormalAction_Idle.h"


NpcNormalAction_Idle::NpcNormalAction_Idle( Npc* npc ) :
	INpcNormalAction(npc)
{
}


NpcNormalAction_Idle::~NpcNormalAction_Idle()
{
}

//アクション。
void NpcNormalAction_Idle::Action()
{
	//何もしないぜ。
	//m_npc->m_position.x += 1.0f; 
}
