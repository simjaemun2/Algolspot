#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define INF 987654321

int N, S;
int nn[MAX_N];
int cache[MAX_N + 1][MAX_N + 1];
int nSum[MAX_N + 1];
int nSqSum[MAX_N + 1];

void init()
{
	memset(cache, -1, sizeof(cache));

	nSum[0] = nn[0];
	nSqSum[0] = nn[0] * nn[0];

	for (int i = 1; i < N; i++)
	{
		nSum[i] = nSum[i - 1] + nn[i];
		nSqSum[i] = nSqSum[i - 1] + nn[i] * nn[i];
	}
}


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int l, int h)
{
	int x = nn[h];
	int i = l - 1;

	for (int j = l; j < h; j++)
	{
		if (x < nn[j])
		{
			i++;
			swap(&nn[i], &nn[j]);
		}
	}

	swap(&nn[i + 1], &nn[h]);

	return i + 1;
}

void quicksort(int l, int h)
{
	if (l < h)
	{
		int p = partition(l, h);
		quicksort(l, p - 1);
		quicksort(p + 1, h);
	}
}

int getMin(int a, int b)
{
	int sum = nSum[b] - (a == 0 ? 0 : nSum[a - 1]);
	int sqSum = nSqSum[b] - (a == 0 ? 0 : nSqSum[a - 1]);
	int min = int(0.5 + (double)sum / (b - a + 1));

	return sqSum - 2 * min*sum + min*min*(b - a + 1);
}

int solve(int nIndex, int sIndex)
{
	if (nIndex == N)
	{
		return 0;
	}

	if (sIndex == 0)
	{
		return INF;
	}

	int& ret = cache[nIndex][sIndex];

	if (ret != -1)
	{
		return ret;
	}

	ret = INF;

	for (int i = 1; nIndex + i <= N; i++)
	{
		ret = min(ret, getMin(nIndex, nIndex + i - 1) + solve(nIndex + i, sIndex - 1));
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("quantize.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> S;

		for (int i = 0; i<N; i++)
		{
			cin >> nn[i];
		}

		quicksort(0, N - 1);

		init();

		cout << solve(0,S) << endl;
	}

	return 0;
}