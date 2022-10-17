#include <iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int arr[10][10];

int count1 = 0;

void convert(int x, int y)
{	
	if (arr[x][y] == 0)
	{
		arr[x][y] = 1;

		convert(x + 1, y);
		convert(x - 1, y);
		convert(x, y + 1);
		convert(x, y - 1);
		count1++;						
	}	
}

void see(int arr[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
		cout << arr[i][j]<<" ";
					if (j == 9)
					cout << "\n";	
		}
	}
	cout << endl;
}

void main()
{	
	int i=0, j=0;
	int count2 = 0;
	int num;
	
	vector<int> sum1;

	//srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			num = rand() % 2;
			if (num== 0)
				arr[i][j]=num;
			else
				arr[i][j]=num;
			if (arr[0][j] == 0 || arr[9][j] == 0)
			{
				arr[0][j] = 1;
				arr[9][j] = 1;
			}
		}
		if (arr[i][0] == 0 || arr[i][9] == 0)
		{
			arr[i][0] = 1;
			arr[i][9] = 1;
		}
	}

	cout << "1 = Black, 0 = White" << endl;
	cout << "\nbefore" << endl;
	see(arr);

		for ( i = 0; i < 10; i++)
		{
			for ( j = 0; j < 10; j++)
			{
				if (arr[i][j] == 0)
				{
					convert(i, j);					
					sum1.push_back(count1);					
					count1 = 0;
					count2++;																				
				}
			}
		}
		
		cout << "After" << endl;
		see(arr);
		cout << count2 << " white areas of ";
		for (vector<int>::iterator a = sum1.begin(); a != sum1.end()-1; ++a)
		{
			cout << *a << ", ";
		}
		/*for (int a:sum1)
		{
			cout << a << ", ";
		}*/
		cout << "and " << *(sum1.end()-1) << " cells." << endl;
}
