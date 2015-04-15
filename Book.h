#pragma once
#include <iostream>
#include <fstream>


using namespace std;
const int NUM1 = 128;
const int NUM2 = 50;
class CBook
{
public:
	CBook();
	~CBook();
	CBook( char* cName,  char* cIsbn,  char* cPrice,  char* cAuthor);
	char *GetName();
	void SetName(char *cname);
	void SetIsbn(char *cisbn);
	char* GetIsbn();

	
	char* GetPrice();
	void SetPrice(char* cPrice);
	char* GetAuthor();
	void SetAuthor(char* cAuthor);
	void WriteData();
	void DeleteData(int iCount);
	void GetBookFromFile(int iCount);

	void printBookInfor()
	{
		cout <<"name:  "<< m_cName << endl;
		cout << "isbn:  " << m_cIsbn << endl;
		cout << "price:  " << m_cPrice << endl;
		cout << "author:  " << m_cAuthor << endl;
	}

private:
	char m_cName[NUM1];
	char m_cIsbn[NUM1];
	char m_cPrice[NUM2] ;
	char m_cAuthor[NUM2];
};

