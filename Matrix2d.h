#ifndef MATRIX2D_H
#define MATRIX2D_H

#include "panel.h"    //constants

class Matrix
{
public:
  Matrix(const short height, const short width);
  Matrix();
  void set_pixel(const short y, const short x, const float val);
  float get_pixel(const short y, const short x)const;
  short get_height() const;
  short get_width() const;
  void set_height(const short new_height);
  void set_width(const short new_width);

private:
  vector<vector<float>> img;
  short m_height;
  short m_width;

};

#endif