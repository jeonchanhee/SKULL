#pragma once
#include"gameNode.h"

struct tagBullet
{
	image* img;			// �Ѿ��̹���
	RECT	rc;				// ��Ʈ
	float	x, y;			// �Ѿ� ��ǥ
	float	angle;			// �Ѿ˰���
	float	speed;			// �Ѿ� ���ǵ�
	float	radius;			// �Ѿ� ������
	float	fireX, fireY;	// �߻���ġ
	bool	isFire;			// �߻翩��
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

