#ifndef MYPOINT_H
#define MYPOINT_H

#include <QObject>
#include <QPoint>
#include <QColor>

class QPainter;

class MyPoint {
  public:
    MyPoint(const QPoint &pt = QPoint(), QColor color = Qt::red);
    void draw(QPainter &painter);
    void setPoint(const QPoint &pt = QPoint());
    void setPoint(int x = 0, int y = 0);
    void setColor(QColor color = Qt::red);
    int getX();

    QPoint _pt;
    QColor _color;
};

#endif // MYPOINT_H


