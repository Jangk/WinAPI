#pragma once

#ifndef __GAMEOBJECT_H__

class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	const INFO& GetInfo() const;
	const RECT& GetRect() const;

public:
	void SetPos(float x, float y);

public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

protected:
	virtual void Release() = 0;	

public:
	void IsDead();

protected:
	void UpdateRect();

protected:
	INFO	m_tInfo;
	RECT	m_tRect;
	bool	m_bIsDead;
};

#define __GAMEOBJECT_H__
#endif

