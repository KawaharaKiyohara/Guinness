#pragma once
class Mikyan : public IGameObject
{
public:
	Mikyan();
	~Mikyan();
	//�C���X�^���X���������ꂽ�Ƃ��ɌĂ΂��֐��B
	bool Start();
	//���t���[���Ă΂��֐��B
	void Update();
	//�J�E���g�A�b�v���ꂽ�Ƃ��ɌĂ΂��֐��B
	void OnCountUp();
	
	prefab::CSkinModelRender*	skinModelRender = nullptr;	//�X�L�����f�������_�[
	CVector3 position = CVector3::Zero;				//���W�B
	CVector3 m_moveTargetPosition = CVector3::Zero;	//�^�[�Q�b�g���W�B
	CQuaternion rotation = CQuaternion::Identity;	//��]�B
};

