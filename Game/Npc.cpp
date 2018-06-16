#include "stdafx.h"
#include "Npc.h"
#include "INpcNormalAction.h"
#include "NpcNormalAction_Idle.h"
#include "NpcNormalAction_LR.h"
#include "NpcNormalAction_Guruguru.h"
#include "NpcNomalActionManzi.h"
#include "Mikyan.h"

Npc::Npc()
{
}


Npc::~Npc()
{
	delete m_normalAction;
}
void Npc::Init(const CLocData::SObjectData& locObjData)
{
	//�z�u����Ă���I�u�W�F�N�g�����烍�[�h���郂�f�����𒊏o
	wchar_t modelName[256], normalActionName[256];
	swscanf(locObjData.name, L"%ls %ls", modelName, normalActionName);
	wchar_t modelFullPath[256];
	swprintf(modelFullPath, L"modelData/%ls.cmo", modelName);
	//�X�L�����f�������_���[���쐬�B
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(modelFullPath);
	
	m_position = locObjData.position;
	m_rotation = locObjData.rotation;
	//�Z���t�V���h�E���I���ɂ���B
	m_skinModelRender->SetShadowCasterFlag(true);
	m_skinModelRender->SetShadowReceiverFlag(true);

	InitNormalAction(normalActionName);
}
void Npc::InitNormalAction(const wchar_t* normalActionName)
{
	//�A�N�V�����̖��O����͂��āA�Ή�����A�N�V�������쐬����B
	if (wcsncmp(normalActionName, L"idle", 4) == 0) {
		//�ҋ@�A�N�V�����B
		m_normalAction = new NpcNormalAction_Idle(this);
	}
	else if (wcsncmp(normalActionName, L"LR", 2) == 0) {

		m_normalAction = new NpcNormalAction_LR(this);
	}
	else if (wcsncmp(normalActionName, L"GR", 2) == 0) {
		m_normalAction = new NpcNormalAction_Guruguru(this);
	}
	else if (wcsncmp(normalActionName, L"Manzi", 5) == 0) {
		//�ҋ@�A�N�V�����B
		m_normalAction = new NpcNomalActionManzi(this);
	}
	//for �����N�A�����N�A����N�B�ҋ@�A�N�V�����̍쐬�̎d�����Q�l��
	//    �e��A�N�V����������Ă����Ă��������B
	//�d�l��
}
void Npc::ChangeStateFollow()
{
	//�݂����ɒǔ������ԂɑJ�ڂ���B
	m_mikyan = FindGO<Mikyan>("�݂����");
	m_state = enState_Follow;
}
void Npc::Update()
{
	switch (m_state) {
	case enState_Normal:
		//�ʏ��ԁB
		if (m_normalAction != nullptr) {
			m_normalAction->Action();
		}
		break;
	case enState_Follow:
		//�ǔ���ԁB
		break;
	}
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
}
bool Npc::Start()
{
	return true;
}
