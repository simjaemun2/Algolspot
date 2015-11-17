#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <queue>

using namespace std;

const int MAX_N =  10000;
const int MAX_M =  20000;
const double INF =  987654321.0;

int N, M;
vector<pair<int, double> > adj[MAX_N];

vector<double> dijkstra(int src)
{
	vector<double > dist(N, INF);

	dist[src] = 0.0;

	priority_queue<pair<double,int> > pq;

	pq.push(make_pair(0.0, src));

	while (!pq.empty())
	{
		int here = pq.top().second;
		double cost = -pq.top().first;

		pq.pop();

		if (dist[here] < cost)
		{
			continue;
		}

		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			double nextDist = adj[here][i].second + cost;

			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;

				pq.push(make_pair(-nextDist, there));
			}
		}
	}

	return dist;
}

int solve()
{
	int result = 0;

	return result;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("ROUTING.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			adj[i].clear();
		}

		for (int i = 0; i<M; i++)
		{
			int here, there;
			double cost;

			cin >> here >> there >> cost;
			
			cost = log10(cost);

			adj[here].push_back(make_pair(there, log(cost)));
		}

		vector<double > d = dijkstra(0);


		cout << exp(d[N-1]) << endl;
	}

	return 0;
}