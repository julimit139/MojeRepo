PUBLIC encryptTextAsm

.data

polybius dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej polybius przechowuj¹cej wskaŸnik 
							;na tablicê Polibiusza
text	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej text przechowuj¹cej tekst do 
							;zaszyfrowania
output	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej output przechowuj¹cej wskaŸnik na 
							;zaszyfrowany tekst
len		 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej len przechowuj¹cej d³ugoœæ tekstu 
							;do zaszyfrowania
sav12	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav12 przechowuj¹cej zawartoœæ 
							;rejestru r12
sav13	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav13 przechowuj¹cej zawartoœæ 
							;rejestru r13
sav14	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav14 przechowuj¹cej zawartoœæ 
							;rejestru r14
sav15	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej sav15 przechowuj¹cej zawartoœæ 
							;rejestru r15
savrbx	 dq 0				;alokacja oœmiu bajtów pamiêci dla zmiennej savrbx przechowuj¹cej zawartoœæ 
							;rejestru rbx

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
	mov rbx, 0				;zerowanie rejestru rbx s³u¿¹cego za licznik wskazuj¹cy na kolejne znaki w 
							;zaszyfrowanym tekœcie
	mov r12, 0				;zerowanie rejestru r12 s³u¿¹cego za licznik wskazuj¹cy na kolejne znaki w 
							;tekœcie do zaszyfrowania 
r12_loop:					;pocz¹tek pêtli iteruj¹cej po kolejnych znakach tekstu do zaszyfrowania
	mov rax, 0				;zerowanie rejestru, do którego bêdzie wpisywany znak 	
	mov al, [rdx + r12]		;wpisanie znaku o indeksie wskazywanym przez licznik znaków w tekœcie do
							;najni¿szych oœmiu bitów zerowanego wczeœniej rejestru
	mov r15, rax			;wpisanie zawartoœci rejestru zawieraj¹cego znak do rejestru r15 w celu 
							;przechowania znaku
	mov r13, 0				;zerowanie rejestru r13 s³u¿¹cego za licznik wskazuj¹cy na kolejne wiersze
							;tablicy Polibiusza
r13_loop:					;pocz¹tek pêtli iteruj¹cej po kolejnych wierszach tablicy Polibiusza
	mov r14, 0				;zerowanie rejestru r14 s³u¿¹cego za licznik wskazuj¹cy na kolejne kolumny
							;tablicy Polibiusza
r14_loop:					;pocz¹tek pêtli iteruj¹cej po kolejnych kolumnach tablicy Polibiusza
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru
	mov rcx, [rcx + r13]	;wpisanie do tego samego rejestru adresu wiersza tablicy Polibiusza o indeksie
							;wskazywanym przez licznik wierszy
	mov rax, 0				;zerowanie rejestru, do którego bêdzie wpisywany znak
	mov al, [rcx + r14]		;wpisanie znaku zawieraj¹cego siê w komórce tablicy Polibiusza z kolumny 
							;wskazywanej przez licznik kolumn do najni¿szych oœmiu bitów zerowanego 
							;wczeœniej rejestru
	cmp rax, r15			;porównanie znaku z tablicy z zapamiêtanym wczeœniej znakiem nale¿¹cym do
							;tekstu do zaszyfrowania
	jne another_letter		;skok do etykiety another_letter, jeœli porównywane wartoœci nie s¹ równe	
	cmp r13, 8				;sprawdzenie, czy zapamiêtany znak nale¿y do s³owa kluczowego
	je is_in_keyword		;skok do etykiety is_in_keyword, jeœli porównywane wartoœci s¹ równe	
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru
	mov rcx, [rcx + r13]	;wpisanie do tego samego rejestru adresu wiersza tablicy Polibiusza o indeksie
							;wskazywanym przez licznik wierszy
	mov rax, 0				;zerowanie rejestru, do którego bêdzie wpisywany znak
	mov al, [rcx]			;wpisanie cyfry zawieraj¹cej siê w komórce tablicy Polibiusza w zerowej kolumnie
							;do najni¿szych oœmiu bitów zerowanego wczeœniej rejestru
	mov [r8 + rbx], al		;wpisanie zawartoœci rejestru do tablicy z zaszyfrowanym tekstem pod indeks
							;wskazywany przez licznik znaków w zaszyfrowanym tekœcie
	add rbx, 1				;inkrementacja licznika znaków w zaszyfrowanym tekœcie
