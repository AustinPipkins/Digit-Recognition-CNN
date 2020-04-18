
#include "panel.h"    //constants
#include "neuron.h"
#include "source.h"

Neuron::Neuron()
{
  m_value = 0;
  m_weights.m_length = 0;

}

void Neuron::initialize(const Neuron neurons[], const short size)
{
  m_weights.m_length = size;
  vector<float> new_weights;
  new_weights.resize(size);

  for (short i = 0; i < size; i++)
  {
    new_weights[i] = random_number(MIN_WEIGHT, MAX_WEIGHT, WEIGHT_PRE);
  }
  m_weights.m_weight_set.resize(size);
  m_weights.m_weight_set = new_weights;
  return;
}

void Neuron::update_value(const Neuron neurons[], const short size)
{
  float temp = 0;
  for (short i = 0; i < size; i++)
  {
    temp += neurons[i].get_value() * m_weights.m_weight_set[i];
  }
  m_value = temp;
  return;
}

void Neuron::set_value(const float new_value)
{
  m_value = new_value;
  return;
}

float Neuron::get_value()const
{
  return m_value;
}

void Neuron::set_weight_set(const weight_set new_weights, const short size)
{
  m_weights.m_weight_set.resize(size);

  m_weights = new_weights;
  return;
}

weight_set Neuron::get_weight_set() const
{
  return m_weights;

}
