#include "stdafx.h"
#include "NpcNormalAction_LRUP.h"


NpcNormalAction_LRUP::NpcNormalAction_LRUP(Npc* npc) :
	INpcNormalAction(npc)
{
	m_initPosition = m_npc->m_position;
	m_moveSpeed = 7.0f;
}


NpcNormalAction_LRUP::~NpcNormalAction_LRUP()
{
}
void NpcNormalAction_LRUP::Action()
{
	m_npc->m_position.x += 2.0f * m_moveDir;

	
	if (m_jump == 3) {
		m_moveDir *= -1;
	}
	else if (m_jump == 2) {
		m_moveDir *= 1;
	}
	else if (m_jump == 1) {
		m_moveDir *= -1;
		m_jump = 0;
	}



	m_moveSpeed -= 0.2f;
	m_npc->m_position.y += m_moveSpeed;
	if (m_npc->m_position.y < 0) {
		m_moveSpeed = 7.0f;
		m_jump++;
	}
	

	

}
