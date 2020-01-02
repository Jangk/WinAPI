#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual EventType Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


	// 이동 관련
	void SetPlayerPosition(float x, float y);
	Direction SetMovePatten(int iMoveLenght);
	void Move(Direction dir);


	// 사격 관련
	void Shoot();

private:
	MonsterType m_MonsterType;
	float m_fPlayerX;
	float m_fPlayerY;
	int m_iMoveCount;
	int m_iDir;
};

