#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>


using namespace std;

#define MAX_N 10000

char stack[MAX_N];

//double cache[MAX_N + 1][MAX_D + 1];
string s;

string open("({[");
string close(")}]");

void init()
{
	//memset(cache, -1, sizeof(cache));
}



string solve()
{
	int front = -1;

	for (int i = 0; i < s.size(); i++)
	{
		if (open.find(s[i]) != -1)
		{
			stack[++front] = s[i];
		}
		else
		{
			if (front < 0 || open.find(stack[front--]) != close.find(s[i]))
			{
				return "NO";
			}
		}
	}

	if (front > -1)
	{
		return "NO";
	}
	
	return "YES";
}

int main(int argc, char** argv)
{
	int tc, C;

	/*
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(8);
	*/


#ifdef _WIN32
	freopen("BRACKETS2.txt", "r", stdin);
#endif

	cin >> C;
	for (tc = 0; tc < C; tc++)
	{
		cin >> s;

		cout << solve() << endl;
	}

	return 0;
}