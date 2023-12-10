#include "BezierController.h"
#include<vector>

BezierController::BezierController(int _size, const std::vector<Point>& ps)
    : size(_size), Vs(ps) {}

void BezierController::modifyPoint(int ind, double x, double y) { 
    Vs[ind].x = x;
    Vs[ind].y = y;
}

double BezierController::getY(double x) {
  const double epsilon = 0.00001;
  double t0 = 0.0;
  double t1 = 1.0;
  double t = (t0 + t1) / 2.0;
  int maxIters = 5000;
  int iters = 0;
  while (true) {
    if (iters > maxIters) break;
    if (t0 < 0.0 || t1 > 1.0) break;
    t = (t0 + t1) / 2.0;

    double xEstimate = (double)pow(1.0 - t, 3.0) * Vs[0].x +
                       (double)3.0 * pow(1.0 - t, 2.0) * t * Vs[1].x +
                       (double)3.0 * (1.0 - t) * pow(t, 2) * Vs[2].x +
                       (double)pow(t, 3) * Vs[3].x;
    double diff = xEstimate - x;
    if (fabs(diff) < epsilon) {
      return (double)pow(1.0 - t, 3) * Vs[0].y + 3.0 * pow(1.0 - t, 2) * t * Vs[1].y +
             3.0 * (1.0 - t) * pow(t, 2) * Vs[2].y + pow(t, 3) * Vs[3].y;
    }
    ++iters;
    if (diff > 0)
      t1 = t;
    else
      t0 = t;
  }
  return pow(1 - t, 3) * Vs[0].y + 3 * pow(1 - t, 2) * t * Vs[1].y +
         3 * (1 - t) * pow(t, 2) * Vs[2].y + pow(t, 3) * Vs[3].y;
}