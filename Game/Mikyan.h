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
	//�C���X�^���X���������ꂽ�Ƃ��ɌĂ΂��֐��B
	bool Start();
	//���t���[���Ă΂��֐��B
	void Update();
	//�J�E���g�A�b�v���ꂽ�Ƃ��ɌĂ΂��֐��B
	void OnCountUp();
	//�ǔ�����NPC�����X�g�ɓo�^���āANPC���ǔ�����ڕW�ƂȂ�݂������W�n�̍��W���擾����B
	void AddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, Npc* npc);
	
	prefab::CSkinModelRender*	skinModelRender = nullptr;	//�X�L�����f�������_�[
	CVector3 position = CVector3::Zero;				//���W�B
	CVector3 m_moveTargetPosition = CVector3::Zero;	//�^�[�Q�b�g���W�B
	CQuaternion rotation = CQuaternion::Identity;	//��]�B
	FollowData m_followData;
private:
	bool InnerAddFolloNpcListAndGetPositionInMikyan(CVector3& offsetPos, FollowData& followData, Npc* npc);
	
};

