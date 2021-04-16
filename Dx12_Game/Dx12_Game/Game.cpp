#include "pch.h"
#include "Game.h"
#include "Engine.h"

void Game::Init(const WindowInfo& info)
{
	g_Engine->Init(info);
}

void Game::Update()
{
	g_Engine->Render();
}
