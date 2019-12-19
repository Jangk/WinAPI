#pragma once
#include "enum.h"
#include "struct.h"
class GameObject
{
public:
	virtual void Initialize() = 0;
	virtual EventType Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;
	void SetPos(float x, float y);
	const INFO& GetInfo();
	const Direction& GetDir();
	void DontEscapeMap();
	void UpdateRect();
	void SetDead();
	const RECT& GetRect();

public:
	GameObject();
	virtual ~GameObject();

protected:
	RECT m_Rect;
	INFO m_tInfo;
	Direction m_eDir;
	float m_fSpeed;
	bool m_bIsDead = false;


};

