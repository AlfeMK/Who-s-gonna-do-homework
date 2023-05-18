#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "math.h" 

void convert(int n, char A[])
{
    A[0] = n / 1000;
    A[1] = (n / 100) % 10;
    A[2] = (n / 10) % 10;
    A[3] = n  % 10;
}

bool repeat(char A[])
{
    for (int i = 0; i < 3; i++)
    for (int j = i+1; j < 4; j++) if (A[i] == A[j]) return true;
    return false;
}

void init(bool Q[])
{
    char A[4];
    for (int i = 0; i < 10000; i++)
    {
        convert(i, A);
        if (repeat(A))Q[i] = false;
        else Q[i] = true;
    }
}

int think(bool Q[])
{
    for (int i = 0; i < 10000; i++)if (Q[i] == true)return i;
    return 0;
}

int match(char X[], char Y[])
{
    int score = 0;
    for(int i=0; i<4; i++)
    for(int j=0;j<4;j++)
    if (X[i] == Y[j])
    {
        if (i == j) score += 10;
        else score += 1;
    }
    return score;
}

void filter(bool Q[], int guess, int ans)
{
    for(int i=0;i<10000;i++)
    if (Q[i] == true)
    {
        char X[4];
        char Y[4];
        convert(i, X);
        convert(guess, Y);
        int score = match(X, Y);
        if (score != ans)Q[i] = false;
    }
}
int main()
{
    bool Q[10000];
    init(Q);
    int ans = 0;
    while (ans < 40)
    {
        int guess = think(Q);
        if (guess == 0)
        {
            std::cout << "Error Jump\n"; break;
        }
        std::cout << "Guess:" << guess << "\n";
        std::cin >> ans;
        filter(Q, guess, ans);
    }
        std::cout << "Program end, congrats!\n";
    }
