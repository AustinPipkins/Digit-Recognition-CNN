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
__/\\\________/\\\__________________________________________________/\\\\\\\____________/\\\\\\\\\\\\\\\_
 _\/\\\_______\/\\\________________________________________________/\\\/////\\\_________\/\\\///////////__
  _\//\\\______/\\\________________________________________________/\\\____\//\\\________\/\\\_____________
   __\//\\\____/\\\_______/\\\\\\\\___/\\/\\\\\\\__________________\/\\\_____\/\\\________\/\\\\\\\\\\\\_____
    ___\//\\\__/\\\______/\\\/////\\\_\/\\\/////\\\_________________\/\\\_____\/\\\________\////////////\\\___
     ____\//\\\/\\\______/\\\\\\\\\\\__\/\\\___\///__________________\/\\\_____\/\\\___________________\//\\\__
      _____\//\\\\\______\//\\///////___\/\\\_________________________\//\\\____/\\\_________/\\\________\/\\\__
       ______\//\\\________\//\\\\\\\\\\_\/\\\__________/\\\____________\///\\\\\\\/____/\\\_\//\\\\\\\\\\\\\/___
        _______\///__________\//////////__\///__________\///_______________\///////_____\///___\/////////////_____

NAME: Veronica(?)
VER 0.5 - connecting brain
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

patch 0.5 - 4-18-2020:
added << overload for 3d filters
added randomize method
fixed zero pad apply
added active all method
added filter list initializer
added layer list initializer
conected layer 1 - unchecked

*/


#include "panel.h"    //constants
#include "source.h"  
#include "matrix3d.h"
#include "matrix2d.h"
#include "neuron.h"




// img -> make many reuslts (for each): zero pad? conv? active:



int main()
{

  srand(time(0));
  //const short INITIAL_H = 28;
  //const short INITIAL_W = 28;
  //const short NUM_OUT = 10;


  
  //initilaize a filter set
  vector<vector<Matrix3d>> filter_list;
  filter_list.resize(NUM_N_LAYERS + 1);
  for (short i = 0; i < NUM_N_LAYERS + 1; i++)
  {
    if (i == 0)
    {
      filter_list[i].resize(NUM_IMG_LAYER_1);
    }
    else
    {
      filter_list[i].resize(NUM_IMG_LAYER_N);
    }
  }


  for (short layer = 0; layer < NUM_N_LAYERS + 1; layer++)
  {
    if(layer == 0)
    {
      for (short filter = 0; filter < NUM_IMG_LAYER_1; filter++)
      {
        //2d in 3dform
        Matrix3d temp_filter(1, FILTER_SIZE_1, FILTER_SIZE_1);
        temp_filter.randomize();
        //cout << temp_filter;
        filter_list[0][filter] = temp_filter;

      }
    }
    else 
    {
      for (short filter = 0; filter < NUM_IMG_LAYER_N; filter++)
      {
        Matrix3d temp_filter(((layer==1)? NUM_IMG_LAYER_1 : NUM_IMG_LAYER_N), FILTER_SIZE_N, FILTER_SIZE_N);
        temp_filter.randomize();
        filter_list[layer][filter] = temp_filter;
      }
    }
  }
  

  for (short i = 0; i < NUM_N_LAYERS + 1; i++)
  {
    cout << "LAYER ===== " << i + 1 << endl;
    if (i == 0)
    {
      for (short j = 0; j < NUM_IMG_LAYER_1; j++)
      {
        cout << "filter" << j+1 << endl << filter_list[0][j] << endl << endl;
      }
    }
    else
    {
      for (short j = 0; j < NUM_IMG_LAYER_N; j++)
      {
        cout << "filter" << j + 1 << endl << filter_list[i][j] << endl << endl;
      }
    }
  }
  
  return 0;

  //filterlist made
  

  

  //initilaize a layer list
  vector<vector<Matrix>> layer_list;
  filter_list.resize(NUM_N_LAYERS + 1);

  for (short i = 0; i < NUM_N_LAYERS + 1; i++)
  {
    if (i == 0)
    {
      filter_list[i].resize(NUM_IMG_LAYER_1);
    }
    else
    {
      filter_list[i].resize(NUM_IMG_LAYER_N);
    }
  }

  


  



  Matrix input_img(INITIAL_H, INITIAL_W);

  //load the img here!
  //for now: fill with random
  input_img.randomize();

  
  //layer 1
  for (short result = 0; result < NUM_IMG_LAYER_1; result++)
  {
    Matrix copy = input_img;
    copy.apply_zero_pad();

    Matrix img_list[] = { copy };

    Matrix convolve(const Matrix pictures[], const short num_matrix, const Matrix3d filter);

    copy = convolve(img_list, 1, filter_list[0][result]);

    copy.apply_active();

    layer_list[0][result] = copy;




  } 

  


  




  return 1;

  


















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


