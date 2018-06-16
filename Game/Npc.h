#pragma once

class INpcNormalAction;
class Npc : public IGameObject
{
public:
	Npc();
	~Npc();
	//初期化。
	//locObjData	配置情報。
	
	void Init(const CLocData::SObjectData& locObjData);
	void Update();
	bool Start();
	void InitNormalAction(const wchar_t* normalActionName);
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	INpcNormalAction* m_normalAction = nullptr;			//通常アクション。
	CVector3 m_position = CVector3::Zero;				//座標。
	CQuaternion m_rotation = CQuaternion::Identity;		//回転。
	
};

