
def countingSort(a, char_number):
    ascii_size = 127
    a_size = len(a)
    b = [0] * a_size
    c = [0] * ascii_size

    for word in a:
        if char_number < len(word):
            if word[char_number].isalpha() is False:
                char = ord(word[char_number])
            elif word[char_number].isalpha() is True:
                char = ord(word[char_number].upper())
        else:
            char = 0
        c[char] += 1

    for i in range(1, ascii_size):
        c[i] += c[i - 1]

    i = a_size - 1
    while i >= 0:
        if char_number < len(a[i]):
            if a[i][char_number].isalpha() is False:
                index = ord(a[i][char_number])
            elif a[i][char_number].isalpha() is True:
                index = ord(a[i][char_number].upper())
        else:
            index = 0
        b[c[index] - 1] = a[i]
        c[index] -= 1
        i -= 1

    for i in range(0, a_size):
        a[i] = b[i]
    return a

def radixSort(word_array):
    max_word_len = len(max(word_array, key=len))
    for char_number in range(max_word_len-1, -1, -1):
        word_array = countingSort(word_array, char_number)
    return word_array

word_array = input().split()
radixSort(word_array)
result = ""

for word in word_array:
    result += word + " "

print(result[:-1])

