#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "math.h" 

int march(char A[], char B[])
{
    int score = 0;
    for(int i=0;i<4;i++)
    for (int j = 0; j < 4; j++)
    if(A[i]==B[j])
    {
        if (i == j) score += 10;
        else score += 1;
    }
    return score;
}

int main()
{
    char Ans[4];
    char Guess[4];
    int score = 0;

    srand(time(NULL)); rand;
    for (int i = 0; i < 4; i++)	
	{
		Ans[i] = rand() % 10;
		if (Ans[i]= Ans[i+1]) Ans[i] = rand() % 10; 
		std::cout << Ans[i];
	}

    while (score < 40)
    {
        int x;
       
        std::cin >> x;
        Guess[0] = x / 1000;
        Guess[1] = (x / 100) % 10;
        Guess[2] = (x / 10) % 10;
        Guess[3] = x % 10;
        score = march(Ans, Guess);

        std::cout << score << "\n";
    }
}
