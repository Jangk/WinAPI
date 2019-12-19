#pragma once

#ifndef __BULLET_H__

#include "GameObject.h"
class CBullet :	public CGameObject
{
public:
	CBullet();
	virtual ~CBullet();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	float	m_fSpeed;
};

#define __BULLET_H__
#endif
