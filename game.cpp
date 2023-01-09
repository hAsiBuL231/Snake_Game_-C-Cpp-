#include <bits/stdc++.h> // all libarary file for c++
#include <stdio.h>       // input and output
#include <conio.h>       // khbit()  if any key is pressed
#include <stdlib.h>      // rand()  to generate random value
#include <unistd.h>      // sleep()  delay the program, control speed
#include <time.h>        // time() output time
using namespace std;
const int row = 25, column = 30;
int x = 0, y = 1, frtx = 10, frty = 10, score = 0;
char ch = 'd';
void setup_border();
void snake_movement();
void setup_fruit_and_score();

deque<pair<int, int>> snk;

int main()
{
    snk.push_front({0,0});
    snk.push_front({0,1});
    snk.push_front({2,0});
    snk.push_front({3,0});
    snk.push_front({4,0});
    snk.push_front({5,0});

    while (1)
    {
        system("cls");

        setup_border();   // Border
        setup_fruit_and_score();    // generate fruit
        snake_movement(); // input & movement

        printf("Snake Game\n");
        printf("By Md Hasibul Hossain Rezvi\n");
        printf("Your score is: %d\n", score);
        sleep(0.9);
    }

    return 0;
}

void setup_border() // Border
{
    for (int i = 0; i < column; i++)
    {
        printf("$ ");
    }
    printf("$$\n");
    for (int i = 0; i < row; i++)
    {
        printf("$");
        for (int j = 0; j < column; j++)
        {
            int t=0;
            for (auto &it : snk)
            {
                int x1 = it.first;
                int y1 = it.second;
                if (i == x1 && j == y1)
                    printf("0"),t++; // Snake
            }

            if (i == frtx && j == frty)
                printf("* ");
            else
                printf("  ");
        }
        printf("$\n");
    }
    for (int i = 0; i < column; i++)
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
    if (y >= column)
        y = 0;

    if (x < 0)
        x = 25;
    if (y < 0)
        y = column;

    snk.pop_back();
    snk.push_front({x,y});

}

void setup_fruit_and_score() // generate fruit
{
    srand(score); // random number sequance changer
    if (x == frtx && y == frty)
    {
        score += 1;
        snk.push_back({snk.at(score).first,snk.at(score).second+1});
    }
    frtx = rand() % 25;
    frty = rand() % 30;
    while (frtx <= 0 && frty <= 0)
    {
        frtx = rand() % 25;
        frty = rand() % 30;
    }
}
