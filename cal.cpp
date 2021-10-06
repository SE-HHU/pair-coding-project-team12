#include"a.h"

string postfixExpression = "";
int gcd(int x, int y) 
{
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	if (x < y) swap(x, y);
	if (!(x % y)) return y;
	return gcd(y, x % y);
}
int IsNum(char h)  
{
	if (h >= '0' && h <= '9') return 1;
	return 0;
}
Num CalculateNum(Num& x, char op, Num& y)  
{
	Num ans;
	int b = x.molecule, d = y.molecule, a = x.denominator, c = y.denominator;
	if (op == '-') {
		ans.molecule = b * c - a * d;
		ans.denominator = a * c;
	}
	if (op == '+') {
		ans.molecule = b * c + a * d;
		ans.denominator = a * c;
	}
	if (op == '*') {
		ans.molecule = b * d;
		ans.denominator = a * c;
	}
	if (op == '/') {
		ans.molecule = b * c;
		ans.denominator = a * d;
	}
	return ans;
}
Num GetPostfixExpressionAnswer(string s, char seperator) 
{
	stack<Num> numStack;   //The stack used to store Num
	int tempNum = 0;       //Get num from the string , and store in it.
	int len = s.length();  
	for (int i = 0; i < len; i++) 
	{
		if (IsNum(s[i]))
		{
			tempNum = tempNum * 10 + s[i] - '0';
			if (!IsNum(s[i + 1])) 
			{
				Num insertNum;
				insertNum.molecule = tempNum;
				insertNum.denominator = 1;
				numStack.push(insertNum);
				tempNum = 0;
			}
		}
		else
		{
			if (s[i] == seperator) continue;
			Num a = numStack.top(); numStack.pop();
			Num b = numStack.top(); numStack.pop();
			a = CalculateNum(b, s[i], a);
			numStack.push(a);
		}
	}
	Num ans = numStack.top();
	int factor = 1;
	if (ans.denominator == 0 || ans.molecule == 0) factor = 1;
	else factor = gcd(ans.denominator, ans.molecule);
	ans.denominator /= factor, ans.molecule /= factor;
	return ans;
}
int CompareOperatorPriority(char op1, char op2)  
{
	if (op2 == '*' || op2 == '/') return 0;
	if (op1 == '*' || op1 == '/') return 1;
	if (op2 == '(') return 1;
	return 0;
}
void ToPostfixExpression(string s, string& postfixExpression)  
{
	postfixExpression = "";
	int lens = s.length(), cnt = 0;
	lens--;  //To delete the char"=",it is at the end of the string
	stack<char> operatorStack;  //The stack to store operator
	for (int i = 0; i < lens; i++) 
	{
		if (IsNum(s[i])) 
		{
			postfixExpression += s[i];
			if (!IsNum(s[i + 1])) postfixExpression += ' ';
		}
		else {
			if (s[i] == '(')
			{
				operatorStack.push('(');
			}
			else {
				if (s[i] == ')') 
				{
					while (operatorStack.top() != '(')
					{
						postfixExpression += operatorStack.top();
						postfixExpression += ' ';
						operatorStack.pop();
					}
					operatorStack.pop();
				}
				else 
				{
					while (!operatorStack.empty() && !CompareOperatorPriority(s[i], operatorStack.top()))
					{
						postfixExpression += operatorStack.top();
						postfixExpression += ' ';
						operatorStack.pop();
					}
					operatorStack.push(s[i]);
				}
			}
		}
	}
	while (!operatorStack.empty()) postfixExpression += operatorStack.top(), postfixExpression += 32, operatorStack.pop();
}
Num CalculateFormula(string s)  
{
	ToPostfixExpression(s, postfixExpression);
	return GetPostfixExpressionAnswer(postfixExpression, ' ');
}
