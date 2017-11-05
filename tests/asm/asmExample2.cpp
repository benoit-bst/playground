/*
 * compile : g++ -S asmExample2.cpp
 *
 */
int main()
{
	long long  a = 0;
	long long b = a + 3;
	if (b > 0)
		a = 10;
	else
		a = 20;

    return 1;
}

/*

        .file   "asmExample2.cpp"
        .text
        .globl  main
        .type   main, @function
main:
.LFB0:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movq    $0, -8(%rbp)
        movq    -8(%rbp), %rax
        addq    $3, %rax
        movq    %rax, -16(%rbp)
        cmpq    $0, -16(%rbp)  // if compare L2 et L3
        jle     .L2
        movq    $10, -8(%rbp)
        jmp     .L3
.L2:
        movq    $20, -8(%rbp)
.L3:
        movl    $1, %eax
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   main, .-main
        .ident  "GCC: (Debian 4.9.2-10) 4.9.2"
        .section        .note.GNU-stack,"",@progbits

*/