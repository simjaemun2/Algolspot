#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>
#include <algorithm>


using namespace std;

#define MAX_N 500

int N;
int cache[MAX_N + 1];
int lis[MAX_N + 1];

void init()
{
	memset(cache, -1, sizeof(cache));
}

int solve()
{
	/*int& ret = cache[index+1];

	if (ret != -1)
	{
		return ret;
	}

	ret = 1;

	for (int next = index + 1; next < N; next++)
	{
		if (index == -1 || lis[index] < lis[next])
		{
			ret = max(ret , solve(next)+1);
		}
	}*/


	for (int i = N-1; i >= 0; i--)
	{
		cache[i] = 1;

		for (int j = i + 1; j < N; j++)
		{
			if (lis[i] < lis[j] && cache[i] < cache[j] +1)
			{
				cache[i] = cache[j] + 1;
			}
		}
	}

	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		ret = max(ret, cache[i]);
	}

	return ret;
}



int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("lis.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		//init();

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> lis[i];
		}

		cout << solve()<< endl;
	}

	return 0;
}