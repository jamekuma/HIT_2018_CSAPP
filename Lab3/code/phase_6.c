typedef struct NODE
{
    long data;
    struct NODE* next;
} node;

node *node1;

void read_six_numbers(char *input, int *a)
{
    if(sscanf(input, "%d %d %d %d %d %d", a, a + 1, a + 2, a + 3, a + 4, a + 5) <= 5)
        explode_bomb();
    return ;
}

void phase(char *input)
{
    int num[6];  //num in 0x30(rsp)
    int *p = num; //p in %r12
    read_six_numbers(input, num);
    int i = 0;  // i in %r13d
    int ax;

    while(i < 6)
    {
        if((unsigned)(*p - 1) > 5) /*若p指向的数大于6，
                                   或小于1，则爆炸*/
            explode_bomb();
        i++;      
        if(i == 6)
            break; //如果i到了6，提前结束，不执行下面的for循环
        for(bx = i; bx <= 5; bx++)
        {
            // ax = i;
            ax = num[bx];  //从第i个数（即p指向的数）开始取
            if(*p == ax)   //若取得这个数等于p指向的数，则爆炸
                explode_bomb();
            bx++;          //每次向后取一个
        }
        p++;      //p向后指一位
    }
    /****************************************
    以上一段的总结：num中的数，只能在1 ~ 6之间，且不能重复
    结论：num[]中的数为1,2,3,4,5,6,（顺序待定） 
    *****************************************/


    node *array[];
    int j, k;  //j in %si
    int cx;
    node *bx, *ax;
    node *dx;
    for(j = 0; j < 6; j++)
    {
        cx = num[j];    //cx为num的第j项
        dx = node1;  //dx指向链表第一项

        if(cx > 1)            
        {
            for(k = 1; k < cx; k++)  //指针dx向后移cx次
                dx = dx -> next;   
        }      //此时，dx指向第cx个元素
        array[j] = dx;    /*链表的第 “num[j]” 个节点地址，
                            给了指针数组array[j]*/
    }
    /****************************************
    以上一段的总结：链表的第 “num[j]” 个节点地址，给了array[j]
    结论：只要找到array[]各个项，是链表的第几个节点，
          就能找出相应num[]的值
    *****************************************/



    bx = array[0]; 
    ax = array[1];
    bx -> next = ax; /*把array[1]指向的节点
                        连在array[0]指向的节点的后面*/
    dx = array[2];
    ax -> next = dx; /*把array[2]指向的节点
                        连在array[1]指向的节点的后面*/
    ax = array[3];
    dx -> next = ax; /*把array[3]指向的节点
                        连在array[2]指向的节点的后面*/
    dx = array[4];
    ax -> next = dx; /*把array[4]指向的节点
                        连在array[3]指向的节点的后面*/
    ax = array[5];
    dx -> next = ax; /*把array[5]指向的节点
                        连在array[4]指向的节点的后面*/
    ax -> next = NULL; //最后几个节点next节点赋为NULL
    /****************************************
    以上一段的总结：把原来的链表，按照array
                   数组的顺序重新排序
    *****************************************/



   //这个时候，bx指向链表的第一个节点
    int k;
    for(k = 5; k > 0; k--)
    {
        ax = bx -> next; //ax指向bx的后趋节点
        if(bx -> data > ax -> data)   /*如果bx节点的值
                                        大于ax节点的值,则爆炸*/
            explode_bomb();
        bx = bx -> next;   //bx向后移动一次
    }
}
    /****************************************
    以上一段的总结：新的链表，必须是从小到大排列，否则会爆炸

    结论：要想不爆炸，array[]依次指向的节点，值必须是从小到大的
    *****************************************/