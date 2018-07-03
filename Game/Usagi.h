#pragma once
class Usagi : public IGameObject
{
public:
	enum State {
		State_FollowMikyan,		//みきゃんを追いかける。
		State_Stop,				//立ち止まっている。
		State_Jump,				//飛び跳ねている。
	};
	Usagi();
	~Usagi();
	bool Start();
	void Update();
	void OnStateFolloMikyan();
	void OnStateStop();
	void OnStateJump();
	prefab::CSkinModelRender* skinModelRender = nullptr;  
	CVector3 u_position = CVector3::Zero;
	CQuaternion u_rotation = CQuaternion::Identity;
	State u_state = State_Stop;		//ウサギの状態。
	CVector3 u_initPosition;
	int u_moveDir = -1;
	float u_moveSpeed = 0.0f;
	float u_timer = 0.0f;	//状態切り替えに使用するタイマー。単位は秒。
};

