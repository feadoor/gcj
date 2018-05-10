OK = 'OK'

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def split_list(lst):
    return lst[::2], lst[1::2]

def find_first_error(lst):
    odds, evens = split_list(lst)
    odds.sort()
    evens.sort()

    for idx, val in enumerate(odds):
        if idx < len(evens) and odds[idx] > evens[idx]:
            return 2 * idx
        elif idx > 0 and evens[idx - 1] > odds[idx]:
            return 2 * idx - 1

    return OK

def do_test_case(case):
    _ = input()
    lst = read_space_separated_integers()
    print("Case #{0}: {1}".format(case, find_first_error(lst)))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()
