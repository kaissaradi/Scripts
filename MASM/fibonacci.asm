TITLE Programming Assignment # 2     (Program2_kais-saradi.asm)

; Author:                       Kais Saradi
; Last Modified:                10/18/2019
; OSU email address:            saradik@oregonstate.edu
; Course number/section:        CS270 section 400
; Project Number:          2    Due Date: 10/20/2019
; Description: A program which prompts the user to enter the number of Fibonacci terms to be displayed. Advise the user to enter an integer in the range
; validates the users inpute and then calculates and displays all of the Fibonacci numbers up to and including the nth term, then displays a terminating message

INCLUDE c:\Irvine\Irvine32.inc

UPPERLIMIT = 46
LOWERLIMIT = 1

.data
;Strings
projTitle       BYTE    "Fibonacci Numbers", 0 
author          BYTE    "Programmed by Kais Saradi", 0
askName         BYTE    "What's your name?      ", 0
response        BYTE    "Hello, ", 0
fristPrompt     BYTE    "Enter the number of Fibonacci terms to be displayed.", 0
secondPrompt    BYTE    "Provide the number as an integer  in the range [1,46].", 0
askFibonacci    BYTE    "How many Fibonacci terms do you want?", 0
errorMessage    BYTE    "Out of range. Please enter an integer in [1,46]", 0
endMessage      BYTE    "Thanks, goodbye!", 0
programBy       BYTE    "Program built by Kais Saradi, ", 0
;Variables
userName        BYTE    56 DUP(0)
fibonacciNum    DWORD   ?
fibonacci_1     DWORD   ?
fibonacci_2     DWORD   ?
previous1       DWORD   ?
previous2       DWORD   ?
temp            DWORD   ?
moduloFive      DWORD   5
spaces          BYTE    "     ", 0
firstTerm          BYTE    "1", 0 
secondTerm          BYTE    "1      1      ", 0

.code
main PROC
; Introduction
    mov     edx, OFFSET projTitle
    call    WriteString
    mov     edx, OFFSET author
    call    WriteString
    call    CrLf
    ;get the user's name
    mov     edx, OFFSET askName
    call    WriteString
    call    CrLf
    mov     edx, OFFSET userName 
    mov     ecx, 55      
    call    ReadString
    ;say hello to user
    mov     edx, OFFSET response
    call    WriteString
    mov     edx, OFFSET userName
    call    WriteString
    call    CrLf

;Dislpay the Instructions
    mov     edx, OFFSET fristPrompt
    call    WriteString
    call    CrLf
    mov     edx, OFFSET secondPrompt
    call    WriteString
    call    CrLf

;Get Information from the User
;Display Fibs

;prompt the user for input
Prompt:
    mov     edx, OFFSET fristPrompt
    call    WriteString
    call    CrLf
    call    ReadInt
    mov     fibonacciNum, eax
    ;validate user input
    cmp     eax, UPPERLIMIT
    jg      inputValidation
    cmp     eax, LOWERLIMIT
    jl      inputValidation
    je      one 
    cmp     eax, 2
    je      two

;error message
inputValidation:
    mov     edx, OFFSET errorMessage
    call    WriteString
    jmp     Prompt

;calculate and display fibonacci numbers
    mov     ecx, fibonacciNum
    sub     ecx, 3       
    mov     eax, 1
    call    WriteDec
    mov     edx, OFFSET spaces
    call    WriteString
    call    WriteDec
    mov     edx, OFFSET spaces
    call    WriteString
    mov     previous2, eax
    mov     eax, 2
    call    WriteDec
    mov     edx, OFFSET spaces
    call    WriteString
    mov     previous1, eax

    calc:
        add     eax, previous2
        call    WriteDec
        mov     edx, OFFSET spaces
        call    WriteString
        mov     temp, eax
        mov     eax, previous1
        mov     previous2, eax
        mov     eax, temp
        mov     previous1, eax
        mov     edx, ecx
        cdq
        div     moduloFive
        cmp     edx, 0
        jne     skip
        call    CrLf

    skip:
        mov     eax, temp
        loop    calc
        jmp     goodbye

;if the user selects 1
one:
    mov     edx, OFFSET firstTerm
    call        WriteString
    jmp     goodbye

;if the user selects 2
two:
    mov     edx, OFFSET secondTerm
    call        WriteString
    jmp     goodbye



;goodbye
goodbye:
    call    CrLf
    mov     edx, OFFSET programBy
    call    WriteString
    call    CrLf
    mov     edx, OFFSET endMessage
    call    WriteString
    mov     edx, OFFSET userName
    call    WriteString
    call    CrLf
	exit
    
main ENDP
END main