#pragma once
//�ǔ��p�̃f�[�^�N���X�B
class Npc;
class FollowData
{
public:
	static const int MAX_FOLLOW = 3;
	FollowData();
	~FollowData();
	Npc* m_npc[MAX_FOLLOW] = { nullptr };			//�ǔ��\��NPC�̐��͂R
	CVector3 offsetPos[MAX_FOLLOW];
};

