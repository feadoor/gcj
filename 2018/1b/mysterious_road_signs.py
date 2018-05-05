from collections import namedtuple

Candidate = namedtuple('Candidate', ['curr', 'other', 'start', 'eq'])

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def update_candidate(candidate, opposite, idx, val):
    if val == candidate.curr:
        return candidate
    elif val == opposite.other:
        return Candidate(opposite.other, opposite.curr, opposite.start, idx)
    else:
        return Candidate(val, opposite.curr, opposite.eq, idx)


def do_test_case(case):
    signs = [read_space_separated_integers() for _ in range(int(input()))]
    signs = [(s[0] + s[1], s[0] - s[2]) for s in signs]

    east_candidate = Candidate(None, None, 0, 0)
    west_candidate = Candidate(None, None, 0, 0)
    best_segment, segment_count = 0, 0

    for idx, (east, west) in enumerate(signs):
        east_candidate, west_candidate = (
            update_candidate(east_candidate, west_candidate, idx, east),
            update_candidate(west_candidate, east_candidate, idx, west)
        )
        best_here = idx - min(east_candidate.start, west_candidate.start) + 1
        if best_here > best_segment:
            best_segment, segment_count = best_here, 0
        if best_here >= best_segment:
            segment_count += 1

    print('Case #{0}: {1} {2}'.format(case, best_segment, segment_count))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == '__main__':
    main()