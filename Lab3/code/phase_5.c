char array[];

void phase_5(char *input)
{
    // char *rbx = input;
    char *p;
    char s[7];   //s = 0x9(%rsp)
    int dx;
    char bt;
    if(string_length(input) != 6)
        explode_bomb();
    for(int i = 0, p = array; i < 6; i++)
    {
        bt = 0xf & input[i];
        s[i] = array[(int)bt];
    }
    s[6] = '\0';
    if(string_not_equal(s, "devils") != 0)
        explode_bomb();
    return;
}

/*
0xf & input[0 ~ 5]= 2, 5, 12, 4, 15, 7
//                    0x2, 0x5, 0xc, 0x4, 0xf ,0x7
// array[] = "maduiersnfotvbylSo you think you can stop the bomb with ctrl-c, do you?"
//input[0 ~ 5] = 
              (a) 0x22, 0x25, 0x2c, 0x24, 0x2f, 0x27 
                  '\"' , '%', ',' ,  '$', '/', '\''   -> "%,$/'
              (b) 0x32, 0x35, 0x3c, 0x34, 0x3f, 0x37
                 '2' , '5', '<',   '4', '?',  '7'     -> 25<4?7
              (c) 0x42, 0x45, 0x4c, 0x44, 0x4f, 0x47
                  'B' , 'E' , 'L' , 'D' , 'O' , 'G'   -> BELDOG
              (d) 0x52, 0x55, 0x5c, 0x54, 0x5f, 0x57
                  'R' , 'U' , '\\' , 'T', '_' , 'W'   -> RU\T_W 
              (e) 0x62, 0x65, 0x6c, 0x64, 0x6f, 0x67
                  'b' , 'e' , 'l' , 'd' , 'o' , 'g'   -> beldog
*/        