#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //We will need to make constant ints for the min possible number. MAX not a const since we can change it
    const int MIN = 1;
    int max = 100;

    // we will also need ints for the guess, and the answer. I want to add how may guesses
    int guess;
    int guesses;
    int answer;

    int gameOption; //this is where we have the user select an option
    do{

    //we will need to have an output that asks for options
    // 1: play the game
    //2: change max number
    //3: to quit 
    printf("Press 1 to Play a game\n Press 2 to change max number \n Pres 3 to quit\n");
    scanf("%d", &gameOption);

    if(gameOption ==1){ //Option 1 selected, runs through the game
    //generate random number between 1-100
    srand(time(0));
    answer = (rand() % max) + MIN;
    //The guess game in general, before options 1 2 3. Just to have the game working
    do{
        printf("Enter a guess: ");
        scanf("%d", &guess);
        
        if(guess > answer)
        {
            printf("Too high!\n");

        }
        else if(guess < answer)
        {
            printf("Too Low!\n");
        }
        else if(guess > 100 && guess < 0) //checks if number is out of bounds
        {
            printf("Enter a number 1-100!!!!!!\n");
        }
        else
        {
            printf("Correct Answer!\n");
        }
        guesses++;
    }while(guess != answer);

    //once guess is q, restart program, not end
    

    //once guess found, restarts the program

    printf("/////////////////\n");
    printf("Answer: %d\n", answer);
    printf("Guesses: %d\n", guesses);
    printf("/////////////////\n");
    }

    if(gameOption ==2)
    {
        printf("Pick a new max number, 1-100\n");
        scanf("%d", &max);
        if(max <1 || max > 100 )
        {
            printf("No Negative numbers or numbers greater than 100 please!\n Enter option 2 and try again\n");
        }

        
    }

    else if(gameOption != 1 && gameOption != 2 && gameOption != 3)
    {
        printf("invalid input\n");
    }

    

    }while(gameOption != 3);//Option 3, Thanks for playing ends program

    printf("Thank you for playing.\n");

    
    //Option 2, not sure what this means tbh. maybe max is 100
    //no negative numbers


    return 0;
}