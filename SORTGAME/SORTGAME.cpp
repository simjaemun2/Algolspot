#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int N;

vector<int> input;

int bfs(const vector<int>& perm)
{
	int n = perm.size();

	vector<int> sorted = perm;

	sort(sorted.begin(), sorted.end());

	queue<vector<int> > q;

	map<vector<int>, int > distance;

	distance[perm] = 0;

	q.push(perm);

	while (!q.empty())
	{
		vector<int> here = q.front();
		q.pop();

		if (here == sorted)
		{
			return distance[here];
		}

		int cost = distance[here];

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 2; j <= n; j++)
			{
				reverse(here.begin() + i, here.begin() + j);

				if (distance.count(here) == 0)
				{
					distance[here] = cost + 1;
					q.push(here);
				}

				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}

	return -1;
}


map<vector<int>, int> toSort;

void precalc(int n)
{
	vector<int> perm(n);

	for (int i = 0; i < n; i++)
	{
		perm[i] = i;
	}

	queue<vector<int> > q;

	q.push(perm);

	toSort[perm] = 0;

	while (!q.empty())
	{
		vector<int> here = q.front();

		q.pop();

		int cost = toSort[here];

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 2; j <= n; j++)
			{
				reverse(here.begin() + i, here.begin() + j);

				if (toSort.count(here) == 0)
				{
					toSort[here] = cost + 1;
					q.push(here);
				}

				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}

int solve(const vector<int>& perm)
{
	//return bfs(input);

	int n = perm.size();

	vector<int> fixed(n);

	for (int i = 0; i < n; i++)
	{
		int smaller = 0;

		for (int j = 0; j < n; j++)
		{
			if (perm[j] < perm[i])
			{
				++smaller;
			}
		}

		fixed[i] = smaller;
	}

	return toSort[fixed];
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("SORTGAME.txt", "r", stdin);
#endif

	for (int i = 1; i <= 8; i++)
	{
		precalc(i);
	}


	cin >> T;



	for (tc = 0; tc < T; tc++)
	{
		input.clear();
		//toSort.clear();
		
		cin >> N;

		for (int i = 0; i<N; i++)
		{
			int a;
			cin >> a;
			input.push_back(a);
		}

		//precalc(N);
		cout << solve(input) << endl;
	}

	return 0;
}