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
__/\\\________/\\\__________________________________________________/\\\\\\\_____________________/\\\\\_
 _\/\\\_______\/\\\________________________________________________/\\\/////\\\_______________/\\\\////__
  _\//\\\______/\\\________________________________________________/\\\____\//\\\___________/\\\///_______
   __\//\\\____/\\\_______/\\\\\\\\___/\\/\\\\\\\__________________\/\\\_____\/\\\_________/\\\\\\\\\\\____
    ___\//\\\__/\\\______/\\\/////\\\_\/\\\/////\\\_________________\/\\\_____\/\\\________/\\\\///////\\\__
     ____\//\\\/\\\______/\\\\\\\\\\\__\/\\\___\///__________________\/\\\_____\/\\\_______\/\\\______\//\\\_
      _____\//\\\\\______\//\\///////___\/\\\_________________________\//\\\____/\\\________\//\\\______/\\\__
       ______\//\\\________\//\\\\\\\\\\_\/\\\__________/\\\____________\///\\\\\\\/____/\\\__\///\\\\\\\\\/___
        _______\///__________\//////////__\///__________\///_______________\///////_____\///_____\/////////_____

NAME: Veronica(?)
VER 0.6 - convolutional forward propagation
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

patch 0.6 4-19-2020:
fixed many bugs with convolve.
complete forward propagation of the convolutional layers
checked operations

*/


#include "panel.h"    //constants
#include "source.h"  
#include "matrix3d.h"
#include "matrix2d.h"
#include "neuron.h"




// img -> make many reuslts (for each): zero pad? conv? active:



int main()
{
  srand(time(0));//seed


  //make input img

  Matrix input_img(INITIAL_H, INITIAL_W);

  //load the img here!
  //for now: fill with random
  input_img.randomize();

  cout << input_img << endl;

  Matrix copy = input_img;
  copy.apply_zero_pad();
  cout << copy << endl;

  //make filter set

  vector<vector<Matrix3d>> filter_list;
  filter_list.resize(NUM_N_LAYERS + 1);
  filter_list = make_filter_set(filter_list);


  //print filters
  
  print_filters(filter_list);

  //filterlist made
  

  

  //initilaize a layer list
  vector<vector<Matrix>> layer_list;
  layer_list.resize(NUM_N_LAYERS+1);
  for (short i = 0; i < NUM_N_LAYERS + 1; i++)
  {
    if (i == 0)
    {
      layer_list[0].resize(NUM_IMG_LAYER_1);
    }
    else
    {
      layer_list[i].resize(NUM_IMG_LAYER_N);
    }
  }

  //fill with random

  for (short i = 0; i < NUM_N_LAYERS + 1; i++)
  {
    if (i == 0)
    {
      for (short j = 0; j < NUM_IMG_LAYER_1; j++)
      {
        //do something to all matrix

        layer_list[i][j].set_height((ZERO_PAD) ? INITIAL_H : (INITIAL_H - FILTER_SIZE_1) + 1);
        layer_list[i][j].set_width((ZERO_PAD) ? INITIAL_W : (INITIAL_W - FILTER_SIZE_1) + 1);
        //layer_list[i][j].randomize();
      }
    }
    else
    {
      for (short j = 0; j < NUM_IMG_LAYER_N; j++)
      {

        short temp = INITIAL_H;
        short temp2 = INITIAL_W;
        for (short k = 0; k < i+1; k++)
        {
          temp = (temp - FILTER_SIZE_N) + 1;
          temp2 = (temp2 - FILTER_SIZE_N) + 1;
        }

        
        layer_list[i][j].set_height((ZERO_PAD) ? INITIAL_H : temp);
        layer_list[i][j].set_width((ZERO_PAD) ? INITIAL_H : temp2);
        //layer_list[i][j].randomize();
        
      }
    }
  }


  //print_layers(layer_list);


  







  

  //skip

  



  
  //layer 1
  for (short result = 0; result < NUM_IMG_LAYER_1; result++)
  {
    Matrix copy = input_img;
    copy.apply_zero_pad();

    Matrix img_list[] = { copy };

    //3d convolve 

    cout << img_list[0] << endl;
    copy = convolve(img_list, 1, filter_list[0][result]);



    copy.apply_active();

    layer_list[0][result] = copy;

  } 


  for (short layer = 1; layer < NUM_N_LAYERS+1; layer++)
  {
    vector<Matrix> prior_layer = layer_list[layer - 1];

    for (short i = 0; i < ((layer == 1) ? NUM_IMG_LAYER_1 : NUM_IMG_LAYER_N); i++)
    {
      prior_layer[i].apply_zero_pad();
    }
    for (short img_num = 0; img_num < NUM_IMG_LAYER_N; img_num++)
    {
      Matrix poop = layer_list[layer][img_num];
      poop = convolve(prior_layer, ((layer == 1) ? NUM_IMG_LAYER_1 : NUM_IMG_LAYER_N), filter_list[layer][img_num]);
      poop.apply_active();
      layer_list[layer][img_num] = poop;
      
      //convolve
      //activate
      //add to layer list
    }

  }


















  print_layers(layer_list);

  return 0;

  /*
  //layer2


  for (short layer = 1; layer < NUM_N_LAYERS; layer++)
  {
    vector<Matrix> prior_img_list = layer_list[layer - 1];

    //aply zero pad here


    //for each filter in layer
    for (short img_num = 0; img_num < NUM_IMG_LAYER_N; img_num++)
    {
      Matrix temp = convolve(prior_img_list, ((layer == 1) ? NUM_IMG_LAYER_1 : NUM_IMG_LAYER_N), filter_list[layer][img_num]);

      temp.apply_active();

      layer_list[layer][img_num] = temp;

    }


  }

  */


  //-----------------------------------------print layer list


  

  













  
  /*

  for (short layer = 1; layer < NUM_N_LAYERS+1; layer++)
  {
    cout << "asshole" << endl;
    vector<Matrix> img_list = layer_list[layer - 1];
    cout << "whore" << endl;

    for (short i = 0; i < ((layer == 1) ? NUM_IMG_LAYER_1 : NUM_IMG_LAYER_N); i++)
    {
      cout << "slut" << endl;
      if (layer == 1)
      {
        img_list[i].apply_zero_pad();
      }
      else
      {
        img_list[2].apply_zero_pad();
      }
      cout << "slut2" << endl;
      
    }
    cout << "shit " << endl;
    for (short result = 0; result < ((layer == 1) ? NUM_IMG_LAYER_1 : NUM_IMG_LAYER_N); result++)
    {
      cout << "cum" << endl;
      Matrix temp = convolve(img_list, ((layer == 1) ? NUM_IMG_LAYER_1 : NUM_IMG_LAYER_N), filter_list[layer][result]);
      cout << "piss " << endl;
      temp.apply_active();

      layer_list[layer][result] = temp;

    }
  }
  

  cout << "god save us please =====================" << endl;


  
  
  for (short i = 0; i < NUM_N_LAYERS + 1; i++)
  {
    if (i == 0)
    {
      cout << "IMG LAYER 1" << endl;
      for (short j = 0; j < NUM_IMG_LAYER_1; j++)
      {
        cout << "\timg " << j << endl;
        cout << layer_list[i][j] << endl;
      }
      cout << endl;
      
    }
    else
    {
      cout << "IMG LAYER " << i+1 << endl;
      for (short j = 0; j < NUM_IMG_LAYER_N; j++)
      {
        cout << "\timg " << j << endl;
        cout << layer_list[i][j] << endl;
      }
      cout << endl;
    }
  }

  */




  return 1;

  















  /*


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

  */

}


