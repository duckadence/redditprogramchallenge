// The game of Yahtzee is played by rolling five 6-sided dice, and scoring the
// results in a number of ways. You are given a Yahtzee dice roll, represented
// as a sorted list of 5 integers, each of which is between 1 and 6 inclusive.
// Your task is to find the maximum possible score for this roll in the upper
// section of the Yahtzee score card.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void roll(int fiveRolls[]);
int score(int fiveRolls[]);

int main()
{
    int finalScore, fiveRolls[6];
    srand(time(NULL));

    roll(fiveRolls);
    finalScore = score(fiveRolls);

    cout << "Numbers rolled: ";
    for (int count = 0; count < 5; count++)
    {
        cout << fiveRolls[count];
        cout << (count < 4 ? ", " : "\n");
    }

    cout << "Highest score: " << finalScore;

    cin.get();

    return 0;
}

void roll(int fiveRolls[])
{
    for (int count = 0; count < 5; count++)
    {
        fiveRolls[count] = rand() % 6 + 1;
    }
}

int score(int fiveRolls[])
{
    int rollCounter[6] = {0}, finalScore;

    for (int count = 0; count < 5; count++)
    {
        switch (fiveRolls[count])
        {
        case 1:
            rollCounter[0]++;
            break;
        case 2:
            rollCounter[1]++;
            break;
        case 3:
            rollCounter[2]++;
            break;
        case 4:
            rollCounter[3]++;
            break;
        case 5:
            rollCounter[4]++;
            break;
        case 6:
            rollCounter[5]++;
            break;
        }
    }

    for (int count = 0; count < 6; count++)
    {
        cout << rollCounter[count];
        cout << (count < 5 ? ", " : "\n");
    }

    finalScore = rollCounter[0] * 1;

    for (int count = 0; count < 6; count++)
    {
        if (finalScore < rollCounter[count] * (count + 1))
        {
            finalScore = rollCounter[count] * (count + 1);
        }
    }

    return finalScore;
}