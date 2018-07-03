#pragma once
class Usagi : public IGameObject
{
public:
	enum State {
		State_FollowMikyan,		//�݂�����ǂ�������B
		State_Stop,				//�����~�܂��Ă���B
		State_Jump,				//��ђ��˂Ă���B
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
	State u_state = State_Stop;		//�E�T�M�̏�ԁB
	CVector3 u_initPosition;
	int u_moveDir = -1;
	float u_moveSpeed = 0.0f;
	float u_timer = 0.0f;	//��Ԑ؂�ւ��Ɏg�p����^�C�}�[�B�P�ʂ͕b�B
};

