// BMSTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "WindowControl.h"
#include "Book.h"

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
#pragma region �������Ա��������
	/*char name[NUM1] = "c++ primer";
	char isbn[NUM1] = "123456";
	char price[NUM2] = "96";
	char author[NUM2] = "wangfeng";
	CBook a(name, isbn, price, author);
	a.WriteData();
	CBook b;
	b.GetBookFromFile(1);
	b.printBookInfor();
	CBook c;
	c.DeleteData(1);
	c.GetBookFromFile(1);
	c.printBookInfor();*/
#pragma endregion


	
	while (true)
	{
		setScreenGrid();
		SetSyscaption();
		showWelcome();
		showRootMenu();
		switch (getSelect())
		{
		case 1:  //�������
			clearScreen();
			guideInput();
			break;

		case 2:  //���ȫ��
			clearScreen();
			viewallData(1);
			break;

		case 3: //ɾ��ͼ��
			clearScreen();
			deleteBook();
			break;
		default:
			break;
		}
	}


	return 0;
}

