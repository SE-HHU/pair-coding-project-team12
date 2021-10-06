#include"a.h"
int GetOperatorPriority(char op)
{
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}
int IsEqualNum(Num a, Num b)
{
	if (a.denominator == b.denominator && b.molecule == a.molecule) return 1;
	return 0;
}
int IsOperator(char h)
{
	if (h == '+' || h == '-' || h == '/' || h == '*') return 1;
	return 0;
}
int IsEqualPostfixExpression(string a, string b)
{
	int na = a.length(), nb = b.length();
	char opa[4][4], opb[4][4], pree = 0; int cnta = 0, Numopa[4] = { 0 }, Numopb[4] = { 0 }, cntb = 0, cengh = 0;
	for (int i = 0; i < na; i++)
	{
		if (IsOperator(a[i]))
		{
			if (GetOperatorPriority(a[i]) != GetOperatorPriority(pree)) cengh++;
			opa[cengh][++Numopa[cengh]] = a[i];
			pree = a[i];
		}
	}
	int cenghh = cengh;
	pree = 0; cengh = 0;
	for (int i = 0; i < nb; i++)
	{
		if (IsOperator(b[i]))
		{
			if (GetOperatorPriority(b[i]) != GetOperatorPriority(pree)) cengh++;
			opb[cengh][++Numopb[cengh]] = b[i];
			pree = b[i];
		}
	}
	if (cengh != cenghh) return 0;
	for (int i = 1; i <= cengh; i++)
	{
		if (Numopa[i] != Numopb[i]) return 0;
		sort(opa[i] + 1, opa[i] + 1 + Numopa[i]);
		sort(opb[i] + 1, opb[i] + 1 + Numopb[i]);
		for (int j = 1; j <= Numopa[i]; j++)
		{
			if (opa[i][j] != opb[i][j]) return 0;
		}
	}
	int aStore[4][4], cntta[4] = { 0 }, bStore[4][4], cnttb[4] = { 0 }, ceng = 0;
	stack<int> q, p;
	int Num1 = 0;
	char pre = 0;
	for (int i = 0; i < na; i++)
	{
		if (IsNum(a[i]))
		{
			Num1 = Num1 * 10 + a[i] - '0';
			if (!IsNum(a[i + 1]))
			{
				q.push(Num1);
				p.push(1);
				Num1 = 0;
			}
		}
		else
		{
			if (!IsOperator(a[i])) continue;
			if (GetOperatorPriority(a[i]) != GetOperatorPriority(pre)) ceng++;
			int aa = q.top(), h = p.top(); p.pop(), q.pop();
			if (h) aStore[ceng][++cntta[ceng]] = aa;
			int bb = q.top(); h = p.top(); p.pop(), q.pop();
			if (h) aStore[ceng][++cntta[ceng]] = bb;
			aa = 0;
			q.push(aa);
			p.push(0);
			pre = a[i];
		}
	}
	pre = 0;
	while (q.size()) q.pop(); while (p.size()) p.pop();
	Num1 = ceng = 0;
	for (int i = 0; i < nb; i++)
	{
		if (IsNum(b[i]))
		{
			Num1 = Num1 * 10 + b[i] - '0';
			if (!IsNum(b[i + 1]))
			{
				q.push(Num1);
				p.push(1);
				Num1 = 0;
			}
		}
		else
		{
			if (!IsOperator(b[i])) continue;
			if (GetOperatorPriority(b[i]) != GetOperatorPriority(pre)) ceng++;
			int aa = q.top(), h = p.top(); p.pop(), q.pop();
			if (h) bStore[ceng][++cnttb[ceng]] = aa;
			int bb = q.top(); h = p.top(); p.pop(), q.pop();
			if (h) bStore[ceng][++cnttb[ceng]] = bb;
			aa = 0;
			q.push(aa);
			p.push(0);
			pre = b[i];
		}
	}
	for (int i = 1; i <= ceng; i++) {
		sort(aStore[i] + 1, aStore[i] + cntta[i] + 1);
		sort(bStore[i] + 1, bStore[i] + cnttb[i] + 1);
		for (int j = 1; j <= cntta[i]; j++) {
			if (aStore[i][j] != bStore[i][j]) return 0;
		}
	}
	return 1;
}
int same(string a, string b)
{
	if (!IsEqualNum(CalculateFormula(a), CalculateFormula(b))) return 0;  //When a and b have diffrent answers
	int aHaveParentheses = 0, bHaveParentheses = 0;  //To record if a or b contains parenthese or not.
	int a_len = a.length(), b_len = b.length(), aLeftParenthesesPos = 0, aRightParenthesesPos = 0, bRightParenthesesPos = 0, bLeftParenthesesPos = 0;
	for (int i = 0; i < a_len; i++)
	{
		if (a[i] == '(') aLeftParenthesesPos = i, aHaveParentheses = 1;  //the pos of left parenthese
		if (a[i] == ')') aRightParenthesesPos = i;  //the pos of right parenthese
	}
	for (int i = 0; i < b_len; i++)
	{
		if (b[i] == '(') bLeftParenthesesPos = i, bHaveParentheses = 1;
		if (b[i] == ')') bRightParenthesesPos = i;
	}
	if (aHaveParentheses)
	{
		string g = a;
		g.erase(aLeftParenthesesPos, 1), g.erase(aRightParenthesesPos - 1, 1);
		string zhuana, zhuang;
		ToPostfixExpression(a, zhuana), ToPostfixExpression(g, zhuang);
		if (IsEqualPostfixExpression(zhuana, zhuang))
		{
			a = g; aHaveParentheses = 0;
		}
	}
	if (bHaveParentheses)
	{
		string g = b;
		g.erase(bLeftParenthesesPos, 1), g.erase(bRightParenthesesPos - 1, 1);
		string zhuang, zhuanb;
		ToPostfixExpression(b, zhuanb), ToPostfixExpression(g, zhuang);
		if (IsEqualPostfixExpression(zhuanb, zhuang))
		{
			b = g; bHaveParentheses = 0;
		}
	}
	if (aHaveParentheses != bHaveParentheses)
	{
		return 0;
	}

	string aPE = "", bPE = "";  ToPostfixExpression(a, aPE); ToPostfixExpression(b, bPE);
	int aPE_len = aPE.length(), bPE_len = bPE.length(), aOperatorPos[4], bOperatorPos[4], aOperatorCnt = 0, bOperatorCnt = 0; char opa[4], opb[4];
	if (!aHaveParentheses)  //When string a does not contian parentheses
	{
		for (int i = 0; i < aPE_len; i++)
		{
			if (IsOperator(aPE[i]))
			{
				aOperatorPos[++aOperatorCnt] = i;
				opa[aOperatorCnt] = aPE[i];
			}
		}
		if (aOperatorCnt == 3 && GetOperatorPriority(opa[1]) == GetOperatorPriority(opa[3]) && GetOperatorPriority(opa[1]) == 1 && GetOperatorPriority(opa[2]) == 2)
		{
			string temp = "";
			temp += aPE.substr(aOperatorPos[1] + 2, aOperatorPos[2] - aOperatorPos[1]);
			temp += aPE.substr(0, aOperatorPos[1] + 2);
			temp += opa[3];
			aPE = temp;
		}
		for (int i = 0; i < bPE_len; i++)
		{
			if (IsOperator(bPE[i]))
			{
				bOperatorPos[++bOperatorCnt] = i;
				opb[bOperatorCnt] = bPE[i];
			}
		}
		if (bOperatorCnt == 3 && GetOperatorPriority(opb[1]) == GetOperatorPriority(opb[3]) && GetOperatorPriority(opb[1]) == 1 && GetOperatorPriority(opb[2]) == 2)
		{
			string temp = "";
			temp += bPE.substr(bOperatorPos[1] + 2, bOperatorPos[2] - bOperatorPos[1]);
			temp += bPE.substr(0, bOperatorPos[1] + 2);
			temp += opb[3];
			bPE = temp;
		}
	}
	else  //When both a and b contains parenthese
	{
		int aInParentheses_len = aRightParenthesesPos - aLeftParenthesesPos + 1, bInParentheses_len = bRightParenthesesPos - bLeftParenthesesPos + 1;  //the length of formula in parenthese
		string aInParentheses = a.substr(aLeftParenthesesPos + 1, aInParentheses_len - 1);  //the formula in a parenthese
		string bInParentheses = b.substr(bLeftParenthesesPos + 1, bInParentheses_len - 1);  //the formula in b parenthese
		if (!same(aInParentheses, bInParentheses)) return 0;
		a[aLeftParenthesesPos] = '1'; string aa;  //delete the parentheses,recorded the parentheses in 1.
		aa = a.substr(0, aLeftParenthesesPos + 1); aa += a.substr(aRightParenthesesPos + 1); ToPostfixExpression(aa, aPE);
		b[bLeftParenthesesPos] = '1'; string bb;
		bb = b.substr(0, bLeftParenthesesPos + 1); bb += b.substr(bRightParenthesesPos + 1); ToPostfixExpression(bb, bPE);
	}
	//aPE，bPE is the postfix expression transformed from a and b.
	if (IsEqualPostfixExpression(aPE, bPE)) return 1;
	return 0;
}



