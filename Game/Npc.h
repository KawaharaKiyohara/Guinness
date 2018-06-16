#pragma once

class INpcNormalAction;
class Mikyan;

class Npc : public IGameObject
{
public:
	enum EnState {
		enState_Normal,	//通常状態。
		enState_Follow,	//追尾。
		enState_Num,
	};
	Npc();
	~Npc();
	//初期化。
	//locObjData	配置情報。
	
	void Init(const CLocData::SObjectData& locObjData);
	void Update();
	bool Start();
	void InitNormalAction(const wchar_t* normalActionName);
	void ChangeStateFollow();
	//追尾状態に遷移できるか判定。
	bool IsPossibleChangeStateFollow() const
	{
		return m_state == enState_Normal;
	}
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	INpcNormalAction* m_normalAction = nullptr;			//通常アクション。
	CVector3 m_position = CVector3::Zero;				//座標。
	CQuaternion m_rotation = CQuaternion::Identity;		//回転。
	EnState m_state = enState_Normal;					//状態。
	Mikyan* m_mikyan;									//みきゃん。
};

