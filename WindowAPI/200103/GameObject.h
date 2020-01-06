#pragma once
class GameObject
{
public: 
	void UpdateRect();
	void SetPos(float x, float y);
	const INFO& GetInfo();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;
private:
	virtual void Release() = 0;

protected:
	INFO m_tInfo;
	RECT m_Rect;
	float m_fSpeed;
};