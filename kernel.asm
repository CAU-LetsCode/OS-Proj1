GLOBAL k_printstr 
k_printstr:
    ; void k_printstr(char *s, int row, int col)
    ; set up abp so we can get to the argument s , row and col
    push ebp
    mov ebp, esp
    ; now push any registers you may use during the function, including the flags register
    pushf
    push eax
    push ebx
    ; and so on
    ; now load row and col into eax and ebx
    mov eax, [ebp+12]
    mov ebx, [ebp+16]
    ; calculate the offset into video memory using row and col 
    ; (offset = (row * 80 + col) * 2)
    imul eax, 80
    add eax, ebx
    imul eax, 2

    ; calculate the absolute address of video memory for storing
    ; the next character by adding 0xB8000 and the offset
    add eax, 0xB8000
    mov edi, eax
    ; now load the address of the string into esi
    mov esi, [ebp+8]

    ;if the address where to write the next character has passed the end of video memory (0xB8000+80*25*2) then
    mov eax, 80
    imul eax, 25
    imul eax, 2
    add eax, 0xB8000

print_again: ;loop
    
    cmp edi, eax
    jge loop_end    ;go to loop_end

    cmp BYTE [esi], 0   ;if string address poins to 0 byte then
    je loop_end     ;go to loop_end
    ; mov the next character from the string into video memory 
    ; and increment the string address and the address where to
    ; write the next character (can be done in one instruction: movsb)
    movsb ; move the byte at esi to edi

    ; mov a color byte into the video memory 
    mov BYTE [edi], 31   ;move a color byte say 31, into the memory at edi  

    ;increment the address where to write the next character
    inc edi ; to point to the next character in memory

    jmp print_again
loop_end:  
    ; clean up and return to the caller
    pop ebx
    pop eax
    popf
    pop ebp
    ret ;return
 