bordel = {}

table = "isrveawhobpnutfg"

def get(index, target):
    all = []
    for i in range(37, 128):
        res = table[i & 0xf]
        if res == target:
            all.append(chr(i))
    return all

# print(get(0, 'g'), get(1, 'i'), get(2, 'a'), get(3, 'n'), get(4, 't'), get(5, 's'))

for i, c in enumerate('giants'):
    print(get(i, c))


# for c in "giants":
#     print(bordel[c])
