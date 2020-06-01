#pragma once
#include"singletonBase.h"
#include"tileNode.h"
#include"UI.h"
#include"inven.h"

enum MOVESTATE
{
	LEFT,
	LEFT_STOP,
	LEFT_JUMP,
	RIGHT,
	RIGHT_STOP,
	RIGHT_JUMP,
	LEFT_ATT,
	RIGHT_ATT
};

enum SKULL
{
	BASICS,
	WARRIOR,
	WARRIOR2,
	SWORD,
	ARCHER,
	SPEAR,
	EMPTY
};

class player : public singletonBase<player>
{
private:

	image* img;

	RECT imgRc;
	RECT hitRc;
	RECT* attRc;

	RECT rcCollision;	// 충돌체크용 렉트
	RECT rcDownColl;	// 아래 검출용 렉트

	MOVESTATE _move;
	SKULL	 _skull;
	SKULL	 _secondSkull;

	int x, y;
	int _speed;
	int _att;
	int _def;
	int _hp;

	int frameIndex;
	int count;
	int money;
	int attCount;
	float jumpTime;

	bool _isJump;
	bool _isAtt;
	bool _headChage;
	bool _isAilve;
	bool _deletRc;
	bool _FirstHit;
	
	UI* _ui;
	inven* _inven;
public:
	player();
	~player();

	HRESULT init();
	void release();
	void update(tagTile tiles[]);
	void update();
	void render(HDC hdc);

	void playerImages();
	void keyControl(tagTile tiles[]);
	void playerFrame();
	void headType();
	void hitRcMove();
	void tileDetection(tagTile tiles[]); // 타일검출
	void downTileDetection(tagTile tiles[]);
	void playerJump();

	void imageFrame(int frameY, int maxFrame);

	int getX() { return x; }
	int getY() { return y; }
	RECT getRc() { return hitRc; }
	SKULL getSkull() { return _skull; }
	SKULL getSecondSkull() { return _secondSkull; }

	void setSkull(SKULL skull) { _skull = skull; }
	void setSecondSkull(SKULL skull) { _secondSkull = _skull; }
	void setChange(bool change) { _headChage = change; }

	RECT* getAttRc() { return attRc; }
	RECT getHitRc() { return hitRc; }

	int getHp() { return _hp; }
	void setHp(int hp) { _hp = hp; }

	void setAilve(bool Ailve) { _isAilve = Ailve; }
	bool getAilve() { return _isAilve; }

	int getDmg() { return _att; }

	void setPoint(POINT xy)
	{
		x = xy.x;
		y = xy.y;
	}

	inven* getIven() { return  _inven; }

	bool getFirstHit() { return _FirstHit; }
	void setFirstHit(bool FirstHit) { _FirstHit = FirstHit; }
};

