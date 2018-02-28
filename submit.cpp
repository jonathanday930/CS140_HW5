/**
 * Assignment 5: Life in Cilk
 * Team Member 1 Name:
 * Team Member 2 Name: 
 *
 */

#include "life.h"
#include <time.h>
#include <cilk.h>
//Generate the life matrix any way you want. We would highly recommend that you print the generated
//matrix into a file, so that you can share it with other teams for checking correctness.

static int COARSENESS = 1000;
static const int OCCUPIED_VALUE = 10;
void genlife(int *a, unsigned int n)
{





}

//Read the life matrix from a file
void readlife(int *a, unsigned int n, char *filename)
{
}

//Life function
void life(int *a, unsigned int n, unsigned int iter, int *livecount)
{
    int * a;
    neighbors = (int *)malloc(sizeof(int)*(n*n));
    int nSquaredDivCoarseness = n*n/COARSENESS;

    cilk_for (int count = 0; count < nSquaredDivCoarseness; ++count){
        for(int count2 = 0; count2 < COARSENESS; ++count2) {
            neighbors[count*n + count2] = 0;
        }
        }



    cilk_for(int count= 0; count < n*n/COARSENESS; ++count){



    }



    // You need to store the total number of livecounts for every 1/0th of the total iterations into the livecount array.
	// For example, if there are 50 iterations in your code, you need to store the livecount for iteration number 5 10 15
	// 20 ... 50. The countlive function is defined in life.cpp, which you can use. Note that you can
	// do the debugging only if the number of iterations is a multiple of 10.
	// Furthermore, you will need to wrap your counting code inside the wrapper #if DEBUG == 1 .. #endif to remove
	// it during performance evaluation.
	// For example, your code in this function could look like -
	//
	//
	//	for(each iteration)
	//      {
	//
	//		Calculate_next_life();
	//
	//		#if DEBUG == 1
	//		  if_current_iteration == debug_iteration
	//		  total_lives = countlive();
	//		  Store_into_livecount(total_lives);
	//		#ENDIF
	//
	//	}
}



void updateNeighborsAlive(int *neighbors, int x, int y, int n){

    // Diagonal cases
    addToCell(neighbors,x+1,y+1,n,1);
    addToCell(neighbors,x+1,y-1,n,1);
    addToCell(neighbors,x-1,y+1,n,1);
    addToCell(neighbors,x-1,y+1,n,1);

    // Middle spots
    addToCell(neighbors,x+1,y,n,1);
    addToCell(neighbors,x,y+1,n,1);
    addToCell(neighbors,x-1,y,n,1);
    addToCell(neighbors,x,y-1,n,1);

    // Update x, y cuz is occupied
    addToCell(neighbors,x,y,n,OCCUPIED_VALUE);

}



void setCell(int *a, int x, int y, int n, int val){
    int * ptr = getCellPtr(a,x,y,n);
    *ptr = val;
}


void addToCell(int *a, int x, int y, int n, int val){
    int * ptr = getCellPtr(a,x,y,n);
    *ptr = *ptr + val;
}



int* getCellPtr(int *a,int x, int y, int n){
    if(x < 0){
        x = n-1;
    }
    else if( x >= n){
        x = 0;
    }

    if(y < 0){
        y = n-1;
    }
    else if (y >= n){
        y = 0;
    }

    int * ptr;
    ptr = a[x*n + y];


    return a;

}