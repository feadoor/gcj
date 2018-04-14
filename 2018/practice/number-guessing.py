import sys

TOO_SMALL = "TOO_SMALL"
TOO_LARGE = "TOO_BIG"
CORRECT   = "CORRECT"

def read_integer():
    return int(input())

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def do_test_case():
    lower, upper = read_space_separated_integers()
    max_guesses = read_integer()

    while True:
        next_guess = (lower + upper + 1) // 2
        print(next_guess, flush=True)
        response = input()

        if response == TOO_SMALL:
            lower = next_guess
        elif response == TOO_LARGE:
            upper = next_guess - 1
        elif response == CORRECT:
            break
        else:
            sys.exit(1)

def main():
    test_cases = read_integer()
    for _ in range(test_cases):
        do_test_case()

if __name__ == "__main__":
    main()