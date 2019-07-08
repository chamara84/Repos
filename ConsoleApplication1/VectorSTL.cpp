#include <algorithm>
#include<vector>
#include <iostream>
using namespace std;
void add_to_vector(vector<int>& A, int x);
void sort_vector_asc(vector<int>& A);
void reverse_vector(vector<int>& A);
int size_of_vector(vector<int>& A);
void sort_vector_desc(vector<int>& A);
void print_vector(vector<int>& A);
int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		vector<int> A;
		int q;
		cin >> q;
		while (q--)
		{
			char c;
			cin >> c;

			if (c == 'a')
			{
				int x;
				cin >> x;
				add_to_vector(A, x);
			}
			if (c == 'b')
			{
				sort_vector_asc(A);
			}
			if (c == 'c')
			{
				reverse_vector(A);
			}
			if (c == 'd')
			{
				cout << size_of_vector(A) << " ";
			}
			if (c == 'e')
			{
				print_vector(A);

			}
			if (c == 'f')
			{
				sort_vector_desc(A);
			}

		}
		cout << endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below methods*/
/*inserts an element x at
the back of the vector A */
void add_to_vector(vector<int>& A, int x)
{
	A.push_back(x);
	//Your code here
}
/*sort the vector A in ascending order*/
void sort_vector_asc(vector<int>& A)
{
	sort(A.begin(), A.end());
	//Your code here
}
/*reverses the vector A*/
void reverse_vector(vector<int>& A)
{
	reverse(A.begin(), A.end());
	//Your code here
}
/*returns the size of the vector  A */
int size_of_vector(vector<int>& A)
{
	return A.size();
	//Your code here
}
/*sorts the vector A in descending order*/
void sort_vector_desc(vector<int>& A)
{
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	//Your code here
}
/*prints space separated
elements of vector A*/
void print_vector(vector<int>& A)
{
	vector<int>::iterator it = A.begin();
	while (it != A.end())
	{
		cout << *it << " ";
		it++;
	}
	//Your code here
}
