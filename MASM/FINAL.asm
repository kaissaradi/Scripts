TITLE Programming Assignment # 6     (Program6_Kais_Saradi.asm)
; Author:               Kais Saradi
; Last Modified:        12/10
; OSU email address:    saradik@oregonstate.edu
; Course number/section:CS270
; Project Number:             6    Due Date: 12/08/19
; Description: Implement macros getString and displayString. Implement and test your
; own ReadVal and WriteVal procedures for unsigned integers. The program will get 10
; valid integers from the user and store the numeric values into an array. The program
; will then display the list of integers, their sum, and the average value of the list
INCLUDE c:\Irvine\Irvine32.inc


getString	MACRO	prompt, stringLocation
    pushad
	mov	    edx, prompt
    call    WriteString
    call    crlf
    mov     edx, stringLocation
    mov     ecx, 11
	call	ReadString 
    popad
ENDM

displayString	MACRO	buffer
	pushad				
	mov	    edx,  buffer
	call	WriteString
	popad	
ENDM
    
.data
;strings
intro            BYTE    "Demonstrating low-level I/O procedures", 0
author		     BYTE    "Programmed By:    Kais Saradi", 0
prompt1          BYTE    "Please provide 10 decimal integers", 0
prompt2          BYTE    "Each number needs to be small enough to fit inside a 32 bit register.", 0
prompt3          BYTE    "After you have finished inputting the raw numbers I will display a list of the integers, their sum, and their average value.", 0
enterNum         BYTE    "Please enter an integer number:     ", 0
errorMessage     BYTE    "ERROR: You did not enter an integer number or your number was too big.", 0
dispPrompt1      BYTE    "You entered the following numbers:", 0
avgprompt        BYTE    "The average is:    ",0
sumprompt        BYTE    "The sum of these numbers is: ",0
bye              BYTE    "Thanks for using my program!!!...  ", 0
comma            BYTE     ", ", 0

;Variables
list             DWORD   11 DUP(?)
sum              DWORD   0
avgIs            DWORD   ?
intVal           BYTE    11 DUP (0)   
testVal          DWORD   ?
.code
main PROC
    ;display intro and instructions on screen
    displayString   OFFSET intro
    call    crlf
    displayString   OFFSET author
    call    crlf
    displayString   OFFSET prompt1
    call    crlf
    displayString   OFFSET prompt2
    call    crlf
    displayString   OFFSET prompt3
    call    crlf

    ;fill array
    push    OFFSET sum      ;28
    push    OFFSET testVal  ;+24
    push    OFFSET enterNum ; +20
    push    OFFSET errorMessage ; +16
    push    OFFSET list ;+12
    push    OFFSET intVal   ;+8
    call    fillArray

    ;display data
    displayString   OFFSET dispPrompt1
    call    crlf
    push    OFFSET sum      ;+24
    push    OFFSET comma    ;+20
    push    OFFSET avgIs    ;+16
    push    OFFSET intVal   ;+12
    push    OFFSET list     ;+8
    call    displayData
    displayString   OFFSET sumPrompt
    push    OFFSET sum      ;+12
    push    OFFSET intVal   ;+8
    call    WriteVal
    call    crlf
    displayString   OFFSET avgprompt
    push    OFFSET avgIs    ;+8
    push    OFFSET intVal   ;+12
    call    WriteVal        
    ;exit
    call    crlf
    displayString   OFFSET bye
    exit 
main ENDP


; Procedure to fill the list with 10 values from the user using the readVal procedure
; receives: memory address of the variables sum and test value, prompts, the list , and string to hold the value
; returns: The array fillled with 10 validated integers that fit in a 32 bit register
; preconditions: adresses passed on the stack in order from top to bottom
; +8 integer string, +12 List, +16 Error Prompt, +20 user Prompt, +24 Test value DWORD, +28 Sum DWORD
; registers changed : None
fillArray PROC
    push	EBP
	mov	    EBP,ESP
    pushad
    mov     EBX, [EBP+28]       ;Move address of sum to EBX
	mov	    ECX, 9		        ;loop  counter
	mov	    EDI,[EBP+12]		;address of array in EDI
again:      ;setup up stack and call ReadVal
    push    [EBP+20]     ;prompt +20
    push    [EBP+24]     ;testval int location +16
    push    [ebp+16]     ;errmsg +12
    push    [ebp+8]      ;string location +8
    call    ReadVal
    mov     eax, [EBP+24]
    add     [EBX], eax   ;calculate sum
	mov	    [EDI],EAX    ;add number to array
	add	    EDI,4        ;store random integer to array[i] and loop
	loop	again        ;loop for 10 integers
    popad
	pop	    EBP
	ret	    24
