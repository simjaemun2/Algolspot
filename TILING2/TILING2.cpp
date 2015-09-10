#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MOD 1000000007


int N;
int cache[MAX_N + 1];


void init()
{
	memset(cache, -1, sizeof(cache));
}




int solve(int nIndex)
{
	if (nIndex <= 1)
	{
		return 1;
	}

	int& ret = cache[nIndex];
	
	if (ret != -1)
	{
		return ret;
	}

	return ret = (solve(nIndex-1) + solve(nIndex -2))%MOD;

}

int asymtiling(int nIndex)
{
	if (nIndex % 2 == 1)
	{
		return (solve(nIndex) - solve(nIndex / 2) + MOD) % MOD;
	}

	int ret = solve(nIndex);
	ret = (ret - solve(nIndex / 2) + MOD) % MOD;
	ret = (ret - solve(nIndex / 2 - 1) + MOD) % MOD;

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("tiling2.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N ;

		init();

		cout << asymtiling(N) << endl;
	}

	return 0;
}