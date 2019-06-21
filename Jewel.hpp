#include <iostream>

class Jewel
{
private:
  int type;
  int x;
  int y;
public:
  Jewel(int _type, int _x, int _y);
  int getType();
  int getX();
  int getY();
};
