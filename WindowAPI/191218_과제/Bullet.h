#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
	void SetShoot(int x, int y, Direction dir);
	const INFO& GetInfo()const;
	bool IsShoot();
private:
	bool m_bIsShoot;
};

