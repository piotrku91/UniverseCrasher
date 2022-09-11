#include "GraphicsObject.hpp"

void GraphicsObject::setPosition(Vector2d new_position)
    {
        Position_.setX(new_position.getX());
        Position_.setY(new_position.getY());
    };

void GraphicsObject::setSize(Size new_size)
    {
        Size_.width = new_size.width;
        Size_.height = new_size.height;
       
    };