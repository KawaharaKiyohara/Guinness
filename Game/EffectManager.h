#pragma once

class Mikyan;
class AppCamera;

class EffectManager : public IGameObject
{
public:
	EffectManager();
	~EffectManager();
	void Update();
	//�J�E���g�A�b�v�̃R�[���o�b�N�B
	void OnCountUp(int count);
	Mikyan* m_mikyan = nullptr;//�݂����
	AppCamera* m_camera = nullptr;//�J����
	void PostRender(CRenderContext& rc) override;

	private:
	CFont m_font;		//�t�H���g�B
	bool m_isNewRecordFlag;
	int m_isNewRecordCount = 0;
	int m_finalCount = 0;

};

