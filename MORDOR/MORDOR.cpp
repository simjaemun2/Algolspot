#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int _INT_MAX = 2000000000;
int N, Q;

vector<int> minRoad, maxRoad;

struct RMQ
{
	int n;

	vector<int> rangeMin;

	RMQ(const vector<int>& array)
	{
		n = array.size();

		rangeMin.resize(n * 4);

		init(array, 0, n-1,1);
	}

	int init(const vector<int>& array, int left, int right, int node)
	{
		if (left == right)
		{
			return rangeMin[node] = array[left];
		}

		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if (right < nodeLeft || nodeRight < left)
		{
			return _INT_MAX;
		}

		if (left <= nodeLeft && nodeRight <= right)
		{
			return rangeMin[node];
		}

		int mid = (nodeLeft + nodeRight) / 2;
		
		return min(query(left, right, node * 2, nodeLeft, mid)
			, query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n - 1);
	}
};

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("MORDOR.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		cin >> N >> Q;

		minRoad.clear();
		maxRoad.clear();

		for (int i = 0; i<N; i++)
		{
			int input;
			cin >> input;

			minRoad.push_back(input);
			maxRoad.push_back(-input);
		}

		RMQ minRMQ(minRoad);
		RMQ maxRMQ(maxRoad);

		for (int i = 0; i < Q; i++)
		{
			int left, right;
			cin >> left >> right;

			int rangeMin = minRMQ.query(left, right);
			int rangeMax = -maxRMQ.query(left, right);

			cout << rangeMax - rangeMin << endl;
		}

		//cout << solve() << endl;
	}

	return 0;
}




