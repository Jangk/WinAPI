#pragma once
#include "GameObject.h"
class Shield :
	public GameObject
{

public:
	void SetActive();

public:
	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render(HDC) override;
	virtual void Release() override;
	~Shield();

private:
	GameObject* m_Target;
	bool m_bIsActive;
	float m_fDistance;
};

