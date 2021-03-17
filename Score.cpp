#include "Score.h"

const void Score::ResetScore()
{
	gametime, hscore, nscore = 0;
}

const void Score::AddScore(eScore data, int v)
{
	switch (data)
	{
		case Gametime:
			gametime++;
			break;

		case HScore:
			hscore += v;
			break;

		case NScore:
			nscore += v;
			break;

	}
}

const int Score::GetScore(eScore data)
{
	switch (data)
	{
	case Gametime:
		return gametime;
		break;

	case HScore:
		return hscore;
		break;

	case NScore:
		return nscore;
		break;

	return -1;
	}

}
