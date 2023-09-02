#include "shapedrawing.h"
#include "ui_shapedrawing.h"

ShapeDrawing::ShapeDrawing(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShapeDrawing)
{
    ui->setupUi(this);
    this->setWindowTitle("Отображение геометрических фигур");

    connect(ui->displayButton, &QPushButton::clicked, this, &ShapeDrawing::displayButtonClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &ShapeDrawing::clearButtonClicked);
    connect(ui->triangleButton, &QPushButton::clicked, this, &ShapeDrawing::triangleButtonClicked);
    connect(ui->circleButton, &QPushButton::clicked, this, &ShapeDrawing::circleButtonClicked);
    connect(ui->squareButton, &QPushButton::clicked, this, &ShapeDrawing::squareButtonClicked);

    shouldDraw = false;
}

ShapeDrawing::~ShapeDrawing()
{
    delete ui;
}

void ShapeDrawing::circleButtonClicked()
{
    circleButtonClickCount++;
    ui->circleLabel->setText(QString::number(circleButtonClickCount));

    shapes.append(QSharedPointer<Shape>(new Circle()));
    if (shouldDraw)
        update();
}

void ShapeDrawing::squareButtonClicked()
{
    squareButtonClickCount++;
    ui->squareLabel->setText(QString::number(squareButtonClickCount));

    shapes.append(QSharedPointer<Shape>(new Square()));
    if (shouldDraw)
        update();
}

void ShapeDrawing::triangleButtonClicked()
{
    triangleButtonClickCount++;
    ui->trianglLabel->setText(QString::number(triangleButtonClickCount));

    shapes.append(QSharedPointer<Shape>(new Triangle()));
    if (shouldDraw)
        update();
}

void ShapeDrawing::displayButtonClicked()
{
    shouldDraw = true;
    update();
}

void ShapeDrawing::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (shouldDraw)
    {
        int xOffset = 0;
        QRect drawingRect(50, 50, ui->centralwidget->width() - 110, ui->centralwidget->height() - 100);
        painter.setClipRect(drawingRect);

        for (const QSharedPointer<Shape>& shape : shapes)
        {
            shape->draw(painter, xOffset);
            xOffset += drawingRect.width() / shapes.size();
        }
    }

    QMainWindow::paintEvent(event);

    shouldDraw = false;
}

void ShapeDrawing::clearButtonClicked()
{
    shapes.clear();

    triangleButtonClickCount = 0;
    circleButtonClickCount = 0;
    squareButtonClickCount = 0;

    ui->trianglLabel->setText("0");
    ui->circleLabel->setText("0");
    ui->squareLabel->setText("0");

    update();
}
