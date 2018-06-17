#pragma once

class Mikyan;

class MikyanWindow : public IGameObject
{
public:
	MikyanWindow();
	~MikyanWindow();
	bool Start() override;
	void Update() override;
	void Render(CRenderContext& rc) override;
private:
	prefab::CSpriteRender* m_bgSpriteRender = nullptr;
	prefab::CSpriteRender* m_spriteRender = nullptr;
	prefab::CSpriteRender* m_mikyanRender = nullptr;
	CRenderTarget m_renderTarget;
	Mikyan* m_mikyan = nullptr;
	CCamera m_mikyanCamera;	//‚İ‚«‚á‚ñƒJƒƒ‰B
	CShader m_psShader;
};

