#include<iostream>
using namespace std;

int** fun1(int* x, int* y, int* r, int** a, int* n, int* z);
int** fun2(int* x, int* y, int* r, int** a, int* n);

int main()
{
	int n, m;
	int x, y, r, z;
	cin >> n >> m;

	int** array1 = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		array1[i] = new int[n];
	}

	int** array = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	for (size_t k = 0, i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			k++;
			array[i][j] = k;
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		cin >> x >> y >> r >> z;
		array1 = fun1(&x, &y, &r, array, &n, &z);
		
	}
	for (size_t i = 0; i < 1; i++)
	{
		for (size_t j = 0; j < n; j++)
			cout << array1[i][j] << " ";
	}
		
	for (size_t i = 1; i < n; i++)
	{
		cout << endl;
		for (size_t j = 0; j < n; j++)
		{
			cout << array1[i][j] << " ";
		}
		
	}
	for (size_t i = 0; i < n; i++)
		delete[] array[i];
	delete[] array;
	for (size_t i = 0; i < n; i++)
		delete[] array1[i];
	delete[] array1;
	getchar();
}


int** fun1(int* x, int* y, int* r, int** a, int* n, int* z)
{
	int m = *n;
	int x1 = *x - 1;
	int y1 = *y - 1;
	static int flag[510][510] = { 0 };
	static int flag1[510][510] = { 0 };
	int** p = new int* [m];
	for (size_t i = 0; i < m; i++)
	{
		p[i] = new int[m];
	}
	for (size_t i = x1 - *r; i < x1 + *r + 1; i++)
	{
		for (size_t j = y1 - *r; j < y1 + *r + 1; j++)
		{
			flag[i][j] = a[i][j];
			flag1[i][j] = a[i][j];
		}
	}
	if (*z == 0)
	{
		for (size_t i = x1 - *r; i < x1 + *r + 1; i++)
		{
			for (size_t j = y1 - *r; j < y1 + *r + 1; j++)
			{
				flag1[x1 - y1 + j][x1 + y1 - i] = flag[i][j];
			}
		}
	}
	if (*z == 1)
	{
		for (size_t i = x1 - *r; i < x1 + *r + 1; i++)
		{
			for (size_t j = y1 - *r; j < y1 + *r + 1; j++)
			{
				flag1[x1 + y1 - j][x1 - y1 + i] = flag[i][j];
			}
		}
	}
	for (size_t i = x1 - *r; i < x1 + *r + 1; i++)
	{
		for (size_t j = y1 - *r; j < y1 + *r + 1; j++)
		{
			flag[i][j] = flag1[i][j];
			a[i][j] = flag[i][j];
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			p[i][j] = a[i][j];
		}
	}
	return p;
}

int** fun2(int* x, int* y, int* r, int** a, int* n)
{
	int m = *n;
	int x1 = *x - 1;
	int y1 = *y - 1;
	static int flag2[510][510] = { 0 };
	static int flag3[510][510] = { 0 };
	int** q = new int* [m];
	for (size_t i = 0; i < m; i++)
	{
		q[i] = new int[m];
	}
	for (size_t i = x1 - *r; i < x1 + *r + 1; i++)
	{
		for (size_t j = y1 - *r; j < y1 + *r + 1; j++)
		{
			flag2[i][j] = a[i][j];
			flag3[i][j] = a[i][j];
		}
	}
	for (size_t i = x1 - *r; i < x1 + *r + 1; i++)
	{
		for (size_t j = y1 - *r; j < y1 + *r + 1; j++)
		{
			//flag[j][*r - i + 1] = flag1[i][j];
			flag3[x1 + y1 - j][x1 - y1 + i] = flag2[i][j];
		}
	}
	for (size_t i = x1 - *r; i < x1 + *r + 1; i++)
	{
		for (size_t j = y1 - *r; j < y1 + *r + 1; j++)
		{
			flag2[i][j] = flag3[i][j];
			a[i][j] = flag2[i][j];
		}
	}
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			q[i][j] = a[i][j];
		}
	}
	return q;
}

 