#include "WindowController.h"

void WindowController::createCIEborder() {
 
  QPainter painter(image.data());

  for (int i = 0; i < DATASET_LENGTH; ++i) {
    QPen pen(qRgb(colorSpace.colors[i].R, colorSpace.colors[i].G,
                  colorSpace.colors[i].B));
    pen.setWidth(2);
    painter.setPen(pen);
    QBrush brush(qRgb(colorSpace.colors[i].R, colorSpace.colors[i].G,
                      colorSpace.colors[i].B));
    painter.setBrush(brush);
    painter.drawEllipse(
        QPointF(imageParams.coordsStartX + (double)colorSpace.points[i].x *
                                               (double)imageParams.coordsWidth,
                imageParams.coordsStartY + imageParams.coordsHeight -
                    (double)colorSpace.points[i].y * (double)imageParams.coordsHeight),
        radius, radius);
  }
  painter.end();
}

void WindowController::createSpecialPoint() {
  double X = 0.0;
  double Y = 0.0;
  double Z = 0.0;
  double hL;
  for (int i = 0; i < DATASET_LENGTH; ++i) {
    hL = bezierController.getY((double)i / (double)DATASET_LENGTH);
    X += hL * colorSpace.data[i][0];
    Y += hL * colorSpace.data[i][1];
    Z += hL * colorSpace.data[i][2];
  }
  double sum = X + Y + Z;
  double X1 = X / sum;
  double Y1 = Y / sum;
  double Z1 = Z / sum;

  Point p = colorSpace.getPointByData(X1, Y1, Z1);
  RGB color = colorSpace.getRgbByData2(X, Y, Z);

 QPainter painter(image.data());
  painter.setRenderHint(QPainter::Antialiasing);
  
 QPen pen(qRgb(color.R, color.G, color.B));
 pen.setWidth(2);
 painter.setPen(pen);
 QBrush brush(qRgb(color.R, color.G,color.B));
 painter.setBrush(brush);
 painter.drawEllipse(
     QPointF(imageParams.coordsStartX + p.x * (double)imageParams.coordsWidth,
             imageParams.coordsStartY + imageParams.coordsHeight -
                 p.y * (double)imageParams.coordsHeight),
     radius, radius);

 QPainterPath path;
 path.addRect(QRect(imageParams.coordsEndX - 250, imageParams.coordsStartY + 40,
                    150, 40));
 painter.setPen(Qt::black);
 painter.fillPath(path, QBrush(qRgb(color.R, color.G, color.B)));
 painter.drawPath(path);

 painter.setFont(QFont("Arial", 12));
 std::string xyinfo =
     std::format("{:.3f}", p.x) + "; " + std::format("{:.3f}", p.y); 
 painter.drawText(
     QPoint(
         imageParams.coordsStartX + p.x * (double)imageParams.coordsWidth - 15,
                         imageParams.coordsStartY + imageParams.coordsHeight -
                             p.y * (double)imageParams.coordsHeight + 25),
                  QString::fromStdString(xyinfo));

  painter.end();
}

void WindowController::drawScene() {
  image->load(CIE_IMAGE);
  if (!isCieImage) {
      
      QPainter painter(image.data());
      QPen pen(Qt::white);
      painter.setPen(pen);
      QBrush brush(Qt::white);
      painter.setBrush(brush);
      painter.drawRect(QRect(imageParams.coordsStartX, imageParams.coordsStartY,
                             imageParams.coordsWidth,
                             imageParams.coordsHeight));
      painter.end();
  }
  if (isBorderPoints) {
    createCIEborder();
  }
  createSpecialPoint();
}

void WindowController::moveControlPoint(int ind, double x, double y) {
  bezierController.modifyPoint(ind - 1, (double)x/480.0, 1.0 - (double)y/480.0);
  drawScene();
  emit controlPointMoved();
}

WindowController::WindowController(QObject* parent) : QObject(parent) {
  image = QSharedPointer<QImage>::create(width, height, QImage::Format_ARGB32);
  imageParams.pixelWidth = 1216.0;
  imageParams.pixelHeight = 1216.0;
  imageParams.coordsStartX = 40.0;
  imageParams.coordsStartY = 5.0;
  imageParams.coordsEndX = 1215.0;
  imageParams.coordsEndY = 1187.0;
  imageParams.coordsWidth = 1175.0;
  imageParams.coordsHeight = 1182.0;
  bezierController = BezierController();
  drawScene();
}

void WindowController::showBorderPoints() { 
    isBorderPoints = true;
  drawScene();
    emit borderPointsShowed();
}

void WindowController::hideBorderPoints() {
  isBorderPoints = false;
  drawScene();
  emit borderPointsHiden();
}

void WindowController::showBackground() { 
    isCieImage = true; 
    drawScene();
    emit backgroundShowed();
}

void WindowController::hideBackground() {
  isCieImage = false;
  drawScene();
  emit backgroundHiden();
}
