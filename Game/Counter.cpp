#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Counter.h"
#include "Game.h"
#include "EffectPlay.h"

#if BUILD_LEVEL != BUILD_LEVEL_MASTER
//#define USE_SAVE_DATA		//有効でセーブデータを使う
#else
#define USE_SAVE_DATA		//有効でセーブデータを使う。マスタービルドでは必ず有効になる。
#endif

Counter::Counter()
{
}


Counter::~Counter()
{
}
bool Counter::Start()
{
	Game* game = FindGO<Game>("Game");
	game->m_countUpListener.push_back([&](int count) {
		OnCountup();
	});
	m_font.SetShadowParam(true, 3.0f, CVector4::Black);
#ifdef USE_SAVE_DATA
	//ここでセーブデータを読み込んで、m_countに反映させる。
	FILE *fp;
	fp = fopen("test.txt", "r");
	if (fp != NULL) {
		fread(hoge, 1, 5, fp);
		fclose(fp);
		m_count = atoi(hoge);
	}
#endif
	return true;
}
void Counter::Update()
{
}
void Counter::OnCountup()
{
	m_count++;
	//ファイルの保存
	FILE *fp;
	fp = fopen("test.txt", "w");
	if (fp != NULL) {
		fprintf(fp, "%d", m_count);
		fclose(fp);
	}

}
void Counter::PostRender(CRenderContext& rc)
{

	m_font.Begin(rc);
	wchar_t text[256];
	swprintf(text, L"%d", m_count);
	m_font.Draw(text, { -80.0f, 200.0f }, CVector4::Yellow, 0.0f, 2.0f);
	m_font.End(rc);
}