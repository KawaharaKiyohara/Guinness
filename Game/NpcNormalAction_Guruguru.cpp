#include "stdafx.h"
#include "NpcNormalAction_Guruguru.h"


NpcNormalAction_Guruguru::NpcNormalAction_Guruguru(Npc* npc) : INpcNormalAction(npc)
{
}


NpcNormalAction_Guruguru::~NpcNormalAction_Guruguru()
{
}

void NpcNormalAction_Guruguru::Action()
{
	Angle += 0.3f;

	m_npc->m_rotation.SetRotation(CVector3::AxisY, Angle);

}