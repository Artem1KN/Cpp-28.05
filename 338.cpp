#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

const int N = 105;

int n, m, massiv[N][N], counts = 1;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool valid(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m;
}

void dfs(int row, int column)
{
    massiv[row][column] = counts;

    for (int i = 0; i < 4; i++) {
        int x = row + dx[i];
        int y = column + dy[i];

        if (valid(x, y))
            if (!massiv[x][y])
                dfs(x, y);
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin >> massiv[i][j];
    for (int z = 1; z <= n; z++)
        for (int k = 1; k <= m; k++)
            if (!massiv[z][k]) {
                dfs(z, k);
                counts++;
            }

    fout << counts - 1;

    return 0;
}