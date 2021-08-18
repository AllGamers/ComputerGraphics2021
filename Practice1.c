#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
void plot_line(int,int,int,int);

int main( )
{
  int x1,y1,x2,y2,x,y,dx,dy,step;
  printf("Enter the value of x1 and y1:");
  scanf("%i%i",&x1,&y1);
  printf("Enter the value of x2 and y2:");
  scanf("%i%i",&x2,&y2);
  plot_line(x1,y1,x2,y2);
  return 0;
}

void plot_line (int x1, int y1, int x2, int y2)
{
  int dx =  abs (x2 - x1), sx = x1 < x2 ? 1 : -1;
  int dy = -abs (y2 - y1), sy = y1 < y2 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
  printf("%i - %i\n",x1,y1);
  for (;;){  /* loop */
    if (x1 == x2 && y1 == y2) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
    printf("%i - %i\n",x1,y1);
  }
}