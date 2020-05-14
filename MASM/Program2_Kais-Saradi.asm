TITLE Programming Assignment # 2     (Program2_Kais-Saradi.asm)

; Author:                       Kais Saradi
; Last Modified:                10/20/2019
; OSU email address:            saradik@oregonstate.edu
; Course number/section:        CS270 section 400
; Project Number:          2    Due Date: 10/20/2019
; Description: A program which prompts the user for their name and to enter an integer for the nth fibonacci term. 
; After checking to make sure the term is in range [1,46] It then displays each fibonacci term in the sequence
; up to and including the term the user entered. the program then exits

INCLUDE c:\Irvine\Irvine32.inc
;constants
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
endMessage      BYTE    "Thanks, Goodbye,", 0
programBy       BYTE    "Program built by Kais Saradi, ", 0
spaces          BYTE    "       ", 0
;Variables
userName        BYTE    56 DUP(0)
fibNum          DWORD   ?
nthTerm         DWORD   ?
prevTerm        DWORD   ?
counter			DWORD	?

.code
main PROC
;Introduction which displays the project title and name. It then asks for the user
;to enter their name and greets the user
Introduction:
    mov     EDX, OFFSET projTitle
    call    WriteString
    mov     EDX, OFFSET author
    call    WriteString
    call    CrLf
    ;get the user's name
    mov     EDX, OFFSET askName
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET userName 
    mov     ECX, 55      
    call    ReadString
    ;say hello to user
    mov     EDX, OFFSET response
    call    WriteString
    mov     EDX, OFFSET userName
    call    WriteString
    call    CrLf
;Displays the prompts which tell the user what to enter
DisplayInstruction:
    mov     EDX, OFFSET fristPrompt
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET secondPrompt
    call    WriteString
    call    CrLf

;Get the information from the user and calculate if the number is in range (1 - 46)
;if the number is out of range, an error message will be displayed and 
;the block is repeated
getUserInfo:
    mov     EDX, OFFSET askFibonacci
    call    WriteString
    call    CrLf
    call    ReadInt
    mov     fibNum, EAX
    cmp     EAX, UPPERLIMIT
    jg      inputValidation
    cmp     EAX, LOWERLIMIT
    jl      inputValidation
    mov     nthTerm, 1
    mov     prevTerm, 0
    ;set loop counters and start calculations
    mov     ECX, fibNum
	mov		counter, 0
    jmp     displayFibs
    ;Validate Input
    inputValidation:
        mov     EDX, OFFSET errorMessage
        call    WriteString
        jmp     getUserInfo

;Display the first fibonacci number, caclulate the next term in the sequnce
;then caclulate if 4 terms have been display for the line and call a new line 
;if neccessary. Finally, the loop instruction is called to continue displaying
;the next fibonacci number
displayFibs:
    ;set loop counter and display first term
	add		counter, 1
    mov     EAX, nthTerm
    call    WriteDec
    mov     EDX, OFFSET spaces
    call    WriteString
    mov     EAX, fibNum
    ;jump to the goodbye satement if only one term is needed
    cmp     EAX, 1
    je      goodbye 
    ;add the previous term to the current term to get the next term
    ;then update the previous and current term
    mov     EBX, prevTerm
    add     EBX, nthTerm
	mov		EAX, nthTerm
    mov     prevTerm, EAX
    ;check if 4 terms have been displayed and jump to the newline block if neccessary
    mov     nthTerm, EBX
    mov     EDX, 0
    mov     EAX, counter
    mov     EBX, 4
    div     EBX
    cmp     EDX, 0
    je      newLine
    loop    displayFibs
    jmp     goodbye
    newLine:
        call    CrLf
        loop    displayFibs
        jmp     goodbye

;Dislays the author's name and says goodby to the user, then exits the program
goodbye:
    call    CrLf
    mov     EDX, OFFSET programBy
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET endMessage
    call    WriteString
    mov     EDX, OFFSET userName
    call    WriteString
    call    CrLf
	exit
    
main ENDP
END main