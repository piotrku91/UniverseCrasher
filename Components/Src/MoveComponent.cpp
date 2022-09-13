#include "MoveComponent.hpp"
#include "GameObject.hpp"

 void MoveComponent::begin() {
     StartPosition_ = getOwner()->getPositionAbs();
 }

void MoveComponent::tick(float delta_time) 
{
    sf::Vector2f current_location = getOwner()->getPositionAbs();
    if (StartPosition_ != EndPosition_)
    {
        sf::Vector2f velocity{0, 5};
        getOwner()->setPositionInc(velocity * delta_time * Speed_);

    }

}