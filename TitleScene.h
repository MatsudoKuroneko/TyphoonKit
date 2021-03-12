#pragma once

#include "BaseScene.h"

class TitleScene : public BaseScene
{
public:
    TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter);
    virtual ~TitleScene() = default;
    void update() override;
    void draw() override;
};