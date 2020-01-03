#pragma once
#include "GameObject.h"
class Monster :
	public GameObject
{
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC) override;
	virtual void Release() override;
	virtual void IsDead() override;

private:
	GameObject* m_Target;
	POINT m_GunPos;
	float m_fGunLength;
};

