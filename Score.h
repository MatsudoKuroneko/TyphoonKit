#pragma once

#include "eScore.h"

class Score
{
private:
	Score() {};
	int gametime,hscore, nscore, camerax, cameray,stage,hp,c,s0,s1,s2, s0lv, s1lv, s2lv, s0r,s1r,s2r,s0g,s1g,s2g,s0b,s1b,s2b, nowslot = 0;
	int playerx = 576 / 2;
	int playery = 672 / 4 * 3;

public:
	static Score* Instance() {
		static Score inst;
		return &inst;
	};
	const void ResetScore();
	const void AddScore(eScore data, int v);
	const int GetScore(eScore data);
	const int GetPace(int v1,int v2);
	const void ConfirmScore(eScore data, int v);
};


