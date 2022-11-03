def combination(per_list, com_num):
    if com_num == 0:
        return[[]]

    tmpList = []
    for i in range(0,len(per_list)):
        first = per_list[i]
        rem = per_list[i + 1:]
        combination_list = combination(rem, com_num - 1)
        for x in combination_list:
            tmpList.append([first] + x)
    return tmpList


input_list = []
while True:
    member = input("Please enter the member of list : ")
    input_list.append(member)

    choice = input("Would you enter the another member ? ( y / n ) : ")
    if choice.casefold() == 'n':
        break

print((combination(input_list, 2)))
