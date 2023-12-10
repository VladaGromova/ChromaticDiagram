#pragma once
#include <QImage>
#include <QColor>
#include <QObject>
#include <QSharedPointer>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QImageReader>
#include <QString>
#include "ColorSpace.h"
#include "BezierController.h"
#include <format>

#define CIE_IMAGE "CIE.png"

class WindowController : public QObject {
  Q_OBJECT
 private:
  ColorSpace colorSpace = ColorSpace();
  BezierController bezierController;
  void createCIEborder();
  void createSpecialPoint();
 public:
  QSharedPointer<QImage> image;
  QColor color = QColor(Qt::darkBlue);
  explicit WindowController(QObject *parent = nullptr);
signals:
  void controlPointMoved();
 public slots:
  void moveControlPoint(int ind, double x, double y);
};
