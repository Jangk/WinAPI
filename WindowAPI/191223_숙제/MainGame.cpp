#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Shield.h"
#include "Bullet.h"
#include "Monster.h"
#include <ctime>

//extern
GameObject* g_Player;


void MainGame::Initialize()
{
	m_iCount = 0;
	m_hdc = GetDC(g_hWnd);
	srand((unsigned int)time(nullptr));


	// Player 관련
	m_ObjectList[PLAYER].push_back(GameObjectCreator<Player>::CreateGameObject(SCREEN_X/2 , SCREEN_Y/2));
	m_ObjectList[PLAYER_SHEILD].push_back(GameObjectCreator<Shield>::CreateGameObject(SCREEN_X / 2, SCREEN_Y / 2));
	for(int i =0; i<100; ++i)
		m_ObjectList[PLAYER_BULLET].push_back(GameObjectCreator<Bullet>::CreateGameObject());
	dynamic_cast<Player*>(m_ObjectList[PLAYER].front())->SetShield(&m_ObjectList[PLAYER_SHEILD]);
	dynamic_cast<Player*>(m_ObjectList[PLAYER].front())->SetMonster(&m_ObjectList[MONSTER]);
	dynamic_cast<Player*>(m_ObjectList[PLAYER].front())->SetBullets(&m_ObjectList[PLAYER_BULLET]);
	g_Player = m_ObjectList[PLAYER].front();


	// Monster 관련
	for (int i =0 ; i< 3; ++i)
		m_ObjectList[MONSTER].push_back(GameObjectCreator<Monster>::CreateGameObject(rand()% SCREEN_X, rand()%SCREEN_Y));
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
