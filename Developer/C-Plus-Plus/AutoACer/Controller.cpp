#include <iostream>
#include <thread>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int system(string s)
{
    char* p=new char[s.size()+8];
    memset(p,0,s.size()+8);
    strcpy(p,s.c_str());
    int ret=system(p);
    delete[] p;
    return ret;
}
char intstr[128];
char cmd[256];
int main()
{
    for(int i=1000;i<5505;i++)
    {
        sprintf(intstr,"%d",i);
        sprintf(cmd,"D:/KKK/main.exe %s",intstr);
        system(cmd);
        sprintf(cmd,"copy D:\\output_decoded.txt D:\\KKK");
        system(cmd);
        sprintf(cmd,"rename D:\\KKK\\output_decoded.txt %d_autoAC.cpp",i);
        system(cmd);
        //this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}
