#include "stdafx.h"
#include "NpcNormalAction_LR.h"



NpcNormalAction_LR::NpcNormalAction_LR(Npc* npc ) :
	INpcNormalAction(npc)
{
	m_initPosition = m_npc->m_position;
}


NpcNormalAction_LR::~NpcNormalAction_LR()
{
}


void NpcNormalAction_LR::Action()
{
	
	m_npc->m_position.x += 2.0f * m_moveDir;

	if (m_npc->m_position.x - m_initPosition.x > 100){ 
		m_moveDir *= -1;
	}
	else if (m_npc->m_position.x - m_initPosition.x < -100) {
		m_moveDir *= -1;
	}

}

