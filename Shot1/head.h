#ifndef HEAD_H
#define HEAD_H

#endif // HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <io.h>
#include <conio.h>
#include <sstream>
#include <SFML/Graphics.hpp> // підключення SFML
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#define N 6
#define M 4

using namespace sf;
using namespace std;


void Memori( long *lSize, char **buffer);
int DownloadBuffer ( long *lSize, char **buffer);
void Memori2( long *lSize, char **buffer);
int DownloadBuffer2 ( long *lSize, char **buffer);
int Type (int keeper, char *masRes, char *buffer);

class Draw
{
    public:
    Image my_image;
    Texture my_texture;
    Sprite my_sprite;
    Font font;

};


