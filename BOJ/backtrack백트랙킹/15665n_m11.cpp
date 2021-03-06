#include <iostream>
using namespace std;

int arr[8];
int printarr[8];
int n, m;

void	sort_up(int arr[8], int num) // sort(arr, arr+n) algorithm
{
	int tmp;

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				//cout << arr[i] << arr[j] << " ";
			}
		}
	}
}

void	recv(int lev)
{
	if (lev == m)
	{
		for (int i = 0; i< m; i++)
			cout << printarr[i] << " ";
		cout << "\n";
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (printarr[lev] != arr[i])
		{
			printarr[lev] = arr[i];
			recv(lev + 1);
		}
	}
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort_up(arr, n);
	recv(0);
}