fillArray ENDP      ;code referenced: demo5.asm

; Procedure to display the ten integer values in an array passed to it and calculate the average of the array
; receives: Address of the sum, comma, average variable, integer string, and list on the top of the stack
; returns: Displays the array on the screen and returns the average stored in the Average variable
; preconditions: Stack is in order +8 List, +12 integer String, +16 average var DWORD, +20 comma string, +24 Sum variable
; registers changed : None
displayData PROC
    push	EBP
	mov	    EBP,ESP
    pushad
	mov	    ECX, 9		    ;loop  counter
	mov	    EDI,[EBP+8]		;address of array in EDI
again:      ;call write val and loop for each value in the array
    push    [EDI]       ;+12int
    push    [EBP+12]    ;+8string
    call    WriteVal
    displayString   [ebp+20]
	add	    EDI,4               
	loop	again   
calcAverage:    ;divide sum by 10 to find the average
    mov     EBX, [ebp+24]   
    mov     EAX, [EBX]
    mov     ECX, [EBP+16]
    mov     ebx, 10
    mov     edx, 0
    div     ebx
    mov     [ECX], eax
    popad
	pop	    EBP
	ret	    20
displayData ENDP      ;code referenced: demo5.asm

; Accepts a numeric string input from the keyboard and will compute the corresponding integer value
; receives: address of intVal, errmsg, testVal DWORD, and prompt for user
; returns: user entered string stored in intVal, error checked integer in testVal
; preconditions: adresses aligned on stack +8 String Location, +12 error message, +16 testVal DWORD, +20 user prompt
; registers changed : None
ReadVal PROC
    push	EBP
	mov	    EBP, ESP
    pushad
    mov     EBX, [EBP+16]   ;move testVal into EBX
beg:    ;setup loop variables and store user input in EDI
    mov     EAX, 0
    mov     [EBX], eax
    mov     ECX, 1
    getString   [ebp+20], [ebp+8]
    mov     ESI, [EBP+8]
top:    ;Validate and convert each digit, then multipy by 10^ factor in ECX
    lodsb   
    cmp		EAX, 0
    je      setPopLoop   
    sub     EAX, 48
    cmp     al,0            
    jl      errorPrompt
    cmp     al,9
    jg      errorPrompt
	push	eax	
	jmp		top
setPopLoop:
	push	0
popNums:
	pop		EAX
	cmp		EAX, 0
	je		endString
    mul     ECX
    jmp     noError
errorPrompt:    ;display error message and reprompt user
    displayString   [ebp+12]
    jmp     beg
noError:    ;add value of digit to the testVal and multiply ECX by 10 
    add     [EBX], EAX
    mov     EDX, 0
    mov     EAX, ECX
    mov     ECX, 10
    mul     ECX
    mov     ECX, EAX
    mov     EAX, 0
    jmp     popNums
	jc      errorPrompt
endString:
    popad
    pop     EBP
    ret     16
ReadVal ENDP


; Accepts a 32 bit unsigned int and display the corresponding ASCII representation on the console 
; receives: The address of the integer to be converted and the string to store it in
; returns: writes the integer to the screen and returns the integer in stored in the adress of the string passed
; preconditions: stack alighned with +8 intVal (string), +12 testVal DWORD
; registers changed : None
WriteVal PROC
    push	EBP
	mov	    EBP,ESP
    pushad
    mov     EDI, [EBP+8]  ;store the locaton of the string  
    mov     EBX, [EBP+12]   
    mov     EAX, [EBX] 
    mov     ecx, 0
pushLastDigit:  ;divides the integer by 10 and pushes the remainder (last digit) onto the stack
    inc     ecx
    mov     ebx, 10
    mov     edx, 0
    div     ebx
    push    edx
    cmp     eax, 0  ;checks if end is reached
    je      popFirstDigit
    jmp     pushLastDigit
popFirstDigit:      ;pops each digit off the stack and adds its ASCII representation to the string
    pop     EAX
    add     EAX, 48
    stosb
    loop    popFirstDigit
    mov     EAX, 0
    stosb       ;and 0 bit to end
    displayString   EDI
    popad   
    pop     EBP
    ret     8
WriteVal ENDP
END main