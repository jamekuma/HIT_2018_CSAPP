void phase_4(char *input)
{
    int num1, num2;  //num1 in 0xc(%rsp),num2 in 0x8(%rip)
    if(sscanf(input, "%d %d", &num1, &num2) != 2)
        explode_bomb();
    if((unsigned)num1 > 14)
        explode_bomb();
    if(func4(num1, 0, 14) != 19)
        explode_bomb();
    if(num2 != 19)
        explode_bomb();
    return;
}
int func4(int x, int y, int z) //x->di y->si z->dx
{
    int ans, rbx;
    ans = z - y;
    rbx = ans + ((unsigned)ans >> 31);//if (ans < 0) rbx = ans + 1;else rbx = ans
    rbx = rbx >> 1; 
    rbx = y + rbx;      //rbx = (z - y) / 2 + y;
    if(rbx == x)   
    {
        return rbx;
    }
    else if(rbx < x)
    {
        return rbx + fun(x,rbx + 1, z);
    }
    else
    {
         return rbx + fun(x, y, rbx - 1);
    }
}