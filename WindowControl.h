#pragma once
#include <iostream>
#include <iomanip>
#include "Book.h"
#define CMD_COLS 80
#define CMD_LINES 25

using namespace std;


void setScreenGrid()
{
	char sysSetBUff[80];
	sprintf_s(sysSetBUff, "mode con cols=%d lines=%d", CMD_COLS, CMD_LINES);
	system(sysSetBUff);
}

void SetSyscaption()
{
	system("title BMPTest");
}

void showWelcome()
{
	for (size_t i = 0; i < 7; i++)
	{
		cout << endl;
	}
	cout << setw(40);
	cout << "*****************" << endl;
	cout << endl;
	cout << setw(40);
	cout << "**ͼ�����ϵͳ**" << endl;
	cout << endl;
	cout << setw(40);
	cout << "*****************" << endl;
}

void clearScreen()
{
	system("cls");
}

void showRootMenu()
{
	cout << endl;
	cout << setw(40);
	cout << ">>>��ѡ����<<<" << endl;
	cout << endl;
	cout << setw(38);
	cout << "1.  �������" << endl;
	cout << endl;
	cout << setw(38);
	cout << "2.  ���ȫ��" << endl;
	cout << endl;
	cout << setw(38);
	cout << "3.  ɾ��ͼ��" << endl;
}

int getSelect()
{
	char buff[256];
	gets_s(buff);
	return atoi(buff);
}

void waitUser()
{
	cout << endl;
	int iCommend = 0;
	cout << "enter. �������˵�  q. �˳�" << endl;
	char buff[256];
	gets_s(buff);
	if (atoi(buff)==0)
	{
		system("exit");
	}
}

void guideInput()
{
	setScreenGrid();
	for (size_t i = 0; i < 7; i++)
	{
		cout << endl;
	}
	cout << setw(40);
	cout << "**��ӭ������������ģ��**" << endl;
	char name[NUM1];
	char isbn[NUM1];
	char price[NUM2];
	char author[NUM2];
	setw(38);
	cout << "������������" << endl;
	setw(38);
	gets_s(name);
	cout << "������ISBN��" << endl;
	gets_s(isbn);
	setw(38);
	cout << "������۸�" << endl;
	gets_s(price);
	setw(38);
	cout << "����������:" << endl;
	gets_s(author);
	CBook a(name, isbn, price, author);
	a.WriteData();
	cout << endl;
	setw(40);
	cout << "write finish" << endl;
	waitUser();
}

int getCountBook()
{
	fstream fs;
	fs.open("data.txt", ios::in | ios::out | ios::binary);
	fs.seekg(0, ios::end);
	int countBook = fs.tellg() / (2 * (NUM1 + NUM2));
	fs.close();
	return countBook;
}
void viewallData(int cur_p);
void waitView(int cur_p)
{
	char buf[256];
	gets_s(buf);
	switch (buf[0])
	{
	case 'n':
		viewallData(++cur_p);
	case 'q':
		system("exit");
	default:
		break;
	}
}

void viewallData(int cur_p=1)
{
	setScreenGrid();
	for (size_t i = 0; i < 7; i++)
	{
		cout << endl;
	}
	cout << setw(40);
	cout << "**��ӭ�������ͼ��ģ��**" << endl;

	
	int countBook = getCountBook();
	int pageCount = countBook / 3;
	if (countBook%3>0)
	{
		pageCount += 1;
	}
	int cur_page = 1;
	setw(24);
	cout << "�ܹ�" << pageCount << "ҳ  ";
	cout << "��ǰ" << cur_p << "ҳ  ";
	cout << "n ��һҳ   ";
	cout << "q ����" << endl;
	//��ô����ÿҳ�������Ŀ��Ŀ

	/*for (size_t i =	1; i <= countBook; i++)
	{
		cout << endl;
		cout << "<<    book" << i << endl;
		CBook a;
		a.GetBookFromFile(i);
		a.printBookInfor();
	}*/
	int cur_bookCount = (cur_p - 1)*3;
	for (size_t i = 1; cur_bookCount+ i <= countBook&&i<4; i++)
	{
		cout << endl;
		cout << "<<    book" << i << endl;
		CBook a;
		int bookIndex = cur_bookCount + i;
		a.GetBookFromFile(bookIndex);
		a.printBookInfor();
	}

	cout << endl;
	waitView(cur_p);
	/*waitUser();*/
}

void deleteBook()
{
	setScreenGrid();
	for (size_t i = 0; i < 7; i++)
	{
		cout << endl;
	}
	cout << setw(40);
	cout << "**��ӭ����ɾ��ͼ��ģ��**" << endl;
	setw(40);
	cout << "����������ɾ����ͼ��ţ�" << endl;
	cout << endl;
	setw(40);
	cout << "q �˳�" << endl;
	cout << endl;
	char buffer[256];
	gets_s(buffer);
	if (buffer[0]=='q')
	{
		system("exit");
	}
	else
	{
		int ideleteIndex = atoi(buffer);
		CBook d;
		d.DeleteData(ideleteIndex);

		cout << "delete finish ." << endl;
		cout << endl;
	}
   
	waitUser();
}