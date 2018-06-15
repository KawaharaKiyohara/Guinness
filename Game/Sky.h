#pragma once
class Sky : public IGameObject
{
public:
	Sky();
	~Sky();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
};

