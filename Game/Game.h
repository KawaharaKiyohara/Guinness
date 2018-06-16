#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

//�w�b�_�ɏ����̂��|�C���^�ϐ������Ȃ�A�N���X�錾�����ł����B
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
	Mikyan* m_mikyan = nullptr;		//�݂����B
	AppCamera* m_camera = nullptr;	//�J�����B
	Ground* m_ground = nullptr;		//�n�ʁB
	Sky* m_sky = nullptr;			//��B
	std::vector<prefab::CDirectionLight*> m_lights;	//�����������B
	std::vector<Npc*> m_npc;		//NPC;
	Counter* m_counter = nullptr;	//�J�E���^�[�B
	std::vector<OnCountUp> m_countUpListener;		//�J�E���g�A�b�v�̃��X�i�[�B
	
};

