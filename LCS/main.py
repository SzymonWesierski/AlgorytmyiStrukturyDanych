def longestCommonSubsequence(s1, s2):
    m = len(s1) + 1
    n = len(s2) + 1
    array = []

    for i in range(m):
        array.append([None] * (n))

    for i in range(m):
        for j in range(n):
            if i == 0 or j == 0:
                array[i][j] = 0
            elif s1[i - 1] == s2[j - 1]:
                array[i][j] = array[i - 1][j - 1] + 1
            else:
                array[i][j] = max(array[i - 1][j], array[i][j - 1])
            #print(array)

    return array[m - 1][n -1]


s1 = input().lower()
s2 = input().lower()
print(longestCommonSubsequence(s1, s2))

