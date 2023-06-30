section .data
    message db 'Hello, world!', 0

section .text
    global _start

_start:
    ; Write the message to stdout
    mov eax, 4       ; System call number for write
    mov ebx, 1       ; File descriptor for stdout
    mov ecx, message ; Address of the message
    mov edx, 13      ; Length of the message
    int 0x80         ; Invoke the kernel interrupt to perform the system call

    ; Terminate the program
    mov eax, 1       ; System call number for exit
    xor ebx, ebx     ; Exit code 0
    int 0x80         ; Invoke the kernel interrupt to perform the system call
