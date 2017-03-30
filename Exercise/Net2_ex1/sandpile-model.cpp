#include <iostream>
#include <stdlib.h>
#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;
int main(int argc, char *argv[])
{
  int sandpile[10][10];
  // int data[]
  int i,j,k,sand,time,s,x,y;
  
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      sandpile[i][j] = 0;
    }
  }

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      cout << sandpile[i][j];
    }
  }

  for (k = 0; k < 100; k++) {
    int sandpile_x,sandpile_y;
    sandpile_x = random(0,9); // [a,b] rand()%(b-a+1)+a；
    sandpile_y = random(0,9);
    sandpile[sandpile_x][sandpile_y]++;

    
    for (x = 0; x < 10; x++) {
      for (y = 0; y < 10; y++) {
	time = 0;
	if (sandpile[x][y] > 3) {
	  sandpile[x][y] -= 4;
	  sandpile[x][y+1] += 1;
	  sandpile[x][y-1] += 1;
	  sandpile[x-1][y] += 1;
	  sandpile[x+1][y] += 1;
	  time++;
	  }
	}
      }
  }

// }

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      cout << sandpile[i][j];
      cout << "T" << time;
    }

  }

  
  return 0;
}

