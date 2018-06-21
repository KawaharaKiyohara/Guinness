#pragma once

#include "FollowData.h"

class INpcNormalAction;
class Mikyan;
class NpcRender;

class Npc : public IGameObject
{
public:
	enum EnState {
		enState_Normal,	//�ʏ��ԁB
		enState_Follow,	//�ǔ��B
		enState_Num,
	};
	Npc();
	~Npc();
	//�������B
	//locObjData	�z�u���B
	
	void Init(const CLocData::SObjectData& locObjData);
	void Update();
	bool Start();
	void InitNormalAction(const wchar_t* normalActionName);
	void ChangeStateFollow();
	void OnStateFollow();
	//�ǔ���ԂɑJ�ڂł��邩����B
	bool IsPossibleChangeStateFollow() const
	{
		return m_state == enState_Normal;
	}
	
	INpcNormalAction* m_normalAction = nullptr;			//�ʏ�A�N�V�����B
	CVector3 m_position = CVector3::Zero;				//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;		//��]�B
	EnState m_state = enState_Normal;					//��ԁB
	Mikyan* m_mikyan;									//�݂����B
	FollowData m_followData;							//�ǔ��f�[�^�B
	CVector3 m_offsetPos;
	NpcRender* m_npcRender = nullptr;
	float m_yspeed = 2.0f;
	int m_count = 0;
};

