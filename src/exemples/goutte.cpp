/* 
 * AP1 PUF Vietnam
 * Exemple de programme d'affichage dans le terminal 
 */
#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <termios.h>
#include <unistd.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

#define N 20
#define NBRE_GOUTTE 2

bool touche_appuyee();
int code_touche();

char screen[N][N];

void paysage();
void affiche_screen();

typedef struct {
  double x;
  double y;
  double dx;
  double dy;
} Sprite;

void init_sprite(Sprite & s, double x, double y, double dx, double dy);
void mise_a_jour_sprite(Sprite & s);

int main () {
  Sprite goutte[NBRE_GOUTTE];
  init_sprite(goutte[0], 4, 5, 0.0, 0.3);
  init_sprite(goutte[1], 6, 8, 0, 0);

  while(1)
  {
    int c = code_touche();
    switch (c) {
    case 'a':
      goutte[0].dx = 0.3;
      break;
    case 'b':
      goutte[0].dx = -0.3;
      break;
    case 'q':
    case 'Q':
      exit(0);
    }

    paysage();
    for (int g=0; g<NBRE_GOUTTE; g++)
      screen[(int) goutte[g].x][(int) goutte[g].y] = 'O';
    for (int g=0; g<NBRE_GOUTTE; g++)
      mise_a_jour_sprite(goutte[g]);

    usleep(40 * 1000);
    affiche_screen();
  }
}


void init_sprite(Sprite & s,
                 double x, 
                 double y, 
                 double dx, 
                 double dy) {
  s.x = x;
  s.y = y;
  s.dx = dx;
  s.dy = dy;
}

void mise_a_jour_sprite(Sprite & s) {
  s.x += s.dx;
  s.y += s.dy;
  
  if (s.x < 0) s.x = N-1;
  if (s.x > N-1) s.x = 0;
  if (s.y < 0) s.y = N-1;
  if (s.y > N-1) s.y = 0;
}

void paysage() {
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      if (i==0 || i==N-1 || j==0 || j==N-1)
        screen[i][j] = '#';
      else
        screen[i][j] = ' ';
}

void affiche_screen() {
  system("clear");
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++)
      cout << screen[i][j];
    cout << endl;
  }
}


/* ce qui suit concerne l'usage des touches du clavier 
 * connaitre ce mécanisme est optionnel. */

int code_touche() {
  int result = -1;
  system ("stty raw");
  if (touche_appuyee())
    result = (int) getchar();
  system ("stty cooked");
  return result;
}

bool touche_appuyee()  
{
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return (FD_ISSET(0, &fds));
}
