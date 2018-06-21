#include "stdafx.h"
#include "MikyanWIndow.h"
#include "Mikyan.h"

MikyanWindow::MikyanWindow()
{
}


MikyanWindow::~MikyanWindow()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_bgSpriteRender);
}

bool MikyanWindow::Start()
{
	DXGI_SAMPLE_DESC multiSampleDesc;
	ZeroMemory(&multiSampleDesc, sizeof(multiSampleDesc));
	multiSampleDesc.Count = 1;
	multiSampleDesc.Quality = 0;
	m_renderTarget.Create(
		512,
		512,
		1,
		1,
		DXGI_FORMAT_R8G8B8A8_UNORM,
		DXGI_FORMAT_D32_FLOAT,
		multiSampleDesc
	);

	m_bgSpriteRender = NewGO<prefab::CSpriteRender>(0);
	m_bgSpriteRender->Init(L"sprite/MiyanWindowBG.dds", 256, 256);
	m_bgSpriteRender->SetPivot({ 1.0f, 0.0f });
	m_bgSpriteRender->SetPosition({ 640, -360, 0.0f });

	m_mikyanRender = NewGO<prefab::CSpriteRender>(0);
	m_mikyanRender->Init(m_renderTarget.GetRenderTargetSRV(), 256, 256);
	m_mikyanRender->SetPivot({ 1.0f, 0.0f });
	m_mikyanRender->SetPosition({ 640, -360, 0.0f });

	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/MikyanWindow.dds", 256, 256);
	m_spriteRender->SetPivot({ 1.0f, 0.0f });
	m_spriteRender->SetPosition({ 640, -360, 0.0f });
	
	m_mikyan = FindGO<Mikyan>("みきゃん");
	m_psShader.Load("shader/model.fx", "PS2DMikyan", CShader::EnType::PS);
	return true;
}
void MikyanWindow::Update()
{
}
void MikyanWindow::Render(CRenderContext& rc)
{
	GraphicsEngine().BeginGPUEvent(L"MikyanWindow::Render");

	//みきゃんをオフスクリーンレンダリング。
	CSkinModel& model = m_mikyan->skinModelRender->GetSkinModel();
	CVector3 target = m_mikyan->position;
	target.z -= 25.0f;
	target.y = 140.0f;
	m_mikyanCamera.SetTarget(target);

	CVector3 pos = target;
	pos.x -= 250.0f;
	m_mikyanCamera.SetPosition(pos);
	m_mikyanCamera.SetNear(0.1f);
	m_mikyanCamera.SetFar(500.0f);
	m_mikyanCamera.SetAspect(1.0f);
	m_mikyanCamera.Update();
	//レンダリングターゲットをクリア
	CRenderTarget* oldRenderTargets[MRT_MAX];
	unsigned int numRenderTargetViews;
	rc.OMGetRenderTargets(numRenderTargetViews, oldRenderTargets);
	float clearColor[] = {
		0.0f, 0.0f, 0.0f, 0.0f
	};
	CRenderTarget* rts[] = {
		&m_renderTarget
	};
	rc.OMSetRenderTargets(1, rts);
	rc.RSSetViewport(0.0f, 0.0f, (float)m_renderTarget.GetWidth(), (float)m_renderTarget.GetHeight());

	rc.ClearRenderTargetView(0, clearColor);
	//2Dみきゃん用のシェーダーに切り替える。
	model.FindMaterial([&](auto mat) {
		mat->SetRender3DModelPSShader(m_psShader);
	});
	model.Draw(rc, m_mikyanCamera.GetViewMatrix(), m_mikyanCamera.GetProjectionMatrix());
	
	//レンダリングターゲットをもどす。
	rc.OMSetRenderTargets(numRenderTargetViews, oldRenderTargets);
	rc.RSSetViewport(0.0f, 0.0f, (float)oldRenderTargets[0]->GetWidth(), (float)oldRenderTargets[0]->GetHeight());

	//シェーダーを戻す。
	model.FindMaterial([&](auto mat) {
		mat->SetRender3DModelDefaultShader();
	});

	GraphicsEngine().EndGPUEvent();
}
