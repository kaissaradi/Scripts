TITLE Programming Assignment # 3     (Program3_Kais-Saradi.asm)

; Author:                       Kais Saradi
; Last Modified:                11/04/2019
; OSU email address:            saradik@oregonstate.edu
; Course number/section:        CS270 section 400
; Project Number:          2    Due Date: 11/03/2019
; Description: A program which prompts the user for their name and to enter negative numbers in the range 
; [-150, -1] until a non negative number is entered, and displays the rounded average
;**EC: Number the lines during user input

INCLUDE c:\Irvine\Irvine32.inc
;constants
LOWERLIMIT = -150

.data
;Strings
projTitle       BYTE    "Welcome to the Accumulator     ", 0 
author          BYTE    "By Kais Saradi", 0
askName         BYTE    "What's your name?      ", 0
response        BYTE    "Hello, ", 0
fristPrompt     BYTE    "Please enter numbers in the range [-150, -1].", 0
secondPrompt    BYTE    "Enter a non-negative number when you are finished to see results.", 0
askNum          BYTE    "Enter number:  ", 0
errorMessage    BYTE    "Ignored that number! It needs to be in the range [-150, -1].", 0
noNumbers       BYTE    "no numbers entered", 0
responseNum1    BYTE    "You entered ", 0
responseNum2    BYTE    " valid numbers", 0
responseSum     BYTE    "The sum of your valid numbers is:  ", 0
responseAvg     BYTE    "The rounded average is:  ", 0
endMessage      BYTE    "Thank you for testing my code! It's been a pleasure to meet you,", 0
ExtraCredit     BYTE    "**EC: Number the lines during user input", 0
EC1             BYTE    "(", 0
EC2             BYTE    ")", 0

;Variables
userName        BYTE    56 DUP(0)
validNums       DWORD   0
sum             DWORD   0
average         DWORD   0
counter			DWORD	1

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
    mov     EDX, OFFSET ExtraCredit
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

;Get the information from the user and calculate if the number is in range [-150, -1]
;if the number is out of range, an error message will be displayed and 
;the block is repeated
negativeIntLoop:
    ;**EC: Number the lines during user input
    mov     EDX, OFFSET EC1
    call    WriteString
    mov     EAX, counter
    call    WriteDec
    mov     EDX, OFFSET EC2
    call    WriteString
    ;ask the user to enter an integer
    mov     EDX, OFFSET askNum
    call    WriteString
    call    ReadInt
    ;check if the number is in range and jump to the calculate block
    jns      goodbye
    cmp     EAX, LOWERLIMIT
    jl      inputValidation
    jmp     calculate
    ;Validates Input by dislpaying the error message and jumping back to the negativeIntLoop block
    inputValidation:
        mov     EDX, OFFSET errorMessage
        call    WriteString
        call    CrLf
        jmp     negativeIntLoop

;The accumulator which calculates the number of valid integers entered, the sum
;and the rounded average of the integers
calculate:
    ;update variables
    add      validNums, 1
    add      counter, 1
    add      sum, EAX
    mov      EAX, sum
    neg      EAX
    mov      EBX, validNums
	mov		 EDX, 0
    div      EBX
    mov      average, EAX
    ;jump back to negativeIntLoopr to continue the loop
    jmp      negativeIntLoop

;Dislays the total number of valid integers entered, the sum
;and the rounded average, then says goodbye to the user and exits the program
goodbye:
    call    CrLf
    cmp     validNums, 0
    je      noInputBye
    ;Display the total, sum and average
    mov     EDX, OFFSET responseNum1
    call    WriteString
    mov     EAX, validNums
    call    WriteDec
    mov     EDX, OFFSET responseNum2
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET responseSum
    call    WriteString
    mov     EAX, sum
    call    WriteInt
    call    CrLf
    mov     EDX, OFFSET responseAvg
    call    WriteString
    mov     EAX, average
    neg     EAX
    call    WriteInt
    call    CrLf
    ;say goodbye
    mov     EDX, OFFSET endMessage
    call    WriteString
    mov     EDX, OFFSET userName
    call    WriteString
    call    CrLf
	exit
noInputBye:
    call    CrLf
    mov     EDX, OFFSET noNumbers
    call    WriteString
    call    CrLf
    exit
main ENDP

END main