#ifndef DRAWINGWIDGET_H
#define DRAWINGWIDGET_H

#include <QWidget>
#include <QList>
#include "shape.h"

class DrawingWidget : public QWidget
{
    Q_OBJECT

public:
    DrawingWidget(QWidget *parent = nullptr);
    void addShape(QSharedPointer<Shape> shape);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QList<QSharedPointer<Shape>> shapes;
};

#endif // DRAWINGWIDGET_H
