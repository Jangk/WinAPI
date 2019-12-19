#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual EventType Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

