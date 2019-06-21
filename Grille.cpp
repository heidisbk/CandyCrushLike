#include <iostream>
#include <cstdlib>

#include "Grille.hpp"

using std::cout;
using std::endl;
using std::string;

Grille::Grille(int _width, int _height)
{
  //int width(4);
  //int height(4);
  this->width = _width;
  this->height = _height;
  this->grille = new Jewel*[_width * _height];
  
  int indice = 0;
  srand((unsigned int)time(0));
  
  for (int i=0; i<height; i++)
    {
      for (int j=0; j<width; j++, indice++)
	{
	  grille[indice] = new Jewel(rand()%5, j, i);
	  cout << indice << endl;
     	}
    }
};

Jewel* Grille::getJewel(int x, int y)
{
  //y*width+x
  return this->grille[y * width + x];
}

int Grille::checkReverse(Jewel& jewel1, Jewel& jewel2)
{
  int indice = 0;
  for (int i=0; i<height; i++)
    {
      for (int j=0; j<width; j++, indice++)
	{
	  if (jewel1.getX() == 0)
	    {
	      if (jewel2.getX() != 1)
		{
		  return 0;
		}
	    }
	  if (jewel1.getX() == height-1)
	    {
	      if (jewel2.getX() != height-2)
		{
		  return 0;
		}
	    }
	  if (jewel1.getY() == 0)
	    {
	      if (jewel2.getY() != 1)
		{
		  return 0;
		}
	    }
	  if (jewel1.getY() == width-1)
	    {
	      if (jewel2.getY() != width-2)
		{
		  return 0;
		}
	    }
	  if (jewel1.getX() != jewel2.getX()+1 || jewel1.getX() != jewel2.getX()-1)
	    {
	      return 0;
	    }
	  if (jewel1.getY() != jewel2.getY()+1 || jewel1.getY() != jewel2.getY()-1)
	    {
	      return 0;
	    }
	  else
	    {
	      return 1;
	    }
	}
    }
}

void Grille::reverse(int x, int y, int direction)
{
  //checkReverse(Jewel jewel1, Jewel jewel2);
  for (int i=0; i<height; i++)
    {
      for (int j=0; i<width; j++)
	{
	  x = j%70;
	  y = i%70;
	}
    }
}

void Grille::reverseHor(Jewel& jewel1, Jewel& jewel2)
{
  int indice = 0;
  for (int i=0; i<height; i++)
    {
      for (int j=0; j<width; j++)
	{
      //if ( jewel.type
	}
    }
  /*if (this->width == width+1 || this->width == width-1)
    {
      int oldWidth = this->width;
      this->width = width;
      width = oldWidth;
      }*/
}

void Grille::reverseVer(Jewel& jewel1, Jewel& jewel2)
{
  if (height == height+1 || height == height-1)
    {
      int oldHeight = this->height;
      this->height = height;
      height = oldHeight;
    }
}

void Grille::removeHor(Jewel& jewel1, Jewel& jewel2, Jewel& jewel3)
{
  for (int i=0; i<8; i++)
    {
      if (jewel1.getX() == jewel2.getX()+1 || jewel1.getX() == jewel2.getX()-1)
	{
	  if (jewel2.getX() == jewel3.getX()+1 || jewel2.getX() == jewel3.getX()-1)
	    {
	      cout << "salut" << endl;
	    }
	}
    }
}

void Grille::removeVer(Jewel& jewel1, Jewel& jewel2, Jewel& jewel3)
{
  for (int i=0; i<8; i++)
    {
      if (jewel1.getY() == jewel2.getY()+4 || jewel1.getY() == jewel2.getY()-4)
	{
	  if (jewel2.getY() == jewel3.getY()+4 || jewel2.getY() == jewel3.getY()-4)
	    {
	      cout << "salut" << endl;
	    }
	}
    }
}
