#include "Controller.hpp"
#include <functional>
#include "GameObject.hpp"
#include "Scene.hpp"
#include "Player.hpp"

void Controller::moveWithSpeed(float dX, float dY) {
    if (ModifierState_ == ControllerModifierState::RightLock && dX > 0) {dX = 0;}
    if (ModifierState_ == ControllerModifierState::LeftLock && dX < 0) {dX = 0;}

    if (ControlledObject_ && Active_ && (dX != 0 || dY != 0)) {
        sf::Vector2f axis{dX, dY};
        ControlledObject_->setPositionInc(axis * SpeedMultiplier_);
    }
}

void Controller::setSpeed(int speed) {
    SpeedMultiplier_ = static_cast<float>(std::clamp(speed, 0, MaxSpeedMultiplier_));
}

void Controller::setActive(bool state) {
    Active_ = state;
}

void Controller::setControlledObject(std::shared_ptr<class GameObject>& object) {
    if (!object) {
        return;
    }
    ControlledObject_ = object;
    Active_ = true;
}

void Controller::handleFireEvent(float d) {
    if (ControlledObject_ && Active_ && (d != 0)) {
        dynamic_cast<Player*>(ControlledObject_.get())->Fire();
    }
}

void Controller::resetControlledObject() {
    ControlledObject_ = nullptr;
    Active_ = false;
    ModifierState_ = ControllerModifierState::None;
}

void Controller::setModifierState(ControllerModifierState new_modifier_state)
{
    ModifierState_ = new_modifier_state;
}


ControllerModifierState Controller::getModifierState()
{
    return ModifierState_;
}