#include <iostream>
#include <cstdlib>

#include "Jewel.hpp"

class Grille
{
private:
  int width;
  int height;
  Jewel** grille;
public:
  Grille(int _width, int _height);
  Jewel* getJewel(int x, int y);
  int checkReverse(Jewel& jewel1, Jewel& jewel2);
  void reverse(int x, int y, int direction);
  void reverseHor(Jewel& jewel1, Jewel& jewel2);
  void reverseVer(Jewel& jewel1, Jewel& jewel2);
  void removeHor(Jewel& jewel1, Jewel& jewel2, Jewel& jewel3);
  void removeVer(Jewel& jewel1, Jewel& jewel2, Jewel& jewel3);
  void fall(int y1, int y2);
};
