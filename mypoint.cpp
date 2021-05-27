#include "mypoint.h"
#include <QPainter>

MyPoint::MyPoint(const QPoint &pt, QColor color)
{
  _pt = pt;
  _color = color;
}

void MyPoint::setPoint(const QPoint &pt)
{
  _pt = pt;
}

void MyPoint::setPoint(int x, int y)
{
  _pt.setX(x);
  _pt.setY(y);
}

void MyPoint::setColor(QColor color)
{
  _color = color;
}

int MyPoint::getX()
{
  return _pt.x();
}

void MyPoint::draw(QPainter &painter)
{
  QPen pen(Qt::SolidLine);
  QBrush br (_color, Qt::SolidPattern);
  painter.setBrush(Qt::NoBrush);
  painter.setPen(QPen(br, 3, Qt::SolidLine));
  painter.drawLine(_pt, QPoint(_pt.x(), _pt.y() + 10));
}

