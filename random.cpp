#include <iostream>
#include <time.h>
#include <stdlib.h>

float z()
{
 float sum=0;
 for(int i=0; i<12; i++)sum+= rand()*1.0/ RAND_MAX;
 return sum -6.0;

}

int main()
{
srand(time(NULL));rand();

for(int i=0; i<6;i++)std::cout << 23+int(rand()*z()/1000) << "\n";

}

