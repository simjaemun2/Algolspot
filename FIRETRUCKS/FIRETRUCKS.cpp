#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <utility>


using namespace std;

const int INF = 987654321;
const int MAX_V = 1000;

int V,E,N,M;


vector<pair<int, int> > adj[MAX_V+1];
vector <int> vSrc, vDst;

vector<int > dijkstra(int src)
{
	vector<int > dist(V+1,INF);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, src));

	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = -pq.top().first;

		pq.pop();

		if (dist[here] < cost)
		{
			continue;
		}

		for (int i = 0; i < adj[here].size(); ++i)
		{
			int there = adj[here][i].first;
			int nextDist = adj[here][i].second + cost;

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
	for (int i = 0; i < M; i++)
	{
		adj[0].push_back(make_pair(vSrc[i],0));
	}

	vector<int> dist = dijkstra(0);

	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		ret += dist[vDst[i]];
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("FIRETRUCKS.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> V >> E >> N >> M;

		vSrc.clear();
		vDst.clear();

		for (int i = 0; i <= V; i++)
		{
			adj[i].clear();
		}


		for (int i = 0; i<E; i++)
		{
			int src, dst, time;
			cin >> src >> dst >> time;

			adj[src].push_back(make_pair(dst, time));
			adj[dst].push_back(make_pair(src, time));
		}

		for (int i = 0; i < N; i++)
		{
			int dst;
			cin >> dst;
			vDst.push_back(dst);
		}

		for (int i = 0; i < M; i++)
		{
			int src;
			cin >> src;
			vSrc.push_back(src);
		}

		cout << solve() << endl;
	}

	return 0;
}