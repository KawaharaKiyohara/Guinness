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
	
	
	prefab::CSkinModelRender*	skinModelRender = nullptr;	//�X�L�����f�������_�[
	CVector3 position = CVector3::Zero;				//���W�B
	CQuaternion rotation = CQuaternion::Identity;	//��]�B
};

