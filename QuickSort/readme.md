Zadanie 3 (5 pkt)

Napisz program, który pobierze ciąg napisów (zapisanych w jednej linii oddzielonych spacją) posortuje dany ciąg rosnąco (czyli od najmniejszego słowa do największego) używając do tego metody sortowania QuickSort

Wybieramy jeden z poniższych wariantów sortowania QuickSort:

max (3 pkt) - podstawowy z podziałem skrajnie prawego elementu
max (3.5 pkt) - z medianą (czyli elementem środkowym co do wartości) z trzech następujących elementów tablicy: skrajnie lewego (A[p]), środkowego (A[p + (r−p)/2]), skrajnie prawego (A[r]).
max (4 pkt) - wybranym pseudolosowo elementem podziału (RandomizedQuicksort);
+ (1 pkt) za dokonanie pomiaru czasu działania algorytmu dla różnych przypadków.
Dla prostoty zadania zakładamy, że ciągi te mają słowa tej samej długości.

Należy tutaj odróżnić wielkość liter w danych słowach. Mają one być zachowane !!!.

Pod ocenę będą brane następujące rzeczy:

Testy (max 1 pkt - w zależności od wybranego wariantu)
Złożoność algorytmu (max 2 pkt - w zależności od wybranego wariantu)
Styl kodu (max 1 pkt - w zależności od wybranego wariantu)
Sample Input 1:

ala ada aaa
Sample Output 1:

aaa ada ala
Sample Input 2:

aaa ada ala
Sample Output 2:

aaa ada ala