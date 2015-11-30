#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>


using namespace std;

const int MAX_K = 1000000000;
const int _INF = MAX_K + 1000;

int N, M, K;

int bino[201][201];

void calcBino()
{
	memset(bino, 0, sizeof(bino));

	for (int i = 0; i <= 200; ++i)
	{
		bino[i][0] = bino[i][i] = 1;

		for (int j = 1; j < i; j++)
		{
			bino[i][j] = min(_INF, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}

void solve(int n, int m, string s)
{
	if (K < 0)
	{
		return;
	}

	if (n == 0 && m == 0)
	{
		if (K == 0)
		{
			cout << s << endl;
		}

		K--;

		return;
	}

	if (bino[n + m][n] <= K)
	{
		K -= bino[n + m][n];
		return;
	}


	if (n > 0)
	{
		solve(n - 1, m, s + "-");
	}

	if (m > 0)
	{
		solve(n, m - 1, s + "o");
	}
}

string kth(int n, int m, int skip)
{
	if (n == 0)
	{
		return string(m, 'o');
	}

	if (skip < bino[n + m - 1][n - 1])
	{
		return "-" + kth(n - 1, m, skip);
	}

	return "o" + kth(n, m - 1, skip - bino[n + m - 1][n - 1]);
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("MORSE.txt", "r", stdin);
#endif

	cin >> T;

	calcBino();

	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> M >> K;

		K--;

		string s;

		//solve(N, M,s);
		//cout << s << endl;

		cout << kth(N, M, K) << endl;

		
	}

	return 0;
}