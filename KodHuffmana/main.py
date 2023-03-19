class Node:
    right = None
    left = None
    bin = ""
    freq = 0
    character = ""

    def __init__(self, freq, character, right, left, bin):
        self.freq = freq
        self.character = character
        self.right = right
        self.left = left
        self.bin = bin

    def __str__(self):
        return self.character + ": " + str(self.freq) + " bin=" + self.bin


def buildTree(letter_list, fathers_list):
    char1 = minFromList(letter_list)
    char2 = minFromList(letter_list)
    character = char1[0]+char2[0]
    freq = char1[1]+char2[1]

    letter_list[character] = freq

    if len(char1[0]) == 1:
        sonR = Node(char1[1],char1[0], None, None, "0")
    else:
        for el in fathers_list:
            if char1[0] == el.character:
                sonR = el
                fathers_list.remove(el)

    if len(char2[0]) == 1:
        sonL = Node(char2[1],char2[0], None, None, "1")
    else:
        for el in fathers_list:
            if char2[0] == el.character:
                el.bin = "1"
                sonL = el
                fathers_list.remove(el)

    father = Node(freq, character, sonR, sonL, "0")
    fathers_list.append(father)

def minFromList(letter_list):
    m = min(letter_list.values())

    for key in letter_list:
        if letter_list[key] == m:
            minimum = [key, m]
    letter_list.pop(minimum[0])
    return minimum

def countLetter(text):
    letter_dict = {}

    for char in text:
        if char in letter_dict:
            letter_dict[char] += 1
        else:
            letter_dict[char] = 1

    return letter_dict

def walkTreeInOrder(node, letterDict):
    if node == None:
        return
    if node.left:
        nodel = node.left
        nodel.bin += node.bin
        walkTreeInOrder(node.left, letterDict)
    if len(node.character) == 1:
        letterDict[node.character] = node.bin
    if node.right:
        noder = node.right
        noder.bin += node.bin
        walkTreeInOrder(node.right, letterDict)

letter_list = []
#text = input("Enter text: ")
text = "gfsdgsdfgsdgdfhbsdfadfgggggggggggsssbb"
letter_list = countLetter(text)

fathers_list = []
while len(letter_list) > 1:
    buildTree(letter_list,fathers_list)
letterDict = {}

root = fathers_list[0]
root.bin = ""

walkTreeInOrder(root, letterDict)
print("Kody liter: ",letterDict)

encoded_text = ""
for char in text:
    encoded_text += letterDict[char]

encoded_text_size = len(encoded_text)
original_text_size = len(text) * 8
print("Zaoszczędzone miejsce: ", original_text_size - encoded_text_size, " bitów")