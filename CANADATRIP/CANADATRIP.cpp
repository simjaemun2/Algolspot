#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX_N = 5000;

int N,K;

int L[MAX_N];
int M[MAX_N];
int G[MAX_N];

bool decision(int dist)
{
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		if (dist >= L[i] - M[i])
		{
			ret += (min(dist, L[i]) - (L[i] - M[i])) / G[i] + 1;
		}
	}

	return ret >= K;
}

int optimize()
{
	int lo = -1;
	int hi = 8030000+1;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;

		if (decision(mid))
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}

	return hi;
}

int main(int argc, char** argv)
{
	int tc, T;

	std::ios::sync_with_stdio(false);

#ifdef _WIN32
	freopen("CANADATRIP.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> K;

		for (int i = 0; i<N; i++)
		{
			cin >> L[i] >> M[i] >> G[i];
		}

		cout << optimize() << endl;
	}

	return 0;
}