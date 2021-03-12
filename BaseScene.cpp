#include "BaseScene.h"

/*!
@brief コンストラクタ
@param impl シーン変更のリスナー
@param parameter 前のシーンから渡されたパラメータ
*/
BaseScene::BaseScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
    _implSceneChanged(impl)
{
}