#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#define MAX_N 100
#define MOD 10000000

#define _MAX(a,b) (a)>(b)?(a):(b)
#define _MIN(a,b) (a)<(b)?(a):(b)

//#define _ABS(v) (+1 | ((v) >> (sizeof(int)*CHAR_BIT - 1)))*(v);


int N;
int nn[MAX_N];
int cache[MAX_N + 1][MAX_N + 1];


void init()
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			cache[i][j] = -1;
		}
	}
}


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int arr[],int l, int h)
{
	int x = arr[h];
	int i = l - 1;

	for (int j = l; j < h; j++)
	{
		if (x < arr[j])
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[h]);

	return i + 1;
}

void quicksort(int arr[], int l, int h)
{
	int p = partition(arr, l, h);
	quicksort(arr, l, p - 1);
	quicksort(arr, p + 1, h);
}

int slen(char* a)
{
	char* eos = a;

	while (*eos++);

	return (int)(eos - a - 1);
}


//return plus, 0, minus
int stmp(char* a, char* b)
{
	int ret = 0;

	while (!(ret = *(unsigned char*)a - *(unsigned char*)b) && *b)
	{
		a++;
		b++;
	}

	return ret;
}

bool isOpposite(int a, int b)
{
	if ((a^b) < 0)
		return true;
	return false;
}

float InvSqrt(float x)
{
	float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f375a86 - (i >> 1);
	x = *(float*)&i;
	x = x*(1.5f - xhalf*x*x);
	x = x*(1.5f - xhalf*x*x);
	x = x*(1.5f - xhalf*x*x);
	x = 1 / x;
	return x;

	/*
int main(){

float a,i;

cin >> a;

a=a*1000000;

for(i=1;i*i>a;i++){}

cout << i/1000;

}
	*/
}