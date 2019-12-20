#pragma once
#ifndef __DEFINE_H__
#define __DEFINE_H__

#define SCREEN_X 1600
#define	SCREEN_Y 900
#define FRAME_RATE 10			// 1 second = 1000 ms

// MAX 
#define MONSTER_MAX 1
#define BULLET_MAX 100


#define SAFE_DELETE(ptr) { if(ptr == nullptr) delete(ptr);}




#endif // !__DEFINE_H__
