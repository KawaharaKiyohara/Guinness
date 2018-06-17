#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

//�w�b�_�ɏ����̂��|�C���^�ϐ������Ȃ�A�N���X�錾�����ł����B
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
	static const int GUINESS_RECORD = 1000;		//�M�l�X���R�[�h
	static const int KAWAHARA_TARGET = 1200;	//�͌��w���̖ڕW�B

	using OnCountUp = std::function<void(int count)>;
	Game();
	~Game();
	bool Start();
	void Update();
	//�J�E���g�A�b�v���X�i�[��ǉ��B
	void AddCountUpListener(OnCountUp cb)
	{
		m_countUpListener.push_back(cb);
	}
	Mikyan* m_mikyan = nullptr;		//�݂����B
	AppCamera* m_camera = nullptr;	//�J�����B
	Ground* m_ground = nullptr;		//�n�ʁB
	Sky* m_sky = nullptr;			//��B
	MikyanWindow* m_mikyanWindow = nullptr;	//�݂������ڂ������B
	std::vector<prefab::CDirectionLight*> m_lights;	//�����������B
	std::vector<Npc*> m_npc;		//NPC;
	Counter* m_counter = nullptr;	//�J�E���^�[�B
	std::vector<OnCountUp> m_countUpListener;		//�J�E���g�A�b�v�̃��X�i�[�B
	prefab::CSoundSource* m_bgm = nullptr;
	std::vector<NpcRender*> m_npcRenderList;
	
};

