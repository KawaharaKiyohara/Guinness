#include "stdafx.h"
#include "Mikyan.h"


Mikyan::Mikyan()
{
}


Mikyan::~Mikyan()
{
	DeleteGO(skinModelRender);
}
bool Mikyan::Start()
{
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/unityChan.cmo");
	skinModelRender->SetShadowCasterFlag(true);
	skinModelRender->SetShadowReceiverFlag(true);
	return true;
}
void Mikyan::Update()
{
	//ƒeƒXƒg
	auto stick = CVector2(Pad(0).GetLStickXF(), Pad(0).GetLStickYF());
	position.x += stick.x * -10.0f;
	position.z += stick.y * -10.0f;
	skinModelRender->SetPosition(position);

}