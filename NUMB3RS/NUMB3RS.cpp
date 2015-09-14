#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>



using namespace std;

#define MAX_N 50
#define MAX_D 100
#define MAX_INF 987654321

int N, D, P, T,Q;
int nn[MAX_N][MAX_N];
int degree[MAX_N];
double cache[MAX_N + 1][MAX_D + 1];
string s;

void init()
{
	memset(cache, -1, sizeof(cache));
}



double solve(int here, int days)
{
	if(days == 0)
	{ 
		return (here == P ? 1.0 : 0.0);
	}

	double& ret = cache[here][days];

	if (ret > -0.5)
	{
		return ret;
	}

	ret = 0.0;

	for (int there = 0; there < N; there++)
	{
		if (nn[here][there])
		{
			ret += solve(there, days - 1) / degree[there];
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, C;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(8);
	


#ifdef _WIN32
	freopen("NUMB3RS.txt", "r", stdin);
#endif

	cin >> C;
	for (tc = 0; tc < C; tc++)
	{
		init();

		cin >> N >> D >> P;

		for (int i = 0; i < N; i++)
		{
			degree[i] = 0;

			for (int j = 0; j < N; j++)
			{
				cin >> nn[i][j];
				
				if (nn[i][j])
				{
					degree[i]++;
				}
			}
		}

		cin >> T;

		for (int i = 0; i < T; i++)
		{
			cin >> Q;
			cout << solve(Q, D) << " ";
		}
		cout << endl;
		//cout << solve(0) << endl;
	}

	return 0;
}