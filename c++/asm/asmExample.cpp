/*
 * compile : g++ -S asmExample.cpp
 * 
 * ou
 * 
 * g++ asmExample.cpp
 * gdb a.out
 * set disassembly-flavor intel
 * disassemble main
 * Dump of assembler code for function main:
   0x0000000000400576 <+0>:     push   rbp
   0x0000000000400577 <+1>:     mov    rbp,rsp
   0x000000000040057a <+4>:     mov    QWORD PTR [rbp-0x8],0x0
   0x0000000000400582 <+12>:    mov    rax,QWORD PTR [rbp-0x8]
   0x0000000000400586 <+16>:    add    rax,0x3
   0x000000000040058a <+20>:    mov    QWORD PTR [rbp-0x10],rax
   0x000000000040058e <+24>:    mov    eax,0x1
   0x0000000000400593 <+29>:    pop    rbp
   0x0000000000400594 <+30>:    ret    
   End of assembler dump
 * 
 */
int main()
{
	long long  a = 0;
	long long b = a + 3;
    return 1;
}

/*
	    .file   "asmExample.cpp"
        .text
        .globl  main
        .type   main, @function
main:
.LFB0:
        .cfi_startproc
        pushq   %rbp                   // place in stack
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    $0, -4(%rbp)
        movl    -4(%rbp), %eax
        addl    $3, %eax
        movl    %eax, -8(%rbp)
        movl    $0, %eax               // eax contains the return of a function
        popq    %rbp                   // pop in stack
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   main, .-main
        .ident  "GCC: (Debian 4.9.2-10) 4.9.2"
        .section        .note.GNU-stack,"",@progbits
*/