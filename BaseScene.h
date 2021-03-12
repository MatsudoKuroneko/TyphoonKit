#pragma once

#include "IOnSceneChangedListener.h"
#include "Parameter.h"

class IOnSceneChangedListener;

class BaseScene
{
protected:
    IOnSceneChangedListener* _implSceneChanged;
public:
    BaseScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~BaseScene() = default;
    virtual void update() = 0;
    virtual void draw() = 0;
};