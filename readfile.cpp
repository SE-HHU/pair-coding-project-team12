#include"a.h"
vector<string> v2;// Store the formula read from the "Exercises.txt".
vector<string> repeatDetail;//Store the repeat formula and its num
vector<int> correctNum;//Store the num of correct formula
vector<int> wrongNum;//Store the num of wrong formula
int correctCnt = 0, wrongCnt = 0, cnt = 1;
int FindPos(char s[])
{
	for (int i = 5; i < 100; i++) {
		if (s[i] == '(') return i;
		if (s[i] >= '0' && s[i] <= '9') return i;
	}
}
string ToString_CalculateFormula(string s)
{
	Num x = CalculateFormula(s);
	string base = "";
	if (x.denominator != 1)
		base = to_string(x.molecule) + '/' + to_string(x.denominator);
	else base = to_string(x.molecule);
	return base;
}
int ReadFile(string ExercisePath,string AnswerPath)
{
	ifstream fp1, fp2;
	fp1.open(ExercisePath, ios::in);
	fp2.open(AnswerPath, ios::in);
	if (!fp1) 
	{
		cout << "��Ŀ�ļ���ʧ�ܣ������ļ�·���Ƿ���ȷ" << endl;
		return -1;
	}
	if (!fp2)
	{
		cout << "���ļ���ʧ�ܣ������ļ�·���Ƿ���ȷ" << endl;
		return -1;
	}
	
	char formula[100];
	char answer[100];
	while (fp1.getline(formula, 100) && fp2.getline(answer, 100))
	{
		string formula2 = formula + FindPos(formula);
		string answer2 = answer + FindPos(answer);//To delete the Chinese before the string
		if (ToString_CalculateFormula(formula2) == answer2) 
		{
			correctCnt++;
			correctNum.push_back(cnt);
		}
		else 
		{
			wrongCnt++;
			wrongNum.push_back(cnt);
		}
		v2.push_back(formula2);
		cnt++;
	}
	fp1.close();
	fp2.close();
	return 0;
}
void PrintCorrect()
{
	cout << "Correct: " << correctCnt;
	if (correctCnt != 0) cout << "(";
	else cout << endl;
	for (int i = 0; i < correctNum.size(); i++)
	{
		if (i == correctNum.size() - 1)
			cout << correctNum[i] << ")" << endl;
		else cout << correctNum[i] << ", ";
	}
}
void PrintWrong()
{
	cout << "Wrong: " << wrongCnt;
	if (wrongCnt != 0) cout << "(";
	else cout << endl;
	for (int i = 0; i < wrongNum.size(); i++)
	{
		if (i == wrongNum.size() - 1)
			cout << wrongNum[i] << ")" << endl;
		else cout << wrongNum[i] << ", ";
	}
}
void PrintRepeat()
{
	bool onVisit[10000];//To record which formula has been visited.
	memset(onVisit, true, sizeof(onVisit));
	for (int i = 0; i < v2.size(); i++)
	{
		if (!onVisit[i]) continue;
		string tmp_detail = "";
		bool haveRepeat = false;
		for (int j = i + 1; j < v2.size(); j++) 
		{
			if (same(v2[i], v2[j]))
			{
				if (!haveRepeat)
				{
					string tmp_s1 = v2[i];
					tmp_s1.pop_back();
					string tmp_s2 = v2[j];
					tmp_s2.pop_back();
					tmp_detail += to_string(i + 1) + "," + tmp_s1 + "  Repeat ";
					tmp_detail += to_string(j + 1) + "," + tmp_s2 + "  ";
					onVisit[j] = false;
					haveRepeat = true;
				}
				else
				{
					string tmp_s = v2[j];
					tmp_s.pop_back();
					tmp_detail += to_string(j + 1) + "," + tmp_s + "  ";
					onVisit[j] = false;
					haveRepeat = true;
				}
			}
		}
		if (haveRepeat)
		{
			repeatDetail.push_back(tmp_detail);
		}
	}
	cout << "Repeat:" << repeatDetail.size() << endl;
	if (repeatDetail.size() > 0)//If there is not repeat,RepeatDetail will not be pritnt.
	{
		cout << "RepeatDetail:" << endl;
		for (int i = 1; i <= repeatDetail.size(); i++)
			cout << "(" << i << ")  " << repeatDetail[i - 1] << endl;
	}
}
int PrintReadResult(string ExercisePath, string AnswerPath)
{	
	int flag=ReadFile(ExercisePath, AnswerPath);
	if (flag == -1) return -1;
	PrintCorrect();
	PrintWrong();
	PrintRepeat();
	return 0;
}
