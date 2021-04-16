#include "Score.h"

const void Score::ResetScore()
{
	gametime, hscore, nscore, camerax, cameray, stage, hp, c, s0, s1, s2, s0lv, s1lv, s2lv, s0r, s1r, s2r, s0g, s1g, s2g, s0b, s1b, s2b,nowslot = 0;
	playerx = 576 / 2;
	playery = 672 / 4 * 3;
	s0lv = 4;
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

		case HP:
			hp += v;
			break;

		case Charge:
			c += v;
			break;

		case Slot0Red:
			s0r += v;
			break;

		case Slot1Red:
			s1r += v;
			break;

		case Slot2Red:
			s2r += v;
			break;

		case Slot0Green:
			s0g += v;
			break;

		case Slot1Green:
			s1g += v;
			break;

		case Slot2Green:
			s2g += v;
			break;

		case Slot0Blue:
			s0g += v;
			break;

		case Slot1Blue:
			s1g += v;
			break;

		case Slot2Blue:
			s2g += v;
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

	case HP:
		return hp;
		break;

	case Charge:
		return c;
		break;

	case Slot0:
		return s0;
		break;

	case Slot1:
		return s1;
		break;

	case Slot2:
		return s2;
		break;

	case Slot0Lv:
		return s0lv;
		break;

	case Slot1Lv:
		return s1lv;
		break;

	case Slot2Lv:
		return s2lv;
		break;

	case Slot0Red:
		return s0r;
		break;

	case Slot1Red:
		return s1r;
		break;

	case Slot2Red:
		return s2r;
		break;

	case Slot0Green:
		return s0g;
		break;

	case Slot1Green:
		return s1g;
		break;

	case Slot2Green:
		return s2g;
		break;

	case Slot0Blue:
		return s0b;
		break;

	case Slot1Blue:
		return s1b;
		break;

	case Slot2Blue:
		return s2b;
		break;

	case NowSlotColor:
		switch (nowslot) {
		case 0:
			return s0;
		case 1:
			return s1;
		case 2:
			return s2;
		
		return -1;
		}
	break;

	case NowSlotLv:
		switch (nowslot) {
		case 0:
			return s0lv;
		case 1:
			return s1lv;
		case 2:
			return s2lv;
		}
		break;


	return -1;
	}

}


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

	case HP:
		hp = v;
		break;

	case Charge:
		c = v;
		break;

	case Slot0:
		s0 = v;
		break;

	case Slot1:
		s1 = v;
		break;

	case Slot2:
		s2 = v;
		break;
	}
}

