#include "pch.h"
#include "MainGame.h"

void MainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);
	GameManager::GetInstance()->Init();
}

void MainGame::Update()
{
	GameManager::GetInstance()->Update();
}

void MainGame::Render()
{
	GameManager::GetInstance()->Render(m_hdc);
}

void MainGame::Release()
{
}

MainGame::~MainGame()
{
	Release();
}
