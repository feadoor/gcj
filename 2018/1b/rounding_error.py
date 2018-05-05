from bisect import bisect_left
from math import floor, modf

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def get_terms_which_round_up(n):
    return [x for x in range(n + 1) if modf(x * 100 / n)[0] >= 0.5]

def get_required_increase_to_round_up(c, rounds_up):
    idx = bisect_left(rounds_up, c)
    return float('inf') if idx >= len(rounds_up) else rounds_up[idx] - c

def round_up_at_half(x):
    return int(floor(x + 0.5))

def do_test_case(case):
    n, l = read_space_separated_integers()
    counts = read_space_separated_integers()

    allowed_increases = n - sum(counts)
    rounds_up = get_terms_which_round_up(n)
    threshold = get_required_increase_to_round_up(0, rounds_up)

    counts.sort(key=lambda c: get_required_increase_to_round_up(c, rounds_up))
    for idx, count in enumerate(counts):
        increase = get_required_increase_to_round_up(count, rounds_up)
        if min(allowed_increases, threshold) >= increase:
            allowed_increases -= increase
            counts[idx] += increase
        else:
            break

    if threshold <= allowed_increases:
        counts += [threshold] * (allowed_increases // threshold)
        allowed_increases %= threshold
    counts += [allowed_increases]

    answer = sum(int(round_up_at_half((c * 100) / n)) for c in counts)
    print('Case #{0}: {1}'.format(case, answer))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == '__main__':
    main()