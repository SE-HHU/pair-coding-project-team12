#include"a.h"
vector<string> v;
int main() {
	srand(time(NULL));
	int n = 100;
	int method = 1;
	int rightEdge=100;
	bool isParentheses=1;
	while (true)
	{
		cout << "请选择需使用的功能，并输入对应代号" << endl;
		cout << "1.生成题目" << endl;
		cout << "2.对给定的题目与答案进行检查" << endl;
		cout << "3.联系开发者" << endl;
		cout << "4.退出程序" << endl;
		cin >> method;
		if (method == 4)
		{
			cout << "谢谢使用！" << endl;
			return 0;
		}
		if (method == 3)
		{
			cout << "欢迎广大用户向开发者反映问题。" << endl;
			cout << "开发者QQ：0000000000" << endl;
			continue;
		}
		if (method == 1) {
			while (true)
			{
				cout << "请输入所需生成算式数量：" << endl;
				cin >> n;
				if (n <= 0)
				{
					cout << "所需生成算式数量应大于0,请重新输入。" << endl;
					continue;
				}
				if (n > 1e4) 
				{
					cout << "所需生成算式数量过多,请重新输入。" << endl;
					continue;
				}
				break;
			}
			while (true)
			{
				cout << "请输入算式数据范围，生成数据的大小将在该数以内。" << endl;
				cin >> rightEdge;
				if (rightEdge <= 0)
				{
					cout << "数据范围应大于0,请重新输入。" << endl;
					continue;
				}
				if (rightEdge > 1e4)
				{
					cout << "数据范围过大,请重新输入。" << endl;
					continue;
				}
				break;
			}
			cout << "如需所生成算式具有小括号运算请输入1，否则请输入0。" << endl;
			cin >> isParentheses;
			ofstream ofs, ofs2;
			ofs.open("Exercises.txt", ios::trunc);
			ofs2.open("Answers.txt", ios::trunc);
			ofs.close();
			ofs2.close();//To ensure "Exercises.txt" and "Answers.txt" are empty when open them.
			time_t st, et;
			st = time(NULL);
			while (v.size() < n&& time(NULL) - st < 10) RandomGenerate(rightEdge, isParentheses);
			et = time(NULL);
			if (et - st >= 10)//To limit the runningtime of the funciton in 10 seconds.
			{
				cout << "运行时间过长，请修改参数后重试" << endl;
				cout << "对应不完整题目文件与答案文件均已在根目录下生成。" << endl;
			}
			else
			{
				for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
				{
					cout << *it << endl;
				}
				cout << "已生成完成。" << endl;
				cout << "对应题目文件与答案文件均已在根目录下生成。" << endl;
			}
			int continueFlag = 0;
			cout << "继续使用请输入1，退出程序请输入0。" << endl;
			cin >> continueFlag;
			if (continueFlag==1)
			{
				continue;
			}
			else
			{
				cout << "谢谢使用！" << endl;
				return 0;
			}
		}
		if (method == 2)
		{
			string ExercisePath = "C:\pairproject2\PairProject\Exercises.txt";
			string AnswerPath = "C:\pairproject2\PairProject\Answers.txt";

			while(true)
			{
				cout << "请输入题目文件所在路径。" << endl;
				cin >> ExercisePath; 
				cout << "请输入答案文件所在路径。" << endl; 
				cin >> AnswerPath;
				int flag=PrintReadResult(ExercisePath, AnswerPath);
				if (flag != -1) break;
			}

			
			int continueFlag = 0;
			cout << "已检查完成。" << endl;
			cout << "继续使用请输入1，退出程序请输入0。" << endl;
			cin >> continueFlag;
			if (continueFlag==1)
			{
				continue;
			}
			else
			{
				cout << "谢谢使用！" << endl;
				return 0;
			}
		}
		cout << "请重新输入正确的功能代码！" << endl;
		cout << "功能列表如下:" << endl;
	}
	
	
}
