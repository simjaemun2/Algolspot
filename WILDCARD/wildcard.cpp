#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory.h>
#include <string>
#include <vector>


using namespace std;

#define MAX_LENGTH 100

string wildcard;
string filename;

int N;
int cache[MAX_LENGTH + 1][MAX_LENGTH + 1];


void init()
{
	memset(cache, -1, sizeof(cache));
}

int solve(int wIndex, int fIndex)
{

	if (wIndex == wildcard.length() && fIndex == filename.length())
	{
		return 1;
	}
	
	int& ret = cache[wIndex][fIndex];
	
	if (ret != -1)
	{
		return ret;
	}

	ret = 0;

	if (wIndex < wildcard.length() || fIndex < filename.length())
	{
		switch (wildcard[wIndex])
		{
		case '*':
			for (int i = fIndex; i < filename.length() + 1; i++)
			{
				ret += solve(wIndex + 1, i);
			}

			break;

		case '?':
			ret += solve(wIndex + 1, fIndex + 1);
			break;

		default:
			if (wildcard[wIndex] == filename[fIndex])
			{
				ret += solve(wIndex + 1, fIndex + 1);
			}
			else
			{
				return ret = 0;
			}

			break;
		}
	}
	
	return ret;
}

int partition(vector<string>& v, int l, int h)
{
	string pivot = v[h];

	int i = l - 1;

	for (int j = l; j < h; j++)
	{
		if (v[j] < pivot)
		{
			i++;
			std::swap(v[i], v[j]);
		}
	}

	std::swap(v[i + 1], v[h]);

	return i + 1;
}

void quicksort(vector<string>& v,int l, int h)
{
	if (l < h)
	{
		int p = partition(v, l, h);
		quicksort(v, l, p - 1);
		quicksort(v, p + 1, h);
	}
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("wildcard.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> wildcard;

		cin >> N;

		vector<string> v;

		for (int i = 0; i < N; i++)
		{
			cin >> filename;

			init();

			if (solve(0,0))
			{
				v.push_back(filename);
			}
		}

		quicksort(v,0,v.size()-1);

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << endl;
		}
	}

	return 0;
}