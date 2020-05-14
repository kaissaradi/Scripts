TITLE Programming Assignment # 1     (Program1_kais-saradi.asm)

; Author:                       Kais Saradi
; Last Modified:                10/13/2019
; OSU email address:            saradik@oregonstate.edu
; Course number/section:        CS270 section 400
; Project Number:          1    Due Date: 10/13/2019
; Description: This is a program which asks the user for two numbers then calculates 
; the sum, difference, product, quotient, and remainder of the two numbers, followed
; by a terminating message.

;**EC: Validate the second number to be less than the first
;**EC: Display the square of each number

INCLUDE c:\Irvine\Irvine32.inc

.data  
;Strings
author		BYTE	"By: Kais Saradi", 0
projTitle	BYTE	"Elementary Arithmetic      ", 0
intro 		BYTE	"Welcome! Enter 2 integers and I will show you the sum, difference, product, quotient, and remainder", 0
firstPrompt	BYTE 	"Please enter the first positive integer: ", 0
secPrompt	BYTE 	"Please enter the second positive integer: ", 0
goodbye		BYTE	"Impressed? Bye!... ", 0

equalSymbol	BYTE	" = ", 0
addSymbol	BYTE	" + ", 0
subSymbol	BYTE	" - ", 0
multSymbol	BYTE	" * ", 0	
divSmybol	BYTE	" / ", 0
remainSym	BYTE	" Remainder: ", 0
;Variables
firstNum	DWORD	?
secondNum	DWORD	?
sum			DWORD	?
difference	DWORD	?
product		DWORD	?
quotient	DWORD	?
remainder	DWORD	?
;Extra Credit
EC_1		BYTE	"**EC: Validate the second number to be less than the first", 0
EC_2		BYTE	"**EC: Display the square of each number", 0
ECPrompt_1  BYTE    "The second integer entered must be less than the first!", 0
ECPrompt_2  BYTE    "The Square of ", 0 
firstNumSqr DWORD   ?
secNumSqr   DWORD   ?

.code
main PROC
;Introduction
    ;Display program title, name, and intro
	mov		EDX, OFFSET	projTitle
	call	WriteString
    mov		EDX, OFFSET author
	call	WriteString
	call	CrLf
	call	CrLf
	mov		EDX, OFFSET EC_1
	call	WriteString
	call	CrLf
	mov		EDX, OFFSET EC_2
	call	WriteString
	call	CrLf
    mov		EDX, OFFSET intro
    call 	WriteString
    call	CrLf
    call	CrLf

;Get the data from the user and store into two variables
    ;Display prompts and get first and second number
    mov		EDX, OFFSET firstPrompt
    call	WriteString
    call 	ReadInt
    mov		firstNum, EAX
    call 	CrLf
    mov		EDX, OFFSET secPrompt
    call	WriteString
    call 	ReadInt
    mov		secondNum, EAX
    call 	CrLf
    ;EC: Veryify the second number is less than the first
    Cmp 	firstNum, EAX
    jle		EC2

;Calculate the required values
    ;Sum
    mov		EAX, firstNum
    add		EAX, secondNum
    mov		sum, EAX
    ;Difference
    mov 	EAX, firstNum
    sub	 	EAX, secondNum
    mov		difference, EAX
    ;Product
    mov 	EAX, firstNum
    mul	 	secondNum
    mov		product, EAX
    ;Quotient
    mov 	EAX, firstNum
    mov		EDX, 0
    div		secondNum
    mov		remainder, EDX
    mov		quotient, EAX
    ;EC: Square
    mov 	EAX, firstNum
    mul	 	firstNum
    mov		firstNumSqr, EAX
    mov 	EAX, secondNum
    mul	 	secondNum
    mov		secNumSqr, EAX    

;Display the Result to the user
	;display squares for extra credit
    call    CrLf
    mov     EDX, OFFSET ECPrompt_2
    call    WriteString
    mov     EAX, firstNum
    call    WriteDec
    mov     EDX, OFFSET equalSymbol
    call    WriteString
    mov     EAX, firstNumSqr
    call    WriteDec
    call    CrLf
	
    mov     EDX, OFFSET ECPrompt_2
    call    WriteString
    mov     EAX, secondNum
    call    WriteDec
    mov     EDX, OFFSET equalSymbol
    call    WriteString
    mov     EAX, secNumSqr
    call    WriteDec
    call    CrLf
	;display sum
    mov     EAX, firstNum
    call    WriteDec
    mov     EDX, OFFSET addSymbol
    call    WriteString
    mov     EAX, secondNum
    call    WriteDec
    mov     EDX, OFFSET equalSymbol
    call    WriteString
    mov     EAX, sum
    call    WriteDec
    call    CrLf
	;display difference
    mov     EAX, firstNum
    call    WriteDec
    mov     EDX, OFFSET subSymbol
    call    WriteString
    mov     EAX, secondNum
    call    WriteDec
    mov     EDX, OFFSET equalSymbol
    call    WriteString
    mov     EAX, difference
    call    WriteDec
    call    CrLf
	;display product
    mov     EAX, firstNum
    call    WriteDec
    mov     EDX, OFFSET multSymbol
    call    WriteString
    mov     EAX, secondNum
    call    WriteDec
    mov     EDX, OFFSET equalSymbol
    call    WriteString
    mov     EAX, product
    call    WriteDec
    call    CrLf
	;display quotient and remainder
    mov     EAX, firstNum
    call    WriteDec
    mov     EDX, OFFSET divSmybol
    call    WriteString
    mov     EAX, secondNum
    call    WriteDec
    mov     EDX, OFFSET equalSymbol
    call    WriteString
    mov     EAX, quotient
    call    WriteDec
    mov     EDX, OFFSET remainSym
    call    WriteString
    mov     EAX, remainder
    call    WriteDec
    call    CrLf

;Say goodbye and exit the program
	mov 	EDX, OFFSET goodbye
	call	WriteString
	call	CrLf
	exit	
    
;extra credit which displays the error message and exits the program
EC2:
    mov     EDX, OFFSET ECPrompt_1
    call    WriteString
    call    CrLf
	exit

main ENDP
END main
