



#include "panel.h"    //constants
#include "source.h"
#include "matrix2d.h"

Matrix::Matrix()
{
  Matrix(1, 1);
}

Matrix::Matrix(const short height, const short width)
{
  m_height = height;
  m_width = width;

  img.resize(height);
  for (short i = 0; i < height; i++)
  {
    img[i].resize(width);
    for (short j = 0; j < width; j++)
    {
      img[i][j] = 0;
    }
  }


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

void Matrix::randomize() 
{
  for (short i = 0; i < m_height; i++)
  {
    for (short j = 0; j < m_width; j++)
    {
      img[i][j] = rand()%((MAX_PIXEL-MIN_PIXEL)*100)/100.0;
    }
  }
  return;
}






void Matrix::apply_zero_pad()
{

  if (ZERO_PAD)
  {
    Matrix output(m_height + 2, m_width + 2);


    for (short i = 1; i < m_height+1; i++)
    {
      for (short j = 1; j < m_width + 1; j++)
      {
        output.set_pixel(i, j, img[i-1][j-1]);
      }
    }
    
    for (short i = 1; i < m_height + 1; i++)
    {
      output.set_pixel(i, 0, 0);
      output.set_pixel(i, m_width + 1, 0);

    }

    for (short i = 1; i < m_width + 1; i++)
    {
      output.set_pixel(0, i, 0);
      output.set_pixel(m_height + 1, i, 0);

    }
    
    set_height(m_height + 2);
    set_width(m_width + 2);

    for (short i = 0; i < m_height ; i++)
    {
      for (short j = 0; j < m_width ; j++)
      {
        img[i][j] = output.get_pixel(i, j);
      }
    }
    


  }

  return;

}



void Matrix::apply_active() 
{

  for (short i = 0; i < m_height; i++)
  {
    for (short j = 0; j < m_width; j++)
    {
      img[i][j] = activate(img[i][j]);
    }
  }
  return;
}


