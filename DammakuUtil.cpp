#include "DammakuUtil.h"
#include <DxLib.h>

/*!
@brief DKHorming
@param x1 �Ώ�x���W
@param y1 �Ώ�y���W
@param x2 ����x���W
@param y2 ����y���W
*/
double DKHorming(double x1, double y1, double x2, double y2)
{
		return atan2((double)(y1 - y2), (double)(x1 - x2));
}


/*!
@brief DKDistance
@param x1 �Ώ�x���W
@param y1 �Ώ�y���W
@param x2 ����x���W
@param y2 ����y���W
*/
double DKDistance(double x1, double y1, double x2, double y2)
{
	double dx = abs(x1 - x2);

	double dy = abs(y1 - y2);

	double d = sqrt(dx * dx + dy * dy);

	return d;
}