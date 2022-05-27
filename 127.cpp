#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

	int n, i, j, k, f, s;
	queue <int> q;
	fin >> n;
	int** a = new int* [n];
	int* d = new int[n];

	for (i = 0; i < n; i++)
	{
		d[i] = 1000000000;
		a[i] = new int[n];
		for (j = 0; j < n; j++)
			fin >> a[i][j];
	}

	fin >> s >> f;
	s--;
	f--;
	d[s] = 0;
	q.push(s);

	while (!q.empty())
	{
		i = q.front();
		q.pop();
		for (j = 0; j < n; j++)
		{
			if (a[i][j] && d[j] > d[i] + 1)
			{
				d[j] = d[i] + 1;
				q.push(j);
			}
		}
	}

	if (d[f] < 1000000000)
		fout << d[f] << endl;
	else fout << -1 << endl;

    return 0;
}