=> 0x5555555554ce <secret_phase>:	push   %rbx
   0x5555555554cf <secret_phase+1>:	callq  0x555555555738 <read_line>
   0x5555555554d4 <secret_phase+6>:	mov    $0xa,%edx
   0x5555555554d9 <secret_phase+11>:	mov    $0x0,%esi
   0x5555555554de <secret_phase+16>:	mov    %rax,%rdi
   0x5555555554e1 <secret_phase+19>:	callq  0x555555554e40 <strtol@plt>
   0x5555555554e6 <secret_phase+24>:	mov    %rax,%rbx
   0x5555555554e9 <secret_phase+27>:	lea    -0x1(%rax),%eax
   0x5555555554ec <secret_phase+30>:	cmp    $0x3e8,%eax
   0x5555555554f1 <secret_phase+35>:	ja     0x55555555551e <secret_phase+80>
   0x5555555554f3 <secret_phase+37>:	mov    %ebx,%esi
   0x5555555554f5 <secret_phase+39>:	
    lea    0x202c34(%rip),%rdi        # 0x555555758130 <n1>
   0x5555555554fc <secret_phase+46>:	callq  0x55555555548f <fun7>
   0x555555555501 <secret_phase+51>:	cmp    $0x2,%eax
   0x555555555504 <secret_phase+54>:	je     0x55555555550b <secret_phase+61>
   0x555555555506 <secret_phase+56>:	callq  0x5555555556d1 <explode_bomb>
   0x55555555550b <secret_phase+61>:	
    lea    0x1186(%rip),%rdi        # 0x555555556698
   0x555555555512 <secret_phase+68>:	callq  0x555555554db0 <puts@plt>
   0x555555555517 <secret_phase+73>:	callq  0x55555555587c <phase_defused>
   0x55555555551c <secret_phase+78>:	pop    %rbx
   0x55555555551d <secret_phase+79>:	retq   
---Type <return> to continue, or q <return> to quit---
   0x55555555551e <secret_phase+80>:	callq  0x5555555556d1 <explode_bomb>
   0x555555555523 <secret_phase+85>:	jmp    0x5555555554f3 <secret_phase+37>
