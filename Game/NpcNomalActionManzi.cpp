#include "stdafx.h"
#include "NpcNomalActionManzi.h"
#include "Npc.h"
NpcNomalActionManzi::NpcNomalActionManzi(Npc* npc):
	INpcNormalAction(npc)
{
	m_InitPosition = m_npc->m_position;
}


NpcNomalActionManzi::~NpcNomalActionManzi()
{
}

void NpcNomalActionManzi::Action()

{
	m_npc->m_position.z += 2.0f * m_moveDir;
	/*if (Pad(0).IsTrigger(enButtonA)) {
		m_moveDir *= -1;
	}*/
	if (m_npc->m_position.z - m_InitPosition.z > 500) {
		m_moveDir *= -1;
	}

	else if (m_npc->m_position.z - m_InitPosition.z < -500) {
		m_moveDir *= -1;
	}
}