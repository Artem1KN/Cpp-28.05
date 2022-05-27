#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int** a;
	int cur = 0;
	a = new int* [n];

	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	for (int c = 0; c < 2 * n; c++)
	{
		if (c % 2 == 0)
		{
			for (int i = 0; i < n; ++i)
			{
				int j = c - i;
				if (0 <= j && j < n)
				{
					cur++;
					a[i][j] = cur;
				}
			}
		}
		else
		{
			for (int i = n - 1; i >= 0; --i)
			{
				int j = c - i;
				if (0 <= j && j < n)
				{
					cur++;
					a[i][j] = cur;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}

		cout << endl;
	}
	
	return 0;
}