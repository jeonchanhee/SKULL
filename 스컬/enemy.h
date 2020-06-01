#pragma once
#include"gameNode.h"

enum STATE
{
	E_LEFT,
	E_LEFT_STOP,
	E_RIGHT,
	E_RIGHT_STOP,
	E_DIE,
	E_IDLE,
	E_ATTACK,
	E_LEFT_ATTACK,
	E_RIHGT_ATTACK
};

class enemy : public gameNode
{
protected:
	image*	_img;		//�̹���
	image*	_attImg;
	RECT	_imgRc;		//�̹�����Ʈ
	RECT	_hitRc;		//�浹�뷺Ʈ
	RECT*	_attRc;
	RECT	rcColl;


	STATE _state;

	int _x, _y;
	int _count;
	int _attCount;
	int _frameX;
	int _frameY;
	int _attNum;
	int _exploreRange;	//Ž���Ÿ�
	int _attRange;		//���ݰŸ�
	int _dmg;
	int _hp;
	int _randNum;

	bool _isAlive;
	bool _isAttack;
	bool _hit;

public:
	enemy();
	~enemy();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void move(tagTile tiles[]);
	void frame(int frameY, int maxFrameX);
	void downTileDetection(tagTile tiles[]);

	void setXY(int x, int y) { _x = x, _y = y; }
	
	RECT* getAttRc() {	return _attRc;}
	RECT getHitRc() { return _hitRc; }

	int getDmg() { return _dmg; }

	int getHp() { return _hp; }
	void setHp(int hp) { _hp = hp; }

	void setAilve(bool ailve) { _isAlive = ailve; }
	bool getAilve() { return _isAlive; }

	bool getIsAttac() { return _isAttack; }

	bool getHit() { return _hit; }
	void setHit(bool hit) { _hit = hit; }
};

