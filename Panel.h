#ifndef PANEL_H
#define PANEL_H

#include<vector>
#include<iostream>
#include<ctime>
#include<cmath>
#include <iomanip>


using namespace std;


// CONTROL PANEL
const bool ZERO_PAD = 1;            // use of zero padding?


const short IMG_SIZE_H_PRE = 10;        // input Matrix height pre zeropad
const short IMG_SIZE_W_PRE = 10;        // input Matrix width pre zeropad

const short IMG_SIZE_H_POST = (ZERO_PAD) ? IMG_SIZE_H_PRE + 2 : IMG_SIZE_H_PRE;        // input Matrix height post zeropad
const short IMG_SIZE_W_POST = (ZERO_PAD) ? IMG_SIZE_W_PRE + 2 : IMG_SIZE_W_PRE;        // input Matrix width post zeropad

const short NUM_IMG_LAYER_1 = 2;   // number of Matrixs in layer 1
const short NUM_IMG_LAYER_N = 3;   // number of Matrixs in layer 2 through N
const short NUM_N_LAYERS = 2;       // N




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



const short MAX_WEIGHT = 1;
const short MIN_WEIGHT = -1;
const short WEIGHT_PRE = 6;

const short MAX_PIXEL = 1;
const short MIN_PIXEL = 0;





/*
OPERATIONS LIST
convolve 2d/3d : "c"
    followed by: number of resulting images

zeropad        : "z"

pooling        : "p"
    followed by: type of pooling:
                  max: 'm'
                  avg: 'a'

Neuron layer   : "n"
    followed by: number of neurons in layer

NOTE: MUST END IN "n10"
*/

const short INITIAL_H = 3;
const short INITIAL_W = 3;
const short NUM_OUT = 10;


#endif