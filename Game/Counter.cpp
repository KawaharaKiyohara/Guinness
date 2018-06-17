#include "stdafx.h"
#include "Counter.h"
#include "Game.h"
#include "EffectPlay.h"

Counter::Counter()
{
}


Counter::~Counter()
{
}
bool Counter::Start()
{
	Game* game = FindGO<Game>("Game");
	game->m_countUpListener.push_back([&]() {
		OnCountup();
	});
	m_font.SetShadowParam(true, 3.0f, CVector4::Black);
	return true;
}
void Counter::Update()
{
}
void Counter::OnCountup()
{
	m_count++;

	NewGO<EffectPlay>(0);

}
void Counter::PostRender(CRenderContext& rc)
{

	m_font.Begin(rc);
	wchar_t text[256];
	swprintf(text, L"%d", m_count);
	m_font.Draw(text, { 0.0f, 200.0f }, CVector4::Yellow, 0.0f, 2.0f);
	m_font.End(rc);
}