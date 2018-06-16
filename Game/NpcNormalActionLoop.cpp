#include "stdafx.h"
#include "NpcNormalActionLoop.h"

NpcNormalActionLoop::NpcNormalActionLoop(Npc* npc) :
	INpcNormalAction(npc)
{
	m_origin = m_npc->m_position;
	m_origin.z -= 500;
}


NpcNormalActionLoop::~NpcNormalActionLoop()
{
}

void NpcNormalActionLoop::Action()
{
	//�@m_origin����m_position�Ɍ������ĐL�т�x�N�g��V�����߂�B
	CVector3 v = m_npc->m_position - m_origin;
	//�AY������1�x�̉�]��\���N�H�[�^�j�I�����쐬����B
	// CQuaternion rot;������āACQuaternion�̃����o�ϐ���SetRotationDeg���g����
	// �쐬����B
	CQuaternion qRot;
	qRot.SetRotationDeg({ 0.0f, 1.0f, 0.0f }, 1.0f);
	 //�B �A�ō�����N�H�[�^�j�I���Ƈ@�ŋ��߂��x�N�g������Z���āA��]��̃x�N�g��v1�����߂�B
	qRot.Multiply(v);
	//�C m_origin��v1�����Z���āA�����m_position�ɑ������B
	m_npc->m_position = m_origin + v;

}