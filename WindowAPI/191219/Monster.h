#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual EventType Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

