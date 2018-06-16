#pragma once

class INpcNormalAction;
class Mikyan;

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
	//�ǔ���ԂɑJ�ڂł��邩����B
	bool IsPossibleChangeStateFollow() const
	{
		return m_state == enState_Normal;
	}
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	INpcNormalAction* m_normalAction = nullptr;			//�ʏ�A�N�V�����B
	CVector3 m_position = CVector3::Zero;				//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;		//��]�B
	EnState m_state = enState_Normal;					//��ԁB
	Mikyan* m_mikyan;									//�݂����B
};

