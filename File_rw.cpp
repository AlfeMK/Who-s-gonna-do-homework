#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "math.h" 

int main()
{
    FILE* f;
    f= fopen("sus.txt", "wa");
    for (float i = 0; i < 10; i++)fprintf(f, "%0.2f\n", (rand() % 100) * 1.0, i);
    fclose(f);

}
