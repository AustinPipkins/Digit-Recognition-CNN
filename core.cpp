/*
/\\\______________/\\\__/\\\\\\\\\\\\\\\__/\\\____________________/\\\\\\\\\_______/\\\\\_______/\\\\____________/\\\\__/\\\\\\\\\\\\\\\_
 _\/\\\_____________\/\\\_\/\\\///////////__\/\\\_________________/\\\////////______/\\\///\\\____\/\\\\\\________/\\\\\\_\/\\\///////////__
  _\/\\\_____________\/\\\_\/\\\_____________\/\\\_______________/\\\/_____________/\\\/__\///\\\__\/\\\//\\\____/\\\//\\\_\/\\\_____________
   _\//\\\____/\\\____/\\\__\/\\\\\\\\\\\_____\/\\\______________/\\\______________/\\\______\//\\\_\/\\\\///\\\/\\\/_\/\\\_\/\\\\\\\\\\\_____
    __\//\\\__/\\\\\__/\\\___\/\\\///////______\/\\\_____________\/\\\_____________\/\\\_______\/\\\_\/\\\__\///\\\/___\/\\\_\/\\\///////______
     ___\//\\\/\\\/\\\/\\\____\/\\\_____________\/\\\_____________\//\\\____________\//\\\______/\\\__\/\\\____\///_____\/\\\_\/\\\_____________
      ____\//\\\\\\//\\\\\_____\/\\\_____________\/\\\______________\///\\\___________\///\\\__/\\\____\/\\\_____________\/\\\_\/\\\_____________
       _____\//\\\__\//\\\______\/\\\\\\\\\\\\\\\_\/\\\\\\\\\\\\\\\____\////\\\\\\\\\____\///\\\\\/_____\/\\\_____________\/\\\_\/\\\\\\\\\\\\\\\_
        ______\///____\///_______\///////////////__\///////////////________\/////////_______\/////_______\///______________\///__\///////////////__
__/\\\________/\\\__________________________________________________/\\\\\\\_____________/\\\\\\\\\_____
 _\/\\\_______\/\\\________________________________________________/\\\/////\\\_________/\\\///////\\\___
  _\//\\\______/\\\________________________________________________/\\\____\//\\\_______\///______\//\\\__
   __\//\\\____/\\\_______/\\\\\\\\___/\\/\\\\\\\__________________\/\\\_____\/\\\_________________/\\\/___
    ___\//\\\__/\\\______/\\\/////\\\_\/\\\/////\\\_________________\/\\\_____\/\\\______________/\\\//_____
     ____\//\\\/\\\______/\\\\\\\\\\\__\/\\\___\///__________________\/\\\_____\/\\\___________/\\\//________
      _____\//\\\\\______\//\\///////___\/\\\_________________________\//\\\____/\\\__________/\\\/___________
       ______\//\\\________\//\\\\\\\\\\_\/\\\__________/\\\____________\///\\\\\\\/____/\\\__/\\\\\\\\\\\\\\\_
        _______\///__________\//////////__\///__________\///_______________\///////_____\///__\///////////////__

NAME: Veronica(?)
VER 0.2 - 3d convolve
START DATE: 4-1-2020 (lol wont be doing much tho)
Credit to: MNIST data


 ==============================================
  ____  _                   _
 / ___|| |_ _ __ _   _  ___| |_ _   _ _ __ ___
 \___ \| __| '__| | | |/ __| __| | | | '__/ _ \
  ___) | |_| |  | |_| | (__| |_| |_| | | |  __/
 |____/ \__|_|   \__,_|\___|\__|\__,_|_|  \___|
 ==============================================

Layer 0: Input pre-processing
Layer 1: Convolutional -> pooling
Layer 2: N times ^
Layer 3: M layer Perceptitron
Layer 4: Output processing

Training:
hahahaha something about back propigation


===========================================
  ____       _              _       _
 / ___|  ___| |__   ___  __| |_   _| | ___
 \___ \ / __| '_ \ / _ \/ _` | | | | |/ _ \
  ___) | (__| | | |  __/ (_| | |_| | |  __/
 |____/ \___|_| |_|\___|\__,_|\__,_|_|\___|
===========================================
Research - brain                                       | start: March 2020   end: April 6th
Concept visuals + architecture design                  | start: April 6th    end: April 6th
Simple brain coding + testing                          | start: April 6th
Brain works                           ← first milestone|
Expand brain                                           |
Research - training                                    |
Research - preprocessing                               |
Concepts + architecture of training algorithm          |
Program preprocessing + test         ← second milestone|
Program training algorithm                             |
Lots and lots of hole testing                          |
Training is operational               ← third milestone|
Train to 20%, 50%, 90%                                 |
Train to max capacity                 ←fourth milestone|

-optional stop - job well done-

Edit pre-processing for stringed characters
Edit training algorithm - test
Train to max capacity multi character responses ← fifth milestone


     8a
     `8b
      `8b
       `8b
888     88
888     88
       ,8P
888   ,8P
888  ,8P
     8"

</end>

Patch 0.0 march:
start file

patch 0.1 - 4-7-2020:
added zero padding
added matrix class
added convolve function

patch 0.2 - 4-8-2020:
added 3d matrix class
added 3d convolve function
started ANN

*/
#include<vector>
#include<iostream>
#include<ctime>
using namespace std;


