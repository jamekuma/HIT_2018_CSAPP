/*datatype.c*/

#include <stdio.h>

typedef unsigned char* byte_p;

int main();
void showByte(byte_p p, int len);

char ch = 'a';
int num = 1170500913;
int *p = &num;
int array[] = {0, 1, 2};
long lnum = 1170500913;
long long llnum = 1170500913;
float f = 1999.0;
double lf = 19991217.0;

enum color
{
    red,
    green,
    yellow,
    blue
} sky = blue;

union var
{
    int num;
    char ch;
} v = {66};
struct student
{
    int num;
    float score;
    char level;
} stu1 = {1, 98.5, 'A'};

int (*p_printf)(const char *, ...) = printf;
int (*p_main)() = main;

int main()
{
    printf("数据类型\t变量名\t\t变量内容\t变量地址\t变量对应的16进制内存字节\n");
    printf("DataType\tDataName\tContent\t\tAddress\t\tContent_HEX(Little_Endian)\n");
    printf("-------------------------------------------------------------------------------------------\n");

    printf("char\t\tch\t\t%c\t\t0x%x\t", ch, (byte_p)&ch); //char
    showByte((byte_p)&ch, sizeof(char));
    printf("int\t\tnum\t\t%d\t0x%x\t", num, (byte_p)&num); //int
    showByte((byte_p)&num, sizeof(int));
    printf("int*\t\tp\t\t0x%x\t0x%x\t", p, (byte_p)&p); //int*
    showByte((byte_p)&p, sizeof(int*));
    printf("int[]\t\tarray\t\tarray[0] = %d\t0x%x\t", array[0], (byte_p)array); //int[]
    showByte((byte_p)array, sizeof(int));
    printf("\t\t\t\tarray[1] = %d\t0x%x\t", array[1], (byte_p)(array + 1));
    showByte((byte_p)(array + 1), sizeof(int));
    printf("\t\t\t\tarray[2] = %d\t0x%x\t", array[2], (byte_p)(array + 2));
    showByte((byte_p)(array + 2), sizeof(int));
    printf("long\t\tlnum\t\t%ld\t0x%x\t", lnum, (byte_p)&lnum);  //long
    showByte((byte_p)&lnum, sizeof(long));
    printf("long long\tllnum\t\t%I64d\t0x%x\t", llnum, (byte_p)&llnum);  //long long
    showByte((byte_p)&llnum, sizeof(long long));
    printf("float\t\tf\t\t%.2f\t\t0x%x\t", f, (byte_p)&f);  //float
    showByte((byte_p)&f, sizeof(float));
    printf("double\t\tlf\t\t%.2lf\t0x%x\t", lf, (byte_p)&lf);  //double
    showByte((byte_p)&lf, sizeof(double));
    printf("enum color\tsky\t\t%d\t\t0x%x\t", sky, (byte_p)&sky);   //enum
    showByte((byte_p)&sky, sizeof(enum color));
    printf("union var\tv\t\tv.num = %d\t0x%x\t", v.num, (byte_p)&(v.num));   //union
    showByte((byte_p)&(v.num), sizeof(v.num));
    printf("\t\t\t\tv.ch = %c\t0x%x\t", v.ch, (byte_p)&(v.ch));
    showByte((byte_p)&(v.ch), sizeof(v.ch));
    printf("struct student\tstu1\t\tstu1.num = %d\t0x%x\t", stu1.num, (byte_p)&(stu1.num));  //struct
    showByte((byte_p)&(stu1.num), sizeof(stu1.num));
    printf("\t\t\t\tstu1.score=%.1f\t0x%x\t", stu1.score, (byte_p)&(stu1.score));
    showByte((byte_p)&(stu1.score), sizeof(stu1.score));
    printf("\t\t\t\tstu1.level = %c\t0x%x\t", stu1.level, (byte_p)&(stu1.level));
    showByte((byte_p)&(stu1.level), sizeof(stu1.level));
    printf("FunctionPointer\tp_main\t\t0x%x\t0x%x\t", p_main, (byte_p)&p_main);      //main
    showByte((byte_p)&p_main, sizeof(p_main));
    printf("FunctionPointer\tp_printf\t0x%x\t0x%x\t", p_printf, (byte_p)&p_printf);    //printf
    showByte((byte_p)&p_printf, sizeof(p_printf));
    printf("\n注：p_main与p_printf的内容即为main函数与printf函数的地址\n");    //tip
}

void showByte(byte_p p, int len)    //用于打印变量对应的16进制内存字节
{
    int i;
    printf("0x");
    for(i = 0; i < len; i++)
    {
        printf("%02x ",*p);
        p++;
    }
    printf("\n");
}
