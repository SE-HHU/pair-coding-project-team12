#include"a.h"
bool CheckFormula(string s, int rightEdge)
{
	int denominator = CalculateFormula(s).denominator;
	int molecule = CalculateFormula(s).molecule;
	if (denominator == 0) return false;
	if (denominator != 1)
	{
		if (molecule < 0 || denominator < 0) return false;
		if (molecule > denominator) return false;
		if (molecule >= rightEdge) return false;
		if (denominator >= rightEdge) return false;
	}
	if (denominator == 1)
	{
		if (molecule < 0) return false;
		if (molecule >= rightEdge) return false;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (same(s, v[i])) return false;
	}
	return true;
}
void RandomGenerate(int rightEdge, bool isParentheses)
{
	string s;
	int opNum = rand() % 3 + 1;//Control how many operators in the formula.
	int op1 = rand() % 4;
	int op2 = rand() % 4;
	int op3 = rand() % 4;
	int parenthesesPos = 0;//It controls the pos where parentheses appear.
	int num1 = rand() % (rightEdge - 1) + 1;
	int num2 = rand() % (rightEdge - 1) + 1;
	int num3 = rand() % (rightEdge - 1) + 1;
	int num4 = rand() % (rightEdge - 1) + 1;
	if (isParentheses == 1 && opNum == 2) parenthesesPos = rand() % 2 + 1;
	if (isParentheses == 1 && opNum == 3) parenthesesPos = rand() % 3 + 1;
	if (parenthesesPos == 1) s = s + "(";
	s = s + to_string(num1);

	if (op1 == 0) s = s + "+";
	if (op1 == 1) s = s + "-";
	if (op1 == 2) s = s + "*";
	if (op1 == 3) s = s + "/";

	if (parenthesesPos == 2) s = s + "(";
	s = s + to_string(num2);
	if (parenthesesPos == 1) s = s + ")";
	if (opNum >= 2)
	{
		if (op2 == 0) s = s + "+";
		if (op2 == 1) s = s + "-";
		if (op2 == 2) s = s + "*";
		if (op2 == 3) s = s + "/";
		if (parenthesesPos == 3) s = s + "(";
		s = s + to_string(num3);
		if (parenthesesPos == 2) s = s + ")";
		if (opNum == 3)
		{
			if (op3 == 0) s = s + "+";
			if (op3 == 1) s = s + "-";
			if (op3 == 2) s = s + "*";
			if (op3 == 3) s = s + "/";
			s = s + to_string(num4);
			if (parenthesesPos == 3) s = s + ")";
		}
	}
	s = s + "=";
/*   If the formula s is legal and is not same with 
	 other formula in the vector v,then push it in v,
	 and write it in"Exercise.txt",write its answer in
	 "Answers.txt".                             
*/	 
	if (CheckFormula(s, rightEdge))
	{
		v.push_back(s);
		WriteFormula(s, v.size());
		WriteAnswer(CalculateFormula(s), v.size());		
	}
}
