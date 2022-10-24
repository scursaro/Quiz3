#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//We will have to create a 2d grid 
int grid[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};


//We will have to make an array with the values
int numbers[9] = {1,2,3,4,5,6,7,8,9};

//There should be a function that checks if the array is Magic
int isBoardMagic(int arr[3][3]) {
    int magic = 1;
    // iterate through columns
    for(int i = 0; i < 3; i++) {
        int isum = 0;
        for (int j = 0; j < 3; j++) {
            isum += arr[i][j];
        }
        if(isum != 15) magic = 0;
    }
    // iterate through rows
    for(int j = 0; j < 3; j++) {
        int jsum = 0;
        for (int i = 0; i < 3; i++) {
            jsum += arr[i][j];
        }
        if(jsum != 15) magic = 0;
    }
    // iterate through diagonals
    if(arr[0][0] + arr[1][1] + arr[2][2] != 15) magic = 0;
    if(arr[2][0] + arr[1][1] + arr[0][2] != 15) magic = 0;
    //return
    return magic;
}

//There should be a function that prints the array
void printBoard(int arr[3][3])
{
    int i, j;
    printf("\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if(j == 0) printf("[ ");
            printf("%d ", arr[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

//Function that randomizes the board
void mix() {

    for(int i = 8; i > 0; i--) {
      int r = (rand() % (i + 1));
      //swap
      int temp = numbers[i];
      numbers[i] = numbers[r];
      numbers[r] = temp;
    }
}

//Function that sets the array/grid
void createBoard() {

    mix();
    int n = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            grid[i][j] = numbers[n];
            n++;
        }
    }

}

//main method that checks if the grid works, and increments tries by one each time it needs to shuffle
int main(void)
{
    srand(time(0));

    int loshuBoard[][3] =
    { //arbitrary numbers
            {4,3,8},
            {9,5,1},
            {2,7,6}
    };

    int found =0;
    int count =0;

    while(!found)
    {
        createBoard(); //creates random board
        count++;

        if(count > 0)
            printf("Attempt %d\n",count);
        if(count > INT_MAX - 10000)
        {
            for(int i=0; i < 3; i++)
            {
                for(int j =0; j <3;j++)
                {
                    grid[i][j] = loshuBoard[i][j];
                }
            }
        }

        if(isBoardMagic(grid) ==1) 
        {
            found =1;
        }
    }
    printf("Found magic square! It took %d tries", count);
    printBoard(grid);

    /*createBoard();
    if(isBoardMagic(loshuBoard))
        {   
    
        }*/

    //return 0;
}