is_in_keyword:				
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru		
	mov rcx, [rcx]			;wpisanie do tego samego rejestru adresu zerowego wiersza tablicy Polibiusza
	mov rax, 0				;zerowanie rejestru, do którego bêdzie wpisywany znak
	mov al, [rcx + r14]		;wpisanie cyfry zawieraj¹cej siê w komórce tablicy Polibiusza z kolumny
							;o indeksie wskazywanym przez licznik kolumn do najni¿szych oœmiu bitów 
							;zerowanego wczeœniej rejestru
	mov [r8 + rbx], al		;wpisanie zawartoœci rejestru do tablicy z zaszyfrowanym tekstem pod indeks
							;wskazywany przez licznik znaków w zaszyfrowanym tekœcie
	add rbx, 1				;inkrementacja licznika znaków w zaszyfrowanym tekœcie
	mov r14, 10				;zwiêkszenie wartoœci licznika kolumn do takiej, aby nast¹pi³o przerwanie
							;wykonywania pêtli iteruj¹cej po kolumnach
	mov r13, 32				;zwiêkszenie wartoœci licznika wierszy do takiej, aby nast¹pi³o przerwanie
							;wykonywania pêtli iteruj¹cej po wierszach
another_letter:				
	add r14, 1				;inkrementacja licznika kolumn
	cmp r14, 11				;sprawdzenie, czy licznik wskazuje na ostatni¹ kolumnê
	jne r14_loop			;skok do etykiety r14_loop, jeœli porównywane wartoœci nie s¹ równe
	add r13, 8				;inkrementacja licznika wierszy
	cmp r13, 40				;sprawdzenie, czy licznik wskazuje na ostatni wiersz
	jne r13_loop			;skok do etykiety r13_loop, jeœli porównywane wartoœci nie s¹ równe
	add r12, 1				;inkrementacja licznika znaków w tekœcie do zaszyfrowania
	cmp r12, r9				;sprawdzenie, czy licznik wskazuje na ostatni znak w tekœcie
	jne r12_loop			;skok do etykiety r12_loop, jeœli porównywane wartoœci nie s¹ równe
	mov r12, sav12			;zapisanie wartoœci zmiennej sav12 do rejestru r12
	mov r13, sav13			;zapisanie wartoœci zmiennej sav13 do rejestru r13
	mov r14, sav14			;zapisanie wartoœci zmiennej sav14 do rejestru r14
	mov r15, sav15			;zapisanie wartoœci zmiennej sav15 do rejestru r15
	mov rbx, savrbx			;zapisanie wartoœci zmiennej savrbx do rejestru rbx
	ret						;powrót z procedury
		
encryptTextAsm ENDP			;koniec procedury




							;Funkcja znajduj¹ca siê poni¿ej s³u¿y ilustracji dzia³ania instrukcji 
							;wektorowych (SIMD). Zadaniem wykonywanym przez funkcjê jest odjêcie od siebie
							;dwóch tablic zmiennych zmiennoprzecinkowych pojedynczej precyzji.
							;Argumenty przyjmowane przez funkcjê to:
							;1. wskaŸnik na pierwsz¹ tablicê liczb (rejestr rcx)
							;2. wskaŸnik na drug¹ tablicê liczb (rejestr rdx)
							;3. wskaŸnik na wynikow¹ tablicê liczb (rejestr r8)
							;4. rozmiar tablic okreœlony w bajtach (rejestr r9)

SIMDProcedure PROC
							
	mov rax, 0				;zerowanie rejestru rax s³u¿¹cego za licznik wskazuj¹cy na kolejne liczby w 
							;tablicach
subtractLoop:
	movups xmm0, [rcx + rax];wpisanie czterech liczb do rejestru xmm0
	movups xmm1, [rdx + rax];wpisanie czterech liczb do rejestru xmm1
	subps xmm0, xmm1		;jednoczesne odejmowanie wszystkich czterech liczb
	movdqu [r8 + rax], xmm0	;wpisanie rezultatu dzia³ania do tablicy wynikowej
	add rax, 16				;inkrementacja licznika
	cmp rax, r9				;sprawdzenie, czy licznik jest równy rozmiarowi tablic
	jne subtractLoop		;skok do etykiety subtractLoop, jeœli porównywane wartoœci nie s¹ równe
	ret						;powrót z procedury

SIMDProcedure ENDP			;koniec procedury

END