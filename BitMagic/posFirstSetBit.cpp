#include<iostream>
#include<string>
#include<vector>
using namespace std;

int posFirstSetBit(int num);
int main()
{
	int T;
	int temp;
	int returnTemp;
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
		returnTemp = posFirstSetBit(temp);
		cout << returnTemp << "\n";
	}


	return 0;
}


int posFirstSetBit(int num)

{
	int setBitPos = 0;
	string binary = "";
	while (num > 0)
	{
		setBitPos++;
		if (num % 2 == 0)
		{
			binary = "0" + binary;
		}
		else
		{
			binary = "1" + binary;

			break;
		}
		num = num / 2;
	}
	int neededZeros = 14 - binary.size();
	while (neededZeros > 0)
	{
		binary = "0" + binary;
		neededZeros--;
	}
	return setBitPos;
}