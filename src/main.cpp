#include <iostream>
#include <algorithm>
using namespace std;
#include<unistd.h>
unsigned int microsecond = 1000000;

// 1.Any live cell with fewer than two live neighbours dies, as if caused by under-population.

// 2.Any live cell with two or three live neighbours lives on to the next generation.

// 3.Any live cell with more than three live neighbours dies, as if by over-population.

// 4.Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

const int x = 10, y = 10;

string grid[x][y]= {};

bool inBounds(int x, int y){
	// just checks if inside grid
	return (( x >= 0 && x < 10) && (y >= 0 && y < 8));
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
			  grid[x+i][y+j] == ".")
              	live_cell_count++;
    	}
	}
	return live_cell_count;
}
bool isAlive(int x, int y){
	//self explainatory
	if (grid[x][y] == ".") {
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
		grid[x][y] = ".";
	}
}
void initialiseGrid() {
	//starts the grid
	for (int i = 0; i<x ; i++) {
		for (int j = 0 ; j < y ; j++) {
			grid[i][j] = "_";
		}
	}

	// starting the starting pattern by myself
	// instead of user input cuz im a lazy bloke
	
	grid[1][1] = ".";
	grid[1][2] = ".";
	grid[1][3] = ".";
	grid[1][5] = ".";
	grid[2][1] = ".";
	grid[3][4] = ".";
	grid[3][5] = ".";
	grid[4][2] = ".";
	grid[4][3] = ".";
	grid[4][5] = ".";
	grid[5][1] = ".";
	grid[5][3] = ".";
	grid[5][5] = ".";
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
	initialiseGrid();

	while (true) {
		printGrid();
		usleep(microsecond/10); //sleeps for 3 second
	}
}