#include <stdio.h>  // input and output
#include <conio.h>  // khbit()  if any key is pressed
#include <stdlib.h> // rand()  to generate random value
#include <unistd.h> // sleep()  delay the program, control speed
#include <time.h>   // time() output time
const int hight = 25, wedth = 30;
int x = 0, y = 0, frtx = 0, frty = 0, score = 0;
char ch = 'd';
void setup_border();
void snake_movement();
void setup_fruit();

int main()
{
    while (1)
    {
        system("cls");
        printf("\nSnake Game\n");
        printf("By Md Hasibul Hossain Rezvi\n\n");

        setup_fruit();    // generate fruit
        setup_border();   // Border
        snake_movement(); // input & movement

        printf("\n Your score is: %d\n", score);
        sleep(0.9);
    }

    return 0;
}

void setup_border() // Border
{
    for (int i = 0; i < wedth; i++)
    {
        printf("$ ");
    }
    printf("$$\n");
    for (int i = 0; i < hight; i++)
    {
        printf("$");
        for (int j = 0; j < wedth; j++)
        {
            if (i == x && j == y)
                printf("0 "); // Snake
            else if (i == frtx && j == frty)
                printf("* ");
            else
                printf("  ");
        }
        printf("$\n");
    }
    for (int i = 0; i < wedth; i++)
    {
        printf("$ ");
    }
    printf("$$\n");
}

void snake_movement() // input & movement
{
    if (kbhit()) // if any key is pressed
    {
        ch = getch();
    }
    switch (ch)
    {
    case 'a':
        y--;
        break;
    case 's':
        x++;
        break;
    case 'd':
        y++;
        break;
    case 'w':
        x--;
        break;
    }

    if (x >= 25)
        x = 0;
    if (y >= wedth)
        y = 0;

    if (x < 0)
        x = 25;
    if (y < 0)
        y = wedth;
}

void setup_fruit() // generate fruit
{
    srand(score); // random number sequance changer
    if (x == frtx && y == frty)
    {
        score += 1;
    }
    frtx = rand() % 25;
    frty = rand() % 30;
    while (frtx <= 0 && frty <= 0)
    {
        frtx = rand() % 25;
        frty = rand() % 57;
    }
}