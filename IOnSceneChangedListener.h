#pragma once

#include "eScene.h"
#include "BaseScene.h"
#include "Parameter.h"

class IOnSceneChangedListener //�V�[���Ď��N���X�BBaseScene���Œ�`���ꂽ�B
{
public:
    IOnSceneChangedListener() = default;
    virtual ~IOnSceneChangedListener() = default;
    virtual void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) = 0;
};

