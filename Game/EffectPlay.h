#pragma once

class EffectPlay : public IGameObject
{
public:
	EffectPlay();
	~EffectPlay();
	bool Start();
	std::wstring animation;
	CVector3 scale;
	CVector3 position;
};

