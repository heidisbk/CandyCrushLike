#include <iostream>
#include <cstdlib>

#include "sdlwrapper/libgraphique.hpp"
#include "Grille.hpp"

using std::cout;
using std::endl;
using std::abs;

/*int initialisation()
  {
  
  }*/

int main()
{
  const int WIDTH = 640;
  const int HEIGHT = 480;

  SDLManager manager(WIDTH, HEIGHT);

  //Grille grille();

  SDL_Texture* diamant = IMG_LoadTexture(manager.getRenderer(), "img/ametist.PNG");
  SDL_Texture* saphir = IMG_LoadTexture(manager.getRenderer(), "img/safir.PNG");
  SDL_Texture* emeraude = IMG_LoadTexture(manager.getRenderer(), "img/emerald.PNG");
  SDL_Texture* rubis = IMG_LoadTexture(manager.getRenderer(), "img/rubin.PNG");
  SDL_Texture* coin = IMG_LoadTexture(manager.getRenderer(), "img/coin.PNG");
  
  SDL_Texture* textures[] = {diamant, saphir, emeraude, rubis, coin};

  int width = 5;
  int height = 5;
  Grille grille(width, height);

  int widthCase = 70;
  int heightCase = 70;
  
  int xStart;
  int yStart;
  int xEnd;
  int yEnd;
  int dX;
  int dY;

  while(manager.isRunning())
    {
      for (int i=0; i<height; i++)
	{
	  for (int j=0; j<width; j++)
	    {
	      //gestion de x&y en fonction de i&j
	      SDL_Rect rectangle;
	      rectangle.x = 70*j+130;
	      rectangle.y = 70*i+70;
	      rectangle.w = widthCase;
	      rectangle.h = heightCase;
	      switch (grille.getJewel(i, j)->getType())
		{
		case 0:
		  SDL_RenderCopy(manager.getRenderer(), diamant, NULL, &rectangle);
		  break;
		case 1:
		  SDL_RenderCopy(manager.getRenderer(), saphir, NULL, &rectangle);
		  break;
		case 2:
		  SDL_RenderCopy(manager.getRenderer(), emeraude, NULL, &rectangle);
		  break;
		case 3:
		  SDL_RenderCopy(manager.getRenderer(), rubis, NULL, &rectangle);
		  break;
		case 4:
		  SDL_RenderCopy(manager.getRenderer(), coin, NULL, &rectangle);
		  break;
		}
	    }
	  SDL_Event e;
	  while (SDL_PollEvent(&e))
	    {
	      if (e.type == SDL_QUIT)
		{
		  manager.stop();
		  return 0;
		}
	  
	      if (e.type == SDL_MOUSEBUTTONDOWN)
		{
		  if (e.button.button == SDL_BUTTON_LEFT)
		    {
		      xStart = e.button.x;
		      yStart = e.button.y;
		      cout << "xStart = " << xStart << endl;
		      cout << "yStart = " << yStart << endl;
		    }
		}
	      if (e.type == SDL_MOUSEMOTION)
		{
		}
	      if (e.type == SDL_MOUSEBUTTONUP)
		{
		  if (e.button.button == SDL_BUTTON_LEFT)
		    {
		      xEnd = e.button.x;
		      yEnd = e.button.y;
		      cout << "xEnd = " << xEnd << endl;
		      cout << "yEnd = " << yEnd << endl;
		      dX = xEnd - xStart;
		      dY = yEnd - yStart;
		      cout << "dX = " << dX << endl;
		      cout << "dY = " << dY << endl;
		      if (abs(xEnd - xStart) < abs(yEnd - yStart))
			{
			  if (dY < 0)
			    {
			      int direction = 0;
			      //Jewel jewel2 = y-1;
			      //direction = haut
			      //rectangle.y -= 70;
			    }
			  else
			    {
			      int direction = 1;
			      //Jewel jewel2 = y+1;
			      //direction = bas
			      //rectangle.y += 70;
			    }
			}
		      else
			{
			  if (dX < 0)
			    {
			      int direction = 2;
			      //Jewel jewel2 = x-1;
			      //direction = gauche
			      //rectangle.x -= 70;
			    }
			  else
			    {
			      int direction = 3;
			      //Jewel jewel2 = x+1;
			      //direction = droite
			      //rectangle.x += 70;
			    }
			}
		    }
		}
	      SDL_RenderPresent(manager.getRenderer());
	      manager.sleep(10);
	    }
	}
    }
}
