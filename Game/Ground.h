#pragma once
class Ground : public IGameObject
{
public:
	Ground();
	~Ground();
	void Update();
	bool Start();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
};

