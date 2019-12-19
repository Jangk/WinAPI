#pragma once

#ifndef __MAINGAME_H__

class CGameObject;
class CMaingame
{
public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Release();

private:
	HDC					m_hDC;
	CGameObject*		m_pPlayer;
	list<CGameObject*>	m_MonsterList;
};

#define __MAINGAME_H__
#endif

