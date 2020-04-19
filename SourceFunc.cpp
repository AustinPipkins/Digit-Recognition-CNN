

#include "panel.h"    //constants
#include "source.h"
#include "matrix2d.h"
#include "matrix3d.h"



siz new_size(const Matrix picture, const Matrix filter)
{
  siz si;
  si.m_height = (picture.get_height() - filter.get_height()) + 1;
  si.m_width = (picture.get_width() - filter.get_width()) + 1;
  return si;
}

siz new_size3d(const Matrix picture, const Matrix3d filter)
{
  Matrix temp;
  temp.set_height(filter.get_height());
  temp.set_width(filter.get_width());
  return new_size(picture, temp);
}



//apply zero pad b4
Matrix convolve(const Matrix picture, const Matrix filter)
{
  short output_height = (picture.get_height() - filter.get_height()) + 1;
  short output_width = (picture.get_width() - filter.get_width()) + 1;

  short val;

  Matrix output(output_height, output_width);

  for (short i = 0; i < output_height; i++)
  {
    for (short j = 0; j < output_width; j++)
    {
      val = 0;

      for (short y = 0; y < filter.get_height(); y++)
      {
        for (short x = 0; x < filter.get_width(); x++)
        {
          val += picture.get_pixel(i + y, j + x) * filter.get_pixel(y, x);
        }
      }


      output.set_pixel(i, j, val);

    }
  }



  return output;
}




//apply zero pad b4
//all pictires same size ;)
Matrix convolve(const Matrix pictures[], const short num_matrix, const Matrix3d filter)
{
  short output_height = (pictures[0].get_height() - filter.get_height()) + 1;
  short output_width = (pictures[0].get_width() - filter.get_width()) + 1;

  short val;

  Matrix output(output_height, output_width);

  for (short i = 0; i < output_height; i++)
  {
    for (short j = 0; j < output_width; j++)
    {
      val = 0;

      for (short z = 0; z < filter.get_depth(); z++)
      {
        for (short y = 0; y < filter.get_height(); y++)
        {
          for (short x = 0; x < filter.get_width(); x++)
          {
            val += pictures[z].get_pixel(i + y, j + x) * filter.get_pixel(z, y, x);
          }
        }
      }


      output.set_pixel(i, j, val);

    }
  }


  return output;
}




//warning
float random_number(const short lower, const short upper, const short pre)
{
  long range = upper - lower;
  long big = static_cast<int>(pow(10, pre));
  return ((rand() % (range * big + 1)) + lower * big) / (pow(10, pre));
}



float activate(float old_num)
{
  float num = old_num;

  /*
  if (ACTIVATION_FUNC == 'r')
  {
    if (old_num < 0)
    {
      num = 0;
    }
  }

  if (ACTIVATION_FUNC == 's')
  {
    num = 1.0 / (1.0 + exp(-old_num));
  }
  */

  return num;
}



Matrix pool(Matrix input, const char kind)
{
  short new_height;
  short new_width;

  bool height_pad = 0;
  bool width_pad = 0;

  float temp;

  

  //even
  if (input.get_height() % 2 == 0)
  {
    new_height = input.get_height() / 2;
  }
  else //odd
  {
    height_pad = 1;
    new_height = input.get_height() / 2 + 1;
  }

  //even
  if (input.get_width() % 2 == 0)
  {
    new_width = input.get_width() / 2;
  }
  else //odd
  {
    width_pad = 1;
    new_width = input.get_width() / 2 + 1;
  }



  if (width_pad || height_pad)
  {
    
    Matrix adjusted((height_pad)? input.get_height()+1: input.get_height(), (width_pad) ? input.get_width() + 1 : input.get_width());

    for (short i = 0; i < adjusted.get_height(); i++)
    {
      for (short j = 0; j < adjusted.get_width(); j++)
      {
        if ((i == adjusted.get_height()-1 && height_pad) || (j == adjusted.get_width() - 1 && width_pad))
        {
          adjusted.set_pixel(i, j, 0);
        }
        else
        {
          adjusted.set_pixel(i, j, input.get_pixel(i, j));
        }
      }
    }

    input = adjusted;
  }

  //all is evn x even

  Matrix output(new_height, new_width);

  if (kind == 'a')
  {
    for (short i = 0; i < new_height; i++)
    {
      for (short j = 0; j < new_width; j++)
      {
        temp = input.get_pixel(i * 2, j * 2) + input.get_pixel(i * 2 + 1, j * 2) + input.get_pixel(i * 2, j * 2 + 1) + input.get_pixel(i * 2 + 1, j * 2 + 1);
        temp /= (((i == new_height - 1 && height_pad) || (j == new_width - 1 && width_pad))? 2:4);
        output.set_pixel(i, j, temp);
      }
    }
  }



  
  if (kind == 'm')
  {
    for (short i = 0; i < new_height; i++)
    {
      for (short j = 0; j < new_width; j++)
      {
        if (input.get_pixel(i * 2, j * 2) > input.get_pixel(i * 2 + 1, j * 2))
        {
          if (input.get_pixel(i * 2, j * 2 + 1) > input.get_pixel(i * 2 + 1, j * 2 + 1))
          {
            temp = ((input.get_pixel(i * 2, j * 2) > input.get_pixel(i * 2, j * 2 + 1)) ? input.get_pixel(i * 2, j * 2) : input.get_pixel(i * 2, j * 2 + 1));
          }
          else 
          {
            temp = ((input.get_pixel(i * 2, j * 2) > input.get_pixel(i * 2 + 1, j * 2 + 1)) ? input.get_pixel(i * 2, j * 2) : input.get_pixel(i * 2 + 1, j * 2 + 1));
          }
        }
        else
        {
          if (input.get_pixel(i * 2, j * 2 + 1) > input.get_pixel(i * 2 + 1, j * 2 + 1))
          {
            temp = ((input.get_pixel(i * 2 + 1, j * 2) > input.get_pixel(i * 2, j * 2 + 1)) ? input.get_pixel(i * 2 + 1, j * 2) : input.get_pixel(i * 2, j * 2 + 1));
          }
          else
          {
            temp = ((input.get_pixel(i * 2 + 1, j * 2) > input.get_pixel(i * 2 + 1, j * 2 + 1)) ? input.get_pixel(i * 2 + 1, j * 2) : input.get_pixel(i * 2 + 1, j * 2 + 1));
          }
        }
        output.set_pixel(i, j, temp);
      }
    }
  }
  

  return output;
  
}


ostream& operator << (ostream& out, Matrix m)
{
  cout << fixed;
  for (short i = 0; i < m.get_height(); i++)
  {
    for (short j = 0; j < m.get_width(); j++)
    {
      out << setprecision(2) << m.get_pixel(i, j) << "\t";
    }
    out << endl;
  }

  return out;
}

ostream& operator << (ostream& out, Matrix3d m)
{
  cout << fixed;

  for (short i = 0; i < m.get_width()/2; i++)
  {
    out << "       ";
  }

  for (short j = 0; j < m.get_depth(); j++)
  {
    out << "Depth " << j;
    for (short i = 0; i < m.get_width(); i++)
    {
      out << "\t" << "    ";
    }
  }

  out << endl;

  for (short k = 0; k < m.get_height(); k++)
  {
    for (short j = 0; j < m.get_depth(); j++)
    {
      for (short i = 0; i < m.get_width(); i++)
      {
        out << setprecision(2) << m.get_pixel(j, k, i) << "\t";
      }
      out << "\t";
    }
    out << endl;
  }


  return out;
}