// CONTROL PANEL
const bool ZERO_PAD = 1;            // use of zero padding?


const short IMG_SIZE_H_PRE = 10;        // input Matrix height pre zeropad
const short IMG_SIZE_W_PRE = 10;        // input Matrix width pre zeropad

const short IMG_SIZE_H_POST = (ZERO_PAD) ? IMG_SIZE_H_PRE + 2 : IMG_SIZE_H_PRE;        // input Matrix height post zeropad
const short IMG_SIZE_W_POST = (ZERO_PAD) ? IMG_SIZE_W_PRE + 2 : IMG_SIZE_W_PRE;        // input Matrix width post zeropad

const short NUM_IMG_LAYER_1 = 10;   // number of Matrixs in layer 1
const short NUM_IMG_LAYER_N = 10;   // number of Matrixs in layer 2 through N
const short NUM_N_LAYERS = 3;       // N


// n = none
// m = maxpool
// a = avgpool
const char POOL_TYPE = 'n';

const short FILTER_SIZE_1 = 3;    // size of filters for layer 1
const short FILTER_SIZE_N = 3;    // size of filters for N layers

// r = ReLu
// s = sigmoid
// l = linear
const char ACTIVATION_FUNC = 'r';   // activation function




// start code

//-----------------------------------------------------------------------------------------------control panel

class Matrix
{
public:
  Matrix(const short height, const short width);
  Matrix();
  void set_pixel(const short y, const short x, const short val);
  short get_pixel(const short y, const short x)const;
  short get_height() const;
  short get_width() const;
  void set_height(const short new_height);
  void set_width(const short new_width);

private:
  vector<vector<short>> img;
  short m_height;
  short m_width;

};

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
void Matrix::set_pixel(const short y, const short x, const short val)
{
  img[y][x] = val;
  return;
}
short Matrix::get_pixel(const short y, const short x)const
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

//-----------------------------------------------------------------------------------------------matrix3d

class Matrix3d
{
public:
  Matrix3d(const short depth, const short height, const short width, const vector<vector<vector<short>>> data);
  Matrix3d();
  void set_pixel(const short z, const short y, const short x, const short val);
  short get_pixel(const short z, const short y, const short x)const;
  short get_height() const;
  short get_width() const;
  short get_depth() const;
  void set_height(const short new_height);
  void set_width(const short new_width);
  void set_depth(const short new_width);

private:
  vector<vector<vector<short>>> img;
  short m_height;
  short m_width;
  short m_depth;
};

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
//-----------------------------------------------------------------------------------------------siz
struct siz
{
  short m_height;
  short m_width;
};

Matrix apply_zero_pad(const Matrix picture);

siz new_size(const Matrix picture, const Matrix filter);

Matrix convolve(const Matrix picture, const Matrix filter);

Matrix convolve(const Matrix pictures[], const short num_matrix, const Matrix3d filter);

siz new_size3d(const Matrix picture, const Matrix3d filter);

//-----------------------------------------------------------------------------------------------main
int main()
{
  srand(time(0));


  //make layer 0 input <- img 1

  //generate filters

  //plug in filters

  //2d convolve the filters

  //place results into array

  //3d convolve

  // N times^

  //last 3d convolve into data img

  //ANN




}

//-----------------------------------------------------------------------------------------------zero pad
Matrix apply_zero_pad(const Matrix picture)
{
  Matrix output = picture;


  for (short i = 0; i < IMG_SIZE_W_POST; i++)
  {
    output.set_pixel(0, i, 0);
    output.set_pixel(IMG_SIZE_H_POST - 1, i, 0);
  }

  for (short i = 0; i < IMG_SIZE_H_POST; i++)
  {
    output.set_pixel(i, 0, 0);
    output.set_pixel(i, IMG_SIZE_W_POST - 1, 0);
  }


  return output;

}

//-----------------------------------------------------------------------------------------------new siz
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


//-----------------------------------------------------------------------------------------------2dconv
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

//-----------------------------------------------------------------------------------------------3d conv

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



