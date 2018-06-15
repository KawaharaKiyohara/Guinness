#include "stdafx.h"
#include "Ground.h"


Ground::Ground()
{
}


Ground::~Ground()
{
	DeleteGO(m_skinModelRender);
}

void Ground::Update()
{
}
bool Ground::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/ground.cmo");
	m_skinModelRender->SetShadowReceiverFlag(true);
	return true;
}