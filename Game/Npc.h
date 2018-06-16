#pragma once

class INpcNormalAction;
class Npc : public IGameObject
{
public:
	Npc();
	~Npc();
	//�������B
	//locObjData	�z�u���B
	
	void Init(const CLocData::SObjectData& locObjData);
	void Update();
	bool Start();
	void InitNormalAction(const wchar_t* normalActionName);
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	INpcNormalAction* m_normalAction = nullptr;			//�ʏ�A�N�V�����B
	CVector3 m_position = CVector3::Zero;				//���W�B
	CQuaternion m_rotation = CQuaternion::Identity;		//��]�B
	
};

