numbers = [0, 0, 0, 0, 0, 0, 0]

numbers[1] = 1
for i in range(1, 6):
    numbers[i + 1] = (i + 1) * numbers[i]

    print(numbers)
