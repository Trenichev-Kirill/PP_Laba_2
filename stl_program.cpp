#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <stack>

bool CheckBrakers(std::stack <char> st);

int main()
{
	std::vector<char> vec;
	char a;
	while ((a = getchar()) != '\n')
	{
		vec.push_back(a);
	}
	for (auto i = vec.rbegin();i != vec.rend(); ++i )
	{
		std::cout <<*i;
	}
	std::cout << std::endl;
	std::list<char> list;
	while ((a = getchar()) != '\n')
	{
		list.push_back(a);
	}
	for (auto i = list.rbegin(), b = list.rend(); i != b; ++i)
	{
		std::cout << *i;
	}

	std::cout << std::endl;
	std::stack <char> st;
	while ((a = getchar()) != '\n')
	{
		st.push(a);
	}
	if (CheckBrakers(st))
	{
		std::cout << "true";
	}
	else
	{
		std::cout << "false";
	}

}

bool CheckBrakers(std::stack <char> st)
{
	int a = 0, b = 0, c = 0; // ( [ {
	while (!st.empty())
	{
		char t = st.top();
		st.pop();
		switch (t)
		{
		case '(':
			a--;
			break;
		case ')':
			a++;
			break;
		case '[':
			b--;
			break;
		case ']':
			b++;
			break;
		case '{':
			c--;
			break;
		case '}':
			c++;
			break;
		}
		if (a < 0 || b < 0 || c < 0)
		{
			return false;
		}
	}
	if (a > 0 || b > 0 || c > 0)
	{
		return false;
	}
	return true;
}
