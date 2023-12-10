#pragma once
#define DATASET_LENGTH 401

typedef struct {
  double x, y;
} Point;

typedef struct {
  //double r, g, b;
  int R, G, B;
} RGB;

class ColorSpace {
 private:
  void initializePoints();
  void createColors();
  double XYZtoRGBmatrix[3][3] = {{3.2404542, -1.5371385, -0.4985314},
                                 {-0.9692660, 1.8760108, 0.0415560},
                                 {0.0556434, -0.2040259, 1.0572252}};
 public:
  double data[DATASET_LENGTH][3];
  Point points[DATASET_LENGTH]; // will be private
  RGB colors[DATASET_LENGTH];
  ColorSpace();
  Point getPointByData(double X, double Y, double Z);
  RGB getRgbByData(double X, double Y, double Z); // from 0 to <1
  RGB getRgbByData2(double X, double Y, double Z);
  Point* getPoints();
};
