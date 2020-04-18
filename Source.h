#ifndef SOURCE_H
#define SOURCE_H

#include "panel.h"    //constants

#include "matrix2d.h"
#include "matrix3d.h"

struct siz
{
  short m_height;
  short m_width;
};


struct weight_set
{
  vector<float> m_weight_set;
  short m_length;
};


Matrix apply_zero_pad(const Matrix picture);

siz new_size(const Matrix picture, const Matrix filter);

Matrix convolve(const Matrix picture, const Matrix filter);

Matrix convolve(const Matrix pictures[], const short num_matrix, const Matrix3d filter);

siz new_size3d(const Matrix picture, const Matrix3d filter);

float random_number(const short lower, const short upper, const short pre);

template <typename T>
T activate(T old_num);

Matrix pool(Matrix input, const char kind);

ostream& operator << (ostream& out, Matrix m);


#endif