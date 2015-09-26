#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 200000
int N;
int A, B;
int minHeap[MAX_N + 1];
int hMinSize;
int maxHeap[MAX_N + 1];
int hMaxSize;
int progression;

void init()
{
	//memset(cache, -1, sizeof(cache));
	progression = 1983;
	hMinSize = 0;
	hMaxSize = 0;
}

int getProgression()
{
	int ret = progression;
	progression = (progression * (long long)A + B) % 20090711;
	return ret;

}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push_minHeap(int heap[], int newValue)
{
	heap[hMinSize++] = newValue;

	int idx = hMinSize - 1;

	while (idx > 0 && heap[(idx - 1) / 2] > heap[idx])
	{
		swap(&heap[(idx - 1) / 2], &heap[idx]);
		idx = (idx - 1) / 2;
	}
}

void push_maxHeap(int heap[], int newValue)
{
	heap[hMaxSize++] = newValue;

	int idx = hMaxSize - 1;

	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx])
	{
		swap(&heap[(idx - 1) / 2], &heap[idx]);
		idx = (idx - 1) / 2;
	}
}

void pop_maxHeap(int heap[])
{
	heap[0] = heap[--hMaxSize];
	int here = 0;

	while (true)
	{
		int left = 2 * here + 1;
		int right = 2 * here + 2;

		int next = here;

		if (left >= hMaxSize)
		{
			break;
		}

		if (heap[next] < heap[left])
		{
			next = left;
		}
		
		if (right < hMaxSize && heap[next] < heap[right])
		{
			next = right;
		}

		if (next == here)
		{
			break;
		}

		swap(&heap[next], &heap[here]);

		here = next;
	}
}

void pop_minHeap(int heap[])
{
	heap[0] = heap[--hMinSize];
	int here = 0;

	while (true)
	{
		int left = 2 * here + 1;
		int right = 2 * here + 2;

		int next = here;

		if (left >= hMinSize)
		{
			break;
		}

		if (heap[next] > heap[left])
		{
			next = left;
		}

		if (right < hMinSize && heap[next] > heap[right])
		{
			next = right;
		}

		if (next == here)
		{
			break;
		}

		swap(&heap[next], &heap[here]);

		here = next;
	}
}

int solve()
{
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		if (hMaxSize == hMinSize)
		{
			push_maxHeap(maxHeap, getProgression());
		}
		else
		{
			push_minHeap(minHeap, getProgression());
		}

		if (hMinSize > 0 && hMaxSize > 0 && maxHeap[0] > minHeap[0])
		{
			int a = maxHeap[0];
			int b = minHeap[0];

			pop_minHeap(minHeap);
			pop_maxHeap(maxHeap);

			push_maxHeap(maxHeap, b);
			push_minHeap(minHeap, a);
		}

		ret = (ret + maxHeap[0]) % 20090711;
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
	freopen("RUNNINGMEDIAN.txt", "r", stdin);
#endif

	cin >> C;

	for (tc = 0; tc < C; tc++)
	{
		cin >> N >> A >> B;

		init();

		cout << solve() << endl;
	}


	return 0;
}