def is_triangle_num(n):
    tri_num = 0
    i = 1
    while tri_num < n:
        tri_num = 0.5 * i * (i + 1)
        i += 1
    return tri_num == n

words = [word.strip("\"") for word in open("words.txt", "r").read().split(",")]

n_tri_words = 0
for word in words:
    word_value = 0
    for char in word:
        word_value += ord(char) - 64
    if is_triangle_num(word_value):
        n_tri_words += 1
        print (word)

print (n_tri_words)
