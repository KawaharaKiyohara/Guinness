#pragma once
#include "Npc.h"
class Npc;
//通常アクションのインターフェイスクラス。
class INpcNormalAction
{
public:
	INpcNormalAction(Npc* npc);
	~INpcNormalAction();
	//アクションを実行。
	virtual void Action() = 0;

	Npc* m_npc = nullptr;
};

