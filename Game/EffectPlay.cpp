#include "stdafx.h"
#include "EffectPlay.h"

bool EffectPlay::Start()
{

	//�G�t�F�N�g�̃C���X�^���X�̍쐬�B
	prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
	effect->Play(L"effect/hanabi.efk");	//�Đ�
	effect->SetScale({ 200.0f,200.0f,200.0f });
	effect->SetPosition({0.0f,150.0f,-1000.0f});

	return true;

}
