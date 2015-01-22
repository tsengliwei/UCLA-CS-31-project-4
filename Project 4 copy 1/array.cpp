#include <iostream>
#include <string>
#include <cassert>
#include <algorithm> 
using namespace std;

int count(const string a[], int n, string target);
int findFirst(const string a[], int n, string target);
int moveToEnd(string a[], int n, int pos);
int firstInequality(const string a1[], int n1, const string a2[], int n2);
int removeCopies(string a[], int n);
bool subsequence(const string a1[], int n1, const string a2[], int n2);
int takeSides(string a[], int n, string barrier);

int main()
{
	string h[7] = {"Phil", "Keegan", "Morgan", "Charl", "", "Stevie", "Morgan"};

	assert(count(h, 5, "Morgan") == 1);
	assert(count(h, 7, "") == 1);
	assert(count(h, 7, "Jhonattan") == 0);
	assert(count(h, 7, "phil") == 0);
	assert(count(h, 0, "Morgan") == 0);
	assert(count(h, -5, "Morgan") == -1);

	assert(findFirst(h, 7, "Morgan") == 2);
	assert(findFirst(h, 2, "Morgan") == -1);
	assert(findFirst(h, 7, "morgan") == -1);
	assert(findFirst(h, -3, "Morgan") == -1);
	string team[5] = { "Phil", "Vijay", "Keegan", "Rickie", "Bubba" };
	assert(moveToEnd(team, 5, 1) == 1 && team[0] == "Phil" && team[1] == "Keegan" && team[2] == "Rickie" && team[3] == "Bubba" && team[4] == "Vijay");

	string g[4] = { "Phil", "Keegan", "Charl", "Stevie" };
	//cerr << firstInequality(h, 0, g, 4);
	assert(firstInequality(h, 4, g, 4) == 2);
	assert(firstInequality(h, 0, g, 4) == 0);
	assert(firstInequality(h, 4, g, 1) == 1);
	assert(firstInequality(h, -4, g, -1) == -1);
	string team2[5] = { "Phil", "Dustin", "Jhonattan", "Charl", "Rickie" };
	string people[6] = { "Phil", "Dustin", "Vijay", "Bubba" };
	assert(firstInequality(team2, 5, people, 4) == 2);  //  returns 2
	assert(firstInequality(team2, 2, people, 1) == 1);  //  returns 1


	string z[5] = { "Phil", "Keegan", "Charl","", "Stevie" };
	//assert(subsequence(h, 7, z, 5));
	string big[10] = { "Phil", "Charl", "Keegan", "Vijay", "Jhonattan", "Keegan" };

	string little1[10] = { "Charl", "Vijay", "Jhonattan" };
	bool b1 = subsequence(big, 6, little1, 3);
	assert(b1 == true);  // returns true
	string little2[10] = { "Keegan", "Charl" };
	bool b2 = subsequence(big, 6, little2, 2);
	assert(b2 == false);  // returns false
		//cerr << big[0] << " " << little2[0]; 

	string little3[10] = { "Charl", "Keegan", "Keegan" };
	bool b3 = subsequence(big, 6, little3, 3);
	assert(b3 == true); 
	string little4[10] = { "Charl", "Charl", "Keegan" };
	bool b4 = subsequence(big, 6, little4, 3);
	assert(b4 == false);
	bool b5 = subsequence(big, -6, little2, 2);
	assert(b5 == false);
	
	assert(moveToEnd(g, 4, 1) == 1 && g[1] == "Charl" && g[3] == "Keegan");
	assert(moveToEnd(h, 5, 1) == 1 && h[1] == "Morgan" && h[4] == "Keegan");
	assert(moveToEnd(g, -4, 1) == -1);

	string e[5] = { "Charl", "Charl", "Charl", "Morgan", "Morgan" };
	assert(removeCopies(e, 5) == 2 && e[1] == "Morgan" && e[0] == "Charl");
	string d[9] = {"Keegan", "Charl", "Vijay", "Vijay", "Bubba", "Bubba", "Bubba", "Vijay", "Vijay"};
	assert(removeCopies(d, 9) == 5 && d[0] == "Keegan" && d[1] == "Charl" && d[2] == "Vijay" && d[3] == "Bubba" && d[4] == "Vijay");
	//cerr << removeCopies(d, 9) << endl;
	//cerr << d[0] << endl;
	
	//assert(takeSides(h, 7, "Morgan") == 3);
	string f[6] = { "Bubba", "Morgan", "Quentin", "Charl", "Stevie", "Keegan" };
	assert(takeSides(f, 6, "Phil") == 4);
	string y[4] = { "Phil", "Morgan", "Stevie", "Keegan" };
	assert(takeSides(y, 4, "Morgan") == 1);
	//cerr << takeSides(y, 4, "Morgan") << endl;
	cout << "All tests succeeded" << endl;
}

