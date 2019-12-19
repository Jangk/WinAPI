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
		monster->Initialize();						// �������� ��ġ�� �ʰ� 300 �����Ÿ�
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
	// �簢�� ������ �Ⱥ��Ϸ��� -1  // ����°ͺ��� �����ϳ� �׷��� ������ �����°� �� ����
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
