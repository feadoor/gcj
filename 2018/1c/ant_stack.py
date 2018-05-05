def last_value_not_exceeding(values, target):
    lo, hi = 0, len(values) - 1
    while lo != hi:
        mid = (lo + hi + 1) // 2
        if values[mid] > target:
            hi = mid - 1
        else:
            lo = mid
    return lo

def longest_stack(ant_weights):
    minimum_weights = [0]
    for weight in ant_weights:

        start_val = last_value_not_exceeding(minimum_weights, 6 * weight)
        if start_val == len(minimum_weights) - 1:
            minimum_weights.append(float('inf'))

        for jdx in range(start_val, -1, -1):
            candidate = minimum_weights[jdx] + weight
            if minimum_weights[jdx + 1] > candidate:
                minimum_weights[jdx + 1] = candidate

    return len(minimum_weights) - 1

def do_test_case(case):
    _, ant_weights = input(), [int(x) for x in input().strip().split(' ')]
    print('Case #{0}: {1}'.format(case, longest_stack(ant_weights)))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == '__main__':
    main()
