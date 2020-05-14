TITLE Programming Assignment # 4     (Program4_Kais_Saradi.asm)
; Author:               Kais Saradi
; Last Modified:        11/08/19
; OSU email address:    saradik@oregonstate.edu
; Course number/section:CS270
; Project Number:             4    Due Date: 11/10/19
; Description: a program to calculate composite numbers. First, the user is instructed to enter the number of composites to be displayed,
; and is prompted to enter an integer in the range [1 .. 400]. The user enters a number, n, and the program verifies that 1 <= n <= 400.
; If n is out of range, the user is re- prompted until s/he enters a value in the specified range. The program then calculates and
; displays all of the composite numbers up to and including the nth composite. The results are displayed 10 composites per line
; with at least 3 spaces between the numbers.
INCLUDE c:\Irvine\Irvine32.inc
    
LOWERLIMIT = 1
UPPERLIMIT = 400
.data
;strings
intro            BYTE    "Welcome to the Composite Number Spreadsheet", 0
author		     BYTE    "Programmed By:    Kais Saradi", 0
prompt1          BYTE    "This program is capable of generating a list of composite numbers.", 0
prompt2          BYTE    "Simply let me know how many you would like to see.", 0
prompt3          BYTE    "I’ll accept orders for up to 300 composites.", 0
enterNum         BYTE    "How many composites do you want to view? [1 .. 300]:   ", 0
errorMessage     BYTE    "Out of range. Please try again.", 0
spaces           BYTE    "     ", 0
bye              BYTE    "Thanks for using my program!!!...  ", 0
;Variables
termNumbers      DWORD   ?
isCompositeBool  DWORD   ?
currTerm         DWORD   4
totalComps       DWORD   0

.code
main PROC
    call introduction
    call getUserData
    call showComposites
    call goodbye
    exit 
main ENDP
    
; Introduce the program to the user
; receives: none
; returns: none
; preconditions: none
; registers changed : EDX
introduction PROC
    mov     EDX, OFFSET intro
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET author
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET prompt1
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET prompt2
    call    WriteString
    call    CrLf
    mov     EDX, OFFSET prompt3
    call    WriteString
    call    CrLf
    ret
introduction ENDP
    
; Procedure gets the nth composite term to be dislpayed from the user
; receives: none
; returns: number of composite terms from user stored in termNumbers
; preconditions: none
; registers changed : EAX, EDX
getUserData PROC
    mov     EDX, OFFSET enterNum
    call    WriteString
    call    CrLf
    call    ReadInt
    mov     termNumbers, EAX
    call    validate
    ret
getUserData ENDP
    
; Sub Procedure to validate user input
; receives: users integer value
; returns: none
; preconditions: integer has been stored in EAX
; registers changed : EDX
validate PROC
    cmp     EAX, UPPERLIMIT
    jg      inputValidation
    cmp     EAX, LOWERLIMIT
    jl      inputValidation
    ;Validate Input
    inputValidation:
        mov     EDX, OFFSET errorMessage
        call    WriteString
        call    getUserData
    ret
validate ENDP
    
; Procedure to print composite numbers
; receives: validated input value stored in termNumbers
; returns: none
; preconditions: integer in termNumbers is in range [1 -300]
; registers changed : EAX, EBX, ECX, EDX
showComposites PROC
    call    CrLf 
    mov     ECX, termNumbers 
    compositeLoop:
        call    isComposite
        cmp     isCompositeBool, 0
        jg      printTerm
    skipCurrentTerm:
        add     currTerm, 1
        jmp     compositeLoop
    printTerm:
        mov     EAX, currTerm
        call    writeInt
        mov     EDX, spaces
        call    WriteString
        mov     EDX, 0
        mov     EAX, totalComps
        div     10
        cmp     EDX, 0
        je      newLine
        jmp     noNewLine
    newLine:
        call CrLf
    noNewLine:
        add     currTerm, 1
        loop    compositeLoop  
    ret
showComposites ENDP
    
; Sub Procedure to check if number is composite
; receives: integer starting at 4
; returns: set the compositeBool to 1 [True] or 0 [False]
; preconditions: integer to be checked is stored in currTerm variable
; registers changed : EAX, EBX, EDX
isComposite PROC
    mov     EDX, 0
    mov     EAX, currTerm
    div     2
    cmp     EDX, 0
    je      setTrue
    mov     EDX, 0 
    mov     EAX, currTerm
    div     3
    cmp     EDX, 0
    je      setTrue
    mov     isCompositeBool, 0
    jmp     setFalse
    setTrue:
        mov     isCompositeBool, 1
        add     totalComps, 1
    setFalse:
        ret
isComposite ENDP
    
; Procedure to say goodbye to user
; receives: none
; returns: none
; preconditions: program is over and should exit
; registers changed : EDX
goodbye PROC
    call CrLf;
    call CrLf;
    mov EDX, OFFSET bye
    call Writestring
    call CrLf
    ret
goodbye ENDP

END main