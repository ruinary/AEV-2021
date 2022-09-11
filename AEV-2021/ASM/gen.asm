.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib D:/AEV-2021/AEV-2021/Debug/LIB.lib
ExitProcess PROTO :DWORD

EXTRN COMBINE: proc
EXTRN LEXCOMP: proc
EXTRN MEASURE: proc
EXTRN BREAKL: proc
EXTRN RANDOMIZE: proc
EXTRN EXPONENT: proc
EXTRN OutputInt: proc
EXTRN OutputStr: proc

.stack 4096

.const
	L1 SDWORD 0
	L2 SDWORD 2
	L3 BYTE "Counting to length: ", 0
	L4 SDWORD 1
	L5 BYTE " ", 0
	L6 SDWORD 1
	L7 SDWORD 0
	L8 BYTE "C o u r s e   W o r k   ", 0
	L9 BYTE "A E V - 2021", 0
	L10 BYTE "A", 0
	L11 BYTE "Numbers: ", 0
	L12 SDWORD -2
	L13 SDWORD 8
	L14 BYTE "Difference = ", 0
	L15 BYTE "Good", 0
	L16 BYTE "Goooob", 0
	L17 BYTE "Lex. comparison: ", 0
	L18 BYTE "Now", 0
	L19 BYTE "Is length of str > 2?", 0
	L20 BYTE "True! ", 0
	L21 BYTE "False! It is less", 0
	L22 SDWORD 3
	L23 BYTE "exp[3,3] = ", 0
	L24 SDWORD 4
	L25 BYTE "Average of 4 and exponent [3,3] = ", 0
	L26 BYTE "Is average of 4 and exponent [3,3] = 0?", 0
	L27 BYTE "True! It is zero", 0
	L28 BYTE "False! It is not zero: ", 0
	L29 BYTE "Remainer is: ", 0
	L30 SDWORD 57
	L31 BYTE "Random number: ", 0
	L32 BYTE "End of example.", 0

.data
	buffer BYTE 256 dup(0)
	averresult SDWORD 0
	countni SDWORD 0
	iszerobuf SDWORD 0
	mainstring DWORD ?
	mainchr DWORD ?
	mainh SDWORD 0
	mainq SDWORD 0
	maindif SDWORD 0
	mainlc SDWORD 0
	mainlength SDWORD 0
	mainexp SDWORD 0
	mainresult SDWORD 0
	mainfl SDWORD 0
	mainrem SDWORD 0
	mainr SDWORD 0

.code

aver PROC avern : SDWORD, averm : SDWORD
	push L1
	pop averresult
	push avern
	push averm
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop averresult
	push averresult
	push L2
	pop ebx
	pop eax
	cdq
	idiv ebx
	push eax
	pop averresult
	push averresult
	jmp local0
local0:
	pop eax
	ret
aver ENDP

countn PROC countnn : SDWORD
	push L1
	pop countni
	push offset L3
	call OutputStr
	push countnn
	call OutputInt
	call BREAKL
	mov eax, countni
	cmp eax, countnn
	jl cycle0
	jmp cyclenext0
cycle0:
	push countni
	push L4
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop countni
	push countni
	call OutputInt
	push offset L5
	call OutputStr
	mov eax, countni
	cmp eax, countnn
	jl cycle0
cyclenext0:
	ret
countn ENDP

iszero PROC iszeron : SDWORD
	mov eax, iszeron
	cmp eax, L1
	jz m0
	jnz m1
	je m1
m0:
	push L6
	pop iszerobuf
	jmp e0
m1:
	push L7
	pop iszerobuf
e0:
	push iszerobuf
	jmp local1
local1:
	pop eax
	ret
iszero ENDP

main PROC
	push offset L8
	push offset L9
	pop edx
	pop edx
	push offset L9
	push offset L8
	push offset buffer
	call COMBINE
	push eax
	pop mainstring
	push mainstring
	call OutputStr
	call BREAKL
	call BREAKL
	push offset L10
	pop mainchr
	push mainchr
	call OutputStr
	call BREAKL
	push offset L11
	call OutputStr
	call BREAKL
	push L12
	pop mainh
	push mainh
	call OutputInt
	call BREAKL
	push L13
	pop mainq
	push mainq
	call OutputInt
	call BREAKL
	push offset L14
	call OutputStr
	push mainh
	push mainq
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop maindif
	push maindif
	call OutputInt
	call BREAKL
	push offset L15
	push offset L16
	pop edx
	pop edx
	push offset L16
	push offset L15
	call LEXCOMP;
	push eax
	pop mainlc
	push offset L17
	call OutputStr
	push mainlc
	call OutputInt
	call BREAKL
	push offset L18
	pop edx
	push offset L18
	call MEASURE;
	push eax
	pop mainlength
	push offset L19
	call OutputStr
	call BREAKL
	mov eax, mainlength
	cmp eax, L2
	jg m2
	jl m3
	je m3
m2:
	push offset L20
	call OutputStr
	push mainlength
	call countn
	call BREAKL
	jmp e1
m3:
	push offset L21
	call OutputStr
	call BREAKL
e1:
	push L22
	push L22
	pop edx
	pop edx
	push L22
	push L22
	call EXPONENT;
	push eax
	pop mainexp
	push offset L23
	call OutputStr
	push mainexp
	call OutputInt
	call BREAKL
	push aver
	push L24
	push mainexp
	pop edx
	pop edx
	push mainexp
	push L24
	call aver
	push eax
	pop mainresult
	push offset L25
	call OutputStr
	push mainresult
	call OutputInt
	call BREAKL
	push offset L26
	call OutputStr
	call BREAKL
	push iszero
	push mainresult
	pop edx
	push mainresult
	call iszero
	push eax
	pop mainfl
	mov eax, mainfl
	cmp eax, 1
	jz m4
	jnz m5
	je m5
m4:
	push offset L27
	call OutputStr
	call BREAKL
	jmp e2
m5:
	push offset L28
	call OutputStr
	push mainresult
	call OutputInt
	call BREAKL
	push offset L29
	call OutputStr
	push mainexp
	push L24
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push L2
	pop ebx
	pop eax
	cdq
	idiv ebx
	push edx
	pop mainrem
	push mainrem
	call OutputInt
	call BREAKL
e2:
	push L2
	push L30
	pop edx
	pop edx
	push L30
	push L2
	call RANDOMIZE;
	push eax
	pop mainr
	push offset L31
	call OutputStr
	push mainr
	call OutputInt
	call BREAKL
	call BREAKL
	push offset L32
	call OutputStr
	call BREAKL
	call ExitProcess
main ENDP
end main