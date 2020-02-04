PUBLIC encryptTextAsm

.data

polybius dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej polybius przechowuj�cej wska�nik 
							;na tablic� Polibiusza
text	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej text przechowuj�cej tekst do 
							;zaszyfrowania
output	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej output przechowuj�cej wska�nik na 
							;zaszyfrowany tekst
len		 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej len przechowuj�cej d�ugo�� tekstu 
							;do zaszyfrowania
sav12	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav12 przechowuj�cej zawarto�� 
							;rejestru r12
sav13	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav13 przechowuj�cej zawarto�� 
							;rejestru r13
sav14	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav14 przechowuj�cej zawarto�� 
							;rejestru r14
sav15	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej sav15 przechowuj�cej zawarto�� 
							;rejestru r15
savrbx	 dq 0				;alokacja o�miu bajt�w pami�ci dla zmiennej savrbx przechowuj�cej zawarto�� 
							;rejestru rbx

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
	mov rbx, 0				;zerowanie rejestru rbx s�u��cego za licznik wskazuj�cy na kolejne znaki w 
							;zaszyfrowanym tek�cie
	mov r12, 0				;zerowanie rejestru r12 s�u��cego za licznik wskazuj�cy na kolejne znaki w 
							;tek�cie do zaszyfrowania 
r12_loop:					;pocz�tek p�tli iteruj�cej po kolejnych znakach tekstu do zaszyfrowania
	mov rax, 0				;zerowanie rejestru, do kt�rego b�dzie wpisywany znak 	
	mov al, [rdx + r12]		;wpisanie znaku o indeksie wskazywanym przez licznik znak�w w tek�cie do
							;najni�szych o�miu bit�w zerowanego wcze�niej rejestru
	mov r15, rax			;wpisanie zawarto�ci rejestru zawieraj�cego znak do rejestru r15 w celu 
							;przechowania znaku
	mov r13, 0				;zerowanie rejestru r13 s�u��cego za licznik wskazuj�cy na kolejne wiersze
							;tablicy Polibiusza
r13_loop:					;pocz�tek p�tli iteruj�cej po kolejnych wierszach tablicy Polibiusza
	mov r14, 0				;zerowanie rejestru r14 s�u��cego za licznik wskazuj�cy na kolejne kolumny
							;tablicy Polibiusza
r14_loop:					;pocz�tek p�tli iteruj�cej po kolejnych kolumnach tablicy Polibiusza
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru
	mov rcx, [rcx + r13]	;wpisanie do tego samego rejestru adresu wiersza tablicy Polibiusza o indeksie
							;wskazywanym przez licznik wierszy
	mov rax, 0				;zerowanie rejestru, do kt�rego b�dzie wpisywany znak
	mov al, [rcx + r14]		;wpisanie znaku zawieraj�cego si� w kom�rce tablicy Polibiusza z kolumny 
							;wskazywanej przez licznik kolumn do najni�szych o�miu bit�w zerowanego 
							;wcze�niej rejestru
	cmp rax, r15			;por�wnanie znaku z tablicy z zapami�tanym wcze�niej znakiem nale��cym do
							;tekstu do zaszyfrowania
	jne another_letter		;skok do etykiety another_letter, je�li por�wnywane warto�ci nie s� r�wne	
	cmp r13, 8				;sprawdzenie, czy zapami�tany znak nale�y do s�owa kluczowego
	je is_in_keyword		;skok do etykiety is_in_keyword, je�li por�wnywane warto�ci s� r�wne	
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru
	mov rcx, [rcx + r13]	;wpisanie do tego samego rejestru adresu wiersza tablicy Polibiusza o indeksie
							;wskazywanym przez licznik wierszy
	mov rax, 0				;zerowanie rejestru, do kt�rego b�dzie wpisywany znak
	mov al, [rcx]			;wpisanie cyfry zawieraj�cej si� w kom�rce tablicy Polibiusza w zerowej kolumnie
							;do najni�szych o�miu bit�w zerowanego wcze�niej rejestru
	mov [r8 + rbx], al		;wpisanie zawarto�ci rejestru do tablicy z zaszyfrowanym tekstem pod indeks
							;wskazywany przez licznik znak�w w zaszyfrowanym tek�cie
	add rbx, 1				;inkrementacja licznika znak�w w zaszyfrowanym tek�cie
