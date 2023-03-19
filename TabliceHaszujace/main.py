class HashTable:
    def __init__(self, size, c1, c2):
        self.c1 = c1
        self.c2 = c2
        self.size = size
        self.table = ["NIL" for i in range(self.size)]

    def hash_function(self, key, i):
        return ((sum(ord(ch) for ch in key) + self.c1 * i) + (self.c2 * i * i)) % self.size

    def insert(self, number, key):
        i = 0
        while i != self.size:
            index = self.hash_function(key, i)
            if self.table[index]=="NIL":
                self.table[index] = [number, key]
                return index
            else:
                i = i + 1

    def search(self, key):
        i = 0
        while i != self.size:
            index = self.hash_function(key, i)
            if self.table[index] == 'NIL':
                break
            if self.table[index][1] == key:
                return "Index szukanego elementu w tej tabeli to: " + str(index)
            else:
                i = i + 1
        return "None"

    def delete(self, key):
        i = 0
        while i != self.size or self.table[index] != 'NIL':
            index = self.hash_function(key, i)
            if self.table[index][1] == key:
                self.table[index] = "NIL"
                return
            else:
                i = i + 1
        return "NIL"


data = []
with open('nazwiska.txt', 'r') as f:
    for line in f:
        number, name = line.strip().split(' ')
        data.append((int(number), name))


ht = HashTable(25000, 5, 7)

for item in data:
    ht.insert(item[0], item[1])

#print(ht.table)

print(ht.search('Nowak')) 
ht.delete('Nowak')
#print(ht.table)
print(ht.search('Nowak'))