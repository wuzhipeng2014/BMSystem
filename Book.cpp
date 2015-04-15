#include "stdafx.h"
#include "Book.h"



CBook::CBook()
{	
	//默认情况下对数组进行初始化
	memset(m_cName, '\0', NUM1*sizeof(char)-1);
	memset(m_cIsbn, '\0', NUM1*sizeof(char)-1);
	memset(m_cPrice, ' ', NUM2*sizeof(char));
	memset(m_cAuthor, ' ', NUM2*sizeof(char));
	m_cName[NUM1 - 1] = '\0';
	m_cIsbn[NUM1 - 1] = '\0';
	m_cPrice[NUM2 - 1] = '\0';
	m_cAuthor[NUM2 - 1] = '\0';
}


CBook::~CBook()
{
	
}
CBook::CBook( char* cName,  char* cIsbn,  char* cPrice,  char* cAuthor)
{
	strncpy_s(m_cName, cName, NUM1);
	strncpy_s(m_cIsbn, cIsbn, NUM1);
	strncpy_s(m_cPrice, cPrice, NUM2);
	strncpy_s(m_cAuthor, cAuthor, NUM2);
}
char* CBook::GetName()
{
	return m_cName;
}
void CBook::SetName(char* cName)
{
	strncpy_s(m_cName, cName, NUM1);
}
char* CBook::GetIsbn()
{
	return m_cIsbn;
}
void CBook::SetIsbn(char* cIsbn)
{
	strncpy_s(m_cIsbn, cIsbn, NUM1);
}
char* CBook::GetPrice()
{
	return m_cPrice;
}
void CBook::SetPrice(char* cPrice)
{
	strncpy_s(m_cPrice, cPrice, NUM2);
}
char* CBook::GetAuthor()
{
	return m_cAuthor;
}
void CBook::SetAuthor(char* cAuthor)
{
	strncpy_s(m_cAuthor, cAuthor, NUM2);
}

void CBook::WriteData()
{
	ofstream fs;
	try
	{
	
	 fs.open("data.txt",ios::app|ios::binary);
	 fs.write(m_cName, NUM1);
	 fs.write(m_cIsbn,NUM1);
	 fs.write(m_cPrice, NUM2);
	 fs.write(m_cAuthor, NUM2);
	}
	catch (...)
	{
		throw("file error occured");
		fs.close();
	}
	fs.close();

}

void CBook::GetBookFromFile(int iCount)
{
	ifstream fs;
	char cName[NUM1];
	char cIsbn[NUM1];
	char cPrice[NUM2];
	char cAuthor[NUM2];
	try
	{
		fs.open("data.txt", ios::binary);
		fs.seekg(0, ios::end);
		int pos = fs.tellg();
		if (pos>=(iCount) * 2 * (NUM1 + NUM2))
		{
			fs.seekg((iCount-1) * 2 * (NUM1 + NUM2), ios::beg);
			fs.read(cName, NUM1);
			if (fs.tellg()>0)
			{
				strncpy_s(m_cName, cName, NUM1);
			}
			fs.read(cIsbn, NUM1);
			if (fs.tellg()>0)
			{
				strncpy_s(m_cIsbn, cIsbn, NUM1);
			}

			fs.read(m_cPrice, NUM2);
			fs.read(m_cAuthor, NUM2);
		}			
	}
	catch (...)
	{
		throw("file error occurred.");
		fs.close();
	}
	fs.close();
}
void CBook::DeleteData(int iCount)
{
	const int Book_len = 2 * (NUM1 + NUM2);
	char tempArray[Book_len];
	ofstream os;
	os.open("tmp.txt");
	fstream fs;
	fs.open("data.txt", ios::binary | ios::in | ios::out);
	fs.seekg(0, ios::end);
	int	iDatacount = fs.tellg() / Book_len;
	if (iCount>iDatacount&&iCount<0)
	{
		cout << "input number error." << endl;
		/*throw("input number error.");*/
		fs.close();
	}
	else
	{
#pragma region 简单的将要删除的图书信息覆盖，但是无法更改文件大小
		//将icount之后的内容拷贝到一个临时的文件内
		/*fs.seekg((iCount)*Book_len, ios::beg);
		int iCountLast = iCount - 1;
		
		while (iCount<iDatacount)
		{
			fs.read(tempArray, Book_len);
			fs.seekg(iCountLast*Book_len,ios::beg);
			fs.write(tempArray, Book_len);
			iCount += 1;
			fs.seekg(iCount,ios::beg);
			iCountLast += 1;	
			
		}
		memset(tempArray, 0, Book_len);
		fs.seekg(iCountLast*Book_len, ios::beg);
		fs.write(tempArray, Book_len);	
		fs.close();*/
#pragma endregion

		//将要删除的图书删除，（分别将其他图书信息拷贝到一个临时文件中）
		fs.seekg(0, ios::beg);
		int count = 1;
		while (count++<iCount)
		{
			fs.read(tempArray, Book_len);
			os.write(tempArray, Book_len);
		}
		fs.seekg((iCount)*Book_len, ios::beg);
		while (iCount++<iDatacount)
		{
			fs.read(tempArray, Book_len);
			os.write(tempArray, Book_len);
		}
		fs.close();
		os.close();
		remove("data.txt");
		rename("tmp.txt", "data.txt");
	}
}