#pragma once
#include "Npc.h"
class Npc;
//�ʏ�A�N�V�����̃C���^�[�t�F�C�X�N���X�B
class INpcNormalAction
{
public:
	INpcNormalAction(Npc* npc);
	~INpcNormalAction();
	//�A�N�V���������s�B
	virtual void Action() = 0;

	Npc* m_npc = nullptr;
};

