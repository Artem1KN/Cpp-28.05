#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    
    int height;
    fin >> height;

    vector<int>djt(height + 1, 0);

    djt[0] = 1;
    const int MOD = 1000 * 1000;

    for (int h = 1; h <= height; ++h)
    {
        if (h >= 10)
            djt[h] += djt[h - 10];
        if (h >= 11)
            djt[h] += djt[h - 11];
        if (h >= 12)
            djt[h] += djt[h - 12];
        djt[h] %= MOD;
    }

    fout << djt[height] * 2 % MOD;


    return 0;
}