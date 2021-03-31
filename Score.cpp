#include "Score.h"

const void Score::ResetScore()
{
	gametime, hscore, nscore, camerax, cameray = 0;
	playerx = 576 / 2;
	playery = 672 / 4 * 3;
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

		case PlayerX:
			playerx += v;
			break;

		case PlayerY:
			playery += v;
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

	case PlayerX:
		return playerx;
		break;

	case PlayerY:
		return playery;
		break;

	case Stage:
		return stage;
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

	case Stage:
		stage = v;
		break;

	}
}

