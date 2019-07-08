#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n, q, k;
	int** varArray;
	cin >> n >> q;
	varArray = new int* [n];
	int **qArray=new int *[q];
	for (int j = 0; j < n; j++)
	{
		cin >> k;
		int *array = new int [k];
		varArray[j] = array;
		for (int l = 0; l < k; l++)
		{
			cin >> array[l];
		}
	}
	for (int p = 0; p < q; p++)
	{
		qArray[p] = new int[2];
		cin >> *qArray[p] >> *(++qArray[p]);
	}

	for (int p = 0; p < q; p++)
	{
		cout << *(varArray[p] + qArray[p][1]) << "\n";
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

