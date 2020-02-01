PUBLIC encryptTextAsm

.data

polybius dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej polybius przechowuj�cej wska�nik na tablic� Polibiusza
text	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej text przechowuj�cej tekst do zaszyfrowania
output	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej output przechowuj�cej wska�nik na zaszyfrowany tekst
len		 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej len przechowuj�cej d�ugo�� tekstu do zaszyfrowania
sav12	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav12 przechowuj�cej zawarto�� rejestru r12
sav13	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav13 przechowuj�cej zawarto�� rejestru r13
sav14	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav14 przechowuj�cej zawarto�� rejestru r14
sav15	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav15 przechowuj�cej zawarto�� rejestru r15
savrbx	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej savrbx przechowuj�cej zawarto�� rejestru rbx

.code

encryptTextAsm PROC			;pocz�tek procedury

							;Poni�ej nast�puje zapisanie zawarto�ci poszczeg�lnych rejestr�w w zmiennych,
							;dla k�rych pami�� zosta�a zaalokowana powy�ej. Celem takiego dzia�ania jest
							;zapami�tanie oryginalnych warto�ci znajduj�cych si� pocz�tkowo w rejestrach.
	mov polybius, rcx		;zapisanie zawarto�ci rejestru rcx w zmiennej polybius
	mov text, rdx			;zapisanie zawarto�ci rejestru rdx w zmiennej text
	mov output, r8			;zapisanie zawarto�ci rejestru r8 w zmiennej output
	mov len, r9				;zapisanie zawarto�ci rejestru r9 w zmiennej len
	mov sav12, r12			;zapisanie zawarto�ci rejestru r12 w zmiennej sav12
	mov sav13, r13			;zapisanie zawarto�ci rejestru r13 w zmiennej sav13
	mov sav14, r14			;zapisanie zawarto�ci rejestru r14 w zmiennej sav14
	mov sav15, r15			;zapisanie zawarto�ci rejestru r15 w zmiennej sav15
	mov savrbx, rbx			;zapisanie zawarto�ci rejestru rbx w zmiennej savrbx
	mov rbx, 0				;zerowanie rejestru rbx s�u��cego za wska�nik pokazuj�cy na kolejne znaki w 
							;zmiennej output
	mov r12, 0				;zerowanie rejestru r12 s�u��cego za wska�nik pokazuj�cy na kolejne znaki w 
							;zmiennej text	
r12_loop:					;pocz�tek p�tli r12 iteruj�cej po kolejnych znakach w zmiennej text
	mov rax, 0				;zerowanie rejestru rax  	
	mov al, [rdx + r12]		;wpisanie znaku ze zmiennej text o indeksie wskazywanym przez zawarto�� r12 do 
							;o�miobitowego rejestru al 
	mov r15, rax			;wpisanie zawarto�ci rejestru rax do rejestru r15 w celu przechowania jednego 
							;znaku ze zmiennej text w rejestrze r15
	mov r13, 0				;zerowanie rejestru r13 s�u��cego za wska�nik pokazuj�cy na kolejne wiersze
							;tablicy Polibiusza
r13_loop:					;pocz�tek p�tli r13 iteruj�cej po kolejnych wierszach tablicy Polibiusza
	mov r14, 0				;zerowanie rejestru r14 s�u��cego za wska�nik pokazuj�cy na kolejne kolumny
							;tablicy Polibiusza
