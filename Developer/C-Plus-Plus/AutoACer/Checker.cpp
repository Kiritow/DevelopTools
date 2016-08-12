#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int getfilesize(const char* Filename)
{
    FILE* fp=fopen(Filename,"r");
    if(fp==nullptr) return -1;
    else
    {
        fseek(fp,0L,SEEK_END);
        int L=ftell(fp);
        fclose(fp);
        return L;
    }
}

char name[256];
int main()
{
    for(int i=1000;i<5505;i++)
    {
        sprintf(name,"D:\\KKK\\%d_autoAC.cpp",i);
        int L=getfilesize(name);
        if(L>=0&&L<10)
        {
            sprintf(name,"RENAME D:\\KKK\\%d_autoAC.cpp %d_empty.txt",i,i);
            printf("Deleting %d...\n",i);
            system(name);
        }
    }
    return 0;
}
