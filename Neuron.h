#ifndef NEURON_H
#define NEURON_H

#include "panel.h"    //constants
#include "source.h"

class Neuron
{
public:
  Neuron();
  void initialize(const Neuron neurons[], const short size);
  void update_value(const Neuron neurons[], const short size);
  void set_value(const float new_value);
  float get_value()const;
  void set_weight_set(const weight_set new_weight, const short size);
  weight_set get_weight_set() const;

private:
  float m_value;
  weight_set m_weights;

};

#endif