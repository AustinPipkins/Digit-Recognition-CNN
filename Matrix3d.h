#ifndef MATRIX3D_H
#define MATRIX3D_H

#include "panel.h"    //constants



class Matrix3d
{
public:
  Matrix3d(const short depth, const short height, const short width);
  Matrix3d();
  void set_pixel(const short z, const short y, const short x, const float val);
  float get_pixel(const short z, const short y, const short x)const;
  short get_height() const;
  short get_width() const;
  short get_depth() const;
  void set_height(const short new_height);
  void set_width(const short new_width);
  void set_depth(const short new_width);

  void randomize();

private:
  vector<vector<vector<float>>> img;
  short m_height;
  short m_width;
  short m_depth;
};

#endif