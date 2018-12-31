void read_six_numbers(char *input, int *a)
{
    if(sscanf(input, "%d %d %d %d %d %d", a, a + 1, a + 2, a + 3, a + 4, a + 5) <= 5)
        explode_bomb();
    return;
}

void phase_2(char* input)
{
    int a[6];
    read_six_numbers(input, a);
    if(a[0] != 1)
        explode_bomb();
    int *rbx = a;
    int *rbp = a + 5;  //5 = 20 / 4
    for(rbx = a; rbx < rbp; rbx++)
    {
        if(*rbx != *(rbx + 1) * 2)
            explode_bomb();
    }
}