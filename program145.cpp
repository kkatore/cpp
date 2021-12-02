#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

using namespace std;

class MarvellousFile
{
public:
	char Fname[30];
	int fd;
	
	MarvellousFile(char * Name)      // constructor
	{
		cout<<"Inside Constructor\n";
		strcpy(Fname,Name);
		fd = open(Fname,O_RDWR);
	}
	
	~MarvellousFile()               // destructor
	{
		cout<<"Inside Destructor\n";
		close(fd);
	}
	
	void Display()
	{
		int iRet = 0;
		char Buffer[10];
		
		lseek(fd,0,0);
		
		cout<<"Data from file is:\n";
		while((iRet = read(fd,Buffer,10))!= 0)
		{
			write(1,Buffer,iRet);
		}
		
		cout<<"\n";
	}
	
	int CapitalCount()
	{
		int iRet = 0, iCnt = 0, i = 0;
		char Buffer[10];
		
		lseek(fd,0,0);
		
		while((iRet = read(fd,Buffer,10)) != 0)
		{
			for(i = 0; i < iRet; i++)
			{
				if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
				{
					iCnt++;
				}
			}
		}
		return iCnt;
		
	}
	
	int SmallCount()
	{
		int iRet = 0, iCnt = 0, i = 0;
		char Buffer[10];
		
		lseek(fd,0,0);
		
		while((iRet = read(fd,Buffer,10)) != 0)
		{
			for(i = 0; i < iRet; i++)
			{
				if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
				{
					iCnt++;
				}
			}
		}
		return iCnt;
		
	}
	int DigitCount()
	{
		int iRet = 0, iCnt = 0, i = 0;
		char Buffer[10];
		
		lseek(fd,0,0);
		
		while((iRet = read(fd,Buffer,10)) != 0)
		{
			for(i = 0; i < iRet; i++)
			{
				if((Buffer[i] >= '0') && (Buffer[i] <= '9'))
				{
					iCnt++;
				}
			}
		}
		return iCnt;
		
	}
	
	
};

int main()
{
	char Name[30];
	int iRet = 0;
	
	cout<<"Enter name of File\n";
	cin>>Name;
	
	MarvellousFile obj(Name);
	
	obj.Display();
	
	iRet = obj.CapitalCount();
	cout<<"Capital letter are: "<<iRet<<"\n";
	
	iRet = obj.SmallCount();
	cout<<"Small letter are: "<<iRet<<"\n";
	
	iRet = obj.DigitCount();
	cout<<"Digit are: "<<iRet<<"\n";
		
	return 0;
}

