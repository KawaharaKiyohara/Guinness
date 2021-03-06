#pragma once
class MapChip : public IGameObject

{
public:
	MapChip();
	~MapChip();
	bool Start();
	std::wstring m_modelName;
	CVector3 m_position = CVector3::Zero;				//座標。
	CQuaternion m_rotation = CQuaternion::Identity;		//回転。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
};



