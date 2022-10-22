#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//We will have to create a 2d grid 
int board[3][3] =
{
    {0,0,0},
    {0,0,0},
    {0,0,0}
}; 


//We will have to make an array with the values
int numbers[9] = {1,2,3,4,5,6,7,8,9};

//There should be a function that checks if the array is Magic
int isBoardMagic(int arr[3][3])
{
    int magic = -1; //negative one so if not found it will be negative 1

    //for loop to iterate through columns
    for(int i =0; i < 3; i++)
    {
        int oneSum = 0;
        for(int j =0; j < 3; j++)
        {
            oneSum += arr[i][j];
        }
        if(oneSum != 15) magic =0;
    }
    //for loop to iterate through rows
    for(int j =0; j < 3; j++)
    {
        int twoSum = 0;
        for(int i =0; i< 3; i++)
        {
            twoSum += arr[i][j];
        }
        if(twoSum != 15) magic =0;
    }

    //finally iterate through diagonals
    if(arr[0][0] + arr[1][1] + arr[2][2] != 15) magic =0;
    if(arr[2][0] + arr[1][1] + arr[0][2] != 15) magic =0;

    return magic;
}

//There should be a function that prints the array
void printBoard(int arr[3][3])
{
    printf("\n");

    for(int i=0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            if(j==0)
            {
                printf("[ ");
            }
            printf("%d ", arr[i][j]);
        }
        printf("]\n");
    }

    printf("\n");


}

//Function that randomizes the board
void mix()
{
    for(int i=8; i>0; i--)
    {
        int random = (rand() % (i+1));

        int temp = numbers[i];
        numbers[i] = numbers[random];
        numbers[random] = temp;
    }
}

//Function that sets the array/grid
void createBoard()
{
    mix();
    int index =0;
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            board[i][j] = numbers[index];
            index++;
        }
    }
}

//main method that checks if the grid works, and increments tries by one each time it needs to shuffle
int main()
{

    return 0;
}