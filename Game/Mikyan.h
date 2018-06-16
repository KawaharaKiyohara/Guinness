#pragma once
class Npc;
#include "FollowData.h"
class Mikyan : public IGameObject
{
public:
	struct SFollowData {
		Npc* m_npc = nullptr;
		CVector3 offsetPoint = CVector3::Zero;
	};
	Mikyan();
	~Mikyan();
	//インスタンスが生成されたときに呼ばれる関数。
	bool Start();
	//毎フレーム呼ばれる関数。
	void Update();
	//カウントアップされたときに呼ばれる関数。
	void OnCountUp();
	//追尾するNPCをリストに登録して、NPCが追尾する目標となるみきゃん座標系の座標を取得する。
	void AddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, Npc* npc);
	
	prefab::CSkinModelRender*	skinModelRender = nullptr;	//スキンモデルレンダー
	CVector3 position = CVector3::Zero;				//座標。
	CVector3 m_moveTargetPosition = CVector3::Zero;	//ターゲット座標。
	CQuaternion rotation = CQuaternion::Identity;	//回転。
	FollowData m_followData;
private:
	bool InnerAddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, FollowData& followData, Npc* npc);
	
};

