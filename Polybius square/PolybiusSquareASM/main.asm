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
savrbx	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej savrbx przechowuj¹cej zawartoœæ rejestru rbx

.code

encryptTextAsm PROC			;pocz¹tek procedury

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
	mov savrbx, rbx			;zapisanie zawartoœci rejestru rbx w zmiennej savrbx
	mov rbx, 0				;zerowanie rejestru rbx s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne znaki w 
							;zmiennej output
	mov r12, 0				;zerowanie rejestru r12 s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne znaki w 
							;zmiennej text	
r12_loop:					;pocz¹tek pêtli r12 iteruj¹cej po kolejnych znakach w zmiennej text
	mov rax, 0				;zerowanie rejestru rax  	
	mov al, [rdx + r12]		;wpisanie znaku ze zmiennej text o indeksie wskazywanym przez zawartoœæ r12 do 
							;oœmiobitowego rejestru al 
	mov r15, rax			;wpisanie zawartoœci rejestru rax do rejestru r15 w celu przechowania jednego 
							;znaku ze zmiennej text w rejestrze r15
	mov r13, 0				;zerowanie rejestru r13 s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne wiersze
							;tablicy Polibiusza
r13_loop:					;pocz¹tek pêtli r13 iteruj¹cej po kolejnych wierszach tablicy Polibiusza
	mov r14, 0				;zerowanie rejestru r14 s³u¿¹cego za wskaŸnik pokazuj¹cy na kolejne kolumny
							;tablicy Polibiusza
r14_loop:					;pocz¹tek pêtli r14 iteruj¹cej po kolejnych kolumnach tablicy Polibiusza
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru rcx
	mov rcx, [rcx + r13]	;wpisanie adresu wiersza tablicy Polibiusza o indeksie wskazywanym przez zawartoœæ r13 
							;do rejestru rcx
	mov rax, 0				;zerowanie rejestru rax
	mov al, [rcx + r14]		;wpisanie znaku zawieraj¹cego siê w komórce tablicy Polibiusza z kolumny wskazywanej 
							;przez r14 do oœmiobitowego rejestru al
	cmp rax, r15			;porównanie zawartoœci rejestru rax z zawartoœci¹ rejestru r15
	jne different_character	;skok do etykiety different_character, jeœli porównywane zawartoœci nie s¹ równe	
	cmp r13, 8				;porówanie wartoœci 8 z zawartoœci¹ rejestru r13 w celu sprawdzenia, czy wskaŸnik r13
							;pokazuje na pierwszy wiersz tablicy Polibiusza, czyli czy zawartoœæ rejestru r15 nale¿y
							;do s³owa kluczowego
	je not_in_keyword		;skok do etykiety not_in_keyword, jeœli porównywane wartoœci s¹ równe	
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru rcx
	mov rcx, [rcx + r13]	;wpisanie adresu wiersza tablicy Polibiusza o indeksie wskazywanym przez zawartoœæ r13 
							;do rejestru rcx
	mov rax, 0				;zerowanie rejestru rax
	mov al, [rcx]			;wpisanie znaku zawieraj¹cego siê w komórce tablicy Polibiusza z kolumny o indeksie 0
							;do oœmiobitowego rejestru al
	mov [r8 + rbx], al		;wpisanie zawartoœci rejestru al do rejestru r8 pod indeks wskazywany przez zawartoœæ rbx
	add rbx, 1				;inkrementacja zawartoœci rejestru rbx w celu przejœcia do kolejnego znaku w zmiennej output
not_in_keyword:				;
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru rcx		
	mov rcx, [rcx]			;wpisanie adresu wiersza tablicy Polibiusza o indeksie 0 do rejestru rcx
	mov rax, 0				;zerowanie rejestru rax
	mov al, [rcx + r14]		;wpisanie znaku zawieraj¹cego siê w komórce tablicy Polibiusza z kolumny wskazywanej 
							;przez r14 do oœmiobitowego rejestru al
	mov [r8 + rbx], al		;wpisanie zawartoœci rejestru al do rejestru r8 pod indeks wskazywany przez zawartoœæ rbx
	add rbx, 1				;inkrementacja zawartoœci rejestru rbx w celu przejœcia do kolejnego znaku w zmiennej output
	mov r14, 10				;wpisanie wartoœci 10 do rejestru r14 w celu przerwania pêtli r14_loop
	mov r13, 32				;wpisanie wartoœci 32 do rejestru r13 w celu przerwania pêtli r13_loop	
different_character			;
	add r14, 1				;inkrementacja zawartoœci rejestru r14 w celu przejœcia do kolejnej kolumny tablicy 
							;Polibiusza
	cmp r14, 11				;porównanie zawartoœci rejestru r14 z wartoœci¹ 11 w celu sprawdzenia, czy iteracja
							;po kolumnach dobieg³a koñca
	jne r14_loop			;skok do etykiety r14_loop, jeœli porównywane wartoœci nie s¹ równe
	add r13, 8				;dodanie wartoœci 8 do zawartoœci rejestru r13 w celu przejœcia do kolejnego wiersza 
							;tablicy Polibiusza
	cmp r13, 40				;porównanie zawartoœci rejestru r13 z wartoœci¹ 40 w celu sprawdzenia, czy iteracja
							;po wierszach dobieg³a koñca
	jne r13_loop			;skok do etykiety r13_loop, jeœli porównywane wartoœci nie s¹ równe
	add r12, 1				;inkrementacja zawartoœci rejestru r12 w celu przejœcia do kolejnego znaku w zmiennej 
							;text
	cmp r12, r9				;porównanie zawartoœci rejestrów r12 i r9 w celu sprawdzenia, czy iteracja po znakach
							;w zmiennej text dobieg³a koñca
	jne r12_loop			;skok do etykiety r12_loop, jeœli porównywane wartoœci nie s¹ równe
	mov r12, sav12			;zapisanie wartoœci zmiennej sav12 do rejestru r12
	mov r13, sav13			;zapisanie wartoœci zmiennej sav13 do rejestru r13
	mov r14, sav14			;zapisanie wartoœci zmiennej sav14 do rejestru r14
	mov r15, sav15			;zapisanie wartoœci zmiennej sav15 do rejestru r15
	mov rbx, savrbx			;zapisanie wartoœci zmiennej savrbx do rejestru rbx
	ret						;powrót z procedury
		
encryptTextAsm ENDP			;koniec procedury



END