; Listing generated by Microsoft (R) Optimizing Compiler Version 19.00.24215.1 

	TITLE	D:\custom\test\练习和实验\算法\递归.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	___local_stdio_printf_options
PUBLIC	___local_stdio_scanf_options
PUBLIC	__vfprintf_l
PUBLIC	_printf
PUBLIC	__vfscanf_l
PUBLIC	_scanf
PUBLIC	_IsBinrayPower
PUBLIC	_IsBinrayPower_2
PUBLIC	_foo
PUBLIC	_Print
PUBLIC	??_C@_02HAOIJKIC@?$CFc?$AA@			; `string'
EXTRN	__imp____acrt_iob_func:PROC
EXTRN	__imp____stdio_common_vfprintf:PROC
EXTRN	__imp____stdio_common_vfscanf:PROC
EXTRN	@_RTC_CheckStackVars@8:PROC
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
_DATA	SEGMENT
COMM	?_OptionsStorage@?1??__local_stdio_printf_options@@9@9:QWORD							; `__local_stdio_printf_options'::`2'::_OptionsStorage
COMM	?_OptionsStorage@?1??__local_stdio_scanf_options@@9@9:QWORD							; `__local_stdio_scanf_options'::`2'::_OptionsStorage
_DATA	ENDS
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
;	COMDAT ??_C@_02HAOIJKIC@?$CFc?$AA@
CONST	SEGMENT
??_C@_02HAOIJKIC@?$CFc?$AA@ DB '%c', 00H		; `string'
CONST	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\custom\test\练习和实验\算法\递归.c
;	COMDAT _Print
_TEXT	SEGMENT
_a$ = -5						; size = 1
_Print	PROC						; COMDAT

; 137  : {

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

; 138  : 	char a;
; 139  : 	scanf("%c", &a);

	lea	eax, DWORD PTR _a$[ebp]
	push	eax
	push	OFFSET ??_C@_02HAOIJKIC@?$CFc?$AA@
	call	_scanf
	add	esp, 8

; 140  : 	if (a != '#')

	movsx	eax, BYTE PTR _a$[ebp]
	cmp	eax, 35					; 00000023H
	je	SHORT $LN2@Print

; 141  : 		Print();

	call	_Print
$LN2@Print:

; 142  : 	printf("%c", a);

	movsx	eax, BYTE PTR _a$[ebp]
	push	eax
	push	OFFSET ??_C@_02HAOIJKIC@?$CFc?$AA@
	call	_printf
	add	esp, 8

; 143  : }

	push	edx
	mov	ecx, ebp
	push	eax
	lea	edx, DWORD PTR $LN6@Print
	call	@_RTC_CheckStackVars@8
	pop	eax
	pop	edx
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
$LN6@Print:
	DD	1
	DD	$LN5@Print
$LN5@Print:
	DD	-5					; fffffffbH
	DD	1
	DD	$LN4@Print
$LN4@Print:
	DB	97					; 00000061H
	DB	0
_Print	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\custom\test\练习和实验\算法\递归.c
;	COMDAT _foo
_TEXT	SEGMENT
_val$ = -8						; size = 4
_x$ = 8							; size = 4
_n$ = 12						; size = 4
_foo	PROC						; COMDAT

; 117  : {

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

; 118  : 	int val;
; 119  : 	val = 1;

	mov	DWORD PTR _val$[ebp], 1

; 120  : 
; 121  : 	if (n>0)

	cmp	DWORD PTR _n$[ebp], 0
	jle	SHORT $LN2@foo

; 122  : 	{
; 123  : 		if (n % 2 == 1) 

	mov	eax, DWORD PTR _n$[ebp]
	and	eax, -2147483647			; 80000001H
	jns	SHORT $LN5@foo
	dec	eax
	or	eax, -2					; fffffffeH
	inc	eax
$LN5@foo:
	cmp	eax, 1
	jne	SHORT $LN3@foo

; 124  : 			val = val *x;

	mov	eax, DWORD PTR _val$[ebp]
	imul	eax, DWORD PTR _x$[ebp]
	mov	DWORD PTR _val$[ebp], eax
$LN3@foo:

; 125  : 		val = val * foo(x*x, n / 2);

	mov	eax, DWORD PTR _n$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	push	eax
	mov	eax, DWORD PTR _x$[ebp]
	imul	eax, DWORD PTR _x$[ebp]
	push	eax
	call	_foo
	add	esp, 8
	imul	eax, DWORD PTR _val$[ebp]
	mov	DWORD PTR _val$[ebp], eax
$LN2@foo:

; 126  : 	}
; 127  : 	return val;

	mov	eax, DWORD PTR _val$[ebp]

; 128  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_foo	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\custom\test\练习和实验\算法\递归.c
;	COMDAT _IsBinrayPower_2
_TEXT	SEGMENT
_tmp$ = -8						; size = 4
_num$ = 8						; size = 4
_IsBinrayPower_2 PROC					; COMDAT

; 28   : {

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

; 29   : 	int tmp = num;

	mov	eax, DWORD PTR _num$[ebp]
	mov	DWORD PTR _tmp$[ebp], eax

; 30   : 	//0的时候返回FALSE
; 31   : 	if (tmp == 0 )

	cmp	DWORD PTR _tmp$[ebp], 0
	jne	SHORT $LN2@IsBinrayPo

; 32   : 	{
; 33   : 		return FALSE;

	xor	eax, eax
	jmp	SHORT $LN1@IsBinrayPo

; 34   : 	}

	jmp	SHORT $LN1@IsBinrayPo
$LN2@IsBinrayPo:

; 35   : 	else if (tmp == 1)

	cmp	DWORD PTR _tmp$[ebp], 1
	jne	SHORT $LN4@IsBinrayPo

; 36   : 	{
; 37   : 		// 1 = 2 ^ 0，所以返回TRUE；
; 38   : 		return TRUE;

	mov	eax, 1
	jmp	SHORT $LN1@IsBinrayPo

; 39   : 	}

	jmp	SHORT $LN1@IsBinrayPo
$LN4@IsBinrayPo:

; 40   : 	else
; 41   : 	{
; 42   : 		if (tmp % 2 == 0)

	mov	eax, DWORD PTR _tmp$[ebp]
	and	eax, -2147483647			; 80000001H
	jns	SHORT $LN9@IsBinrayPo
	dec	eax
	or	eax, -2					; fffffffeH
	inc	eax
$LN9@IsBinrayPo:
	test	eax, eax
	jne	SHORT $LN6@IsBinrayPo

; 43   : 		{
; 44   : 			return IsBinrayPower_2(num / 2);

	mov	eax, DWORD PTR _num$[ebp]
	cdq
	sub	eax, edx
	sar	eax, 1
	push	eax
	call	_IsBinrayPower_2
	add	esp, 4
	jmp	SHORT $LN1@IsBinrayPo

; 45   : 		}

	jmp	SHORT $LN1@IsBinrayPo
$LN6@IsBinrayPo:

; 46   : 		else
; 47   : 			return FALSE;

	xor	eax, eax
$LN1@IsBinrayPo:

; 48   : 	}
; 49   : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 204				; 000000ccH
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_IsBinrayPower_2 ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\custom\test\练习和实验\算法\递归.c
;	COMDAT _IsBinrayPower
_TEXT	SEGMENT
tv67 = -196						; size = 4
_num$ = 8						; size = 4
_IsBinrayPower PROC					; COMDAT

; 22   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 196				; 000000c4H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-196]
	mov	ecx, 49					; 00000031H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 23   : 	return (num & (num - 1)) ? FALSE : TRUE;

	mov	eax, DWORD PTR _num$[ebp]
	sub	eax, 1
	and	eax, DWORD PTR _num$[ebp]
	je	SHORT $LN3@IsBinrayPo
	mov	DWORD PTR tv67[ebp], 0
	jmp	SHORT $LN4@IsBinrayPo
$LN3@IsBinrayPo:
	mov	DWORD PTR tv67[ebp], 1
$LN4@IsBinrayPo:
	mov	eax, DWORD PTR tv67[ebp]

; 24   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
_IsBinrayPower ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.10240.0\ucrt\stdio.h
;	COMDAT _scanf
_TEXT	SEGMENT
__ArgList$ = -20					; size = 4
__Result$ = -8						; size = 4
__Format$ = 8						; size = 4
_scanf	PROC						; COMDAT

; 1276 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 216				; 000000d8H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-216]
	mov	ecx, 54					; 00000036H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 1277 :     int _Result;
; 1278 :     va_list _ArgList;
; 1279 :     __crt_va_start(_ArgList, _Format);

	lea	eax, DWORD PTR __Format$[ebp+4]
	mov	DWORD PTR __ArgList$[ebp], eax

; 1280 :     _Result = _vfscanf_l(stdin, _Format, NULL, _ArgList);

	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR __Format$[ebp]
	push	ecx
	mov	esi, esp
	push	0
	call	DWORD PTR __imp____acrt_iob_func
	add	esp, 4
	cmp	esi, esp
	call	__RTC_CheckEsp
	push	eax
	call	__vfscanf_l
	add	esp, 16					; 00000010H
	mov	DWORD PTR __Result$[ebp], eax

; 1281 :     __crt_va_end(_ArgList);

	mov	DWORD PTR __ArgList$[ebp], 0

; 1282 :     return _Result;

	mov	eax, DWORD PTR __Result$[ebp]

; 1283 : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 216				; 000000d8H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_scanf	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.10240.0\ucrt\stdio.h
;	COMDAT __vfscanf_l
_TEXT	SEGMENT
__Stream$ = 8						; size = 4
__Format$ = 12						; size = 4
__Locale$ = 16						; size = 4
__ArgList$ = 20						; size = 4
__vfscanf_l PROC					; COMDAT

; 1058 : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 1059 :     return __stdio_common_vfscanf(

	mov	esi, esp
	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	mov	ecx, DWORD PTR __Locale$[ebp]
	push	ecx
	mov	edx, DWORD PTR __Format$[ebp]
	push	edx
	mov	eax, DWORD PTR __Stream$[ebp]
	push	eax
	call	___local_stdio_scanf_options
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR __imp____stdio_common_vfscanf
	add	esp, 24					; 00000018H
	cmp	esi, esp
	call	__RTC_CheckEsp

; 1060 :         _CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
; 1061 :         _Stream, _Format, _Locale, _ArgList);
; 1062 : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
__vfscanf_l ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.10240.0\ucrt\stdio.h
;	COMDAT _printf
_TEXT	SEGMENT
__ArgList$ = -20					; size = 4
__Result$ = -8						; size = 4
__Format$ = 8						; size = 4
_printf	PROC						; COMDAT

; 950  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 216				; 000000d8H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-216]
	mov	ecx, 54					; 00000036H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 951  :     int _Result;
; 952  :     va_list _ArgList;
; 953  :     __crt_va_start(_ArgList, _Format);

	lea	eax, DWORD PTR __Format$[ebp+4]
	mov	DWORD PTR __ArgList$[ebp], eax

; 954  :     _Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);

	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	push	0
	mov	ecx, DWORD PTR __Format$[ebp]
	push	ecx
	mov	esi, esp
	push	1
	call	DWORD PTR __imp____acrt_iob_func
	add	esp, 4
	cmp	esi, esp
	call	__RTC_CheckEsp
	push	eax
	call	__vfprintf_l
	add	esp, 16					; 00000010H
	mov	DWORD PTR __Result$[ebp], eax

; 955  :     __crt_va_end(_ArgList);

	mov	DWORD PTR __ArgList$[ebp], 0

; 956  :     return _Result;

	mov	eax, DWORD PTR __Result$[ebp]

; 957  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 216				; 000000d8H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
_printf	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.10240.0\ucrt\stdio.h
;	COMDAT __vfprintf_l
_TEXT	SEGMENT
__Stream$ = 8						; size = 4
__Format$ = 12						; size = 4
__Locale$ = 16						; size = 4
__ArgList$ = 20						; size = 4
__vfprintf_l PROC					; COMDAT

; 638  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 639  :     return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);

	mov	esi, esp
	mov	eax, DWORD PTR __ArgList$[ebp]
	push	eax
	mov	ecx, DWORD PTR __Locale$[ebp]
	push	ecx
	mov	edx, DWORD PTR __Format$[ebp]
	push	edx
	mov	eax, DWORD PTR __Stream$[ebp]
	push	eax
	call	___local_stdio_printf_options
	mov	ecx, DWORD PTR [eax+4]
	push	ecx
	mov	edx, DWORD PTR [eax]
	push	edx
	call	DWORD PTR __imp____stdio_common_vfprintf
	add	esp, 24					; 00000018H
	cmp	esi, esp
	call	__RTC_CheckEsp

; 640  : }

	pop	edi
	pop	esi
	pop	ebx
	add	esp, 192				; 000000c0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	0
__vfprintf_l ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.10240.0\ucrt\corecrt_stdio_config.h
;	COMDAT ___local_stdio_scanf_options
_TEXT	SEGMENT
___local_stdio_scanf_options PROC			; COMDAT

; 82   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 83   :     static unsigned __int64 _OptionsStorage;
; 84   :     return &_OptionsStorage;

	mov	eax, OFFSET ?_OptionsStorage@?1??__local_stdio_scanf_options@@9@9 ; `__local_stdio_scanf_options'::`2'::_OptionsStorage

; 85   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
___local_stdio_scanf_options ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File c:\program files (x86)\windows kits\10\include\10.0.10240.0\ucrt\corecrt_stdio_config.h
;	COMDAT ___local_stdio_printf_options
_TEXT	SEGMENT
___local_stdio_printf_options PROC			; COMDAT

; 73   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 192				; 000000c0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-192]
	mov	ecx, 48					; 00000030H
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 74   :     static unsigned __int64 _OptionsStorage;
; 75   :     return &_OptionsStorage;

	mov	eax, OFFSET ?_OptionsStorage@?1??__local_stdio_printf_options@@9@9 ; `__local_stdio_printf_options'::`2'::_OptionsStorage

; 76   : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
___local_stdio_printf_options ENDP
_TEXT	ENDS
END
