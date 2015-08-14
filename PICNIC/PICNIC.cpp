#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>


using namespace std;

#define MAX_N 10


int N, M;
bool map[MAX_N][MAX_N];
bool checked[MAX_N];


void init()
{
	memset(checked, false, sizeof(checked));
	memset(map, false, sizeof(map));
}

int solve()
{
	int ret = 0;

	int index = -1;

	for (int i = 0; i < N; i++)
	{
		if (!checked[i])
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		return 1;
	}

	for (int i = index + 1; i < N; i++)
	{
		if (!checked[i] && map[index][i])
		{
			checked[index] = checked[i] = true;
			ret += solve();
			checked[index] = checked[i] = false;
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("PICNIC.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> M;

		init();

		for (int i = 0; i<M; i++)
		{
			int a, b;
			cin >> a >> b;

			map[a][b] = map[b][a] = true;
		}


		cout << solve() << endl;
	}

	return 0;
}