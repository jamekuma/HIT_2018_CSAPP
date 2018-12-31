void phase_3(char *input)
{
    int num1, num2, eax;  //num1 in 0xc(%rsp),num2 in 0x8(%rsp)
    if(sscanf(input, "%d %d", &num1, &num2) <= 1)
        explode_bomb();
    switch(num1)
    {
        case 0: eax = 50;
                eax = eax - 936;
                break;
        case 1: eax = 0;
                eax = eax - 936;
                break;
        case 2: eax = 0;
                eax = eax - 526;
                break;
        case 3: eax = 0;
                eax = eax - 835;
                break;
        case 4: eax = 0;
                break;
        case 5: eax = 0;
                eax = eax - 835;
                break;
        case 6:
        case 7:
        default: explode_bomb();
    }
    if(eax == num2)
        return;
    else
        explode_bomb();
}
/* jump = 0x5555555566d0
jump[0] = 0xffffeb52  jump[0] + jump = 0x555555555222
jump[1] = 0xffffeb59  jump[1] + jump = 0X555555555229
jump[2] = 0xffffeb98  jump[2] + jump = 0x555555555268
jump[3] = 0xffffeb9f  jump[3] + jump = 0x55555555526F
jump[4] = 0xffffeba6  jump[4] + jump = 0x555555555276
jump[5] = 0xffffebad  jump[5] + jump = 0x55555555527D
jump[6] = 0xffffebb4  jump[6] + jump = 0x555555555284
jump[7] = 0xffffebbb  jump[7] + jumo = 0x55555555528B
*/