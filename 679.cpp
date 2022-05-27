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

	long long n, a;
	fin >> n;

	a = n / 3;
	n = n % 3;

	if (n == 1)
	{
		a -= 1;
		n += 3;
	}

	if (n > 1)
		fout << 2 << ' ' << n / 2 << ' ';

	if (a > 0)
		fout << 3 << ' ' << a;

    return 0;
}