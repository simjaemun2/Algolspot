#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX_M = 200;

int N , M;

double locations[MAX_M];


double decision(double gap)
{
	double limit = -1;
	int installed = 0;

	for (int i = 0; i < M; i++)
	{
		if (limit <= locations[i])
		{
			installed++;

			limit = locations[i] + gap;
		}
	}

	return installed >= N;
}

double optimize()
{
	double lo = 0, hi = 241;

	for (int it = 0; it < 100; it++)
	{
		double mid = (lo + hi) / 2.0;

		if (decision(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}

	return lo;
}

int solve()
{
	int ret = 0;

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("DARPA.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> M;

		for (int i = 0; i<M; i++)
		{
			cin >> locations[i];
		}

		double ret = optimize();

		printf("%.2f\n", ret);
	}

	return 0;
}