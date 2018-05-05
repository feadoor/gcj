def generate_prefix_counts(words):
    counts = {}
    for word in words:
        branch = counts
        for letter in word:
            branch['_count'] = branch.get('_count', 0) + 1
            branch = branch.setdefault(letter, {})
        branch['_count'] = 1
    return counts

def get_prefix_count(counts, prefix):
    branch = counts
    for letter in prefix:
        if letter not in branch:
            return 0
        else:
            branch = branch[letter]
    return branch['_count']

def read_words():
    n_words, n_letters = [int(x) for x in input().strip().split(' ')]
    words, letters_by_place = [], [set() for _ in range(n_letters)]
    for _ in range(n_words):
        words.append(input())
        for ix, letter in enumerate(words[-1]):
            letters_by_place[ix].add(letter)
    return words, letters_by_place

def find_missing_word(words, letters_by_place):
    prefix_counts = generate_prefix_counts(words)
    total_possible_words = [1] * (len(letters_by_place) + 1)
    for idx in range(len(letters_by_place) - 1, -1, -1):
        total_possible_words[idx] = total_possible_words[idx + 1] * len(letters_by_place[idx])

    candidate = ''
    for idx in range(len(letters_by_place)):
        for letter in letters_by_place[idx]:
            if get_prefix_count(prefix_counts, candidate + letter) < total_possible_words[idx + 1]:
                candidate = candidate + letter
                break
        else:
            return '-'
    return candidate

def do_test_case(case):
    words, letters_by_place = read_words()
    print('Case #{0}: {1}'.format(case, find_missing_word(words, letters_by_place)))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == '__main__':
    main()
