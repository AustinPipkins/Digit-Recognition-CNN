#include "panel.h"    //constants

#include "matrix3d.h"

Matrix3d::Matrix3d()
{
  m_height = 1;
  m_width = 1;
  m_depth = 1;
}

Matrix3d::Matrix3d(const short depth, const short height, const short width, const vector<vector<vector<short>>> data)
{
  img.resize(depth);
  for (short i = 0; i < depth; i++)
  {
    img[i].resize(height);
    for (short j = 0; j < height; j++)
    {
      img[i][j].resize(width);
      for (short k = 0; k < width; k++)
      {
        img[i][j][k] = data[i][j][k];
      }
    }
  }

  m_height = height;
  m_width = width;
  m_depth = depth;
}

//width, heigh
void Matrix3d::set_pixel(const short z, const short y, const short x, const short val)
{
  img[z][y][x] = val;
  return;
}
short Matrix3d::get_pixel(const short z, const short y, const short x)const
{
  return img[z][y][x];
}

short Matrix3d::get_height() const
{
  return m_height;
}

short Matrix3d::get_width() const
{
  return m_width;
}
short Matrix3d::get_depth() const
{
  return m_depth;
}
void Matrix3d::set_height(const short new_height)
{
  m_height = new_height;
  for (short i = 0; i < m_depth; i++)
  {
    img[i].resize(new_height);
  }
  return;
}
void Matrix3d::set_width(const short new_width)
{
  m_width = new_width;
  for (short i = 0; i < m_depth; i++)
  {
    for (short i = 0; i < m_height; i++)
    {
      img[i].resize(new_width);
    }
  }
  return;
}
void Matrix3d::set_depth(const short new_depth)
{
  m_depth = new_depth;
  img.resize(new_depth);
  return;
}