#include <bits/stdc++.h>
#include <time.h>
#define MAX_SIZE 10000001
using namespace std;
int N[5] = {100, 1000, 10000, 100000, 1000000};
int a[MAX_SIZE];
int n;
int b;
int c;
int main()
{
    clock_t start_time, end_time;
    double time_use;
    cin >> n;
    cout << "n : " << N[n] << endl;
    srand(time(NULL)); // seed the random number generator with the current time
    int range = 101; // 100 - 0 + 1
    int sign[2] = {-1, 1};
    for (int i = 0; i < N[n]; i++) {
        a[i] = (rand() % range)*sign[rand()%2];
        // cout << a[i] << " ";
    }
    // cout << endl;
    start_time = clock();
    int maxSum = a[0];
    for (int i = 0; i < N[n]; i++)
    {
        for (int j = i; j < N[n]; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += a[k];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << maxSum << endl;
    end_time = clock();
    time_use = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time used for BF1: " << time_use << endl;
    return 0;
}
