#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public : 
	void Input();
public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

private:
	bool m_bIsJump;
	float m_fJumpForce;
	float m_fJumpAcc;		// ���ӵ�
	float m_fAccIncrease;	// ���ӵ� ������
};

