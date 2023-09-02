#include "drawingwidget.h"
#include <QPainter>

DrawingWidget::DrawingWidget(QWidget *parent) : QWidget(parent) {}

void DrawingWidget::addShape(QSharedPointer<Shape> shape)
{
    shapes.append(shape);
    update();
}

void DrawingWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int xOffset = 0;

    for (const QSharedPointer<Shape> &shape : shapes)
    {
        shape->draw(painter, xOffset);
        xOffset += 60;
    }
}
