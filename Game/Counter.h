#pragma once
class Counter : public IGameObject
{
public:
	Counter();
	~Counter();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& rc) override;
	//カウントアップ。
	void OnCountup();
private:
	CFont m_font;		//フォント。
	int m_count = 0;
};

