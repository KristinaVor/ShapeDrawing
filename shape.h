#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>

class Shape
{
public:
    virtual ~Shape() {}
    virtual void draw(QPainter& painter, int xOffset) const = 0;
};

class Circle : public Shape
{
public:
    Circle() {}
    ~Circle() {}

    void draw(QPainter& painter, int xOffset) const override;
};

class Square : public Shape
{
public:
    Square() {}
    ~Square() {}

    void draw(QPainter& painter, int xOffset) const override;
};

class Triangle : public Shape
{
public:
    Triangle() {}
    ~Triangle() {}

    void draw(QPainter& painter, int xOffset) const override;
};

#endif // SHAPE_H
