#include "head.h"
#include "menu.h"

int main()   //RenderWindow& window
{
    setlocale(LC_ALL, "Rus");
    RenderWindow window(VideoMode(1000, 588), "Test");
    menu(window);
    Draw painter;
    painter.my_image.loadFromFile ("E:/IT/Kontrol/Probnik/Images/1010.png");
    painter.my_texture.loadFromImage (painter.my_image);
    painter.my_sprite.setTexture (painter.my_texture);
    painter.my_sprite.setPosition (0,0);
    painter.font.loadFromFile("Images/arial.ttf");
    long lSize, lSize2;
    char *buffer, *buffer2;
    int keeper=0, answer[N][M]= { {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4} };

        Memori(&lSize, &buffer);
        DownloadBuffer(&lSize, &buffer);
    char mas[lSize]; char*pmas=mas;
        Memori2( &lSize2, &buffer2);
        DownloadBuffer2( &lSize2, &buffer2);
    char  masRes[lSize2];

    Text text ;
    text.setFont(painter.font);
    text.setCharacterSize(18);
    text.setColor(Color::White);
    text.setOutlineColor(Color::Black);
    text.setPosition(150, 100);

    Text text2 ;
    text2.setFont(painter.font);
    text2.setCharacterSize(14);
    text2.setColor(Color::White);
    text2.setOutlineColor(Color::Black);
    text2.setPosition(150, 460);

    bool wait = false;
    int j = 0;

    while (window.isOpen())
    {
        if(!wait)
        {
            if(j < 6)
            {
                for(int i=0;i<lSize; i++)  //обнулення масиву
                  *(pmas+i)=0;

                int y=0;

                while(*buffer != '#')
                {
                   *(pmas+y)=*buffer++;
                     y++;
                }

                text.setString (mas);
                window.clear(); // очищаємо екран
                window.draw(painter.my_sprite); // малюємо спрайт
                window.draw(text); // малюємо text
                buffer++;
            }
            else
            {
                Type (keeper, masRes, buffer2);

                text.setString (masRes);
                window.clear(); // очищаємо екран
                window.draw(painter.my_sprite); // малюємо спрайт
                window.draw(text); // малюємо text

            }
            window.display(); // показуємо результат користувачу
            wait = true;
            j++;
        }
        //----------------------------------------------------------//
        Event event;
        while (window.pollEvent(event))
        {
           if((event.type == Event::KeyPressed))
           {
               switch(event.key.code)
               {
               case Keyboard::A: keeper += answer[j-1][0]; wait = false; break;
               case Keyboard::B: keeper += answer[j-1][1]; wait = false; break;
               case Keyboard::C: keeper += answer[j-1][2]; wait = false; break;
               case Keyboard::D: keeper += answer[j-1][3]; wait = false; break;
               }
           }

           else if (event.type == Event::Closed||(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))  //закриття по Ескейпу
              {
               window.close();
               exit(0);
              }
        }
    }

    return 0;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------

void Memori(long *lSize, char **buffer) // виділяємо память  під масив
{
      FILE *fpointer;
      fpointer = fopen("TestForProgrammer.txt", "r" );  //відкриваєм файл на читання
      // определяем размер файла

      fseek(fpointer , 0 , SEEK_END);                          // устанавливаем позицию в конец файла
      *lSize = ftell(fpointer);                           // получаем размер в байтах
      rewind (fpointer);                                      // устанавливаем указатель в конец файла
      fclose (fpointer);
      *buffer = (char*) calloc( *lSize, sizeof(char)); // выделить память для хранения содержимого файла
        if (*buffer == NULL)
        {
            puts("ERROR 1");
           // return 0;
        }
}


int DownloadBuffer(long *lSize, char **buffer) //считываем файл в буфер
{
    FILE *fpointer;
    fpointer = fopen("TestForProgrammer.txt", "r" );  //відкриваєм файл на читання
       if(fpointer == NULL) //перевіряємо чи файли відкриваються
       {
           puts("ERROR 2");
           return 0;
       }
       else
       {
           fread(*buffer, 1, *lSize, fpointer);      // считываем файл в буфер
           fclose(fpointer);
       }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

void Memori2(long *lSize, char **buffer) // виділяємо память  під масив
{
      FILE *fpointer;
      fpointer = fopen("Answers.txt", "r" );  //відкриваєм файл на читання
      // определяем размер файла
      fseek(fpointer , 0 , SEEK_END);                          // устанавливаем позицию в конец файла
      *lSize = ftell(fpointer);                            // получаем размер в байтах
      rewind (fpointer);                                       // устанавливаем указатель в конец файла
      fclose (fpointer);
      *buffer = (char*) calloc( *lSize, sizeof(char)); // выделить память для хранения содержимого файла
        if (*buffer == NULL)
        {
            puts("ERROR 3");
            //return 0;
        }
}


int DownloadBuffer2(long *lSize, char **buffer) //считываем файл в буфер
{
    FILE *fpointer;
    fpointer = fopen("Answers.txt", "r" );  //відкриваєм файл на читання
       if(fpointer == NULL) //перевіряємо чи файли відкриваються
       {
           puts("ERROR 4");
           return 0;
       }
       else
       {

           fread(*buffer, 1, *lSize, fpointer);      // считываем файл в буфер
           fclose(fpointer);
       }
}


int Type (int keeper,  char *masRes,  char *buffer)  //визначаємо результат тестування
{
      if( keeper>=6 && keeper<10)
      {
            int y=0;
            while(*buffer != '#')
            {
                masRes[y]=*buffer++;
                y++;
            }
            masRes[y]='\0';
      }
      if( keeper>=10 && keeper<15 )
      {
          for(int j=0; j<2; j++)
              {
                int y=0;
                while(*buffer != '#')
                    {
                        masRes[y]=*buffer++;
                        y++;
                    }
                buffer++;
                masRes[y]='\0';
              }
      }

      if( keeper>=15 && keeper<20 )
      {
          for(int j=0; j<3; j++)
              {
                int y=0;
                while(*buffer != '#')
                    {
                        masRes[y]=*buffer++;
                        y++;
                    }
                buffer++;
                masRes[y]='\0';
              }
      }
      if( keeper>=20 &&  keeper<=24 )
      {
          for(int j=0; j<4; j++)
              {
              int y=0;
                while(*buffer != '#')
                    {
                        masRes[y]=*buffer++;
                        y++;
                    }
                buffer++;
                 masRes[y]='\0';
              }
       }
  }
