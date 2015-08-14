#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>


using namespace std;

#define MAX_N 100

int N;
int MAP[MAX_N + 1][MAX_N + 1];
int cache[MAX_N + 1][MAX_N + 1];


void init()
{
	memset(cache, -1, sizeof(cache));
}

int solve(int y, int x)
{
	if (y >= N)
	{
		return 0;
	}

	if (x >= N)
	{
		return 0;
	}

	if (y == N - 1 && x == N - 1)
	{
		return 1;
	}

	int& ret = cache[y][x];

	if (ret != -1)
	{
		return ret;
	}

	return ret = solve(y + MAP[y][x], x) || solve(y, x + MAP[y][x]);
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("JUMPGAME.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		init();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> MAP[i][j];
			}
		}

		if (solve(0, 0) > 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}


	}

	return 0;
}