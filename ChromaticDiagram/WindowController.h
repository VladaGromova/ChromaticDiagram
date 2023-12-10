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
#include <QPainterPath>
#include "ColorSpace.h"
#include "BezierController.h"
#include <format>

#define CIE_IMAGE "CIE.png"

typedef struct {
  double pixelWidth; // 1216
  double pixelHeight; // 1216
  double coordsStartX; //40
  double coordsStartY; //5
  double coordsEndX;  // 1215
  double coordsEndY;  // 1187
  double coordsWidth; //1175
  double coordsHeight; //1182
} CIEImageData;

class WindowController : public QObject {
  Q_OBJECT
 private:
  double radius = 5.0;
  CIEImageData imageParams;
  ColorSpace colorSpace = ColorSpace();
  BezierController bezierController;
  void createCIEborder();
  void createSpecialPoint();
  void drawScene();
  bool isBorderPoints = true;
  bool isCieImage = true;
  int width = 530;
  int height = 530;
 public:
  QSharedPointer<QImage> image;
  QColor color = QColor(Qt::darkBlue);
  explicit WindowController(QObject *parent = nullptr);
signals:
  void controlPointMoved();
 void borderPointsShowed();
  void borderPointsHiden();
 void backgroundShowed();
 void backgroundHiden();
 public slots:
  void moveControlPoint(int ind, double x, double y);
  void showBorderPoints();
  void hideBorderPoints();
  void showBackground();
  void hideBackground();
};
