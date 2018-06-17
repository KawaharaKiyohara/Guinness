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
	int GetCount() const
	{
		return m_count;
	}
private:
	CFont m_font;		//フォント。
	int m_count = 0;
};

