#include "stdafx.h"
#include "GoalCamera.h"
#include "Mikyan.h"


GoalCamera::GoalCamera(AppCamera* camera) :
	IAppCameraMove(camera)
{
	//�݂�������������B
	m_mikyan = FindGO<Mikyan>("�݂����");

}

GoalCamera::~GoalCamera()
{
}

void GoalCamera::Move()
{
	if (m_state == 0) {
		//�X�e�[�g�ϐ����P�̂Ƃ��͐^���Ɉړ��B
		cameraX = -600;
		cameraY = 400;
		cameraZ = -1000;

		CVector3 cameraTarget = m_mikyan->position;
		cameraTarget.y = m_mikyan->position.y + 200.0f; //�v���C���[�̂�����Ə�ɂ���B 
		m_appCamera->m_springCamera.SetTarget(cameraTarget);

		CVector3 cameraPos = m_mikyan->position;
		cameraPos.x -= cameraX;
		cameraPos.y += cameraY;
		cameraPos.z += cameraZ; //���_���J�����ɓ`����B 
		m_appCamera->m_springCamera.SetPosition(cameraPos);
		m_appCamera->m_springCamera.Refresh();
		m_appCamera->m_springCamera.Update();
		//�J�����ړ�
		cameraPos = m_mikyan->position;
		cameraPos.y += 400;
		cameraPos.z -= 1000;
		m_appCamera->m_springCamera.SetPosition(cameraPos);

		m_state = 1;
	}
	else if (m_state == 1) {
		//�X�e�[�g���P�̂Ƃ��݂͂����̐^���Ɉړ�����B
		//���ۂ̎��_�̍��W���擾����͉̂��L�̃R�[�h
		CVector3 realPos = m_appCamera->m_springCamera.GetRealPosition();
		//�ڕW���_�͉��L
		CVector3 tarPos = m_appCamera->m_springCamera.GetPosition();
		//���̓���g���āA�Q�_�Ԃ̋������v�Z���āA���ꂪ10�ȉ��ɂȂ�����
		//�O�Ɉړ����鎋�_��ݒ肵�āA�X�e�[�g��2�ɂ���B
		CVector3 diff = realPos - tarPos;
		float len = diff.Length();// sqrt(diff.x * diff.x + diff.y * diff.y + diff.z * diff.z);
		if (len<=300) {
			m_state = 2;
		}		
	}
	else if (m_state == 2) {
		//�J�����ړ�
		CVector3 cameraPos = m_mikyan->position;
		cameraPos.z += 200;
		cameraPos.y += 400;
		cameraPos.x -= 600;
		m_appCamera->m_springCamera.SetPosition(cameraPos);

		m_state = 3;

	}



}


