#pragma once

class Mikyan;
class AppCamera;

class EffectManager : public IGameObject
{
public:
	EffectManager();
	~EffectManager();
	void Update();
	//カウントアップのコールバック。
	void OnCountUp(int count);
	Mikyan* m_mikyan = nullptr;//みきゃん
	AppCamera* m_camera = nullptr;//カメラ
	void PostRender(CRenderContext& rc) override;

	private:
	CFont m_font;		//フォント。
	bool m_isNewRecordFlag;
	int m_isNewRecordCount = 0;
	int m_finalCount = 0;

};

