#pragma once
class Counter : public IGameObject
{
public:
	Counter();
	~Counter();
	bool Start() override;
	void Update() override;
	void PostRender(CRenderContext& rc) override;
	//�J�E���g�A�b�v�B
	void OnCountup();
private:
	CFont m_font;		//�t�H���g�B
	int m_count = 0;
};

