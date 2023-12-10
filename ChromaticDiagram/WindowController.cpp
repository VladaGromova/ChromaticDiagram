#include "WindowController.h"

void WindowController::createCIEborder() {
  double minX = 40.0, minY = 5.0, maxY = 1187.0, maxX = 1215.0, radius = 5.0;
  double width = maxX - minX;
  double height = maxY - minY;
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
        QPointF(
            minX + (double)colorSpace.points[i].x * (double)width,
            minY + height - (double)colorSpace.points[i].y * (double)height),
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
    hL = bezierController.getY((double)i / (double)DATASET_LENGTH) ;
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

  double minX = 40.0, minY = 5.0, maxY = 1187.0, maxX = 1215.0, radius = 10.0;
  double width = maxX - minX;
  double height = maxY - minY;
 QPainter painter(image.data());
  
 QPen pen(qRgb(color.R, color.G, color.B));
 pen.setWidth(2);
 painter.setPen(pen);
 QBrush brush(qRgb(color.R, color.G,color.B));
 painter.setBrush(brush);
 painter.drawEllipse(
     QPointF(minX + p.x * (double)width,
             minY + height - p.y * (double)height),
     radius, radius);
 painter.setPen(Qt::black);
 painter.setFont(QFont("Arial", 12));
 std::string xyinfo =
     std::format("{:.3f}", p.x) + "; " + std::format("{:.3f}", p.y); 
 painter.drawText(
     QPoint(minX + p.x * (double)width - 15, minY + height - p.y * (double)height + 25),
                  QString::fromStdString(xyinfo));
  painter.end();
}

void WindowController::moveControlPoint(int ind, double x, double y) {
  bezierController.modifyPoint(ind - 1, (double)x/480.0, 1.0 - (double)y/480.0);
  image->load(CIE_IMAGE);
  createCIEborder();
  createSpecialPoint();
  emit controlPointMoved();
}

WindowController::WindowController(QObject* parent) : QObject(parent) {
  image = QSharedPointer<QImage>::create(500, 500, QImage::Format_ARGB32);
  image->load(CIE_IMAGE);
  createCIEborder();
  bezierController = BezierController();
  createSpecialPoint();
}