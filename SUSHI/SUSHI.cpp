#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;


const int MAX_N = 20;
const int MAX_M = 21474836;
const int MAX_BUDGET = 200  ;
int N,M;
int preference[MAX_N];
int price[MAX_N];
int cache[MAX_BUDGET + 1];


int solve(int budget)
{
	int& ret = cache[budget];

	if (ret != -1)
	{
		return ret;
	}

	for (int i = 0; i < N; i++)
	{
		if (budget < price[i])
		{
			continue;
		}
		
		ret = max(ret, solve(budget - price[i]) + preference[i]);
	}

	return ret;
}

int solve2()
{
	int ret = 0;
	cache[0] = 0;
	for (int budget = 1; budget <= M; budget++)
	{
		int c = 0;

		for (int i = 0; i < N; i++)
		{
			if (budget >= price[i])
			{
				c = max(c, cache[(budget - price[i])%201] + preference[i]);
			}
		}

		cache[budget % 201] = c;

		ret = max(ret, c);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("SUSHI.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		memset(cache, -1, sizeof(cache));

		cin >> N >> M;

		M /= 100;

		for (int i = 0; i<N; i++)
		{
			cin >> price[i] >> preference[i];
			price[i] /= 100;
		}

		cout << solve2() << endl;
	}

	return 0;
}