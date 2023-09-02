#ifndef SHAPEDRAWING_H
#define SHAPEDRAWING_H

#include <QMainWindow>
#include <shape.h>
#include <memory>
#include <QSharedPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class ShapeDrawing; }
QT_END_NAMESPACE

class ShapeDrawing : public QMainWindow
{
    Q_OBJECT

public:
    ShapeDrawing(QWidget *parent = nullptr);
    ~ShapeDrawing();

private slots:
    void displayButtonClicked();
    void clearButtonClicked();
    void triangleButtonClicked();
    void circleButtonClicked();
    void squareButtonClicked();

private:
    Ui::ShapeDrawing *ui;

    bool shouldDraw;

    int triangleButtonClickCount = 0;
    int circleButtonClickCount = 0;
    int squareButtonClickCount = 0;

    QVector<QSharedPointer<Shape>> shapes;

    void paintEvent(QPaintEvent *event);


};
#endif // SHAPEDRAWING_H
