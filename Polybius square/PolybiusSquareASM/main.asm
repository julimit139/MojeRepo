PUBLIC encryptTextAsm

.data

polybius dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej polybius przechowuj¹cej wskaŸnik na tablicê Polibiusza
text	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej text przechowuj¹cej tekst do zaszyfrowania
output	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej output przechowuj¹cej wskaŸnik na zaszyfrowany tekst
len		 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej len przechowuj¹cej d³ugoœæ tekstu do zaszyfrowania
sav12	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav12 przechowuj¹cej zawartoœæ rejestru r12
sav13	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav13 przechowuj¹cej zawartoœæ rejestru r13
sav14	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav14 przechowuj¹cej zawartoœæ rejestru r14
sav15	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav15 przechowuj¹cej zawartoœæ rejestru r15

.code

encryptTextAsm PROC			;

							;Poni¿ej nastêpuje zapisanie zawartoœci poszczególnych rejestrów w zmiennych,
							;dla kórych pamiêæ zosta³a zaalokowana powy¿ej. Celem takiego dzia³ania jest
							;zapamiêtanie oryginalnych wartoœci znajduj¹cych siê pocz¹tkowo w rejestrach.
	mov polybius, rcx		;zapisanie zawartoœci rejestru rcx w zmiennej polybius
	mov text, rdx			;zapisanie zawartoœci rejestru rdx w zmiennej text
	mov output, r8			;zapisanie zawartoœci rejestru r8 w zmiennej output
	mov len, r9				;zapisanie zawartoœci rejestru r9 w zmiennej len
	mov sav12, r12			;zapisanie zawartoœci rejestru r12 w zmiennej sav12
	mov sav13, r13			;zapisanie zawartoœci rejestru r13 w zmiennej sav13
	mov sav14, r14			;zapisanie zawartoœci rejestru r14 w zmiennej sav14
	mov sav15, r15			;zapisanie zawartoœci rejestru r15 w zmiennej sav15
	mov rbx, 0				;wpisanie wartoœci 0 do rejestru rbx s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne 
							;elementy zmiennej output
	mov r12, 0				;wpisanie wartoœci 0 do rejestru r12 s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne 
							;elementy zmiennej text	
r12_loop:					;pocz¹tek pêtli r12 iteruj¹cej po kolejnych elementach zmiennej text
	mov rax, 0				;wpisanie wartoœci 0 do rejestru rax 	
	mov al, [rdx + r12]		;
	mov r15, rax			;		
	mov r13, 0				;wpisanie wartoœci 0 do rejestru r13 s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne
							;wiersze tablicy Polibiusza
r13_loop:					;pocz¹tek pêtli r13 iteruj¹cej po kolejnych wierszach tablicy Polibiusza
	mov r14, 0				;wpisanie wartoœci 0 do rejestru r14 s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne
							;kolumny tablicy Polibiusza
r14_loop:					;pocz¹tek pêtli r14 iteruj¹cej po kolejnych kolumnach tablicy Polibiusza
	mov rcx, polybius		;
	mov rcx, [rcx + r13]	;
	mov rax, 0				;
	mov al, [rcx + r14]		;
	cmp rax, r15			;
	jne different_letter	;	
	cmp r13, 8				;
	je not_in_keyword		;
	mov rcx, polybius		;
	mov rcx, [rcx + r13]	;
	mov rax, 0				;
	mov al, [rcx]			;
	mov [r8 + rbx], al		;
	add rbx, 1				;
not_in_keyword:				;
	mov rcx, polybius		;		
	mov rcx, [rcx]			;
	mov rax, 0				;
	mov al, [rcx + r14]		;
	mov [r8 + rbx], al		;
	add rbx, 1				;
	mov r14, 10				;
different_letter:			;
	add r14, 1				;
	cmp r14, 11				;
	jne r14_loop			;
	add r13, 8				;
	cmp r13, 40				;
	jne r13_loop			;
	add r12, 1				;
	cmp r12, r9				;
	jne r12_loop			;
	mov r12, sav12			;
	mov r13, sav13			;
	mov r14, sav14			;
	mov r15, sav15			;
	ret						;
		
encryptTextAsm ENDP



END