#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>


using namespace std;

int N, P, L;

const int MAX_N = 50;
const int _INF = 1000000000 + 1;

int length[MAX_N + 1];

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";

void preCal()
{
	length[0] = 1;

	for (int i = 1; i <= MAX_N; i++)
	{
		length[i] = min(length[i - 1] * 2 + 2,_INF);
	}
}

char expand(const string& dragonCurve, int generations, int skip)
{
	if (generations == 0)
	{
		return dragonCurve[skip];
	}

	for (int i = 0; i < dragonCurve.size(); i++)
	{
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
		{
			if (skip >= length[generations])
			{
				skip -= length[generations];
			}
			else if (dragonCurve[i] == 'X')
			{
				return expand(EXPAND_X, generations - 1, skip);
			}
			else
			{
				return expand(EXPAND_Y, generations - 1, skip);
			}
		}
		else if (skip > 0)
		{
			--skip;
		}
		else
		{
			return dragonCurve[i];
		}
	}

	return '0';
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("DRAGON.txt", "r", stdin);
#endif

	cin >> T;

	preCal();

	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> P >> L;

		for (int i = 0; i < L; i++)
		{
			cout << expand("FX", N, P - 1 + i);
		}

		cout << endl;
	}

	return 0;
}