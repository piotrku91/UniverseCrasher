#include "Controller.hpp"
#include <functional>
#include "GameObject.hpp"

void Controller::moveWithSpeed(float dX, float dY) {
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
    };
    ControlledObject_ = object;
    Active_ = true;
}

void Controller::resetControlledObject() {
    ControlledObject_ = nullptr;
    Active_ = false;
}