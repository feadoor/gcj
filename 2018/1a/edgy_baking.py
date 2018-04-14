from math import floor, sqrt

MAX_COOKIE_SIZE = 250

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def read_cookies(n_cookies):
    return [read_space_separated_integers() for _ in range(n_cookies)]

def hypot(x, y):
    return sqrt(x * x + y * y)

def calculate_ranges(cookies, largest_excess):
    ranges = [0] * (largest_excess + 1)
    for cookie in cookies:
        min_cut, max_cut = min(cookie), hypot(*cookie)
        for min_total in range(len(ranges) - 1, min_cut - 1, -1):
            ranges[min_total] = max(ranges[min_total], ranges[min_total - min_cut] + max_cut)
    return ranges

def do_test_case(case):
    n_cookies, perimeter = read_space_separated_integers()
    cookies = read_cookies(n_cookies)

    base_perimeter = sum(2 * sum(cookie) for cookie in cookies)
    excess = (perimeter - base_perimeter) / 2
    max_excess = sum(hypot(*cookie) for cookie in cookies)

    if max_excess <= excess:
        best_excess = max_excess
    else:
        best_excess = 0
        ranges = calculate_ranges(cookies, int(floor(excess)))
        for max_delta in ranges:
            best_excess = max(best_excess, min(excess, max_delta))

    best_perimeter = 2 * best_excess + base_perimeter
    print("Case #{0}: {1}".format(case, best_perimeter))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()
