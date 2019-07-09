#include<iostream>
#include<string>
#include<vector>
using namespace std;

string calculateBinary(int num);
int main()
{
	int T;
	int temp;
	string returnTemp;
	vector<int>all_arr;

	char c;

	cin >> T;


	for (int i = 0; i < T; i++)
	{

		cin >> temp;
		all_arr.push_back(temp);

	}

	for (int i = 0; i < T; i++)
	{

		temp = all_arr.at(i);
		returnTemp = calculateBinary(temp);
		cout << returnTemp << "\n";
	}


	return 0;
}


string calculateBinary(int num)

{
	string binary = "";
	while (num > 0)
	{
		if (num % 2 == 0)
		{
			binary = "0" + binary;
		}
		else
			binary = "1" + binary;
		num = num / 2;
	}
	int neededZeros = 14 - binary.size();
	while (neededZeros > 0)
	{
		binary = "0" + binary;
		neededZeros--;
	}
	return binary;
}