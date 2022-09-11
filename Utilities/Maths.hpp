#pragma once

struct Size
{
    int width;
    int height;
};

class Vector2d
{
private:
    int x_;
    int y_;

public:
    Vector2d(int x, int y) : x_(x), y_(y){};

    inline int getX() const { return x_; };
    inline int getY() const { return y_; };

    inline void setX(int x) { x_ = x; };
    inline void setY(int y) { y_ = y; };

    inline Vector2d operator+(const Vector2d& v) const { return Vector2d(x_ + v.x_, y_ + v.y_); };
    inline Vector2d operator-(const Vector2d& v) const { return Vector2d(x_ - v.x_, y_ - v.y_); };
    inline Vector2d operator*(const Vector2d& v) const { return Vector2d(x_ * v.x_, y_ * v.y_); };
    inline Vector2d operator/(const Vector2d& v) const { return Vector2d(x_ / v.x_, y_ / v.y_); };
};