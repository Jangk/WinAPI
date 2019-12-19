#pragma once
#include "Struct.h"
class GameObject
{
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;
	void SetPos(float x, float y);
	void UpdateRect();
	GameObject();
protected:
	INFO m_tInfo;
	RECT m_tRect;
	float m_fSpeed;
	Direction m_tDir;

};

