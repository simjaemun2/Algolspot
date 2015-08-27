#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <limits>

using namespace std;

#define MAX_N 100

const long long NEGINF = numeric_limits<long long>::min();
int cache[MAX_N + 1][MAX_N + 1];
int N,M;
int nn[MAX_N + 1];
int mm[MAX_N + 1];

void init()
{
	memset(cache, -1, sizeof(cache));
}

int solve(int indexN, int indexM)
{

	int& ret = cache[indexN+1][indexM+1];

	if (ret != -1)
	{
		return ret;
	}

	ret = 2;

	long long a = (indexN == -1 ? NEGINF : nn[indexN]);
	long long b = (indexM == -1 ? NEGINF : mm[indexM]);


	int maxValue = max(a,b);

	for (int next = indexN + 1; next < N; next++)
	{
		if (indexN == -1 || maxValue < nn[next])
		{
			ret = max(ret, solve(next, indexM)+1);
		}
	}

	for (int next = indexM + 1; next < M; next++)
	{
		if (indexM == -1 || maxValue < mm[next])
		{
			ret = max(ret, solve(indexN, next)+1);
		}
	}


	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("jlis.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		init();

		cin >> N >> M;

		for (int i = 0; i<N; i++)
		{
			cin >> nn[i];
		}

		for (int i = 0; i<M; i++)
		{
			cin >> mm[i];
		}

		cout << solve(-1,-1) -2 << endl;
	}

	return 0;
}