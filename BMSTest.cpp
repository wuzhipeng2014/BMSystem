// BMSTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "WindowControl.h"
#include "Book.h"

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
#pragma region 测试类成员函数功能
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
		case 1:  //添加新书
			clearScreen();
			guideInput();
			break;

		case 2:  //浏览全部
			clearScreen();
			viewallData(1);
			break;

		case 3: //删除图书
			clearScreen();
			deleteBook();
			break;
		default:
			break;
		}
	}


	return 0;
}

