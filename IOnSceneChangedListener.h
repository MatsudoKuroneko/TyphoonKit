#pragma once

#include "eScene.h"
#include "BaseScene.h"
#include "Parameter.h"

class IOnSceneChangedListener //シーン監視クラス。BaseScene内で定義された。
{
public:
    IOnSceneChangedListener() = default;
    virtual ~IOnSceneChangedListener() = default;
    virtual void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) = 0;
};

