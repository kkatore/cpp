/*toggle more than one bit*/

#include<iostream>

using namespace std ;

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo, int iPos1,int iPos2)
{
	int iMask1 = 0x00000001,iMask2 = 0x00000001,iMask = 0;
	int iRet = 0;
	
	if((iPos1 < 1)||(iPos1 > 32))
	{
		return 0;
	}
	
	if((iPos2 < 1)||(iPos2 > 32))
	{
		return 0;
	}
	
	iMask1 = iMask1 << (iPos1-1);
	iMask2 = iMask2 << (iPos2-1);
	
	iMask = iMask1 | iMask2;
	
	iRet = iNo ^ iMask;
	
	return iRet;
		
}

int main()
{
	int iValue = 0, iRet = 0, i = 0, j = 0;
	
	cout<<"Enter number\n";
	cin>>iValue;
	
	cout<<"Enter first position\n";
	cin>>i;
	
	cout<<"Enter first position\n";
	cin>>j;
	
	iRet = ToggleBit(iValue,i,j);
	
	cout<<"Updated number is: "<<iRet<<"\n";
	
	return 0;
}