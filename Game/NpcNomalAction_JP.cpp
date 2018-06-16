#include "stdafx.h"
#include "NpcNomalAction_JP.h"

NpcNomalAction_JP::NpcNomalAction_JP(Npc* npc):
	INpcNormalAction(npc)
{
	m_initPosition = m_npc->m_position;
	m_moveSpeed = 10.0f;
}


NpcNomalAction_JP::~NpcNomalAction_JP()
{
}

void NpcNomalAction_JP::Action()
{
	m_moveSpeed -= 0.2f;
	m_npc->m_position.y += m_moveSpeed;
	if (m_npc->m_position.y < 0) {
		m_moveSpeed = 10.0f;
	}
}