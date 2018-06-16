#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

//ヘッダに書くのがポインタ変数だけなら、クラス宣言だけでおｋ。
class Mikyan;
class AppCamera;
class Ground;
class Sky;
class Npc;
class Counter;

class Game : public IGameObject
{
private:
	void InitLight();
	void InitNpc();
public:
	using OnCountUp = std::function<void()>;
	Game();
	~Game();
	bool Start();
	void Update();
	Mikyan* m_mikyan = nullptr;		//みきゃん。
	AppCamera* m_camera = nullptr;	//カメラ。
	Ground* m_ground = nullptr;		//地面。
	Sky* m_sky = nullptr;			//空。
	std::vector<prefab::CDirectionLight*> m_lights;	//ｌｉｇｈｔ。
	std::vector<Npc*> m_npc;		//NPC;
	Counter* m_counter = nullptr;	//カウンター。
	std::vector<OnCountUp> m_countUpListener;		//カウントアップのリスナー。
	
};

