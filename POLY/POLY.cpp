#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>

using namespace std;

#define MAX_N 100
#define MOD 10000000


int N;
int cache[MAX_N + 1][MAX_N+1];


void init()
{
	memset(cache, -1, sizeof(cache));
}

int solve(int n, int f)
{
	if (n == f)
	{
		return 1;
	}

	int & ret = cache[n][f];

	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	for (int s = 1; s <= n - f; s++)
	{
		int a = f + s - 1;
		a *= solve(n - f, s);
		a %= MOD;
		ret += a;
		ret %= MOD;
	}

	return ret;
}



int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("poly.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		init();

		int result = 0;

		for (int i = 1; i <= N; i++)
		{
			result += solve(N, i);
			result %= MOD;
		}

		cout << result << endl;
	}

	return 0;
}