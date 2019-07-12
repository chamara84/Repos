// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Given a keypad as shown in diagram, and an N digit number. List all words which are possible by pressing these numbers.

#include <iostream>
#include<vector>
#include<algorithm> 
#include<iterator>
using namespace std;

vector<string> printWord(vector<string> letters, vector<int> numbers, string currentWord, int index);
int main()
{
	int T, temp;
	vector<vector<int>> all_arr;
	vector<string> letters;
	letters.push_back("abc");
	letters.push_back("def");
	letters.push_back("ghi");
	letters.push_back("jkl");
	letters.push_back("mno");
	letters.push_back("pqrs");
	letters.push_back("tuv");
	letters.push_back("wxyz");

	int N;
	cin >> T;


	for (int i = 0; i < T; i++)
	{
		vector<int> arr;
		cin >> N;
		for (long int j = 0; j < N; j++)
		{
			cin >> temp;
			arr.push_back(temp);
		}
		all_arr.push_back(arr);
	}
	string currentWord = "";
	for (int i = 0; i < T; i++)
	{
		vector<int>arr(all_arr.at(i));
		vector<string> output = printWord(letters, arr, currentWord, arr.size()-1);
		sort(output.begin(), output.end());
		vector<string>::iterator it = output.begin();
		while (it != output.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << "\n";
	}
	cin >> temp;
	return 0;
}

vector<string> printWord(vector<string> letters, vector<int> numbers, string currentWord, int index)
{
	vector<string> combinations;
	if (index == -1)
	{
		combinations.push_back(currentWord);
		return combinations;

	}
	else
	{
		for (int i = 0; i < letters.at(numbers.at(index)-2).length(); i++)
		{
			vector<string> temp = printWord(letters, numbers, letters.at(numbers.at(index)-2).at(i) + currentWord, index - 1);
			copy(temp.begin(), temp.end(), back_inserter(combinations));
		}
		return combinations;

	}

}