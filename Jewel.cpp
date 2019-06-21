#include <iostream>

#include "Jewel.hpp"

using std::cout;
using std::endl;

Jewel::Jewel(int _type, int _x, int _y)
{
  this->type = _type;
  this->x = _x;
  this->y = _y;
}

int Jewel::getType()
{
  return type;
}

int Jewel::getX()
{
  return x;
}

int Jewel::getY()
{
  return y;
}
