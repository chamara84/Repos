
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n, int k) {
	unsigned long int temp = 0;

	if (n.size() == 1 && k == 1) {
		temp = stoi(n) * k;
		return (int)temp;
	}
	else {
		temp = 0;
		string::iterator it = n.begin();
		for (it = n.begin(); it != n.end(); it++)
			temp += (*it - '0');
		temp *= k;
		return superDigit(to_string(temp), 1);
	}

}




int main()
{
	

	string nk_temp;
	getline(cin, nk_temp);

	vector<string> nk = split_string(nk_temp);

	string n = nk[0];

	int k = stoi(nk[1]);

	int result = superDigit(n, k);

	cout << result << "\n";

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
		return x == y and x == ' ';
		});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
