#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

//ヘッダに書くのがポインタ変数だけなら、クラス宣言だけでおｋ。
class Mikyan;
class AppCamera;
class Ground;
class Sky;
class Npc;
class Counter;
class NpcRender;
class MikyanWindow;

class Game : public IGameObject
{
private:
	void InitLight();
	void InitNpc();
public:
	static const int GUINESS_RECORD = 1000;		//ギネスレコード
	static const int KAWAHARA_TARGET = 1200;	//河原学園の目標。

	using OnCountUp = std::function<void(int count)>;
	Game();
	~Game();
	bool Start();
	void Update();
	//カウントアップリスナーを追加。
	void AddCountUpListener(OnCountUp cb)
	{
		m_countUpListener.push_back(cb);
	}
	Mikyan* m_mikyan = nullptr;		//みきゃん。
	AppCamera* m_camera = nullptr;	//カメラ。
	Ground* m_ground = nullptr;		//地面。
	Sky* m_sky = nullptr;			//空。
	MikyanWindow* m_mikyanWindow = nullptr;	//みきゃんを移す小窓。
	std::vector<prefab::CDirectionLight*> m_lights;	//ｌｉｇｈｔ。
	std::vector<Npc*> m_npc;		//NPC;
	Counter* m_counter = nullptr;	//カウンター。
	std::vector<OnCountUp> m_countUpListener;		//カウントアップのリスナー。
	prefab::CSoundSource* m_bgm = nullptr;
	std::vector<NpcRender*> m_npcRenderList;
	
};

