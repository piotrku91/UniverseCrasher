#include "SimpleRectangleObject.hpp"

SimpleRectangleObject::SimpleRectangleObject(const std::string &objectName, Vector2d position, Size size, Color objectColor)
    : GraphicsObject{objectName, position, size}, objectColor_{objectColor} {};

void SimpleRectangleObject::drawObject()
{
  
}