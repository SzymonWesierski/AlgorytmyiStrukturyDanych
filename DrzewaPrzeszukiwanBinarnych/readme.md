Zadanie 5 (8 pkt)

Wybieramy jedno z zadań programistycznych.

Zaimplementuj działanie drzewa binarnego, gdzie w działaniu programu będzie można (z poziomu użytkownika wpisać następujące opcje):

init_tree - Inicjalizuje drzewo zdefiniowane wcześniej w programie
insert value - wstawia do drzewa binarnego wartość value (liczby). W przypadku wprowadzenia tej samej wartości, węzeł ma być zduplikowany i wstawiony jako osobny węzeł do drzewa (korzystając ze strategii przełączników)
search value - wyświetla True/False, jeżeli value znajduje się w drzewie binarnym
delete value - usuwa węzeł z wartością value (słowa) w drzewie binarnym. Bierzemy tutaj pod uwagę węzeł najbliżej liści. Przyjmujemy tutaj strategię znajdywania poprzednika w przypadku, kiedy węzeł ma obydwu synów.
in_order - wypisuje porządek inorder drzewa binarnego
pre_order - wypisuje porządek preorder drzewa binarnego
post_order - wypisuje porządek postorder drzewa binarnego
Program ma być napisany w języku C/C++ i używać wskaźników. Struktura powinna być generowana dynamicznie.

W przypadku występowania błędu w jakiejkolwiek metodzie program powinien wyświetlić komunikat Error nazwa_metody.

Sample Input jest skonstruowany jako ciąg poleceń reprezentujący powyższe metody. 

Sample output ma wyświetlać wyniki (jeśli metoda ma je zwracać) używanej metody.

Pod ocenę będą brane następujące elementy:

Testy (5 pkt)
Alokacja pamięci (1.5 pkt)
Styl kodu (1.5 pkt)
Punkty za to zadanie dostaje się po pokazaniu kodu prowadzącemu zajęcia.

Sample Input:

init_tree
insert 5
insert 1
insert 10
in_order
pre_order
post_order
insert 5
insert 5
in_order
pre_order
post_order
search 1
search 2
delete 10
search 10
Sample Output:

1 5 10
5 1 10
1 10 5
1 5 5 5 10
5 1 5 10 5
5 1 5 10 5
True
False
False