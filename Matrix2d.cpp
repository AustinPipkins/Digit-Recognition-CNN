



#include "panel.h"    //constants
#include "matrix2d.h"

Matrix::Matrix()
{
  Matrix(1, 1);
}

Matrix::Matrix(const short height, const short width)
{
  img.resize(height);
  for (short i = 0; i < height; i++)
  {
    img[i].resize(width);
    for (short j = 0; j < width; j++)
    {
      img[i][j] = 0;
    }
  }

  m_height = height;
  m_width = width;
}

//width, heigh
void Matrix::set_pixel(const short y, const short x, const float val)
{
  img[y][x] = val;
  return;
}
float Matrix::get_pixel(const short y, const short x)const
{
  return img[y][x];
}

short Matrix::get_height() const
{
  return m_height;
}

short Matrix::get_width() const
{
  return m_width;
}
void Matrix::set_height(const short new_height)
{
  m_height = new_height;
  img.resize(m_height);
  return;
}
void Matrix::set_width(const short new_width)
{
  m_width = new_width;
  for (short i = 0; i < m_height; i++)
  {
    img[i].resize(m_width);

  }
  return;
}


