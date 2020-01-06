#pragma once
class GameObject;
class MainGame
{
public:
	void Initialize();
	void Update();
	void Render();
	~MainGame();
private:
	void Release();

private:
	HDC m_hdc;
	
};

