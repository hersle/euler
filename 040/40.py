n_list = ""
for i in range(1, 10**6 + 1):
    n_list += str(i)
    print (i)

print (int(n_list[1 - 1]) * int(n_list[10 - 1]) * int(n_list[100 - 1]) * int(n_list[1000 - 1]) * int(n_list[10000 - 1]) * int(n_list[100000 - 1]) * int(n_list[1000000 - 1]))
