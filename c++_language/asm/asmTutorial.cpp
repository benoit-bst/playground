/**
 * ASM analysis
 *
 * Main registers :
 * EAX (accumulator register) arithmetics operations and sys call return 32 bits -> AX bits 16 bits -> AL 8 bits AH 8 bits
 * EDX (data register) arithmetics operations and I/O operations 32 bits         -> DX bits 16 bits -> DL 8 bits DH 8 bits
 * ECX (counter register) data pointer 32 bits                                   -> CX bits 16 bits -> CL 8 bits CH 8 bits
 * EBX (base register) 32 bits                                                   -> BX bits 16 bits -> BL 8 bits BH 8 bits
 *
 * Offset register :
 * EBP : (Extended Base Pointer) base pointer
 * ESP : (Extended Stack Pointer) stack pointer
 * ESI : (Extended Source Index) source pointer, used for mem copy
 * EDI : (Extended Destination Index) destination pointer, used for mem copy
 *
 * Segment register :
 *
 * CS : pointe vers les instructions du programme (code segment).
 * DS : pointe vers les données du programme (data segment).
 * SS : pointe vers la pile programme (stack segment).
 * ES : pointe vers les données du programme multi-segments (extra segment).
 * FS : pointe vers les données du programme multi-segments en mode protégé.
 * GS : pointe vers les données du programme multi-segments en mode protégé.
 *
 * State register :
 * Chaque bit du registre EFLAGS est un indicateur d'état qui peut être modifié à chaque instruction exécutée :
 * retenue (addition ou soustraction),
 * dépassement,
 * comparaison,
 * autoriser les interruptions,
 * ...
 *
 * Instruction pointer :
 * Le registre EIP est utilisé avec le segment du registre CS par le processeur pour connaitre la prochaine instruction à exécuter.
 * Ce registre est donc modifié implicitement par le processeur (instruction suivante, saut à l'adresse indiquée, appel d'une fonction, interruption ...).
 *
 *
 * View ASM
 * g++ asmTutorial.cpp
 * gdb a.out
 * set disassembly-flavor intel
 * disassemble main
 *
Dump of assembler code for function main:
   0x00000000004005f6 <+0>: push   rbp                              // main
   0x00000000004005f7 <+1>: mov    rbp,rsp                          // main
   0x00000000004005fa <+4>: sub    rsp,0x20                         // main
   0x00000000004005fe <+8>: mov    DWORD PTR [rbp-0xc],0x3          // int a = 3;
   0x0000000000400605 <+15>:  add    DWORD PTR [rbp-0xc],0x1        // a++;
   0x0000000000400609 <+19>:  mov    edi,0x4                        // int * ptr = new int(1);
   0x000000000040060e <+24>:  call   0x4004e0 <_Znwm@plt>           // int * ptr = new int(1);
   0x0000000000400613 <+29>:  mov    DWORD PTR [rax],0x1            // int * ptr = new int(1);
   0x0000000000400619 <+35>:  mov    QWORD PTR [rbp-0x8],rax        // int * ptr = new int(1);
   0x000000000040061d <+39>:  mov    eax,DWORD PTR [rbp-0xc]        // int b = a;
   0x0000000000400620 <+42>:  mov    DWORD PTR [rbp-0x14],eax       // int b = a;
   0x0000000000400623 <+45>:  mov    DWORD PTR [rbp-0x10],0x0       // for (int i = 0; i < 10; ++i)
   0x000000000040062a <+52>:  cmp    DWORD PTR [rbp-0x10],0x9       // for (int i = 0; i < 10; ++i)
   0x000000000040062e <+56>:  jg     0x40063a <main+68>             // for (int i = 0; i < 10; ++i)
   0x0000000000400630 <+58>:  add    DWORD PTR [rbp-0x14],0x1       // b++;
   0x0000000000400634 <+62>:  add    DWORD PTR [rbp-0x10],0x1       // for (int i = 0; i < 10; ++i)
   0x0000000000400638 <+66>:  jmp    0x40062a <main+52>             // for (int i = 0; i < 10; ++i)
   0x000000000040063a <+68>:  mov    eax,0x1                        // return 1;
   0x000000000040063f <+73>:  leave                                 // return 1;
   0x0000000000400640 <+74>:  ret                                   // return 1;
End of assembler dump.

with O3 :
 jmp QWORD PTR [rip+0x200baa] # 601020 <_GLOBAL_OFFSET_TABLE_+0x20>
 push 0x1
 jmp 400450 <_init+0x28>
main:
 sub rsp,0x8                                                        // main
 mov edi,0x4                                                        // int * ptr = new int(1);
 call 400470 <operator new(unsigned long)@plt>                      // int * ptr = new int(1);
 mov eax,0x1                                                        // return 1;
 add rsp,0x8
 ret
 nop DWORD PTR [rax+rax*1+0x0]

 */
int main() {
  int a = 3;

  {
    a++;
  }

  {
    int * ptr = new int(1);
  }

  {
    int b = a;
    for (int i = 0; i < 10; ++i)
    {
      b++;
    }
  }
  return 1;
}