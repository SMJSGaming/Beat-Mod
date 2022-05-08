#include "PlayLayer.hpp"
#include "../methods/fromOffset.hpp"

void __fastcall PlayLayer_update_H(PlayLayer* self, void*, float unk) {
    bool isAverage = truncf(1000.0f * self->getScale()) == 1000.0f;
    bool isNew = fromOffset<bool>(self, 0x461);
    float beatScale;

    if (isNew) {
        beatScale = fromOffset<float>(FMODAudioEngine::sharedEngine(), 0x110);
    } else {
        beatScale = fromOffset<float>(fromOffset<void*>(self, 0x380), 0x1B0) + 0.4f; // From my experience this is needed
    }

    if (beatScale > 0.5f && self->getActionByTag(1001) == nullptr && pulseEnabled) {
        CCScaleTo* scaleTo = CCScaleTo::create(
            0.1f, 
            1.0f + (beatScale - 0.5f) * (0.4f + static_cast<int>(!isNew) * 0.4f)
        );
        scaleTo->setTag(1001);
        self->stopActionByTag(1002);
        self->runAction(scaleTo);
    } else if (!isAverage && self->getActionByTag(1002) == nullptr) {
        CCScaleTo* scaleTo = CCScaleTo::create(0.1f, 1.0f);
        scaleTo->setTag(1002);
        self->stopActionByTag(1001);
        self->runAction(scaleTo);
    }

    return PlayLayer_update(self, unk);
}