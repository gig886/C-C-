#ifndef __OJ_H__
#define __OJ_H__

/*
功能:

输入:

输出:

返回:成功返回0,其它-1;
*/
//十六进制字符串转十进制字符串
int GetValue(char* strInValue, char* strOutValue);
//十六进制字符串转十进制整数
int HstrToDec(const char* strInValue, int* pDec);
//十进制字符串转十进制整数，未测试
int DecStrToDec(const char* strInValue, int *piDec);
//十进制整数转十进制字符串
int DecToDecStr(const int iDec, char* strOutValue);

#endif
