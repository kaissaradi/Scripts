TITLE Programming Assignment # 5     (Program5_Kais_Saradi.asm)
; Author:               Kais Saradi
; Last Modified:        11/25/19
; OSU email address:    saradik@oregonstate.edu
; Course number/section:CS270
; Project Number:             5    Due Date: 11/24/19
; Description: Introduce the program. Get a user request in the range [min = 15 .. max = 200], 
; Generate request random integers in the range [lo = 100 .. hi = 999], storing them in 
; consecutive elements of an array, Display the list of integers before sorting, 10 numbers per
; line,Sort the list in descending order (i.e., largest first),Calculate and display the median
; value, rounded to the nearest integer,Display the sorted list, 10 numbers per line.
INCLUDE c:\Irvine\Irvine32.inc
    
MIN = 15
MAX = 200
LO = 100
HI = 999
.data
;strings
intro            BYTE    "Sorting Random Integers", 0
author		     BYTE    "Programmed By:    Kais Saradi", 0
prompt1          BYTE    "This program generates random numbers in the range [100 .. 999],", 0
prompt2          BYTE    "displays the original list, sorts the list, and calculates the", 0
prompt3          BYTE    "median value. Finally, it displays the list sorted in descending order.", 0
enterNum         BYTE    "How many numbers should be generated? [15 .. 200]:   ", 0
errorMessage     BYTE    "Invalid Input", 0
unsorted         BYTE    "The unsorted random numbers:", 0
sorted           BYTE    "The sorted list:",0
medianIs         BYTE    "The median is: ",0
bye              BYTE    "Thanks for using my program!!!...  ", 0
spaces           BYTE    "   ",0
;Variables
request          DWORD   ?
list             DWORD   300 DUP(?)
median           DWORD   ?

.code
main PROC
    call    Randomize
    call    introduction

    push    OFFSET request
    call    getData 

    push    OFFSET list
    push    request
    call    fillArray
    ;display unsorted list
    push    OFFSET unsorted
    push    OFFSET list
    push    request
    call    dislpayList
    ;sort
    push    OFFSET list
    push    request
    call    sortList
    ;display median and sorted list
    push    OFFSET list
    push    request
    call    displaymedian

    push    OFFSET sorted
    push    OFFSET list
    push    request
    call    dislpayList

    call    goodbye
    exit 
main ENDP
    
; Introduce the program to the user
; receives: none
; returns: none
; preconditions: none
; registers changed : EDX
introduction PROC               ;display intro and prompts
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
    
; Procedure gets a request of random numbers in the range [15...200]
; receives: address of request variable on the system stack
; returns: user validated input in request variable
; preconditions: none
; registers changed : EAX, EBX, EDX
getData PROC
	push	EBP
	mov	    EBP,ESP
getInput:   ;get user input
	mov	    EDX,OFFSET enterNum ;display prompt 
	call	WriteString		
	call	ReadInt			
    cmp     EAX, MAX
    jg      invalidInput
    cmp     EAX, MIN
    jl      invalidInput
    jmp     valid
invalidInput:   ;Validate Input
        mov     EDX, OFFSET errorMessage
        call    WriteString
        call    CrLf
        jmp     getInput
valid:
	mov	    EBX,[EBP+8]		
	mov	    [EBX],EAX		;stores user value in request
	pop	    EBP
	ret 	4
getData ENDP
    

; Procedure to fill the unsorted List with random integers in the range [100...999]
; receives: Value of the request request and the adress of the list on the top of the system stack
; returns: The unsorted array fillled with request number of random integers in the range
; preconditions: request is at the top of the system stack, request is in the rand [15..200]
; registers changed : EDX, ECX
fillArray PROC
    push	EBP
	mov	    EBP,ESP
	mov	    ECX,[EBP+8]		    ;store request in ECX
	mov	    EDI,[EBP+12]		;address of array in EDI
again:
    mov     EAX, 900
    call    randomRange
    add     EAX, LO             ;call randomrange from lo to hi
	mov	    [EDI],EAX
	add	    EDI,4               ;store random integer to array[i] and loop
	loop	again
	pop	    EBP
	ret	    8
fillArray ENDP      ;code referenced: demo5.asm

