#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> preorder;
vector<int> inorder;

//double cache[MAX_N + 1][MAX_D + 1];

void init()
{
	//memset(cache, -1, sizeof(cache));
	
	preorder.clear();
	inorder.clear();
}

vector<int> slice(const vector<int>& v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

void solve(const vector<int>& p, const vector<int>& i)
{
	if (p.empty())
	{
		return;
	}

	int N = p.size();

	int root = p[0];

	int L = find(i.begin(), i.end(), root) - i.begin();

	int R = N - L - 1;

	solve(slice(p, 1, L + 1), slice(i, 0, L));
	solve(slice(p, L + 1, N), slice(i, L + 1, N));

	cout << root << ' ';
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
	freopen("TRAVERSAL.txt", "r", stdin);
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
		cin >> N;

		init();

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			preorder.push_back(a);
		}

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			inorder.push_back(a);
		}

		solve(preorder, inorder);
		cout << endl;
	}


	return 0;
}