#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int K, N;
unsigned long long iNext;

//double cache[MAX_N + 1][MAX_D + 1];

void init()
{
	//memset(cache, -1, sizeof(cache));
	iNext = 1983;
}

int getNext()
{
	int ret = (int)(iNext%10000) + 1;
	long long MOD = 0x100000000;
	iNext = (iNext * 214013 + 2531011) % MOD;
	return ret;
}

int solve()
{
	int ret = 0;

	int sum = 0;

	queue<int> q;

	for (int i = 0, front = 0; i < N; i++)
	{
		int n = getNext();
		
		q.push(n);

		sum += n;

		while (sum > K && !q.empty())
		{
			sum -= q.front();
			q.pop();
		}

		if (sum == K)
		{
			ret++;
		}
	}

	return ret;
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
	freopen("ITES.txt", "r", stdin);
#endif
	
	cin >> C;
	
/*
	init();

	for (int i = 0; i < 5; i++)
	{
		cout << getNext() << endl;
	}
*/
	for (tc = 0; tc < C; tc++)
	{
		cin >> K >> N;

		init();

		cout << solve() << endl;
	}
	

	return 0;
}