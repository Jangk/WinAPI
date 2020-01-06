#include "pch.h"
#include "Player.h"
#include "GameManager.h"

GameManager* GameManager::m_Instance = nullptr;

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

GameManager* GameManager::GetInstance()
{
	if (nullptr == m_Instance)
		m_Instance = new GameManager;
	return m_Instance;
}

// ���� ��� �Լ�.
void GameManager::AddPoint(float x, float y)
{
	FPOINT* point = new FPOINT;
	point->x = x;
	point->y = y;
	m_Point.push_back(point);
}

void GameManager::SetScreenMove(float x)
{
	m_fScreenMoveX += x;
}

float GameManager::GetScreenMove()
{
	return m_fScreenMoveX;
}

void GameManager::LineToPoint(HDC hdc)
{	// Ŭ���� �� ���� ������ �� ����.
	m_fScreenMoveX = 0;
	
	int iCount = 0;
	if (m_Point.size() != 0)
	{
		MoveToEx(hdc, (*m_Point.begin())->x, (*m_Point.begin())->y, nullptr);
		for (auto iter : m_Point)
		{
			if (m_Point.size() == iCount)
				break;
			LineTo(hdc, (*iter).x, (*iter).y);
			iCount++;
		}
	}
}

void GameManager::ComparePos()
{	// �÷��̾� ��ġ�� ���� ��ġ ���
	float cal = 0;
	float playerX = m_ObjectList[PLAYER].front()->GetInfo().fX;
	float playerY =	m_ObjectList[PLAYER].front()->GetInfo().fY;

	
	for (int i = 0; i < m_Point.size()-1; ++i)
	{
		if (m_Point.size() == 0)
				break;
		if (m_Point[i]->x <= playerX && playerX < m_Point[i + 1]->x)
		{	// Ư�� ���� �ȿ� ������
			// x = �÷��̾� ��ġ.
			// **  y = (y2 - y1) / (x2 - x1) * (x - x1) + y1	// ������ ������ ����
			if(m_Point[i + 1]->y >= m_Point[i]->y)
				cal = (m_Point[i + 1]->y - m_Point[i]->y) / (m_Point[i + 1]->x - m_Point[i]->x) * (playerX - m_Point[i]->x) + m_Point[i]->y;
			else
				cal = (m_Point[i]->y - m_Point[i+1]->y) / (m_Point[i]->x - m_Point[i+1]->x) * (playerX - m_Point[i+1]->x) + m_Point[i+1]->y;

			if(playerY > cal)
				m_ObjectList[PLAYER].front()->SetPos(playerX, cal);
		}
	}
}



// �⺻ ���� �Լ�
void GameManager::Init()
{
	m_fCount = 0;
	m_ObjectList[PLAYER].push_back(CreateManager<Player>::CreateObject(SCREEN_X / 2, SCREEN_Y / 2));
}

int GameManager::Update()
{
	ComparePos();

	for (auto iter : m_ObjectList)
	{
		for (auto iter2 : iter)
			iter2->Update();
	}

	for (auto iter : m_Point)
		iter->x -= m_fScreenMoveX;
	return 0;
}

void GameManager::Render(HDC hdc)
{
	//Rectangle(hdc, 0, 0, SCREEN_X, SCREEN_Y);
	// Ŭ���� ������ �� ����.
	LineToPoint(hdc);

	for (auto iter : m_ObjectList)
	{
		for (auto iter2 : iter)
			iter2->Render(hdc);
	}
}


