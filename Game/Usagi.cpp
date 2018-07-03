#include "stdafx.h"
#include "Usagi.h"
#include "Game.h"
#include "Mikyan.h"




Usagi::Usagi()
{
}


Usagi::~Usagi()
{
	DeleteGO(skinModelRender);
}
bool Usagi::Start()
{
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/usagigi.cmo");
	skinModelRender->SetShadowCasterFlag(true);
	skinModelRender->SetShadowReceiverFlag(true);
	Game* game = FindGO<Game>("Game");
	u_rotation.SetRotationDeg(CVector3::AxisX, 90.0f);
	skinModelRender->SetRotation(u_rotation);//回転
	return true;
}


void Usagi::OnStateFolloMikyan()
{
	if (u_position.y < 0.1f) {
		u_moveSpeed = 5.0f;
	}
	Mikyan* mikyan = FindGO<Mikyan>("みきゃん");
	CVector3 v = mikyan->position - u_position;
	v.y = 0.0f;
	v.Normalize();
	CVector3 diff = mikyan->position - u_position;
	diff.y = 0.0f;
	if (diff.Length() < 11.0f) {
		u_position.x = mikyan->position.x;
		u_position.z = mikyan->position.z;
	}
	else {
		u_position += v * 11;
	}
	skinModelRender->SetPosition(u_position);//座標
}
void Usagi::OnStateStop()
{
	u_position.x ;
}
void Usagi::OnStateJump()
{
	
	//u_position.x += 2.0f * u_moveDir;
	if (u_position.y < 0.1f) {
		u_moveSpeed = 5.0f;
	}
	
	skinModelRender->SetPosition(u_position);//座標
	skinModelRender->SetRotation(u_rotation);//回転

}
void Usagi::Update()
{
	switch (u_state) {
	case State_FollowMikyan: 
		//みきゃんを追いかけている状態。
		OnStateFolloMikyan();
		break;
	case State_Stop:
		//立ち止まっている状態。
		OnStateStop();
		break;
	case State_Jump:
		//飛び跳ねている状態
		OnStateJump();
		break;
	}
	//重力かそく
	
	u_moveSpeed -= 0.5f;
	u_position.y += u_moveSpeed;
	if (u_position.y < 0) {
		u_moveSpeed = 0.0f;
		u_position.y = 0.0f;
	}
	skinModelRender->SetPosition(u_position);//座標
	//状態決定処理
	u_timer += GameTime().GetFrameDeltaTime();
	Mikyan* mikyan = FindGO<Mikyan>("みきゃん");
	CVector3 v = mikyan->position - u_position;
	if (v.Length() > 300.0f) {
		//必ず状態を追尾にする。
		u_state = State_FollowMikyan;
	}
	else {
		if (u_timer > 2.0f) {
			//10以内にいるときはランダムで状態変化。
			float t = Random().GetRandDouble();
			if (t < 0.1f) {
				//10%の確率で、待機状態に遷移
				u_state = State_Stop;
			}
			else if (t < 0.6f) {
				//10%の確率で、飛び跳ね状態に遷移
				u_state = State_Jump;
			}
			
			u_timer = 0.0f;
		}
	}
	/*	Mikyan* mikyan = FindGO<Mikyan>("みきゃん");
		CVector3 v = mikyan->position - u_position;
		v.Normalize();
		CVector3 diff = mikyan->position - u_position;
		if (diff.Length() < 4.0f) {
			u_position = mikyan->position;
		}else if (diff.Length() < 200.0f) {
			u_position += v * 4;
		}
		else {
			u_position += v * 10;
		}
		

		skinModelRender->SetPosition(u_position);//座標
	*/
}

