#pragma once
#ifndef __FUNCTION_H__
#include "GameObject.h"


template<typename T>
class GameObjectCreator
{
public:
	static GameObject* CreateGameObject()
	{
		GameObject* obj = new T;
		obj->Initialize();
		return obj;
	}

	static GameObject* CreateGameObject(float x, float y)
	{
		GameObject* obj = new T;
		obj->Initialize();
		obj->SetPos(x, y);
		return obj;
	}
};


class Collision
{
public:
	static void CollisionRect(OBJECT_LIST& dest, OBJECT_LIST& src)
	{
		for (auto& destObj : dest)
			for (auto& srcObj : src)
				ColRect(*destObj, *srcObj);
				//ColRectTeacherVersion(*destObj, *srcObj);
	}
	static void CollisionSphere(OBJECT_LIST& dest, OBJECT_LIST& src)
	{
		for (auto& destObj : dest)
			for (auto& srcObj : src)
				ColSphere(*destObj, *srcObj);
	}

private:
	static void ColRectTeacherVersion(GameObject& dest, GameObject& src)
	{
		// x���� ������ �հ� �Ÿ��� ����.
		// x�� �������� ���� ���� �� �簢���� ������ �Ÿ����� ũ�� ��ħ.
		float fSumX = dest.GetInfo().fWidthHalf + src.GetInfo().fWidthHalf;
		float fDisX = fabs(dest.GetInfo().fX - src.GetInfo().fX);

		float fSumY = dest.GetInfo().fHeightHalf + src.GetInfo().fHeightHalf;
		float fDisY = fabs(dest.GetInfo().fY - src.GetInfo().fY);

		if (fSumX > fDisX&& fSumY > fDisY)
		{	// �浹�� Ȯ���� ����. ��ġ�� �κ��� ª�� ������ �о.
			fSumX -= fDisX;
			fSumY -= fDisY;
			if (fSumX > fSumY)
				src.SetPos(src.GetInfo().fX, src.GetInfo().fX - fSumY);
			else
				src.SetPos(src.GetInfo().fX - fSumX, src.GetInfo().fX);
		}
	}

	static void ColRect(GameObject& dest, GameObject& src)
	{
		if (&dest == &src)
			return;
		bool isX = false;
		bool isY = false;
		Direction dir = dest.GetDir();

		//  ���� X ��
		if ((dest.GetRect().left > src.GetRect().left) &&
			(dest.GetRect().left < src.GetRect().right))
			isX = true;
		// ���� X ��
		if ((dest.GetRect().right > src.GetRect().left) &&
			(dest.GetRect().right < src.GetRect().right))
			isX = true;
		// ���� Y��
		if ((dest.GetRect().top > src.GetRect().top) &&
			(dest.GetRect().top < src.GetRect().bottom))
			isY = true;
		// �Ʒ��� Y��
		if ((dest.GetRect().bottom > src.GetRect().top) &&
			(dest.GetRect().bottom < src.GetRect().bottom))
			isY = true;


		

		if (isX && isY)
		{	
			float saveDis = 8;
			// ���� ��ġ�� �ٲ��ߴ�
			switch (dir)
			{
			case UP:
				src.SetPos(src.GetInfo().fX, dest.GetRect().top - src.GetInfo().fHeightHalf-saveDis);
				break;
			case DOWN:
				src.SetPos(src.GetInfo().fX, dest.GetRect().bottom + src.GetInfo().fHeightHalf+saveDis);
				break;
			case LEFT:
				src.SetPos(dest.GetRect().left - src.GetInfo().fWidthHalf - saveDis, src.GetInfo().fY);
				break;
			case RIGHT:
				src.SetPos(dest.GetRect().right + src.GetInfo().fWidthHalf + saveDis, src.GetInfo().fY);
				break;
			}
		}
	}

	static void ColSphere(GameObject& dest, GameObject& src)
	{
		float fMin = dest.GetInfo().fWidthHalf + src.GetInfo().fWidthHalf; // ���� ������ ���ϱ�
		float fDisX = 0.0f;
		float fDisY = 0.0f;
		float fTotal = 0.0f;
		if (src.GetInfo().fX > dest.GetInfo().fX)
			fDisX = src.GetInfo().fX - dest.GetInfo().fX;
		else
			fDisX = dest.GetInfo().fX - src.GetInfo().fX;

		if (src.GetInfo().fY > dest.GetInfo().fY)
			fDisY = src.GetInfo().fY - dest.GetInfo().fY;
		else
			fDisY = dest.GetInfo().fY - src.GetInfo().fY;
		fTotal = sqrt((fDisX * fDisX) + (fDisY * fDisY));
		if (fMin > fTotal)
		{
			dest.SetDead();
			src.SetDead();
		}
	}
};



#define __FUNCTION_H__
#endif // !__FUNCTION_H__

