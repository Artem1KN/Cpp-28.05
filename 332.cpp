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

    int n;
    fin >> n;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            fin >> cost[i][j];

    vector<int> ansct(n + 1, 10000);
    ansct[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            ansct[i] = min(ansct[i], ansct[j] + cost[j][i]);

    fout << ansct[n];


    return 0;
}