r14_loop:					;pocz�tek p�tli r14 iteruj�cej po kolejnych kolumnach tablicy Polibiusza
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru rcx
	mov rcx, [rcx + r13]	;wpisanie adresu wiersza tablicy Polibiusza o indeksie wskazywanym przez zawarto�� r13 
							;do rejestru rcx
	mov rax, 0				;zerowanie rejestru rax
	mov al, [rcx + r14]		;wpisanie znaku zawieraj�cego si� w kom�rce tablicy Polibiusza z kolumny wskazywanej 
							;przez r14 do o�miobitowego rejestru al
	cmp rax, r15			;por�wnanie zawarto�ci rejestru rax z zawarto�ci� rejestru r15
	jne different_character	;skok do etykiety different_character, je�li por�wnywane zawarto�ci nie s� r�wne	
	cmp r13, 8				;por�wanie warto�ci 8 z zawarto�ci� rejestru r13 w celu sprawdzenia, czy wska�nik r13
							;pokazuje na pierwszy wiersz tablicy Polibiusza, czyli czy zawarto�� rejestru r15 nale�y
							;do s�owa kluczowego
	je not_in_keyword		;skok do etykiety not_in_keyword, je�li por�wnywane warto�ci s� r�wne	
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru rcx
	mov rcx, [rcx + r13]	;wpisanie adresu wiersza tablicy Polibiusza o indeksie wskazywanym przez zawarto�� r13 
							;do rejestru rcx
	mov rax, 0				;zerowanie rejestru rax
	mov al, [rcx]			;wpisanie znaku zawieraj�cego si� w kom�rce tablicy Polibiusza z kolumny o indeksie 0
							;do o�miobitowego rejestru al
	mov [r8 + rbx], al		;wpisanie zawarto�ci rejestru al do rejestru r8 pod indeks wskazywany przez zawarto�� rbx
	add rbx, 1				;inkrementacja zawarto�ci rejestru rbx w celu przej�cia do kolejnego znaku w zmiennej output
not_in_keyword:				;
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru rcx		
	mov rcx, [rcx]			;wpisanie adresu wiersza tablicy Polibiusza o indeksie 0 do rejestru rcx
	mov rax, 0				;zerowanie rejestru rax
	mov al, [rcx + r14]		;wpisanie znaku zawieraj�cego si� w kom�rce tablicy Polibiusza z kolumny wskazywanej 
							;przez r14 do o�miobitowego rejestru al
	mov [r8 + rbx], al		;wpisanie zawarto�ci rejestru al do rejestru r8 pod indeks wskazywany przez zawarto�� rbx
	add rbx, 1				;inkrementacja zawarto�ci rejestru rbx w celu przej�cia do kolejnego znaku w zmiennej output
	mov r14, 10				;wpisanie warto�ci 10 do rejestru r14 w celu przerwania p�tli r14_loop
	mov r13, 32				;wpisanie warto�ci 32 do rejestru r13 w celu przerwania p�tli r13_loop	
different_character			;
	add r14, 1				;inkrementacja zawarto�ci rejestru r14 w celu przej�cia do kolejnej kolumny tablicy 
							;Polibiusza
	cmp r14, 11				;por�wnanie zawarto�ci rejestru r14 z warto�ci� 11 w celu sprawdzenia, czy iteracja
							;po kolumnach dobieg�a ko�ca
	jne r14_loop			;skok do etykiety r14_loop, je�li por�wnywane warto�ci nie s� r�wne
	add r13, 8				;dodanie warto�ci 8 do zawarto�ci rejestru r13 w celu przej�cia do kolejnego wiersza 
							;tablicy Polibiusza
	cmp r13, 40				;por�wnanie zawarto�ci rejestru r13 z warto�ci� 40 w celu sprawdzenia, czy iteracja
							;po wierszach dobieg�a ko�ca
	jne r13_loop			;skok do etykiety r13_loop, je�li por�wnywane warto�ci nie s� r�wne
	add r12, 1				;inkrementacja zawarto�ci rejestru r12 w celu przej�cia do kolejnego znaku w zmiennej 
							;text
	cmp r12, r9				;por�wnanie zawarto�ci rejestr�w r12 i r9 w celu sprawdzenia, czy iteracja po znakach
							;w zmiennej text dobieg�a ko�ca
	jne r12_loop			;skok do etykiety r12_loop, je�li por�wnywane warto�ci nie s� r�wne
	mov r12, sav12			;zapisanie warto�ci zmiennej sav12 do rejestru r12
	mov r13, sav13			;zapisanie warto�ci zmiennej sav13 do rejestru r13
	mov r14, sav14			;zapisanie warto�ci zmiennej sav14 do rejestru r14
	mov r15, sav15			;zapisanie warto�ci zmiennej sav15 do rejestru r15
	mov rbx, savrbx			;zapisanie warto�ci zmiennej savrbx do rejestru rbx
	ret						;powr�t z procedury
		
encryptTextAsm ENDP			;koniec procedury



END