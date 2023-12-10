#pragma once
#include "ColorSpace.h"
#include <vector>

class BezierController {
 private:
  int size = 4;
  std::vector<Point> Vs = {{0.0, 0.2}, {0.3, 0.8}, {0.7, 0.8}, {1.0, 0.2}};
  //std::vector<Point> Vs = {{0 384}, {144 96}, {336 96}, {480 384}}
 public:
  BezierController(int _size, const std::vector<Point>& ps);
  BezierController() = default;
  void modifyPoint(int ind, double x, double y);
  double getY(double x);
};
