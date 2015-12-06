#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const int MAX_N = 100;
const int MAX_W = 1000;

int N,W;

string ITEM[MAX_N];
int CAPACITY[MAX_N];
int NEED[MAX_N];
vector<string> PICKED;

int cache[MAX_W+1][MAX_N+1];

void init()
{
	memset(cache, -1, sizeof(cache));

	PICKED.clear();
}

int solve(int capacity, int index)
{
	if (index == N)
	{
		return  0;
	}

	int &ret = cache[capacity][index];

	if (ret != -1)
	{
		return ret;
	}

	ret = solve(capacity, index + 1);

	if (capacity >=  CAPACITY[index])
	{
		ret = max(ret,solve(capacity - CAPACITY[index], index + 1) + NEED[index]);
	}

	return ret;
}

void reconstruct(int capacity, int index)
{
	if (index == N)
	{
		return;
	}

	if (solve(capacity, index) == solve(capacity, index + 1))
	{
		reconstruct(capacity, index + 1);
	}
	else
	{
		PICKED.push_back(ITEM[index]);
		reconstruct(capacity - CAPACITY[index], index + 1);
	}
}

int main(int argc, char** argv)
{
	int tc, T;

	ios::sync_with_stdio(false);

#ifdef _WIN32
	freopen("PACKING.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		init();

		cin >> N >> W;

		for (int i = 0; i<N; i++)
		{
			cin >> ITEM[i] >> CAPACITY[i] >> NEED[i];
		}

		cout << solve(W,0);
		reconstruct(W, 0);

		cout << " " << PICKED.size() << endl;

		for (int i = 0; i < PICKED.size(); i++)
		{
			cout << PICKED[i] << endl;
		}
	}

	return 0;
}