is_in_keyword:				
	mov rcx, polybius		;wpisanie adresu tablicy Polibiusza do rejestru		
	mov rcx, [rcx]			;wpisanie do tego samego rejestru adresu zerowego wiersza tablicy Polibiusza
	mov rax, 0				;zerowanie rejestru, do kt�rego b�dzie wpisywany znak
	mov al, [rcx + r14]		;wpisanie cyfry zawieraj�cej si� w kom�rce tablicy Polibiusza z kolumny
							;o indeksie wskazywanym przez licznik kolumn do najni�szych o�miu bit�w 
							;zerowanego wcze�niej rejestru
	mov [r8 + rbx], al		;wpisanie zawarto�ci rejestru do tablicy z zaszyfrowanym tekstem pod indeks
							;wskazywany przez licznik znak�w w zaszyfrowanym tek�cie
	add rbx, 1				;inkrementacja licznika znak�w w zaszyfrowanym tek�cie
	mov r14, 10				;zwi�kszenie warto�ci licznika kolumn do takiej, aby nast�pi�o przerwanie
							;wykonywania p�tli iteruj�cej po kolumnach
	mov r13, 32				;zwi�kszenie warto�ci licznika wierszy do takiej, aby nast�pi�o przerwanie
							;wykonywania p�tli iteruj�cej po wierszach
another_letter:				
	add r14, 1				;inkrementacja licznika kolumn
	cmp r14, 11				;sprawdzenie, czy licznik wskazuje na ostatni� kolumn�
	jne r14_loop			;skok do etykiety r14_loop, je�li por�wnywane warto�ci nie s� r�wne
	add r13, 8				;inkrementacja licznika wierszy
	cmp r13, 40				;sprawdzenie, czy licznik wskazuje na ostatni wiersz
	jne r13_loop			;skok do etykiety r13_loop, je�li por�wnywane warto�ci nie s� r�wne
	add r12, 1				;inkrementacja licznika znak�w w tek�cie do zaszyfrowania
	cmp r12, r9				;sprawdzenie, czy licznik wskazuje na ostatni znak w tek�cie
	jne r12_loop			;skok do etykiety r12_loop, je�li por�wnywane warto�ci nie s� r�wne
	mov r12, sav12			;zapisanie warto�ci zmiennej sav12 do rejestru r12
	mov r13, sav13			;zapisanie warto�ci zmiennej sav13 do rejestru r13
	mov r14, sav14			;zapisanie warto�ci zmiennej sav14 do rejestru r14
	mov r15, sav15			;zapisanie warto�ci zmiennej sav15 do rejestru r15
	mov rbx, savrbx			;zapisanie warto�ci zmiennej savrbx do rejestru rbx
	ret						;powr�t z procedury
		
encryptTextAsm ENDP			;koniec procedury




							;Funkcja znajduj�ca si� poni�ej s�u�y ilustracji dzia�ania instrukcji 
							;wektorowych (SIMD). Zadaniem wykonywanym przez funkcj� jest odj�cie od siebie
							;dw�ch tablic zmiennych zmiennoprzecinkowych pojedynczej precyzji.
							;Argumenty przyjmowane przez funkcj� to:
							;1. wska�nik na pierwsz� tablic� liczb (rejestr rcx)
							;2. wska�nik na drug� tablic� liczb (rejestr rdx)
							;3. wska�nik na wynikow� tablic� liczb (rejestr r8)
							;4. rozmiar tablic okre�lony w bajtach (rejestr r9)

SIMDProcedure PROC
							
	mov rax, 0				;zerowanie rejestru rax s�u��cego za licznik wskazuj�cy na kolejne liczby w 
							;tablicach
subtractLoop:
	movups xmm0, [rcx + rax];wpisanie czterech liczb do rejestru xmm0
	movups xmm1, [rdx + rax];wpisanie czterech liczb do rejestru xmm1
	subps xmm0, xmm1		;jednoczesne odejmowanie wszystkich czterech liczb
	movdqu [r8 + rax], xmm0	;wpisanie rezultatu dzia�ania do tablicy wynikowej
	add rax, 16				;inkrementacja licznika
	cmp rax, r9				;sprawdzenie, czy licznik jest r�wny rozmiarowi tablic
	jne subtractLoop		;skok do etykiety subtractLoop, je�li por�wnywane warto�ci nie s� r�wne
	ret						;powr�t z procedury

SIMDProcedure ENDP			;koniec procedury

END