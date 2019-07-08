#include<iostream>
#include<string>
#include<vector>
using namespace std;

string removeDup(string temp);

int main()
{
	int T;
	string temp;
	string returnTemp;
	vector<string>all_arr;

	char c;

	cin >> T;


	for (int i = 0; i < T; i++)
	{
		temp.clear();
		cin >> temp;
		all_arr.push_back(temp);

	}

	for (int i = 0; i < T; i++)
	{
		temp.clear();
		temp = all_arr.at(i);
		returnTemp = removeDup(temp);
		cout<< returnTemp <<"\n";
	}

	cin.get(c);

	return 0;
}

string removeDup(string temp)
{
	string functemp;
	if (temp=="\0" ||temp.size()==1)
		return temp;
	else
	{
		if (temp.at(0) == temp.at(1))
		{
			functemp = temp.substr(2, temp.size() - 1);
			return temp[0] + removeDup(functemp);
		}
		else
		{
			functemp = temp.substr(1, temp.size() - 1);
			return temp[0] + removeDup(functemp);
		}
		
				

	}
}

