0x555555555390 <phase_6>:	push   %r13
   0x555555555392 <phase_6+2>:	push   %r12
   0x555555555394 <phase_6+4>:	push   %rbp
   0x555555555395 <phase_6+5>:	push   %rbx
   0x555555555396 <phase_6+6>:	sub    $0x58,%rsp
   0x55555555539a <phase_6+10>:	lea    0x30(%rsp),%r12
   0x55555555539f <phase_6+15>:	mov    %r12,%rsi
   0x5555555553a2 <phase_6+18>:	callq  0x5555555556f7 <read_six_numbers>
   0x5555555553a7 <phase_6+23>:	mov    $0x0,%r13d
   0x5555555553ad <phase_6+29>:	jmp    0x5555555553d5 <phase_6+69>
   0x5555555553af <phase_6+31>:	callq  0x5555555556d1 <explode_bomb>
   0x5555555553b4 <phase_6+36>:	jmp    0x5555555553e4 <phase_6+84>
    for(bx = i; bx <= 5; bx++)  
        {
            // ax = i;
            ax = num[bx];
            if(*p == ax)
                explode_bomb();
            bx++;
        }
   0x5555555553b6 <phase_6+38>:	add    $0x1,%ebx
   0x5555555553b9 <phase_6+41>:	cmp    $0x5,%ebx
   0x5555555553bc <phase_6+44>:	jg     0x5555555553d1 <phase_6+65>
   
   0x5555555553be <phase_6+46>:	movslq %ebx,%rax
   0x5555555553c1 <phase_6+49>:	mov    0x30(%rsp,%rax,4),%eax
   0x5555555553c5 <phase_6+53>:	cmp    %eax,0x0(%rbp)
   0x5555555553c8 <phase_6+56>:	jne    0x5555555553b6 <phase_6+38>
   0x5555555553ca <phase_6+58>:	callq  0x5555555556d1 <explode_bomb>
   0x5555555553cf <phase_6+63>:	jmp    0x5555555553b6 <phase_6+38>
   p++;
   0x5555555553d1 <phase_6+65>:	add    $0x4,%r12
   if((unsigned)(*p - 1) > 5)
            explode_bomb();
   0x5555555553d5 <phase_6+69>:	mov    %r12,%rbp
   0x5555555553d8 <phase_6+72>:	mov    (%r12),%eax
   0x5555555553dc <phase_6+76>:	sub    $0x1,%eax
   0x5555555553df <phase_6+79>:	cmp    $0x5,%eax
   0x5555555553e2 <phase_6+82>:	ja     0x5555555553af <phase_6+31>
   i++;
   0x5555555553e4 <phase_6+84>:	add    $0x1,%r13d
   if(i == 6)
            break;
   0x5555555553e8 <phase_6+88>:	cmp    $0x6,%r13d
   0x5555555553ec <phase_6+92>:	je     0x555555555423 <phase_6+147>
   
   0x5555555553ee <phase_6+94>:	mov    %r13d,%ebx    # bx = i
   0x5555555553f1 <phase_6+97>:	jmp    0x5555555553be <phase_6+46>
   
   0x5555555553f3 <phase_6+99>:	mov    0x8(%rdx),%rdx
   0x5555555553f7 <phase_6+103>:	add    $0x1,%eax
   0x5555555553fa <phase_6+106>:	cmp    %ecx,%eax
   0x5555555553fc <phase_6+108>:	jne    0x5555555553f3 <phase_6+99>
   0x5555555553fe <phase_6+110>:	mov    %rdx,(%rsp,%rsi,8)
   0x555555555402 <phase_6+114>:	add    $0x1,%rsi
   0x555555555406 <phase_6+118>:	cmp    $0x6,%rsi
   0x55555555540a <phase_6+122>:	je     0x55555555542a <phase_6+154>
   0x55555555540c <phase_6+124>:	mov    0x30(%rsp,%rsi,4),%ecx
   0x555555555410 <phase_6+128>:	mov    $0x1,%eax
   0x555555555415 <phase_6+133>:	
    lea    0x202df4(%rip),%rdx        # 0x555555758210 <node1>
   0x55555555541c <phase_6+140>:	cmp    $0x1,%ecx
   0x55555555541f <phase_6+143>:	jg     0x5555555553f3 <phase_6+99>
   0x555555555421 <phase_6+145>:	jmp    0x5555555553fe <phase_6+110>
   
   0x555555555423 <phase_6+147>:	mov    $0x0,%esi
   0x555555555428 <phase_6+152>:	jmp    0x55555555540c <phase_6+124>
    
   0x55555555542a <phase_6+154>:	mov    (%rsp),%rbx
   0x55555555542e <phase_6+158>:	mov    0x8(%rsp),%rax
   0x555555555433 <phase_6+163>:	mov    %rax,0x8(%rbx)
   0x555555555437 <phase_6+167>:	mov    0x10(%rsp),%rdx
   0x55555555543c <phase_6+172>:	mov    %rdx,0x8(%rax)
   0x555555555440 <phase_6+176>:	mov    0x18(%rsp),%rax
   0x555555555445 <phase_6+181>:	mov    %rax,0x8(%rdx)
   0x555555555449 <phase_6+185>:	mov    0x20(%rsp),%rdx
   0x55555555544e <phase_6+190>:	mov    %rdx,0x8(%rax)
   0x555555555452 <phase_6+194>:	mov    0x28(%rsp),%rax
   0x555555555457 <phase_6+199>:	mov    %rax,0x8(%rdx)
   0x55555555545b <phase_6+203>:	movq   $0x0,0x8(%rax)
   0x555555555463 <phase_6+211>:	mov    $0x5,%ebp
   0x555555555468 <phase_6+216>:	jmp    0x555555555473 <phase_6+227>
   0x55555555546a <phase_6+218>:	mov    0x8(%rbx),%rbx
   0x55555555546e <phase_6+222>:	sub    $0x1,%ebp
   0x555555555471 <phase_6+225>:	je     0x555555555484 <phase_6+244>
   0x555555555473 <phase_6+227>:	mov    0x8(%rbx),%rax
   0x555555555477 <phase_6+231>:	mov    (%rax),%eax
   0x555555555479 <phase_6+233>:	cmp    %eax,(%rbx)
   0x55555555547b <phase_6+235>:	jle    0x55555555546a <phase_6+218>
   0x55555555547d <phase_6+237>:	callq  0x5555555556d1 <explode_bomb>
   0x555555555482 <phase_6+242>:	jmp    0x55555555546a <phase_6+218>
   0x555555555484 <phase_6+244>:	add    $0x58,%rsp
   0x555555555488 <phase_6+248>:	pop    %rbx
   0x555555555489 <phase_6+249>:	pop    %rbp
   0x55555555548a <phase_6+250>:	pop    %r12
   0x55555555548c <phase_6+252>:	pop    %r13
   0x55555555548e <phase_6+254>:	retq   
