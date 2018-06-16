#include "stdafx.h"
#include "NpcRender.h"


NpcRender::NpcRender()
{
}


NpcRender::~NpcRender()
{
}
void NpcRender::Init(int numInstance, const wchar_t* modelPath)
{
	m_skinModelData.Load(modelPath);
	m_skinModel.Init(m_skinModelData, numInstance);
	m_skinModel.SetShadowCasterFlag(true);
	m_skinModel.SetShadowReceiverFlag(true);
}
void NpcRender::PreUpdate()
{
	m_skinModel.BeginUpdateInstancingData();
}
void NpcRender::UpdateWorldMatrix(CVector3 trans, CQuaternion rot)
{
	m_skinModel.UpdateInstancingData(trans, rot, CVector3::One);
}
void NpcRender::PostUpdate()
{
	m_skinModel.EndUpdateInstancingData();
}
void NpcRender::Render(CRenderContext& rc)
{
	m_skinModel.Draw(rc);
}
