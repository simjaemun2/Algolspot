#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


const int MAX_N = 10000;
int N;
int heat[MAX_N];
int eat[MAX_N];

int solve()
{
	vector<pair<int, int> > order;

	for (int i = 0; i < N; i++)
	{
		order.push_back(make_pair(-eat[i], i));
	}

	sort(order.begin(), order.end());

	int ret = 0;
	int beginEat = 0;

	for (int i = 0; i < N; i++)
	{
		int box = order[i].second;
		
		beginEat += heat[box];
		
		ret = max(ret, beginEat + eat[box]);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("LUNCHBOX.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		for (int i = 0; i<N; i++)
		{
			cin >> heat[i];
		}

		for (int i = 0; i<N; i++)
		{
			cin >> eat[i];
		}

		cout << solve() << endl;
	}

	return 0;
}