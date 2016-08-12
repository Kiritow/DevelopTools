#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
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
char buffer[409600];
char code[409600];

void Deal()
{
    FILE* fp=fopen("D:/xxx.txt","r");
    FILE* ofp=fopen("D:/output_re.txt","w");
    memset(buffer,0,409600);
    while(fgets(buffer,409600,fp)>0)
    {
        if(strstr(buffer,"<pre><code>")==NULL) {memset(buffer,0,409600);continue;}
        else break;
    }
    char* p=buffer;
    char* q;
    string finalcode;
    while(1)
    {
        if(strstr(p,"</div>")<strstr(p,"<span")) finalcode+='\n';
        p=strstr(p,"<span");
        if(p==nullptr) break;
        p=strstr(p,">")+1;
        q=strstr(p,"</span>");
        memset(code,0,409600);
        strncpy(code,p,q-p);
        finalcode+=code;
        p=q+7;
    }
    fprintf(ofp,"%s\n",finalcode.c_str());
    fclose(fp);
    fclose(ofp);
}
void htmldecode()
{
    FILE* fp=fopen("D:/output_re.txt","r");
    FILE* ofp=fopen("D:/output_decoded.txt","w");
    int c;
    while((c=fgetc(fp))!=EOF)
    {
        if(c=='&')
        {
            int a=fgetc(fp);
            if(a=='a')
            {
                int b=fgetc(fp);
                if(b=='m')
                {
                    fputc('&',ofp);
                    fgetc(fp);//p
                }
                else //p
                {
                    fputc('\'',ofp);
                    fgetc(fp);//o
                    fgetc(fp);//s
                }
            }
            else if(a=='c')
            {
                int b=fgetc(fp);
                if(b=='e')
                {
                    fprintf(ofp,"￠");
                    fgetc(fp);//n
                    fgetc(fp);//t
                }
                else //o
                {
                    fprintf(ofp,"©");
                    fgetc(fp);//p
                    fgetc(fp);//y
                }
            }
            else if(a=='e')
            {
                fprintf(ofp,"€");
                fgetc(fp);//u
                fgetc(fp);//r
                fgetc(fp);//o
            }
            else if(a=='d')
            {
                fprintf(ofp,"÷");
                fgetc(fp);//i
                fgetc(fp);//v
                fgetc(fp);//i
                fgetc(fp);//d
                fgetc(fp);//e
            }
            else if(a=='g')
            {
                fputc('>',ofp);
                fgetc(fp);//t
            }
            else if(a=='l')
            {
                fputc('<',ofp);
                fgetc(fp);//t
            }
            else if(a=='n')
            {
                fputc(' ',ofp);
                fgetc(fp);//b
                fgetc(fp);//s
                fgetc(fp);//p
            }
            else if(a=='p')
            {
                fprintf(ofp,"£");
                fgetc(fp);//o
                fgetc(fp);//u
                fgetc(fp);//n
                fgetc(fp);//d
            }
            else if(a=='q')
            {
                fputc('\"',ofp);
                fgetc(fp);//u
                fgetc(fp);//o
                fgetc(fp);//t
            }
            else if(a=='r')
            {
                fprintf(ofp,"®");
                fgetc(fp);//e
                fgetc(fp);//g
            }
            else if(a=='s')
            {
                fprintf(ofp,"§");
                fgetc(fp);//e
                fgetc(fp);//c
                fgetc(fp);//t
            }
            else if(a=='t')
            {
                int b=fgetc(fp);
                if(b=='i')
                {
                    fprintf(ofp,"×");
                    fgetc(fp);//m
                    fgetc(fp);//e
                    fgetc(fp);//s
                }
                else//r
                {
                    fprintf(ofp,"™");
                    fgetc(fp);//a
                    fgetc(fp);//d
                    fgetc(fp);//e
                }
            }
            else //y
            {
                fprintf(ofp,"¥");
                fgetc(fp);//e
                fgetc(fp);//n
            }
            fgetc(fp);//;
        }
        else
        {
            fputc(c,ofp);
        }
    }
    fclose(fp);
    fclose(ofp);
}
int main(int argc,char** argv)
{
    if(argc<2)
    {
        printf("No input.\n");
        return 0;
    }
    string cmd="C:/curl ";
    string ss=argv[1];
    cmd+="http://www.jtahstu.com/acoj/show.php?pid="+ss+" > D:/xxx.txt";
    system(cmd);
    Deal();
    htmldecode();
    return 0;
}
