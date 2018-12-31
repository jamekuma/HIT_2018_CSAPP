long fun7(long *p, long num)
{
    long ax;
    if(p == NULL)
        return -1;

    // ax = 0;
    if(*p == num)
        return 0;//ax;

    else if(*p < num)
    {
        p = *(p + 2); //right
        return (2 * fun7(p, num) + 1);
    }

    else
    {
        p = *(p + 1); //left
        return (2 * fun7(p,num));
    }
}

void phase_secret(void)
{
    char *input = read_line();
    long num = strtol(input, NULL, 10);
    long bx = num;
    long ax = num - 1;
    if(ax > 1000)
        explode_bomb();
    long n1 = 36;
    if(fun7(&n1, num) != 2)
        explode_bomb();
    puts("Wow! You've defused the secret stage!");
    phase_defused();
    return;
}