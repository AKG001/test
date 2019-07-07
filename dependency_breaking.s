	.file	"dependency_breaking.c"
	.text
	.globl	thread0
	.type	thread0, @function
thread0:
.LFB0:
	.cfi_startproc
	movabsq	$-180388626474, %rax
	movl	$-44, rt+8(%rip)
	movq	%rax, rt(%rip)
	movq	$rt, gp(%rip)
	ret
	.cfi_endproc
.LFE0:
	.size	thread0, .-thread0
	.globl	thread1
	.type	thread1, @function
thread1:
.LFB1:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movq	gp(%rip), %rax
	movq	%rax, 8(%rsp)
	movq	8(%rsp), %rax
	movl	(%rax), %ebx
	movq	8(%rsp), %rax
	cmpq	$rt, %rax
	movq	8(%rsp), %rax
	jne	.L3
	movl	4(%rax), %edi
	jmp	.L4
.L3:
	orl	$-1, %edi
	testq	%rax, %rax
	je	.L4
	movq	8(%rsp), %rax
	movl	8(%rax), %edi
.L4:
	shrl	$31, %edi
	xorl	%eax, %eax
	shrl	$31, %ebx
	call	assert
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	movl	%ebx, %edi
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	assert
	.cfi_endproc
.LFE1:
	.size	thread1, .-thread1
	.globl	rt
	.data
	.align 8
	.type	rt, @object
	.size	rt, 12
rt:
	.long	1
	.long	2
	.long	3
	.comm	gp,8,8
	.ident	"GCC: (GNU) 10.0.0 20190607 (experimental)"
	.section	.note.GNU-stack,"",@progbits
