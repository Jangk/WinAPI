#include "pch.h"
#include "MainGame.h"
#include "Player.h"


void MainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);
	m_ObjectList[PLAYER].push_back(GameObjectCreator<Player>::CreateGameObject(SCREEN_X/2 , SCREEN_Y/2));
}

void MainGame::Update()
{
	for (int i = 0; i < OBJECT_TYPE_END; ++i)
	{
		for (auto iter : m_ObjectList[PLAYER])
			iter->Update();
	}
}

void MainGame::Render()
{
	//Rectangle(m_hdc, -1, -1, SCREEN_X, SCREEN_Y);
	for (int i = 0; i < OBJECT_TYPE_END; ++i)
	{
		for (auto iter : m_ObjectList[PLAYER])
			iter->Render(m_hdc);
	}
}

void MainGame::Release()
{
}

MainGame::~MainGame()
{
	Release();
}
