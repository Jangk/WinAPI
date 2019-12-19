#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual EventType Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
	void SetDirection(Direction dir);
private:
};

