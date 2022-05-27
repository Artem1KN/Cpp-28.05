#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, a = 1;
    fin >> n;

	for (int j = 2; a <= sqrt(n); j++)
	{
		if (n % j == 0)
		{
			for (a <= sqrt(n); ++a;)
			{
				if (n % a == 0)
				{
					break;
				}
			}
			fout << n / a << " " << n - (n / a);
			return 0;
		}
	}

	fout << 1 << " " << n - 1;

    return 0;
}