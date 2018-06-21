#include "stdafx.h"
#include "MapChip.h"


MapChip::MapChip()
{
}


MapChip::~MapChip()
{
	DeleteGO(m_skinModelRender);
}
bool MapChip::Start()
{
	wchar_t modelFullPath[256];
	swprintf(modelFullPath, L"modelData/%ls.cmo", m_modelName.c_str());
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(modelFullPath);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	return true;
}
