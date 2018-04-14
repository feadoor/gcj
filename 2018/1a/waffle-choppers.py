CHIP = '@'
POSSIBLE = 'POSSIBLE'
IMPOSSIBLE = 'IMPOSSIBLE'

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def read_waffle(rows):
    return [[1 if x == '@' else 0 for x in input()] for _ in range(rows)]

def get_total_chips(waffle):
    return sum(sum(row) for row in waffle)

def get_sections(waffle, horizontal_cuts):
    sections, tracker = [], 0
    for cut in horizontal_cuts:
        sections.append(waffle[tracker : cut + 1])
        tracker = cut + 1
    sections.append(waffle[tracker:])
    return sections

def get_horizontal_cuts(waffle, required_cuts):

    total_chips = get_total_chips(waffle)
    if total_chips % (required_cuts + 1) == 0:
        per_section = total_chips // (required_cuts + 1)
    else:
        return None

    cuts, current_chips, next_target = [], 0, per_section
    for idx, row in enumerate(waffle):
        current_chips += sum(row)
        if current_chips == next_target:
            cuts.append(idx)
            next_target += per_section
        elif current_chips > next_target:
            return None

    if len(cuts) < required_cuts:
        return None
    else:
        return cuts[:required_cuts]

def transpose(waffle):
    return [list(x) for x in zip(*waffle)]

def all_equal(lst):
    return len(lst) == 0 or all(x == lst[0] for x in lst)

def exist_vertical_cuts(waffle, horizontal_cuts, required_cuts):

    waffle_sections = get_sections(waffle, horizontal_cuts)

    total_chips = get_total_chips(waffle_sections[0])
    if total_chips % (required_cuts + 1) == 0:
        per_section = total_chips // (required_cuts + 1)
    else:
        return False

    cuts, current_chips, next_target = [], [0 for section in waffle_sections], per_section
    for idx in range(len(waffle[0])):
        for jdx, section in enumerate(waffle_sections):
            current_chips[jdx] += sum(x[idx] for x in section)
        if all(x == next_target for x in current_chips):
            cuts.append(idx)
            next_target += per_section

    if len(cuts) < required_cuts:
        return False
    else:
        return True

def answer(case, ans):
    print("Case #{0}: {1}".format(case, ans))

def do_test_case(case):
    rows, cols, h_cuts, v_cuts = read_space_separated_integers()
    waffle = read_waffle(rows)
    horizontal_cuts = get_horizontal_cuts(waffle, h_cuts)
    if horizontal_cuts is None:
        answer(case, IMPOSSIBLE)
    else:
        answer(case, POSSIBLE if exist_vertical_cuts(waffle, horizontal_cuts, v_cuts) else IMPOSSIBLE)

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()
