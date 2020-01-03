#pragma once
#ifndef __COLLISIONMANAGER_H__
#define	 __COLLISIONMANAGER_H__
class GameObject;
class CollisionManager
{
public:
	static void CollisionRect(OBJECT_LIST& dstList, OBJECT_LIST& srcList);
	static void CollisionSphere(OBJECT_LIST& dstList, OBJECT_LIST& srcList);
private:
	static bool IntersectSphere(GameObject* pDest, GameObject* pSource);
};


#endif // !__COLLISIONMANAGER_H__