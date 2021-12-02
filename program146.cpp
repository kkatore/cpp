/*toggle bit*/

#include<iostream>

using namespace std ;

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo, int iPos)
{
	int iMask = 0x00000001;
	int iResult = 0;
	
	if((iPos < 1)||(iPos > 32))
	{
		return 0;
	}
	
	iMask = iMask << (iPos-1);
	
	iResult = iNo ^ iMask;
	
	return iResult;
		
}

int main()
{
	int iValue = 0, iRet = 0, i = 0;
	
	cout<<"Enter number\n";
	cin>>iValue;
	
	cout<<"Enter position\n";
	cin>>i;
	
	iRet = ToggleBit(iValue,i);
	
	cout<<"Updated number is: "<<iRet<<"\n";
	
	return 0;
}