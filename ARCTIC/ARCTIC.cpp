#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100;
int N;

double dist[MAX_N + 1][MAX_N + 1];
double x[MAX_N];
double y[MAX_N];

double decision(double gap)
{
	vector<bool> visited(N, false);
	queue<int> q;
	q.push(0);
	int seen = 0;
	visited[0] = true;


	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		++seen;

		for (int there = 0; there < N; there++)
		{
			if (!visited[there] && dist[here][there] <= gap)
			{
				visited[there] = true;
				q.push(there);
			}
		}
	}

	return seen == N;
}

double optimize()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			dist[i][j] = dist[j][i] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
		}
	}

	double lo = 0, hi = 1000.0*sqrt(2.0);

	for (int i = 0; i < 100; i++)
	{
		double mid = (lo + hi) / 2.0;

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

#ifdef _WIN32
	freopen("ARCTIC.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		for (int i = 0; i<N; i++)
		{
			cin >> x[i] >> y[i];
		}

		double ret = optimize();
		printf("%.2f\n", ret);
	}

	return 0;
}