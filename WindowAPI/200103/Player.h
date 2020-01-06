#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public : 
	void Input();
public:
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	bool m_bIsJump;
	float m_fCount;
};

