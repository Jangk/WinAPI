#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Monster.h"

CMaingame::CMaingame()
	: m_pPlayer(nullptr)
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

	if (nullptr == m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

	CGameObject* pMonster = nullptr;
	float fX = 0.f, fY = 0.f;

	for (int i = 0; i < 5; ++i)
	{
		fX = float(rand() % WINCX);
		fY = float(rand() % WINCY);

		pMonster = new CMonster;
		pMonster->Initialize();
		pMonster->SetPos(fX, fY);

		m_MonsterList.push_back(pMonster);
	}
}

void CMaingame::Update()
{
	m_pPlayer->Update();

	auto iter_begin = m_MonsterList.begin();
	auto iter_end = m_MonsterList.end();

	for (; iter_begin != iter_end; ++iter_begin)
		(*iter_begin)->Update();

	// 과제2. 총알과 몬스터가 충돌. 충돌 되면 둘다 삭제!
	// - 원충돌
	
}

void CMaingame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	m_pPlayer->Render(m_hDC);

	// 범위 기반 for문
	for (auto pMonster : m_MonsterList)
		pMonster->Render(m_hDC);
}

void CMaingame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);

	SafeDelete(m_pPlayer);
	
	for_each(m_MonsterList.begin(), m_MonsterList.end(), SafeDelete<CGameObject*>);
	m_MonsterList.clear();
}
