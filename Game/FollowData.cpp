#include "stdafx.h"
#include "FollowData.h"


FollowData::FollowData()
{
	offsetPos[0] = { 1.0f, 0.0f, 0.0f };		//ê^å„ÇÎÅB
	offsetPos[1] = { 0.707, 0.0f, 0.707f };	//éŒÇﬂ45Åã
	offsetPos[2] = { 0.707, 0.0f, -0.707f };	//éŒÇﬂ45Åã
	offsetPos[0] *= 100.0f;
	offsetPos[1] *= 100.0f;
	offsetPos[2] *= 100.0f;
}


FollowData::~FollowData()
{
}
