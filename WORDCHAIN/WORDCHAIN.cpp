#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
#define NUM_ALPHABET 26

int N;
vector<string> input;
vector<int> order;
int adj[NUM_ALPHABET][NUM_ALPHABET];
vector<int > indegree, outdegree;
vector<string > graph[NUM_ALPHABET][NUM_ALPHABET];


void makeGraph()
{
	memset(adj, 0, sizeof(adj));

	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		for (int j = 0; j < NUM_ALPHABET; j++)
		{
			graph[i][j].clear();
		}
	}

	indegree = outdegree = vector<int >(26, 0);

	for (int i = 0; i < N; i++)
	{
		int a = input[i][0] - 'a';
		int b = input[i][input[i].size()-1] - 'a';

		graph[a][b].push_back(input[i]);

		adj[a][b]++;

		outdegree[a]++;
		indegree[b]++;
	}
}

void getEulerCircit(int src, vector<int >& circuit)
{
	for (int des = 0; des < NUM_ALPHABET; des++)
	{
		while (adj[src][des])
		{
			adj[src][des]--;
			getEulerCircit(des,circuit);
		}
	}

	circuit.push_back(src);
}

vector<int> getEulerTrailOrCircit()
{
	vector<int > circuit;

	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		if (outdegree[i] == indegree[i] + 1)
		{
			getEulerCircit(i, circuit);
			return circuit;
		}
	}

	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		if (outdegree[i])
		{
			getEulerCircit(i, circuit);
			return circuit;
		}
	}

	return circuit;
}

bool checkEuiler()
{
	int plus1 = 0, minus1 = 0;

	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		int delta = outdegree[i] - indegree[i];

		if (delta < -1 || 1 < delta)
		{
			return false;
		}

		if (delta == 1)
		{
			plus1++;
		}

		if (delta == -1)
		{
			minus1++;
		}
	}

	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve()
{
	makeGraph();

	if (!checkEuiler())
	{
		return "IMPOSSIBLE";
	}

	vector<int> circuit = getEulerTrailOrCircit();

	if (circuit.size() != input.size() + 1)
	{
		return "IMPOSSIBLE";
	}

	reverse(circuit.begin(), circuit.end());

	string ret;

	for (int i = 1; i < circuit.size(); i++)
	{
		int a = circuit[i - 1], b = circuit[i];

		if (ret.size())
		{
			ret += " ";
		}

		ret += graph[a][b].back();

		graph[a][b].pop_back();
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("WORDCHAIN.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		input.clear();

		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			input.push_back(s);
		}
		cout << solve() << endl;
	}

	return 0;
}