int count(const string a[], int n, string target)
{
	int count = 0;
	if (n < 0)
	{
		return -1;
	}

	else if (n >= 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == target)
				count++;
		}
			return count;
	}
}

int findFirst(const string a[], int n, string target)
{
	if (n < 0)
	{
		return -1;
	}

	else if (count(a, n, target) == 0)
	{
		return -1;
	}

	else if (n >= 0)
	{
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == target)
			{
				num = i;
				return num;
			}
		}
	}
}

int moveToEnd(string a[], int n, int pos)
{
	if (n < 0)
	{
		return -1;
	}

	else if (n >= 0)
	{
		for (int i = pos; i < n - 1; i++)
		{
			string temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
		}	
		return pos;
	}
}

int firstInequality(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)
	{
		return -1;
	}

	else if (n1 >= 0 && n2 >= 0)
	{
		for (int i = 0, j = 0; i < n1 && j < n2; i++, j++)
		{
			if (a1[i] != a2[j])
			{
				//cerr << "a1[i] is " << a1[i] << endl << "a2[j] is " << a2[j] << endl;
				return i;
			}
		}
		return  min(n1, n2);
	}
}

int removeCopies(string a[], int n)
{
	int retain = 0;
	int copy = 0;

	if (n < 0)
	{
		return -1;
	}

	else if (n >= 0)
	{
		for (int i = 0; i < n-1; i++)
		{
			if (a[i] == a[i+1])
			{
				copy++;
			}
		}

		for (int i = 0; i < n-1; i++)
		{
			if (a[i] == a[i+1])
			{
				moveToEnd(a, n, i);
				i--;
			}
		}
	}
	retain = n - copy;
	return retain;
}

bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)
	{
		return false;
	}

	

	else if (n1 >= 0 && n2 >= 0)
	{
		int j = 0;	
		for (int i = 0; i < n2; i++)
		{
			for (; j < n1; j++)
			{
				if (a2[i] == a1[j])
				{
					break;
				}
			}
			j++;
			if (j > n1)
				{
					return false;
				}
		}
	}
	//cerr << a1[0] << " " << a2[0];
	return true;
}

int takeSides(string a[], int n, string barrier)
{
	int position = 0, position2 = 0;

	if (n < 0)
	{
		return -1;
	}

	else if (n >= 0)
	{
		for (int i = 0; i < n - 2; i++)
		{
			if (a[i] > barrier)
			{
				moveToEnd(a, n, i);
				i--;
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			if (a[i] > barrier)
			{
				position2 = i;
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (a[i] == barrier)
			{
				a[i] = a[position2 - 1];
				a[position2 - 1] = barrier;
				break;
			}
		}

		/*for (int i = 0; i < n; i++)
		{
			cerr << a[i] << " " << endl;
		}*/

		for (int i = 0; i < n; i++)
		{
			if (a[i] >= barrier)
			{
				position = i;
				return position;
			}
		}
		if (position == 0)
		{
			return n;
		}

	}
}
