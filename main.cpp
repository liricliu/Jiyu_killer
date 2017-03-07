//我们在测试的时候使用dev-cpp进行编译，由于匆忙，所以没有上传某些需要自己下载的头文件。
//该版本算一个0.1版，后续会推出带注释，并且优化代码风格的更新，敬请期待。
//将推出lite版本分支，lite版本将由Liric Liu进行维护。
//下面开始信息声明：
/**************************************************************************
Name:Jiyu Killer
Branch:full function
Writer:Neverisk Tian
Version:0.1 alpha
Copyright(c)2017 Neverisk Tian
From No.2 High School Affliated to East China Nomal University Zizhu Campus
**************************************************************************/
#include <io.h>    
#include <WINDOWS.H>
#include "psapi.h"    
#include "stdio.h"  
#include <tlhelp32.h>  
#include <iostream>
#include <string>

#define max 100 

using namespace std;

string a,temporder;
char order[1000];
int PID;


void zhuan( string a )
{
	int len = a.size();
	
	for(int i=0;i<len;i++)
		order[i] = a[i];
		
	return;
}

string to_string(int n)  
{  
    int m=n;  
    int i=0,j=0;  
    char s[max];  
    char ss[max];  
    while(m>0)  
    {  
        s[i++]= m%10 + '0';  
        m/=10;  
    }  
    s[i]='\0';  
  
    i=i-1;  
    while(i>=0)  
    {  
        ss[j++]=s[i--];  
    }  
    ss[j]='\0';  
  
    return ss;  
}  

BOOL FindProcess()  
{  
    int i=0;  
    PROCESSENTRY32 pe32;  
    pe32.dwSize = sizeof(pe32);   
    HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	  
    if(hProcessSnap == INVALID_HANDLE_VALUE)  
    {  
        i+=0;  
    }
	  
    BOOL bMore = ::Process32First(hProcessSnap, &pe32); 
	 
    while(bMore)  
    {  
    	a = pe32.szExeFile;
        if(a=="StudentMain.exe")  
        {  
            i=1;
            PID = pe32.th32ProcessID;
        }  
        bMore = ::Process32Next(hProcessSnap, &pe32);  
    }  
    return i;
}  





int main()
{
	char systemloc[] ="C:\\Windows\\System32\\Sethc.exe";
	
	temporder += "ntsd -c q -p ";
	
	
	
	if(access("D:/bat/start.bat",0))
		system("start D:/bat/start.bat");
	
	
	
	if(  access("C:/Windows/System32/Sethc.exe",0) ==-1 )
	{
		MessageBox( NULL,"检测到您是第一次使用,或使用后重启了,现在已安装","通知",MB_YESNO );
		MessageBox( NULL,"版本V1.0，制作人：efzzz_1904_ty","通知",MB_YESNO );
		
		CopyFile( "Killer.exe" , systemloc , TRUE);
		CopyFile( "ntsd.exe" , "C:\\Windows\\ntsd.exe" , TRUE );
    
	}

	FindProcess();
	if ( FindProcess( ) )
	{
		temporder += to_string( PID ) ;
		zhuan (temporder);		
		cout<<"PID is :"<<PID;
		system(order);		//存在
		
	}
	else
		if ( MessageBox ( NULL , "请您选择是否打开学生端" , "请选择" , MB_YESNO ) == IDYES )    //不存在
			system("start d:/bat/学生端程序.lnk");  //点击是 
		else
			return 0;//点击否 
	
	return 0;
}
