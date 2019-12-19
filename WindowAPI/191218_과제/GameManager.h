#pragma once
#include "pch.h"
class GameObect;
class GameManager
{
public:
	static GameManager* GetInstance();
	void Initialize();
	void Update();
	void Render();
	void Release();
	~GameManager();


private:
	static GameManager* m_Instance;
	GameObject* m_Player;
	vector<Monster*> m_MonsterList;
	HDC m_HDC;
};

