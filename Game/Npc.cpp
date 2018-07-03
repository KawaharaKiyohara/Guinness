#include "stdafx.h"
#include "Npc.h"
#include "INpcNormalAction.h"
#include "NpcNormalAction_Idle.h"
#include "NpcNormalAction_LR.h"
#include "NpcNormalAction_Guruguru.h"
#include "NpcNomalActionManzi.h"
#include "Mikyan.h"
#include "NpcNormalAction_Urouro.h"
#include "NpcNomalAction_JP.h"
#include"NpcNormalActionLoop.h"
#include "NpcRender.h"
#include "NpcNormalAction_LRUP.h"


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

	m_position = locObjData.position;
	m_rotation = locObjData.rotation;
	

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
	else if (wcsncmp(normalActionName, L"UR", 2) == 0) {
		m_normalAction = new NpcNormalAction_Urouro(this);
	}
	else if (wcsncmp(normalActionName, L"JP", 2) == 0) {

		m_normalAction = new NpcNomalAction_JP(this);
	}
	else if (wcsncmp(normalActionName, L"Loop", 4) == 0) {
		//�ҋ@�A�N�V�����B
		m_normalAction = new NpcNormalActionLoop(this);
	}
	else if (wcsncmp(normalActionName, L"LRUP", 4) == 0) {
		m_normalAction = new NpcNormalAction_LRUP(this);
	}

	//for �����N�A�����N�A����N�B�ҋ@�A�N�V�����̍쐬�̎d�����Q�l��
	//    �e��A�N�V����������Ă����Ă��������B
	//�d�l��
}
void Npc::ChangeStateFollow()
{
	//�݂����ɒǔ������ԂɑJ�ڂ���B
	//�ǔ����W���擾�B
	m_mikyan = FindGO<Mikyan>("�݂����");
	m_mikyan->AddFolloNpcListAndGetPositionInMikyan(m_offsetPos, this);
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
		OnStateFollow();
		break;
	}
	m_npcRender->UpdateWorldMatrix(m_position, m_rotation);
}
void Npc::OnStateFollow()
{
	CVector3 targetPos = m_mikyan->position + m_offsetPos;
//	if (m_position.x > targetPos.x) {
		//�ǔ��B
		CVector3 moveDir = targetPos - m_position;
		moveDir.Normalize();
		//�����ɔ�Ⴕ�Ĉړ������グ��B
		CVector3 moveSpeed = moveDir * 250.0f * min( 2.0f, pow(fabsf(targetPos.x - m_position.x) * 0.005f, 2.0f) * GameTime().GetFrameDeltaTime() );
		m_position += moveSpeed;
		m_count++;
		if (m_count % 10 == 0) {
			m_yspeed = m_yspeed * -1.0f;
		}

		m_position.y += m_yspeed;
		if (m_position.y <= 0) {
			m_position.y = 0.0f;
		}
		
		
		
//	}
	CVector3 dir = m_mikyan->position - m_position;
	m_rotation.SetRotation(CVector3::AxisY, -atan2f(dir.z, dir.x) - CMath::PI * 0.5f);
}
bool Npc::Start()
{
	return true;
}
