#include "pch.h"
#include "CollisionManager.h"
#include "GameObject.h"

void CollisionManager::CollisionRect(OBJECT_LIST& dstList, OBJECT_LIST& srcList)
{
	for (auto pDest : dstList)
	{
		for (auto pSrc : srcList)
		{
			RECT rc = {};

			// �� �簢���� �����Ǿ����� �Ǻ��ϴ� �Լ�. ���������� TRUE, �ƴϸ� FALSE ��ȯ.
			// �� �簢���� �����Ǿ��� �� ��ģ ������ �Ǵٸ� �簢���� ���������. 
			// �� ��ģ �簢���� ù��° ���ڷ� ��ȯ�Ѵ�
			if (IntersectRect(&rc, &pDest->GetRect(), &pSrc->GetRect()))
			{
				pDest->IsDead();
				pSrc->IsDead();
			}
		}
	}
}

void CollisionManager::CollisionSphere(OBJECT_LIST& dstList, OBJECT_LIST& srcList)
{
	for (auto pDest : dstList)
	{
		for (auto pSrc : srcList)
		{
			if (IntersectSphere(pDest, pSrc))
			{
				pDest->IsDead();
				pSrc->IsDead();
			}
		}
	}
}

bool CollisionManager::IntersectSphere(GameObject* pDest, GameObject* pSource)
{
	// ���浹
	// �� ���� ������ ���� ���Ѵ�. r1 + r2
	// �� ���� ���� �� �Ÿ��� ���Ѵ�. d
	// r1 + r2 >= d ������ �����ϸ� TRUE

	float r1 = pDest->GetInfo().fWidth * 0.5f;
	float r2 = pSource->GetInfo().fWidth * 0.5f;

	float w = pDest->GetInfo().fX - pSource->GetInfo().fX;
	float h = pDest->GetInfo().fY - pSource->GetInfo().fY;

	// sqrtf: ������ ���ϴ� �Լ�. <cmath>���� ����.
	float d = sqrtf(w * w + h * h);

	return r1 + r2 >= d;
}	
