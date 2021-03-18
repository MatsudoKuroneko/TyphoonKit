#include "Score.h"

const void Score::ResetScore()
{
	gametime, hscore, nscore, camerax, cameray = 0;
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

		case CameraX:
			camerax += v;
			break;

		case CameraY:
			cameray += v;
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

	case NScore:
		return nscore;
		break;
	case CameraX:
		return camerax;
		break;

	case CameraY:
		return cameray;
		break;

	return -1;
	}

}

/*!
@brief フレーム区切り
@param scene v1:全体フレーム
@param parameter v2:分けフレーム
*/
const int Score::GetPace(int v1, int v2)
{

	return 0;
}

const void Score::ConfirmScore(eScore data, int v)
{
	switch (data) {

	case HScore:
		hscore = v;
		break;

	case CameraX:
		camerax = v;
		break;

	case CameraY:
		cameray = v;
		break;

	}
}

