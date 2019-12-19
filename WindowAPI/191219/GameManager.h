#pragma once
class GameManager
{
public:
	static GameManager* GetInstance();
	void Initialize();
	void Update();
	void Render();
	void Release();
	~GameManager();
private:
	static GameManager* m_Instance;
	HDC m_HDC;
	OBJECT_LIST m_ObjectList[GAMEOBJECT_END];
};

