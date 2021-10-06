#include"a.h"
void WriteFormula(string s, int i)
{
	ofstream ofs;
	ofs.open("Exercises.txt", ios::app);
	ofs << i << "." << "四则运算题目" << "  ";
	ofs << s << endl;
	ofs.close();
}
void WriteAnswer(Num ans, int i)
{
	ofstream ofs;
	ofs.open("Answers.txt", ios::app);
	ofs << i << "." << "答案" << "  ";
	if (ans.denominator != 1)
		ofs << ans.molecule << '/' << ans.denominator << endl;
	else ofs << ans.molecule << endl;
	ofs.close();
}
