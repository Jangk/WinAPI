#pragma once

class MainGame
{
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
	~MainGame();
private:
	OBJECT_LIST m_ObjectList[OBJECT_TYPE_END];
	HDC m_hdc;
};

