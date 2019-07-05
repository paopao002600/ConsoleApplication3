
#include "pch.h"
#include <iostream>
#include<string>
#include<cstring>
#include <regex>

using namespace std;



bool isCharAndNumic(const string &str) {
	//正则表达式判断输入字符是否在a-z与0-9之间
	regex rx("[a-z0-9]+");
	bool bl = std::regex_match(str.begin(), str.end(), rx);
	return bl;
}

bool orderFunction(int i, int j) { return (i > j); }


int main()
{
	//读取字符串
	bool isWrong = true;
	int size;										//字符串长度
	string str;										//输入字符串
	const char * character = NULL;
	const char* a = new char;						//字符串常量
	a = "0123456789";

	while (isWrong) {
		cout << "input :" << endl;
		cin >> str;
		size = str.size();								//获得字符串长度
		character = str.c_str();			//string转换为char
			//对输入字符进行校验
		if (size < 10) {
			if (isCharAndNumic(str) == 0) {
				cout << "Your input is wrong!!!" << endl;
			}
			else {
				break;
			}
		}
		else {
			cout << "Your input is more than 10 characters." << endl;
		}
	}

	/*test*/
	cout << " the length of characters:" << size << endl;
	cout << "character:";
	for (int i = 0; i < size; i++) {
		cout << character[i] << " ";
	}
	cout << endl;
	/*test*/
	/****************************************************输入字符串检验结束**********************************************************/
	char * judgement = new char[size];
	for (int i = 0; i < size; i++) {

		judgement[i] = character[i];
	}


	//最小基数判断
	int baseNumber = size;				//出现字符的个数		
	int Hex = 0;						//进制基数
	//检查字符串中重复次数
	int *count = new int[size];
	char *temp = new char[size];
	for (int i = 0; i < size; i++) {
		count[i] = 0;
		for (int j = 0; j < size; j++)
			if (temp[j] == judgement[i]) { //判断是否重复
				baseNumber--;
				break;
			}
			else if (judgement[i] == judgement[j]) { //计算重复
				count[i]++;
				temp[i] = judgement[i];
			}
	}
	for (int i = 0; i < size; i++) {
		if (count[i] != 0) {
			cout << temp[i] << ":" << count[i] << endl;
		}
	}

	//重复次数排序
	int *order = new int[size];
	order = count;
	cout << "order:";
	for (int i = 0; i < size; i++) {
		sort(order, order + size, orderFunction);
		cout << " " << order[i];
	}
	cout << "baseNumber" << baseNumber << endl;
	//最小秒数计算（加入判断条件，基数>1）
	char *matchList = new char[size];	//存放最小可能对应数列
	/*matchList = NULL;*/
	for (int i = 0; i < size; i++) {
		matchList[i] = NULL;
	}
	//字符串转换
	if (baseNumber <= 1) {
		//字符串输入0或输入全部字符相同时，所有字符最小值为1，进制为二进制
		Hex = 2;
		for (int i = 0; i < size; i++) {
			judgement[i] = a[1];
			/***********************************/
			cout << "The same judgment: ";
			for (int i = 0; i < size; i++) {
				cout << judgement[i] << endl;
			}
			/***********************************/
		}
	}
	else {
		//检验输入字符是否有重复元素
		if (order[0] > 1) {
			//给对应字符赋值
			for (int i = 0; i < baseNumber; i++) {
				for (int j = 0; j < baseNumber; j++) {
					if (order[i] == count[j]) {
						if (matchList[j] == NULL) {
							matchList[j] = a[i];
							/******************************/
							cout << "*************************matchList: ";
							cout << matchList[j] << endl;

							/******************************/
						}
						else {
							break;
						}
					}
				}

			}
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < baseNumber; j++) {
					if (judgement[i] == temp[j]) {
						judgement[i] = matchList[j];
						if (judgement[0] == 0) {
							matchList[j] = a[1];
							judgement[0] = a[1];
							for (int t = 0; t < baseNumber; t++) {
								if (matchList[j] == 1) {
									matchList[j] = a[0];
								}
							}
					}
				}
			}
			

			}
			if (baseNumber <= 2) {
				//二进制
				Hex = 2;
			}
			else if (baseNumber <= 6) {
				//六进制
				Hex = 6;
			}
			else if (baseNumber <= 8) {
				//八进制
				Hex = 8;
			}
			else {
				//十进制
				Hex = 10;
			}
			/******************************/
			cout << "normal judgment: ";
			for (int i = 0; i < size; i++) {
				cout << judgement[i];
			}
			cout << endl;
			cout << "Hex: " << Hex << endl;
			/******************************/
		}
		else {
			//输入字符没有重复元素
			judgement[0] = a[1];	//初始字符不为0
			judgement[1] = a[0];
			for (int i = 2; i < size; i++) {
				judgement[i] = a[i];
			}

			if (size <= 2) {
				//二进制
				Hex = 2;
			}
			else if (size <= 6) {
				//六进制
				Hex = 6;
			}
			else if (size <= 8) {
				//八进制
				Hex = 8;
			}
			else {
				//十进制
				Hex = 10;
			}

			/******************************/
			cout << "Different judgment: ";
			for (int i = 0; i < size; i++) {
				cout << judgement[i];
			}
			cout << endl;
			cout << "Hex: " << Hex << endl;
			/******************************/
		}



	}


	return 0;
}
