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
bool visited[NUM_ALPHABET];


void makeGraph()
{
	memset(adj, 0, sizeof(adj));

	
	for (int j = 1; j < N; j++)
	{
		int i = j - 1;
		int len = min(input[i].size(), input[j].size());

		for (int k = 0; k < len; k++)
		{
			if (input[i][k] != input[j][k])
			{
				adj[input[i][k] - 'a'][input[j][k] - 'a'] = 1;
				break;
			}
		}
	}
}

void dfs(int src)
{
	visited[src] = true;

	for (int des = 0; des < NUM_ALPHABET; des++)
	{
		if (adj[src][des] == 1 && !visited[des])
		{
			dfs(des);
		}
	}
	order.push_back(src);
}

vector<int> topologicalSort()
{
	memset(visited, false, sizeof(visited));
	order.clear();
	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		if (!visited[i])
		{
			dfs(i);
		}
	}

	reverse(order.begin(), order.end());

	for (int i = 0; i < order.size(); i++)
	{
		for (int j = i + 1; j < order.size(); j++)
		{
			if (adj[order[j]][order[i]] == 1)
			{
				return vector<int>();
			}
		}
	}

	return order;
}

void solve()
{
	makeGraph();
	
	vector<int> result = topologicalSort();

	if (result.size() == 0)
	{
		cout<< "INVALID HYPOTHESIS";
		return;
	}

	string dic = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < NUM_ALPHABET; i++)
	{
		cout << dic[result[i]];
	}

}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("DICTIONARY.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;

		input.clear();

		for (int i = 0; i<N; i++)
		{
			string s;
			cin >> s;
			input.push_back(s);
		}

		solve();

		cout << endl;
	}

	return 0;
}