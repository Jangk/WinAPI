#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"

CMaingame::CMaingame()
{
}

CMaingame::~CMaingame()
{
	Release();
}

void CMaingame::Initialize()
{
	srand(unsigned(time(nullptr)));

	m_hDC = GetDC(g_hWnd);	

	// Player	
	m_ObjectList[PLAYER].push_back(CObjectFactory<CPlayer>::CreateObject());
	dynamic_cast<CPlayer*>(m_ObjectList[PLAYER].front())->SetBulletList(&m_ObjectList[BULLET]);

	// Monster
	float fX = 0.f, fY = 0.f;

	for (int i = 0; i < 5; ++i)
	{
		fX = float(rand() % WINCX);
		fY = float(rand() % WINCY);		

		m_ObjectList[MONSTER].push_back(CObjectFactory<CMonster>::CreateObject(fX, fY));
	}
}

void CMaingame::Update()
{
	// 이터레이터 패턴(반복자 패턴)
	// 객체 관리 통일성에 초점을 둔 디자인 패턴
	for (int i = 0; i < OBJECT_END; ++i)
	{
		auto iter_begin = m_ObjectList[i].begin();
		auto iter_end = m_ObjectList[i].end();

		for (; iter_begin != iter_end; )
		{
			int iEvent = (*iter_begin)->Update();

			if (DEAD_OBJ == iEvent)
			{
				SafeDelete((*iter_begin));
				iter_begin = m_ObjectList[i].erase(iter_begin);
			}
			else
				++iter_begin;
		}
	}

	//CCollisionMgr::CollisionRect(m_ObjectList[BULLET], m_ObjectList[MONSTER]);
	CCollisionMgr::CollisionSphere(m_ObjectList[BULLET], m_ObjectList[MONSTER]);
}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	// 이터레이터 패턴(반복자 패턴)
	for (int i = 0; i < OBJECT_END; ++i)
	{
		auto iter_begin = m_ObjectList[i].begin();
		auto iter_end = m_ObjectList[i].end();

		for (; iter_begin != iter_end; ++iter_begin)
			(*iter_begin)->Render(m_hDC);
	}
}

void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);	

	for (int i = 0; i < OBJECT_END; ++i)
	{
		for_each(m_ObjectList[i].begin(), m_ObjectList[i].end(), SafeDelete<CGameObject*>);
		m_ObjectList[i].clear();
	}
}
