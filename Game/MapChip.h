#pragma once
class MapChip : public IGameObject

{
public:
	MapChip();
	~MapChip();
	bool Start();
	std::wstring m_modelName;
	CVector3 m_position = CVector3::Zero;				//ç¿ïWÅB
	CQuaternion m_rotation = CQuaternion::Identity;		//âÒì]ÅB
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
};



