#pragma once
//追尾用のデータクラス。
class Npc;
class FollowData
{
public:
	static const int MAX_FOLLOW = 3;
	FollowData();
	~FollowData();
	Npc* m_npc[MAX_FOLLOW] = { nullptr };			//追尾可能なNPCの数は３
	CVector3 offsetPos[MAX_FOLLOW];
};

