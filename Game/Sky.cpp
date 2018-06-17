#include "stdafx.h"
#include "Sky.h"
#include "Mikyan.h"

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

	m_shader.Load("shader/model.fx", "PSMainSky", CShader::EnType::PS);

	m_skinModelRender->FindMaterial([&](auto material) {
		material->SetRender3DModelPSShader(m_shader);
	});
	m_mikyan = NewGO<Mikyan>(0);
	return true;
}
void Sky::Update()
{
	CVector3 pos = m_mikyan->position;
	pos.y = 0.0f;
	m_skinModelRender->SetPosition(pos);
}