#include "ColorSpace.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> 
//#define DATA_FILE "color_matching_functions.txt"
#define DATA_FILE "ciexyz.txt"
#define EPS 0.0000001

ColorSpace::ColorSpace() {
  std::ifstream inputFile;
  inputFile.open(DATA_FILE, std::ios::in);
  if (!inputFile.is_open()) {
    std::cout << "Error opening file: " << DATA_FILE << std::endl;
    return;
  }
  std::string inputString;
  getline(inputFile, inputString);
  int i = 0;
  while (getline(inputFile, inputString)) {
    std::istringstream iss(inputString);
    double val;
    iss >> val;
    for (int j = 0; j < 3; ++j) {
      iss >> data[i][j];
    }
    ++i;
  }
  initializePoints();
  createColors();
}

void ColorSpace::initializePoints() {
  double sum;
  for (int i = 0; i < DATASET_LENGTH; i++) {
    points[i] = getPointByData(data[i][0], data[i][1], data[i][2]);
  }
}

void ColorSpace::createColors() {
  for (int i = 0; i < DATASET_LENGTH; i++) {
    colors[i] = getRgbByData(data[i][0],data[i][1],data[i][2]);
    // change
  }
}

Point* ColorSpace::getPoints() { return points; }

RGB ColorSpace::getRgbByData(double X, double Y, double Z) {
  double a, bb, c, tmp, r, g, b;
  if (Y < EPS) {
    tmp = EPS;
  } else {
    tmp = Y;
  }
  a = (double)X / tmp;
  bb = tmp;
  c = (double)Z / tmp;
  r = std::max(a * XYZtoRGBmatrix[0][0] + bb * XYZtoRGBmatrix[0][1] +
                   c * XYZtoRGBmatrix[0][2],
               0.0);
  g = std::max(a * XYZtoRGBmatrix[1][0] + bb * XYZtoRGBmatrix[1][1] +
                   c * XYZtoRGBmatrix[1][2],
               0.0);
  b = std::max(a * XYZtoRGBmatrix[2][0] + bb * XYZtoRGBmatrix[2][1] +
                   c * XYZtoRGBmatrix[2][2],
               0.0);
  tmp = std::max(r, g);
  tmp = std::max(tmp, b);
  r = (double)r / (double)tmp;
  g = (double)g / (double)tmp;
  b = (double)b / (double)tmp;
  RGB res;
  res.R = (double)r * (double)255;
  res.G = (double)g * (double)255;
  res.B = (double)b * (double)255;
  return res;
}

Point ColorSpace::getPointByData(double X, double Y, double Z) {
  double sum = X + Y + Z;
  Point p;
  p.x = (double)X / (double)sum;
  p.y = (double)Y / (double)sum;
  return p;
}

RGB ColorSpace::getRgbByData2(double X, double Y, double Z) {
  double _X = X / 100;
  double _Y = Y / 100;
  double _Z = Z / 100;
  double var_R = std::max(_X * XYZtoRGBmatrix[0][0] + _Y * XYZtoRGBmatrix[0][1] +
                   _Z * XYZtoRGBmatrix[0][2],
               0.0);
  double var_G = std::max(_X * XYZtoRGBmatrix[1][0] + _Y * XYZtoRGBmatrix[1][1] +
                   _Z * XYZtoRGBmatrix[1][2],
               0.0);
  double var_B = std::max(_X * XYZtoRGBmatrix[2][0] + _Y * XYZtoRGBmatrix[2][1] +
                   _Z * XYZtoRGBmatrix[2][2],
               0.0);

  if (var_R > 0.0031308) {
    var_R = 1.055 * (pow(var_R,(1.0 / 2.4))) - 0.055;
  } else {
    var_R = 12.92 * var_R;
  }
  if (var_G > 0.0031308) {
    var_G = 1.055 * (pow(var_G ,(1.0 / 2.4))) - 0.055;
  } else {
    var_G = 12.92 * var_G;
  }
  if (var_B > 0.0031308) {
    var_B = 1.055 * (pow(var_B, (1.0 / 2.4))) - 0.055;
  } else {
    var_B = 12.92 * var_B;
  }
  RGB res;
  res.R = var_R * 255;
  res.G = var_G * 255;
  res.B = var_B * 255;
  return res;
}