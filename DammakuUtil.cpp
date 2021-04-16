#include "DammakuUtil.h"
#include <DxLib.h>

/*!
@brief DKHorming
@param x1 対象x座標
@param y1 対象y座標
@param x2 自分x座標
@param y2 自分y座標
*/
double DKHorming(double x1, double y1, double x2, double y2)
{
		return atan2((double)(y1 - y2), (double)(x1 - x2));
}


/*!
@brief DKDistance
@param x1 対象x座標
@param y1 対象y座標
@param x2 自分x座標
@param y2 自分y座標
*/
double DKDistance(double x1, double y1, double x2, double y2)
{
	double dx = abs(x1 - x2);

	double dy = abs(y1 - y2);

	double d = sqrt(dx * dx + dy * dy);

	return d;
}