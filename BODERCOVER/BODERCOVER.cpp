#include <iostream>
#include <string>

using namespace std;


#define MAX_HW 20
int H, W;
int map[MAX_HW][MAX_HW];
int numWhite;

int type[4][3][2] =
{
	{ { 0,0 },{ 0,1 },{ 1,0 } },
	{ { 0,0 },{ 0,1 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,-1 } }
};

bool check(int y, int x, int t, int cover)
{
	bool c = true;

	for (int i = 0; i < 3; i++)
	{
		int cy = y + type[t][i][0];
		int cx = x + type[t][i][1];

		if (cy < 0 || cy >= H || cx < 0 || cx >= W)
		{
			c = false;
		}
		else if ((map[cy][cx] += cover) > 1)
		{
			c = false;
		}
	}

	return c;
}

int solve()
{
	int y = -1;
	int x = -1;

	for (int i = 0; i < H && y == -1; i++)
	{
		for (int j = 0; j < W && y == -1; j++)
		{
			if (!map[i][j])
			{
				y = i;
				x = j;
			}
		}
	}

	if (y == -1)
	{
		return 1;
	}

	int ret = 0;

	for (int i = 0; i < 4; i++)
	{
		if (check(y, x, i, 1))
		{
			ret += solve();
		}

		check(y, x, i, -1);
	}


	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("BOARDCOVER.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> H >> W;

		numWhite = 0;

		for (int i = 0; i<H; i++)
		{
			string s;
			cin >> s;

			for (int j = 0; j < W; j++)
			{
				if (s[j] == '#')
				{
					map[i][j] = 1;
				}
				else
				{
					map[i][j] = 0;
					numWhite++;
				}
			}
		}

		if (numWhite % 3 != 0 || numWhite == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << solve() << endl;
		}
	}

	return 0;
}