#pragma once
#include"gameNode.h"

struct tagBullet
{
	image* img;			// 총알이미지
	RECT	rc;				// 렉트
	float	x, y;			// 총알 좌표
	float	angle;			// 총알각도
	float	speed;			// 총알 스피드
	float	radius;			// 총알 반지름
	float	fireX, fireY;	// 발사위치
	bool	isFire;			// 발사여부
	float   range;
};


class bullet : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;



public:
	bullet();
	~bullet();

	HRESULT init();
	void release();
	void update();
	void render();

	void fire();
	void bulletMove();
	void removeBullet();

};

