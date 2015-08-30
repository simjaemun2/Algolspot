#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
#include <math.h>


using namespace std;

#define MAX_N 10000
#define MAX_INF 987654321

int cache[MAX_N + 10];
string s;

void init()
{
	memset(cache, -1, sizeof(cache));
}

int getLevel(int indexN, int length)
{
	string str1 = "";

	for (int i = 0; i < length; i++)
	{
		str1 += s[indexN];
	}

	string m = s.substr(indexN,length);

	if (m == str1)
	{
		return 1;
	}

	bool lev5 = true;

	for (int i = 1; lev5 && i < length - 1; i++)
	{
		if (m[0] - m[1] != m[i] - m[i + 1])
		{
			lev5 = false;
		}
			
	}

	if (lev5 && abs(m[0] - m[1]) == 1)
	{
		return 2;
	}

	bool lev4 = true;

	for (int i = 0; lev4 && i < length - 2; i++)
	{
		if (m[i] != m[i+2])
		{
			lev4 = false;
		}
	}

	if (lev4)
	{
		return 4;
	}

	if (lev5)
	{
		return 5;
	}

	return 10;
}

int solve(int indexN)
{
	if (indexN >= s.size())
	{
		return 0;
	}

	int& ret = cache[indexN];

	if (ret != -1)
	{
		return ret;
	}

	ret = MAX_INF;

	for (int i = 3 ; i <= 5; i++)
	{
		if (indexN + i <= s.size())
		{
			ret = min(ret, solve(indexN + i) + getLevel(indexN, i));
		}
	}	

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("pi.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		init();

		
		cin >> s;
		

		cout << solve(0) << endl;
	}

	return 0;
}