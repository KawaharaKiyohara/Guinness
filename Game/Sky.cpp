#include "stdafx.h"
#include "Sky.h"


Sky::Sky()
{
}


Sky::~Sky()
{
	DeleteGO(m_skinModelRender);

}
bool Sky::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/sky.cmo");
	return true;
}
void Sky::Update()
{
}