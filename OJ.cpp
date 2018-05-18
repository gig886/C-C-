#include <stdlib.h>
#include <string.h>
#include "oj.h"


/*
功能:

输入:

输出:

返回:成功返回0,其它-1;

*/
//十六进制字符串转十进制整数
int HstrToDec(const char* strInValue, int* pDec)
{
	int i = 0;
	int iDec = 0;
	if (!strInValue || strlen(strInValue) < 2 || (strInValue[1] != 'x' && strInValue[1] != 'X'))
	{
		return -1;
	}
	for (i = 2; i < strlen(strInValue); i++)
	{
		if (strInValue[i] >= '0' && strInValue[i] <= '9')
		{
			iDec = iDec * 16 + strInValue[i] - '0';
		}
		else if (strInValue[i] >= 'a' && strInValue[i] <= 'f')
		{
			iDec = iDec * 16 + 10 + strInValue[i] - 'a';
		}
		else if (strInValue[i] >= 'A' && strInValue[i] <= 'F')
		{
			iDec = iDec * 16 + 10 + strInValue[i] - 'A';
		}
		else//字符大于F也就是说不是十六进制，或者其他符号
		{
			return -1;
		}
	}
	*pDec = iDec;	
	return 0;
}
//十进制字符串转十进制整数
int DecStrToDec(const char* strInValue, int *piDec)
{
	int i = 0;
	int iTemp = 0;
	if (!strInValue)
	{
		return -1;
	}
	for (i = strlen(strInValue) - 1; i >= 0; i--)
	{
		if (!i && strInValue[i] == '-')//负数
		{
			iTemp *= -1;
		}
		if (strInValue[i] >= '0' && strInValue[i] <= '9')
		{
			iTemp += iTemp * 10 + strInValue[i] - '0';
		}
		else
		{
			return -1;
		}
	}
	*piDec = iTemp;
	return 0;
}
//十进制整数转十进制字符串
int DecToDecStr(const int iDec, char* strOutValue)
{
	int iTemp = 0;
	int iBuf = iDec;
	int i = 0;
	int j = 0;
	if (!strOutValue)
	{
		return -1;
	}
	if (!iDec)
	{
		strOutValue[0] = '0';
		strOutValue[1] = '\0';
		return 0;
	}
	while (iBuf)
	{
		iBuf /= 10;
		i++;
	}
	j = i;
	iBuf = iDec;
	if (0 > iBuf)//负数
	{
		iBuf *= -1;
		while (iBuf)
		{
			iTemp = iBuf % 10;
			strOutValue[i] = '0' + iTemp;
			iBuf /= 10;
			i--;
		}
		strOutValue[i] = '-';
		strOutValue[j + 1] = '\0';
	}
	else
	{
		while (iBuf)
		{
			i--;
			iTemp = iBuf % 10;
			strOutValue[i] = '0' + iTemp;
			iBuf /= 10;
		}
		strOutValue[j] = '\0';
	}
	return 0;
}

int GetValue(char* strInValue, char* strOutValue)
{
	int i = 0;
	int iNum = 0;
	//确保入参有效
	if (!strInValue || !strOutValue || strlen(strInValue) < 2 || (strInValue[1] != 'x' && strInValue[1] != 'X'))
	{
		return -1;
	}
	if (HstrToDec(strInValue, &iNum))
	{
		return -1;
	}
	if (DecToDecStr(iNum, strOutValue))
	{
		return -1;
	}
	return  0;
}
