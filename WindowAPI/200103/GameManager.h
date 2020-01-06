#pragma once
#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__


#include <vector>
class GameManager
{
private:
	GameManager();
	~GameManager();
	void LineToPoint(HDC hdc);
	void ComparePos();

public:
	static GameManager* GetInstance();
	void Init();
	int Update();
	void Render(HDC);
	void AddPoint(float x, float y);
	void SetScreenMove(float x);
	float GetScreenMove();

private:	// º¯¼ö¿ë
	static GameManager* m_Instance;
	OBJECT_LIST m_ObjectList[OBJECT_END];
	std::vector<FPOINT*> m_Point;
	float m_fScreenMoveX;
	float m_fCount;
};


#endif // !__GAMEMANAGER_H__