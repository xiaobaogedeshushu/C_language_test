; Listing generated by Microsoft (R) Optimizing Compiler Version 19.00.24215.1 

	TITLE	D:\custom\test\练习和实验\算法\交换.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	_swap
PUBLIC	_test_swap
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\custom\test\练习和实验\算法\交换.c
;	COMDAT _test_swap
_TEXT	SEGMENT
_temp$ = -56						; size = 4
_d$ = -44						; size = 4
_c$ = -32						; size = 4
_b$ = -20						; size = 4
_a$ = -8						; size = 4
_test_swap PROC						; COMDAT

; 28   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 252				; 000000fcH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-252]
	mov	ecx, 63					; 0000003fH
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 29   : 	int a = 1;

	mov	DWORD PTR _a$[ebp], 1

; 30   : 	int b = 2;

	mov	DWORD PTR _b$[ebp], 2

; 31   : 
; 32   : 	int c = 3, d = 4;

	mov	DWORD PTR _c$[ebp], 3
	mov	DWORD PTR _d$[ebp], 4

; 33   : 
; 34   : 
; 35   : 	//	printf("a = %d, b = %d", a, b);
; 36   : 	SWAP(a, b);

	mov	eax, DWORD PTR _a$[ebp]
	xor	eax, DWORD PTR _b$[ebp]
	mov	DWORD PTR _a$[ebp], eax
	mov	ecx, DWORD PTR _b$[ebp]
	xor	ecx, DWORD PTR _a$[ebp]
	mov	DWORD PTR _b$[ebp], ecx
	mov	edx, DWORD PTR _a$[ebp]
	xor	edx, DWORD PTR _b$[ebp]
	mov	DWORD PTR _a$[ebp], edx

; 37   : 	//		printf("a = %d, b = %d", a, b);
; 38   : 	//	SWAP(a, a);
; 39   : 	//		printf("a = %d",a);//结果变成了0
; 40   : 
; 41   : 	int temp = c;

	mov	eax, DWORD PTR _c$[ebp]
	mov	DWORD PTR _temp$[ebp], eax

; 42   : 	d = c;

	mov	eax, DWORD PTR _c$[ebp]
	mov	DWORD PTR _d$[ebp], eax

; 43   : 	c = temp;

	mov	eax, DWORD PTR _temp$[ebp]
	mov	DWORD PTR _c$[ebp], eax

; 44   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_test_swap ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\custom\test\练习和实验\算法\交换.c
;	COMDAT _swap
_TEXT	SEGMENT
_temp$ = -8						; size = 4
_a$ = 8							; size = 4
_b$ = 12						; size = 4
_swap	PROC						; COMDAT

; 21   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 204				; 000000ccH
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-204]
	mov	ecx, 51					; 00000033H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 22   : 	int temp = *a;

	mov	eax, DWORD PTR _a$[ebp]
	mov	ecx, DWORD PTR [eax]
	mov	DWORD PTR _temp$[ebp], ecx

; 23   : 	*a = *b;

	mov	eax, DWORD PTR _a$[ebp]
	mov	ecx, DWORD PTR _b$[ebp]
	mov	edx, DWORD PTR [ecx]
	mov	DWORD PTR [eax], edx

; 24   : 	*b = temp;

	mov	eax, DWORD PTR _b$[ebp]
	mov	ecx, DWORD PTR _temp$[ebp]
	mov	DWORD PTR [eax], ecx

; 25   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_swap	ENDP
_TEXT	ENDS
END
