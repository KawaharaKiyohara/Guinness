#pragma once

class Mikyan;

class Sky : public IGameObject
{
public:
	Sky();
	~Sky();
	bool Start();
	void Update();
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CShader m_shader;
	Mikyan* m_mikyan = nullptr;
};

