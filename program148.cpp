/*count number of on bit without using % and / operator*/

#include<iostream>

using namespace std ;

typedef unsigned int UINT;

UINT CountBit(UINT iNo)
{
	int i = 0,iCnt = 0;
	int iMask = 0x00000001;
	
	for(i = 1; i < 32; i++,iMask = iMask << 1)
	{
		if((iNo & iMask) == iMask)
		{
			iCnt++;
		}
	}
	return iCnt;

}

int main()
{
	int iValue = 0, iRet = 0;
	
	cout<<"Enter number\n";
	cin>>iValue;
		
	iRet = CountBit(iValue);
	
	cout<<"Count of ON Bit are: "<<iRet<<"\n";
	
	return 0;
}