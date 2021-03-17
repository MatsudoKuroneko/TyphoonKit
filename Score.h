#pragma once

#include "eScore.h"

class Score
{
private:
	Score();
	~Score() = default;
	int gametime,hscore, nscore;

public:
	static Score* Instance() {
		static Score inst;
		return &inst;
	};
	const void ResetScore();
	const void AddScore(eScore data, int v);
	const int GetScore(eScore data);
};


