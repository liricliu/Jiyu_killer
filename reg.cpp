#include<iostream>
#include<"atlbase.h"

int main(){
	HKEY hKEY;  
	LPCTSTR data_Set=_T("HARDWARE\\DESCRIPTION\\System\\BIOS\\");  
	long ret0, ret1;  
	DWORD dataType;  
	DWORD dataSize;  
	char data[100] = {0};  
	//char *ami = "American Megatrends Inc.";  
	//char *award="Award Software International, Inc.";  
	char biosVendor[100];  
	memset(biosVendor, 0, 100);  
  
	ret0 = RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_Set, NULL, KEY_READ, &hKEY);  
if(ret0 != ERROR_SUCCESS)        //如果无法打开hKEY,则中止程序的执行  
{  
    printf("获取注册表项失败，请联系作者\n");  
    return 1;  
}  
  
ret1 = RegQueryValueEx(hKEY, _T("BIOSVendor"), NULL, &dataType, (LPBYTE)data, &dataSize );  
if(ret1 != ERROR_SUCCESS)       //如果无法打开hKEY,则中止程序的执行  
{  
    printf("Error #RegQueryValueEx !!\n");  
    return 1;  
}  
  
printf("Data Type:%d\n", dataType);  
printf("Data Size:%d\n", dataSize);  
printf("data: ");  // 为毛这里分每个字节来打印，而不是直接puts什么的。  
  
// 因为键值数据每个字符中间都是0x00 = “/0”，so  puts只能输出一个字符。我也是调试才看到的，还以为是API参数错误呢。  
for (unsigned i = 0, j = 0; i < dataSize; i += 2, j++)  
{  
    printf("%c", data[i]);  
    memcpy(biosVendor + j, data + i, 1);  
}  
printf("\n");  
  
printf("BIOS Vendor: %s\n", biosVendor);  //   你看明白我是怎么看主机BIOS固件厂商的了吧  
  
RegCloseKey(hKEY);        // 程序结束前要关闭已经打开的 hKEY。  
system("pause");  
return 0;
}
