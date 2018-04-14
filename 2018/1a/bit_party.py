def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def capacity(cashier, time):
    m, s, p = cashier
    return max(0, min(m, (time - p) // s))

def can_do_time(robots, bits, cashiers, time):
    capacities = sorted((capacity(cashier, time) for cashier in cashiers), reverse=True)
    return sum(capacities[:robots]) >= bits

def minimum_time(robots, bits, cashiers):
    lower, upper = 1, 2
    while not can_do_time(robots, bits, cashiers, upper):
        upper *= 2
    while lower != upper:
        mid = (lower + upper) // 2
        if can_do_time(robots, bits, cashiers, mid):
            upper = mid
        else:
            lower = mid + 1
    return lower

def do_test_case(case):
    robots, bits, n_cashiers = read_space_separated_integers()
    cashiers = [read_space_separated_integers() for _ in range(n_cashiers)]
    print("Case #{0}: {1}".format(case, minimum_time(robots, bits, cashiers)))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()
