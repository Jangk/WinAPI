#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Shield.h"


void MainGame::Initialize()
{
	m_iCount = 0;
	m_hdc = GetDC(g_hWnd);
	m_ObjectList[PLAYER].push_back(GameObjectCreator<Player>::CreateGameObject(SCREEN_X/2 , SCREEN_Y/2));
	m_ObjectList[PLAYER_SHEILD].push_back(GameObjectCreator<Shield>::CreateGameObject(SCREEN_X / 2, SCREEN_Y / 2));
	dynamic_cast<Player*>(m_ObjectList[PLAYER].front())->SetShield(&m_ObjectList[PLAYER_SHEILD]);
}

void MainGame::Update()
{
	for (int i = 0; i < OBJECT_TYPE_END; ++i)
	{
		for (auto iter : m_ObjectList[i])
			iter->Update();
	}
}

void MainGame::Render()
{
	//m_iCount++;
	//if (m_iCount >= 10)
	//{
	//	Rectangle(m_hdc, -1, -1, SCREEN_X, SCREEN_Y);
	//	m_iCount = 0;
	//}
	for (int i = 0; i < OBJECT_TYPE_END; ++i)
	{
		for (auto iter : m_ObjectList[i])
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
