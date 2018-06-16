#pragma once
class NpcRender : public IGameObject
{
public:
	NpcRender();
	~NpcRender();
	void Init( int numInstance, const wchar_t* modelPath );
	void PreUpdate()override;
	void UpdateWorldMatrix( CVector3 trans, CQuaternion rot );
	void PostUpdate()override;
	void Render(CRenderContext& rc) override;
private:
	CSkinModelData m_skinModelData;	//スキンモデルデータ。
	CSkinModel m_skinModel;
	int m_numInstance = 0;
	
};

