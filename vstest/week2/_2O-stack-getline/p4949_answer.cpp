// #include "bits/stdc++.h"
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string s;

bool isBalance(string _input)
{
	stack<char> stk;

	for (char i : _input)
	{
		// 유효하지 않은 문자는 건너뛴다
		if (i != '[' && i != ']' && i != '(' && i != ')')
			continue;

		if (i == '[' || i == '(')
		{
			stk.push(i);
		}
		else if (i == ']' || i == ')')
		{
			if (stk.empty())
				return false;

			char top = stk.top();
			stk.pop();

			if ((top == '(' && i != ')') || (top == '[' && i != ']'))
				return false;
		}
	}

	// 모든 여는 괄호에 대해 닫는 괄호가 있어야 함
	return stk.empty();
}

int main()
{
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (getline(cin, s))
	{
		if (s == ".")
			break;

		if (isBalance(s))
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}
