#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
using namespace std;

struct FenwickTree
{
	vector<int> tree;

	FenwickTree(int n) : tree(n + 1) {}

	int sum(int pos)
	{
		pos++;

		int ret = 0;

		while (pos > 0)
		{
			ret += tree[pos];
			pos &= (pos - 1);
		}

		return ret;
	}

	void add(int pos, int val)
	{
		++pos;

		while (pos < tree.size())
		{
			tree[pos] += val;

			pos += (pos & -pos);
		}
	}
};


int N;
vector<int> input;

long long countMoves(const vector<int>& A)
{
	FenwickTree tree(1000000);
	long long ret = 0;

	for (int i = 0; i < A.size(); i++)
	{
		ret += tree.sum(999999) - tree.sum(A[i]);
		tree.add(A[i], 1);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;
	ios::sync_with_stdio(false);
#ifdef _WIN32
	freopen("MEASURETIME.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N;
		input.clear();


		for (int i = 0; i<N; i++)
		{
			int a;
			cin >> a; 
			input.push_back(a);
		}

		cout << countMoves(input) << endl;
	}

	return 0;
}