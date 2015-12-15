#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int MAX_HEAP_SIZE = 100;
int heap[MAX_HEAP_SIZE];
int heapSize;

int N;

void init()
{
	heapSize = 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push_heap(int v)
{
	heap[heapSize++] = v;
	int idx = heapSize - 1;

	while (idx > 0 && heap[idx] < heap[(idx - 1) / 2])
	{
		swap(&heap[idx], &heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void pop_heap()
{
	heap[0] = heap[--heapSize];
	heap[heapSize] = 0;

	int here = 0;

	while (true)
	{
		int left = here * 2 + 1;
		int right = here * 2 + 2;

		if (left >= heapSize)
		{
			break;
		}

		int next = here;

		if (heap[next] > heap[left])
		{
			next = left;
		}

		if (right < heapSize && heap[next] > heap[right])
		{
			next = right;
		}

		if (here == next)
		{
			break;
		}

		swap(&heap[here], &heap[next]);

		here = next;
	}
}

int solve()
{
	int ret = 0;

	while (heapSize > 1)
	{
		int min1 = heap[0];
		pop_heap();
		
		int min2 = heap[0];
		pop_heap();

		ret += min1 + min2;

		push_heap(min1 + min2);
	}

	return ret;
}

int main(int argc, char** argv)
{
	int tc, T;

#ifdef _WIN32
	freopen("STRJOIN.txt", "r", stdin);
#endif

	cin >> T;
	for (tc = 0; tc < T; tc++)
	{
		init();

		cin >> N;

		for (int i = 0; i<N; i++)
		{
			int v;
			cin >> v;
			push_heap(v);
		}

		cout << solve() << endl;
	}

	return 0;
}