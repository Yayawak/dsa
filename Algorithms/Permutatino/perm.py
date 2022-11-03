# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.

def permutations(per_list):
    # perm
    if len(per_list) == 1:
        return per_list

    perms = permutations(per_list[1:])
    char = per_list[0]
    result = []

    for perm in perms:
        for i in range(len(perm)+1):
            result.append(perm[:i] + char + perm[i:])
    return result


input_list = []
while True:
    member = input("Please enter the member of list : ")
    input_list.append(member)

    choice = input("Would you enter the another member ? ( y / n ) : ")
    if choice.casefold() == 'n':
        break

print(permutations(input_list))
