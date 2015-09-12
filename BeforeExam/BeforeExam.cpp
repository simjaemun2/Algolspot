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

float fsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));   // 1st iteration
	//y = y * (threehalfs - (x2 * y * y));   // 2nd iteration, this can be removed

	return 1 / y;
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


bool isPrime[MAX_N + 1];
void eratosthenes()
{
	for (int i = 1; i <= N; i++)
	{
		isPrime[i] = true;
	}

	isPrime[0] = isPrime[1] = false;

	int sqrtn = int(fsqrt(N));

	for (int i = 2; i <= sqrtn; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <= N; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main(int argc, char** argv)
{
	init();

	//cout << InvSqrt(2.0);

	
	return 0;
}