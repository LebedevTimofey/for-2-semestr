﻿#include<iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	bool flag = false;
	string c;
	cout << "Введите образ" << endl;
	cin >> c;
	int k = c.length();
	int* arr = new int[k + 1];
	int* mas = new int[k + 1];
	for (int i = 0; i < k; i++)
	{
		mas[i] = k - i - 1;
	}
	for (int i = k - 2; i >= 0; i--)
	{
		int count = 0;
		for (int j = 0; j < k - 1; j++)
		{
			if (c[i] == c[j])
			{
				count += 1;
				arr[i] = mas[j];
			}
		}
		if (count == 1)
		{
			arr[i] = k - i - 1;
		}
	}
	int templ1 = 0;
	int temp;
	for (int i = 0; i < k - 1; i++)
	{
		if (c[k - 1] == c[i])
		{
			templ1 += 1;
			arr[k - 1] = mas[i];
		}
	}
	if (templ1 == 0)
	{
		arr[k - 1] = k;
	}
	arr[k] = k;
	string s;
	cout << "Введите строку" << endl;
	cin.ignore(32767, '\n');
	getline(cin, s);
	int templ2;
	int j = 0;
	for (int i = c.length() - 1; i < s.length() && flag != true; j++)
	{
		if (s[i] == c[c.length() - 1])
		{
			int count1 = 0;
			for (int l = 1; l < c.length(); l++)
			{
				if (s[i - l] == c[c.length() - l])
				{
					count1 += 1;
				}
			}
			if (count1 + c.length() == c.length())
			{
				flag = true;
				templ2 = i;
				break;
			}
		}
		bool flag1 = false;
		for (int b = 0; b < c.length() && flag1 == false; b++)
		{
			if (s[i] == c[b])
			{
				i += arr[b];
				flag1 = true;
			}
		}
		if (flag1 == false)
		{
			i += c.length();
		}
	}


	if (flag == true)
	{
		for (int i = 0; i < templ2 - (c.length() - 1); i++)
		{
			cout << s[i];
		}
		for (int i = templ2 + 1; i < s.length(); i++)
		{
			cout << s[i];
		}
	}
	else
	{
		for (int i = 0; i < s.length(); i++)
		{
			cout << s[i];
		}
	}

	delete mas;
	delete arr;
	return 0;
}