#include "DammakuUtil.h"
#include <DxLib.h>

double DKHorming(double x1, double y1, double x2, double y2)
{
		return atan2((double)(y1 - y2), (double)(x1 - x2));
}