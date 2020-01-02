#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	void SetShoot(float angle);
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC) override;
	virtual void Release() override;
private:
	bool m_bIsShoot;

};

