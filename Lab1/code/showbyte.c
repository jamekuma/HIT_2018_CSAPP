#include <stdio.h>
#include <stdlib.h>
/*函数声明*/
void ShowLine(char *s, int len);

int main()
{
    FILE *fp1;
    char s[60];
    char ch;
    int counter = 0;
    if((fp1 = fopen("F:\\ICS\\Lab\\Lab1\\my_code\\hellowin.c","r")) == NULL)
        //打开当前目录的hellowin文件
    {
        printf("failure to open!\n");
        exit(0);
    }
    while((ch = fgetc(fp1)) != EOF)
    {
        s[counter % 16] = ch;
        counter++;                  //counter计数，控制换行

        if(counter % 16 == 0)       //一行完整16个字符
        {
            ShowLine(s, 16);
        }
    }
    if(counter % 16 != 0)         //若最后一行不满16个字符
    {
        ShowLine(s, counter % 16);
    }
    fclose(fp1);
    // getchar();
    return 0;
}

void ShowLine(char *s, int len)     //输出一行（16个字符）的字符和十六进制
{
    int i;
    for(i = 0; i < len; i++)
    {

        if(s[i] == '\n')           //考虑制表符、回车符、换行符
            printf("\\n ");
        else if(s[i] == '\r')
            printf("\\n ");
        else if(s[i] == '\t')
            printf("\\t ");

        else if(s[i] < 0)     //收到汉字字符
        {
            printf("%c%c ",s[i],s[i + 1]);   //ASCII中一个汉字为2个字节
            i++;
        }
        else             //普通字符
        {
            printf("%c  ",s[i]);
        }
    }
    printf("\n");
    for(i = 0; i < len; i++)             //输出十六进制
        printf("%02x ",s[i] & 0xff);          //只取低8位
    printf("\n");
}
