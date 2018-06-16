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
	//カウントアップされたときに呼ばれる関数。
	void OnCountUp();
	
	prefab::CSkinModelRender*	skinModelRender = nullptr;	//スキンモデルレンダー
	CVector3 position = CVector3::Zero;				//座標。
	CVector3 m_moveTargetPosition = CVector3::Zero;	//ターゲット座標。
	CQuaternion rotation = CQuaternion::Identity;	//回転。
};

