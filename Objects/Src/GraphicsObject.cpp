#include "GraphicsObject.hpp"

void GraphicsObject::setPosition(Vector2d new_position)
    {
        Position_.setX(new_position.getX());
        Position_.setY(new_position.getY());
        ObjectRect_.x = Position_.getX();
        ObjectRect_.y = Position_.getY();
    };

void GraphicsObject::setSize(Size new_size)
    {
        Size_.width = new_size.width;
        Size_.height = new_size.height;
        ObjectRect_.w = Size_.width;
        ObjectRect_.h = Size_.height;
    };