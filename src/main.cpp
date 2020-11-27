#include <iostream>
#include <algorithm>
using namespace std;
#include<unistd.h>
#include <math.h>
unsigned int microsecond = 1000000;

// 1.Any live cell with fewer than two live neighbours dies, as if caused by under-population.

// 2.Any live cell with two or three live neighbours lives on to the next generation.

// 3.Any live cell with more than three live neighbours dies, as if by over-population.

// 4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

const int x = 30, y = 30;

string grid[x][y]= {};

bool inBounds(int xcoo, int ycoo){
	// just checks if inside grid
	return (( xcoo >= 0 && xcoo < x) && (ycoo >= 0 && ycoo < y));
}
int checkCell(int x, int y){
	//checks neighboring cells
int live_cell_count = 0;
	for (int i = -1; i <= 1; i++)
	{
   	 for (int j = -1; j <= 1; j++)
    	{
        	if (!(i == 0 && j == 0) &&
			 inBounds(x+i,y+j) &&
			  grid[x+i][y+j] ==  "\u25A0")
              	live_cell_count++;
    	}
	}
	return live_cell_count;
}
bool isAlive(int x, int y){
	//self explainatory
	if (grid[x][y] ==  "\u25A0") {
		return true;
	}
	return false;
}
void killCell(int x, int y){
	//self explainatory
	if (isAlive(x,y)) {
		grid[x][y] = "_";
	}
}
void resCell(int x, int y) {
	// resurrects cell if dead.
	if (isAlive(x,y) == false){
		grid[x][y] =  "\u25A0";
	}
}
void initialiseGrid() {
  int counter = 0;
	//starts the grid
  srand(time(0));
  int rangex = rand() % 10;
  int rangey= rand() % 10;
	for (int i = 0; i<x ; i++) {
		for (int j = 0 ; j < y ; j++) {
			grid[i][j] = "_";
		}
	}

  for (int i = 0 ; i < x ; i++){
    for (int j = 0; j < y; j++){
      int randox = rand() % 10;
      int randoy = rand() %10;
      if(inBounds(randox, randoy))
      grid[randox][randoy] = "\u25A0";
    }
  }
	// starting the starting pattern by myself
	// instead of user input cuz im a lazy bloke
	
	// grid[1][1] =  "\u25A0";
	// grid[1][2] =  "\u25A0";
	// grid[1][3] =  "\u25A0";
	// grid[1][5] =  "\u25A0";
	// grid[2][1] =  "\u25A0";
	// grid[3][4] =  "\u25A0";
	// grid[3][5] =  "\u25A0";
	// grid[4][2] =  "\u25A0";
	// grid[4][3] =  "\u25A0";
	// grid[4][5] =  "\u25A0";
	// grid[5][1] =  "\u25A0";
	// grid[5][3] =  "\u25A0";
	// grid[5][5] =  "\u25A0";
}

void printGrid(){
	// prints the grid
	for (int i = 0; i<x ; i++) {
		cout << endl;
		for (int j = 0 ; j < y ; j++) {
			cout << grid[i][j] << " ";
			if (checkCell(i,j) < 2 || checkCell(i,j) > 3)
				killCell(i,j);
			if (checkCell (i,j) == 3)
				resCell(i,j);
		}
	}
	cout << endl << endl;
}


int main()
{
	initialiseGrid();
	printGrid();

	cout << " 1.Any live cell with fewer than two live neighbours dies, as if caused by under-population. \n\n 2.Any live cell with two or three live neighbours lives on to the next generation.\n\n 3.Any live cell with more than three live neighbours dies, as if by over-population.\n\n 4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction. \n\n";
	while (true) {
		
		printGrid();
		usleep(microsecond/5); //sleeps for 3 second
	}

}