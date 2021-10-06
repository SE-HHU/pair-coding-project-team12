#pragma once
#include<bits/stdc++.h>
using namespace std; 
/*store the formula*/
extern vector<string> v;
/*store the num may appeared,it includes integer and fraction*/
struct Num {
	int molecule;/*store the num molecule */
	int	denominator;/*store the num denominator */
};  
/**
*@brief				Calculate the answer of x(+,-,*,/)y
* @param x			The first num in calculation
* @param op			The operator ,it is one of the "+ - * \ "	
* @param y			The second num in calculation
* @return			Return the answer in Num
*/
Num CalculateNum(Num& x, char op, Num& y);  
/**
* @brief			Calculate the answer of the formula
* @param s			The formula need to be calculated
* @return			Return the answer in Num
*/
Num CalculateFormula(string s); 
/**
* @brief			Calculate formula and return ans in string
* @param s			The formula need to be calculated
* @return			Return the answer in string
*/
string ToString_CalculateFormula(string s);
/**
* @brief			Write the formula in the file"Exercise.txt",this function
*					Will be called multiple times
* @param s			The formula need to be write
* @param i			The num tied to the formula
* @return			none
*/
void WriteFormula(string s, int i); 
/**
* @brief			Write the answer in the file"Exercise.txt",this function
*					Will be called multiple times
* @param ans		The answer need to be write
* @param i			The num tied to the answer
* @return			none
*/
void WriteAnswer(Num ans, int i);
int gcd(int x, int y); 
/**
* @brief			Judge if the char is a num.
* @param char		The char need to be checked
* @return			Return 1 if the char is a num ,else return 0.
*/
int IsNum(char h); 
/**
* @brief				Calculate the answer of the postfix expression,
* @param s				The postfix expression need to be calculated
* @param seperator      The seperator used in postfix expression to seperate two numbers,Normally it is " ".
* @return				Return the answer in Num
*/
Num GetPostfixExpressionAnswer(string s, char seperator);  
/**
* @brief			Compare the priorrity of the two operator
* @param op1		The first operator ,it is one of the "+ - * \ "		
* @param op2		The second operator ,it is one of the "+ - * \ "		
* @return			Return 1 if op1 is prior to op2,else return 0
*/
int CompareOperatorPriority(char op1, char op2); 
/**
* @brief						Transform the formula(the first param s) into postfix expression,and store  
*								It in postfixExpression(the second param )
* @param s						The formula need to be transformed ,and it must be ended with "="
* @param postfixExpression		It is used to store the result of the transformlation
* @return						none
*/
void ToPostfixExpression(string s, string& postfixExpression); 
/**
* @brief						Check the formula meet the condition or not,the conditon includes 
*								1.the answer ofhe formula must be a integer or rue fraction.
*								2.the answer must bigger than 0,smaller than rightEdge(the second param).
*								3.the formula cannot be same with other formula in vector v.
*								If the formula meet the condition,it will be inserted in vector c.
* @param s						The formula need to be checked ,and it must be ended with "=".
* @param rightEdge				The answer of the formula must smaller than it
* @return						Return true if the formula pass the check,else return false.
*/
bool CheckFormula(string s, int rightEdge);
/**
* @brief						This function is used to random generate the formula until the the size of 
*                               vector v reached to n
* @param rightEdge				The answer of the formula must smaller than it	
* @param isParentheses		    It is 1 or 0,if it is 1,the formula will be generated with parenttheses.if it
*								is 0,the formula will be generated without parenttheses
* @return						none
*/
void RandomGenerate(int rightEdge, bool isParentheses);
/**
* @brief			Get a operator priority			
* @param op			The operator ,it is one of the "+ - * /"		
* @return			Return 1 if the operator is '+' or '-'.return 2 if the operator is '*' or '/'.			
*/
int GetOperatorPriority(char op); 
/**
* @brief			Judge if two Num is equal ,the num will be judged int struct Num.
* @param a			The first Num 
* @param b			The second Num 
* @return			If a is equal to b return 1,else return 0.
*/
int IsEqualNum(Num a, Num b); 
/**
* @brief			Judge if the char is a operator.
* @param char		The char need to be checked
* @return			Return 1 if the char is a operator ,else return 0.
*/
int IsOperator(char h);  
/**
* @brief			Judge if two postfix expression is logically equal
* @param a			The first postfix expression
* @param b			The second postfix expression
* @return			If a is logically equal to b return 1,else return 0.
*/
int IsEqualPostfixExpression(string a, string b); 
/**
* @brief			Judge if two formula is logically equal. e.x.the formula "1+3=" is logically equal
*					to the formula "3+1=".
* @param a			The first formula
* @param b			The second formula
* @return			If a is logically equal to b return 1,else return 0.
*/
int same(string a, string b); 
/**
* @brief			Calls this function when need to get the formula from the string a,
*					find the first pos of the formula in string a.
* @param a			The string a,it contains a formula,and there are some other chars before the formula.
* @return			Return the first pos of the formula in string a.
*/
int FindPos(char s[]);    
/**
* @brief						Open the file through path,read the formula and answer in two files ,then 
*								store the formula and answers in string.
* @param ExercisePath			The path of "Exercises.txt".
* @param AnswerPath				The path of "Exercises.txt".
* @return						If open two files successfully,return 0,else return -1.
*/
int ReadFile(string ExercisePath, string AnswerPath);
/**
* @brief						check the formula and answers,print correct count and detail.
* @return						none
*/
void PrintCorrect();
/**
* @brief						check the formula and answers,print wrong count and detail.
* @return						none
*/
void PrintWrong();
/**
* @brief						check the formula and answers,print repeat count and detail.
* @return						none
*/
void PrintRepeat();
/**
* @brief						Calls other functions and print check result of two files.
* @param ExercisePath			The path of "Exercises.txt".
* @param AnswerPath				The path of "Exercises.txt".
* @return						If open two files successfully,return 0,else return -1.
*/
int PrintReadResult(string ExercisePath, string AnswerPath);
