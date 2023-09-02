#include"shape.h"

void Circle::draw(QPainter& painter, int xOffset) const
{
    painter.drawEllipse(50 + xOffset, 50, 50, 50);
}

void Square::draw(QPainter& painter, int xOffset) const
{
    painter.drawRect(50 + xOffset, 50, 50, 50);
}

void Triangle::draw(QPainter& painter, int xOffset) const
{
    QPoint points[3] =
    {
        QPoint(50 + xOffset, 100),
        QPoint(75 + xOffset, 50),
        QPoint(100 + xOffset, 100)
    };

    painter.drawPolygon(points, 3);
}
