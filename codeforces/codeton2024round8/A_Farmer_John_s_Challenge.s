	.file	"A_Farmer_John_s_Challenge.cpp"
	.text
	.p2align 4
	.globl	_Z4powexx
	.def	_Z4powexx;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4powexx
_Z4powexx:
.LFB10589:
	.seh_endprologue
	movabsq	$-8543223828751151131, %r11
	movq	%rcx, %rax
	movq	%rdx, %r9
	imulq	%r11
	movq	%rcx, %rax
	sarq	$63, %rax
	leaq	(%rdx,%rcx), %r8
	sarq	$29, %r8
	subq	%rax, %r8
	imulq	$1000000007, %r8, %rax
	subq	%rax, %rcx
	movabsq	$-8543223818847630945, %rax
	imulq	%r9
	movq	%r9, %rax
	movq	%rcx, %r8
	movl	$1, %ecx
	sarq	$63, %rax
	leaq	(%rdx,%r9), %r10
	sarq	$29, %r10
	subq	%rax, %r10
	imulq	$1000000006, %r10, %rax
	movq	%r9, %r10
	subq	%rax, %r10
	testq	%r10, %r10
	jle	.L1
	.p2align 4,,10
	.p2align 3
.L4:
	testb	$1, %r10b
	je	.L3
	imulq	%r8, %rcx
	movq	%rcx, %rax
	movq	%rcx, %r9
	imulq	%r11
	movq	%r9, %rax
	sarq	$63, %rax
	leaq	(%rdx,%rcx), %rcx
	sarq	$29, %rcx
	subq	%rax, %rcx
	imulq	$1000000007, %rcx, %rax
	movq	%r9, %rcx
	subq	%rax, %rcx
.L3:
	movq	%r8, %r9
	imulq	%r8, %r9
	movq	%r9, %rax
	mulq	%r11
	movq	%rdx, %r8
	shrq	$29, %r8
	imulq	$1000000007, %r8, %rax
	movq	%r9, %r8
	subq	%rax, %r8
	sarq	%r10
	jne	.L4
.L1:
	movq	%rcx, %rax
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "\12\0"
.LC1:
	.ascii " \0"
	.text
	.p2align 4
	.globl	_Z5solvev
	.def	_Z5solvev;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5solvev
_Z5solvev:
.LFB10590:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	40(%rsp), %rdx
	call	_ZNSirsERi
	leaq	44(%rsp), %rdx
	movq	%rax, %rcx
	call	_ZNSirsERi
	movl	44(%rsp), %eax
	cmpl	$1, %eax
	je	.L12
	cmpl	40(%rsp), %eax
	jne	.L26
	movq	.refptr._ZSt4cout(%rip), %rsi
	testl	%eax, %eax
	jle	.L17
	xorl	%ebx, %ebx
.L15:
	movq	.refptr._ZSt4cout(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	.p2align 4,,10
	.p2align 3
.L18:
	movl	$1, %edx
	movq	%rsi, %rcx
	addl	$1, %ebx
	call	_ZNSolsEi
	movl	$1, %r8d
	movq	%rdi, %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	cmpl	%ebx, 40(%rsp)
	jg	.L18
.L17:
	movl	$1, %r8d
	leaq	.LC0(%rip), %rdx
	movq	%rsi, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	nop
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
	.p2align 3
.L12:
	movl	40(%rsp), %eax
	xorl	%ebx, %ebx
	cmpl	$1, %eax
	je	.L15
	movq	.refptr._ZSt4cout(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	testl	%eax, %eax
	jle	.L17
	.p2align 4,,10
	.p2align 3
.L16:
	addl	$1, %ebx
	movq	%rsi, %rcx
	movl	%ebx, %edx
	call	_ZNSolsEi
	movl	$1, %r8d
	movq	%rdi, %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	cmpl	40(%rsp), %ebx
	jl	.L16
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L26:
	movq	.refptr._ZSt4cout(%rip), %rcx
	movl	$-1, %edx
	call	_ZNSolsEi
	movl	$1, %r8d
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x
	nop
	addq	$48, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10591:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
	call	_ZNSt8ios_base15sync_with_stdioEb
	movq	.refptr._ZSt3cin(%rip), %rcx
	movq	.refptr._ZSt4cout(%rip), %rax
	leaq	44(%rsp), %rdx
	movl	$1, 44(%rsp)
	movq	$0, 232(%rcx)
	movq	$0, 224(%rax)
	call	_ZNSirsERi
	jmp	.L34
	.p2align 4,,10
	.p2align 3
.L35:
	call	_Z5solvev
.L34:
	movl	44(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 44(%rsp)
	testl	%eax, %eax
	jne	.L35
	xorl	%eax, %eax
	addq	$56, %rsp
	ret
	.seh_endproc
	.ident	"GCC: (Rev5, Built by MSYS2 project) 13.2.0"
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_x;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base15sync_with_stdioEb;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
