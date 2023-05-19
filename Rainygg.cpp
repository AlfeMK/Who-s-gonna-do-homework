// Rainygg.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <time.h>

void example(float x[], float y[][2], int n)
{
    float h = 0;
    for (int i = 0; i < n; i++)
    {
        x[i] = rand() % 2;
        if (x[i] == 0)
        {
            if (h == 3)
            {
                y[i][0] = 1;
                y[i][1] = 0;
            }
            else
            {
                y[i][0] = 0;
                y[i][1] = 0;
                h++;
            }
        }
        else
        {
            if (h == 3)
            {
                y[i][0] = 0;
                y[i][1] = 1;
                h = 0;
            }
            else
            {
                y[i][0] = 0;
                y[i][1] = 0;
            }
        }
    }
}

float sigmoid(float y)
{
    return 1.0 / (1 + exp(-y));
}

float RNN(float x, float y[], float w[],float h)
{
    y[0] = sigmoid(w[0] * x + w[1] * h +w[2]);
    y[1] = sigmoid(w[3] * x + w[4] * h + w[5]);
    h = h + w[6]*y[0] + w[7] * y[2] + w[8]*x + w[9];
    return h;
}

#define L 0.3

int main()
{
    float y[20][2];
    float x[20];
    float h;
    srand(time(NULL)); rand();
    example(x, y, 20);

    //float w[10] = { -8,8,-20,8,8,-28,-1,-3,-1,1 };
    float w[10] = { 1,2,3,4,5,6,7,8,9 };

    //for (int i = 0; i < 20; i++) std::cout << x[i] << " "; std::cout << "\n";
    //for (int i = 0; i < 20; i++) std::cout << y[i][0] << " "; std::cout << "\n";
    //for (int i = 0; i < 20; i++) std::cout << y[i][1] << " "; std::cout << "\n";

    float yy[20][2];

    for (int k = 0; k < 100000; k++)
    {
        for (int i = 0; i < 20; i++)
        {
            h = 0;
            float hh = RNN(x[i], yy[i], w, h);
            float e0 = y[i][0] - yy[i][0];
            float e1 = y[i][1] - yy[i][1];
            w[0] += L * e0 * x[i];
            w[1] += L * e0 * h;
            w[2] += L * e0;
            w[3] += L * e1*x[i];
            w[4] += L * e1 * h;
            w[5] += L * e1;
            w[6] += L * (e0 * w[1] + e1 * w[4]) * y[i][0];
            w[7] += L * (e0 * w[1] + e1 * w[4]) * y[i][1];
            w[8] += L * (e0 * w[1] + e1 * w[4]) * x[i];
            w[9] += L * (e0 * w[1] + e1 * w[4]);
            h = hh;

        }
    }
    

    for (int k = 0; k < 10; k++)std::cout << w[k] << "\n";

    example(x, y, 20);
    for (int i = 0; i < 20; i++)h = RNN(x[i], y[i], w, h);
    for (int i = 0; i < 20; i++) std::cout << x[i] << " "; std::cout << "\n";
    for (int i = 0; i < 20; i++) std::cout << round(y[i][0]) << " "; std::cout << "\n";
    for (int i = 0; i < 20; i++) std::cout << round(yy[i][0]) << " "; std::cout << "\n";
    for (int i = 0; i < 20; i++) std::cout << round(y[i][1]) << " "; std::cout << "\n";
    for (int i = 0; i < 20; i++) std::cout << round(yy[i][1]) << " "; std::cout << "\n";

    //for (int i = 0; i < 20; i++) std::cout << x[i] << " "; std::cout << "\n";
    //for (int i = 0; i < 20; i++) std::cout << round(y[i][0]) << " "; std::cout << "\n";
    //for (int i = 0; i < 20; i++) std::cout << round(y[i][1]) << " "; std::cout << "\n";

}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
