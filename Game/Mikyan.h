#pragma once
class Mikyan : public IGameObject
{
public:
	Mikyan();
	~Mikyan();
	//インスタンスが生成されたときに呼ばれる関数。
	bool Start();
	//毎フレーム呼ばれる関数。
	void Update();
	
	
	prefab::CSkinModelRender*	skinModelRender = nullptr;	//スキンモデルレンダー
	CVector3 position = CVector3::Zero;				//座標。
	CQuaternion rotation = CQuaternion::Identity;	//回転。
};

