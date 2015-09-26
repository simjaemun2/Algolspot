#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100
int N;

int Y[MAX_N];
int X[MAX_N];
int R[MAX_N];

int longest;
struct TreeNode
{
	vector<TreeNode*> children;
};

void init()
{
	//memset(cache, -1, sizeof(cache));

	
	
}

int height(TreeNode* root)
{
	vector<int> heights;

	for (int i = 0; i < root->children.size(); i++)
	{
		heights.push_back(height(root->children[i]));
	}

	if (heights.empty())
	{
		return 0;
	}

	sort(heights.begin(), heights.end());

	if (heights.size() >= 2)
	{
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	}

	return heights.back() + 1;
}

int solve(TreeNode* root)
{
	longest = 0;

	int h = height(root);
	return max(h,longest);
}

int sqr(int x)
{
	return x*x;
}

int sqrdist(int a, int b)
{
	return sqr(Y[a] - Y[b]) + sqr(X[a] - X[b]);
}

bool encloses(int a, int b)
{
	return R[a] > R[b] && sqrdist(a, b) < sqr(R[a] - R[b]);
}

bool isChild(int parent, int child)
{
	if (!encloses(parent, child))
	{
		return false;
	}

	for (int i = 0; i < N; i++)
	{
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
		{
			return false;
		}
	}

	return true;
}

TreeNode* getTree(int root)
{
	TreeNode* ret = new TreeNode();
	
	for (int child = 0; child < N; child++)
	{
		if (isChild(root, child))
		{
			ret->children.push_back(getTree(child));
		}
	}

	return ret;
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
	freopen("FORTRESS.txt", "r", stdin);
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

		for (int i = 0; i < N; i++)
		{
			cin >> X[i] >> Y[i] >> R[i];
		}

		TreeNode* r = getTree(0);

		cout << solve(r) << endl;
	}


	return 0;
}