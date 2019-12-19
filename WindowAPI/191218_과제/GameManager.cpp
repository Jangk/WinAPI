#include "pch.h"
#include "GameManager.h"


GameManager* GameManager::m_Instance = nullptr;


GameManager* GameManager::GetInstance()
{
	if (nullptr == m_Instance)
		m_Instance = new GameManager;
	return m_Instance;
}

   
void GameManager::Initialize()
{
	srand(unsigned int(time(NULL)));
	m_HDC = GetDC(g_hWnd);
	m_Player = new Player;
	m_Player->Initialize();

	Monster* monster;
	for (int i = 0; i < MONSTER_MAX; ++i)
	{
		monster = new Monster;
		monster->Initialize();						// 테투리에 걸치지 않게 300 안전거리
		monster->SetPos(rand() % (SCREEN_WIDTH - 500), rand() % (SCREEN_HEIGHT - 500));
		m_MonsterList.push_back(monster);
	}
}

void GameManager::Update()
{
	m_Player->UpdateRect();
	m_Player->Update();
	for (auto& monster : m_MonsterList)
	{
		monster->UpdateRect();
		monster->Update();
		for (auto& bullet : dynamic_cast<Player*>(m_Player)->GetBullets())
			monster->CollisionBullet(bullet);
	}
}


void GameManager::Render()
{
	// 사각형 테투리 안보일려거 -1  // 지우는것보다 상자하나 그려서 기존꺼 가리는게 더 빠름
	Rectangle(m_HDC, -1, -1, SCREEN_WIDTH, SCREEN_HEIGHT);
	m_Player->Render(m_HDC);
	for (auto& monster : m_MonsterList)
		monster->Render(m_HDC);
}

void GameManager::Release()
{
	m_Player->Release();
	SAFE_DELETE(m_Player);
	for (auto& monster : m_MonsterList)
	{
		monster->Release();
		SAFE_DELETE(monster);
	}
}

GameManager::~GameManager()
{
	Release();
}