; Sorts the array from greatest to least
; receives: the address of the unsorted list and the value of the request on the top of the stack
; returns: the array in sorted order from greatest to least
; preconditions: request must be on the top of the stack
; registers changed : EAX, EBX, ECX, EDI, EDX
sortList PROC
    push	EBP
	mov	    EBP,ESP
	mov	    ECX,[EBP+8]		    ;store request in ECX
    dec     ECX
	mov	    EDI,[EBP+12]		;address of array in EDI
    mov     EBX, 0
indexCheck:         ;outer loop to check index
    cmp     EBX, ECX
    je      endCheck
    mov     EDX, EBX  ;sets index to current index
	mov     EAX, EBX
    inc     EAX
arrayCheck:         ;checks the array from index+1 until the end for a larger value
    cmp     EAX, ECX
    jg      callExchange
	push	ECX ;save register
	mov		ECX, [EDI + EDX*4]
    cmp	    [EDI + EAX*4], ECX   ;compare current value with value in array[j]
	pop		ECX    
    jg      greaterThan
    inc     EAX
    jmp     arrayCheck
greaterThan:        ;set new largest value and continues checking the rest of the array
    mov     EDX, EAX
    inc     EAX
    jmp     arrayCheck
callExchange:       ;push address of value onto stack and call echange procedure
    push    [EDI + EBX*4]
    push    [EDI + EDX*4]
    call    exchange
    inc     EBX     ;increment outer loop and return to the top
    jmp     indexCheck
endCheck:
    pop     EBP
    ret     8
sortList ENDP

; Exchanges the values in the array passed to it
; receives: the memory adress of each index in the array passed on the system stack
; returns: the array with the two values switched
; preconditions: none
; registers changed : EDI, ESI
exchange PROC
    push	EBP
	mov	    EBP,ESP
	push	EAX
    push	ECX     ;set up stack fram and save registers 
    mov	    EAX,[EBP+8]
	mov		ECX,[EBP+12]    ;store old values in EAX, ECX
	mov     [EDI + EBX*4], EAX
	mov		[EDI + EDX*4], ECX  ;Move old values into new positions
	pop		ECX
	pop		EAX ;restore EAX, ECX registers
    pop     EBP
    ret     8
exchange ENDP



; Calculates and display the median value in the sorted list
; receives: the memory address of the sorted list and a value of the request on the top of the stack
; returns: none
; preconditions: request must be on the top of the system stak
; registers changed : EAX, EBX, EDX
displaymedian PROC
    push	EBP
	mov	    EBP,ESP
    call    CrLf
	call	crlf
    mov     EDX, OFFSET medianIs
    call    Writestring
	mov	    EAX,[EBP+8]		    ;store request in ECX
	inc		EAX
	mov		EBX, 2
	mov		EDX, 0
	div		EBX
	dec     EAX
	mov	    ESI,[EBP+12]		;address of array in EDI
    mov	    EAX,[ESI + EAX*4]
	call	WriteDec		
	call	CrLf
    pop     EBP
    ret     8
displaymedian ENDP

    
; Procedure to print the numbers in a list
; receives: the title, address of a list, and request value on the top of the stack
; returns: none
; preconditions: request is at the top of the stack
; registers changed : EAX, EBX, ECX, EDX
dislpayList PROC
    push    EBP
    mov     EBP,ESP
    mov     EDX, [EBP+16]   ;Store Name
    mov     ESI,[EBP+12]    ;Store List   
    mov     ECX,[EBP+8]     ;request to initialize loop
    push    0               ;push count onto the stack
    call    CrLf
    call    WriteString
    call    CrLf
more:
    pop     EAX
	push	EAX
    mov     EDX, 0
    mov		EBX, 10
	div		EBX
    cmp     EDX, 0
	je      newLine
	pop		EAX
    inc     EAX     ;update counter and save to stack
    push    EAX
    jmp     noNewLine
newLine:
	pop		EAX
    inc     EAX     ;update counter and save to stack
	push	EAX
    call	CrLf
noNewLine:
    mov     EAX,[ESI] ;display current element
    call    WriteDec
    mov     EDX, OFFSET spaces
    call    Writestring
    add     ESI, 4 
    loop    more    ;get next element
	pop		EAX
    pop     EBP
    ret     12
dislpayList ENDP    ;code referenced: Lecture20.pdf
    
    
; Procedure to say goodbye to user
; receives: none
; returns: none
; preconditions: program is over and should exit
; registers changed : EDX
goodbye PROC
    call    CrLf
    call    CrLf
    mov     EDX, OFFSET bye
    call    Writestring
    call    CrLf
    ret
goodbye ENDP

END main