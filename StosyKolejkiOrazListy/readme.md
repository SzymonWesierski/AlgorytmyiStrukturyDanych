Zadanie 6 (10 pkt)

Wybieramy jedno z zadań programistycznych.

Zaimplementuj strukturę listy dowiązaniowej (dwukierunkowej, cyklicznej z wartownikiem), której elementami są słowa (czyli ciągi znaków), oraz operacje:

init_list - inicjalizuje listę 
add s - Wstawia słowo s na koniec listy 
print - Wypisuje elementy listy. W przypadku pustej listy program ma wyświetlić ciąg []
search s - Wyświetla na ekranie wartość True/False, jeśli odpowiednio słowo s znajduje się na liście
remove s - Usuwa z listy węzeł zawierający słowo s, o ile takie słowo znajduje się na liście
clean - Usuwa wszystkie węzły listy, wraz z wyczyszczeniem pamięci
non_repeated - Usuwa z listy wszystkie powtarzające się elementy
merge - Dokonuje "scalenia" listy z ustawioną wcześniej na sztywno listą postaci: ["one" -> "two" -> "three"].
Zwróć uwagę na wyświetlenie listy metodą print.

Program ma być napisany w języku C/C++ i używać wskaźników. Struktura powinna być generowana dynamicznie.

W przypadku występowania błędu w jakiejkolwiek metodzie program powinien wyświetlić komunikat Error nazwa_metody.

Sample Input jest skonstruowany jako ciąg poleceń reprezentujący powyższe metody. 

Sample output ma wyświetlać wyniki (jeśli metoda ma je zwracać) używanej metody.

Pod ocenę będą brane następujące elementy:

Testy (4 pkt)
Struktura listy (2 pkt)
Złożoność metod (1 pkt)
Alokacja pamięci (1.5 pkt)
Styl kodu (1.5 pkt)
Punkty za to zadanie dostaje się po pokazaniu kodu prowadzącemu zajęcia.

Sample Input 1:

init_list
print
add ala
print
add ma
print
add kota
print
search ala
search kot
remove kota
print
clean
print
Sample Output 1:

[]
[ala]
[ala <-> ma]
[ala <-> ma <-> kota]
True
False
[ala <-> ma]
Error print
Sample Input 2:

init_list
add ala
add ma
add kota
print
remove ma
print
merge
print
Sample Output 2:

[ala <-> ma <-> kota]
[ala <-> kota]
[ala <-> kota <-> one <-> two <-> three]
Sample Input 3:

init_list
print
merge
merge
print
non_repeated
print
Sample Output 3:

[]
[one <-> two <-> three <-> one <-> two <-> three]
[one <-> two <-> three]