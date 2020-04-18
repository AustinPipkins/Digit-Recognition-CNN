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
__/\\\________/\\\__________________________________________________/\\\\\\\_____________________/\\\____
 _\/\\\_______\/\\\________________________________________________/\\\/////\\\_________________/\\\\\____
  _\//\\\______/\\\________________________________________________/\\\____\//\\\______________/\\\/\\\____
   __\//\\\____/\\\_______/\\\\\\\\___/\\/\\\\\\\__________________\/\\\_____\/\\\____________/\\\/\/\\\____
    ___\//\\\__/\\\______/\\\/////\\\_\/\\\/////\\\_________________\/\\\_____\/\\\__________/\\\/__\/\\\____
     ____\//\\\/\\\______/\\\\\\\\\\\__\/\\\___\///__________________\/\\\_____\/\\\________/\\\\\\\\\\\\\\\\_
      _____\//\\\\\______\//\\///////___\/\\\_________________________\//\\\____/\\\________\///////////\\\//__
       ______\//\\\________\//\\\\\\\\\\_\/\\\__________/\\\____________\///\\\\\\\/____/\\\___________\/\\\____
        _______\///__________\//////////__\///__________\///_______________\///////_____\///____________\///_____

NAME: Veronica(?)
VER 0.4 - pre-compiler
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

patch 0.3 - 4-12-2020:
add neuron structure
added random number function (LUP)
added neuron forward propagation

patch 0.4 - 4-17-2020:
seperated files
added activation functions
added pooling
started op_list compiler

*/


#include "panel.h"    //constants
#include "source.h"  
#include "matrix3d.h"
#include "matrix2d.h"
#include "neuron.h"



int main()
{
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
  
  



  //make func: op_check

  // i = single image
  // I = multiple images
  // n = single neuron
  // N = many neurons

  char layer_type = 'i';
  // checks that opload is valid
  for (short i = 0; i < NUM_OP; i++)
  {

    
  }

  return 1;

  */

  srand(time(0));
  short h = 5;
  short w = 4;

  Matrix poop(h,w);

  for (short i = 0; i < h; i++)
  {
    for (short j = 0; j < w; j++)
    {
      poop.set_pixel(i, j, rand() % 15/1.72);
    }
  }

  cout << poop << endl;

  Matrix loop = pool(poop, 'a');

  cout << loop;

}


