#include "pch.h"
#include "GameManager.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"

GameManager* GameManager::m_Instance = nullptr;

GameManager* GameManager::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new GameManager;
	return m_Instance;
}

void GameManager::Initialize()
{
	m_HDC = GetDC(g_hWnd);
	m_ObjectList[PLAYER].push_back(GameObjectCreator<Player>::CreateGameObject(SCREEN_X * 0.5, SCREEN_Y * 0.5));
	dynamic_cast<Player*>(m_ObjectList[PLAYER].front())->SetBulletList(&m_ObjectList[PLAYER_BULLET]);
	
	
	for (int i = 0; i < MONSTER_MAX; ++i)
		m_ObjectList[MONSTER].push_back(
			GameObjectCreator<Monster>::CreateGameObject(rand() % SCREEN_X, rand() % SCREEN_X)
		);
}

void GameManager::Update()
{
	for (int i = 0; i < GAMEOBJECT_END; ++i)
	{
		for (auto iter = m_ObjectList[i].begin();
			iter != m_ObjectList[i].end();)
		{
			if (DEAD == (*iter)->Update())
				iter = m_ObjectList[i].erase(iter);
			else
				++iter;
		}
	}
	Collision::CollisionRect(m_ObjectList[MONSTER], m_ObjectList[PLAYER]);
	//Collision::CollisionRect(m_ObjectList[PLAYER], m_ObjectList[MONSTER]);
	Collision::CollisionSphere(m_ObjectList[MONSTER], m_ObjectList[PLAYER_BULLET]);
	Collision::CollisionSphere(m_ObjectList[PLAYER], m_ObjectList[MONSTER_BULLET]);
}

void GameManager::Render()
{	// 화면 갱신용1
	Rectangle(m_HDC, -1, -1, SCREEN_X, SCREEN_Y);
	for (int i = 0; i < GAMEOBJECT_END; ++i)
	{
		for (auto iter = m_ObjectList[i].begin();
			iter != m_ObjectList[i].end();
			++iter)
			(*iter)->Render(m_HDC);
	}
}

void GameManager::Release()
{
	SAFE_DELETE(m_Instance);
	for (int i = 0; i < GAMEOBJECT_END; ++i)
	{
		for (auto iter = m_ObjectList[i].begin();
			iter != m_ObjectList[i].end();
			++iter)
			SAFE_DELETE(*iter);
		m_ObjectList[i].clear();
	}
}

GameManager::~GameManager()
{
	Release();
}