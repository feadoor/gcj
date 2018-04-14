from collections import defaultdict

CHARGE = 'C'
SHOOT = 'S'
IMPOSSIBLE = 'IMPOSSIBLE'

def get_hack_reductions(moves):
    total_charges = moves.count(CHARGE)
    power = 1 << total_charges

    reductions = defaultdict(int)
    for move in moves[::-1]:
        if move == SHOOT:
            reductions[power >> 1] += 1
        elif move == CHARGE:
            power >>= 1
            reductions[power >> 1] = reductions[power]

    reductions.pop(0, None)
    return reductions

def get_damage(moves):
    damage, power = 0, 1
    for move in moves:
        if move == SHOOT:
            damage += power
        elif move == CHARGE:
            power <<= 1
    return damage

def get_minimum_hacks(moves, target_damage):
    required_reduction = get_damage(moves) - target_damage
    hack_reductions = get_hack_reductions(moves)
    hacks = 0

    for amt in sorted(hack_reductions.keys(), reverse=True):
        if required_reduction <= 0:
            return hacks
        if amt * hack_reductions[amt] >= required_reduction:
            return hacks + (required_reduction + amt - 1) // amt
        else:
            hacks += hack_reductions[amt]
            required_reduction -= amt * hack_reductions[amt]

    return IMPOSSIBLE if required_reduction > 0 else hacks

def do_test_case(case):
    inputs = input().strip().split(' ')
    target, moves = int(inputs[0]), list(inputs[1])
    print("Case #{0}: {1}".format(case, get_minimum_hacks(moves, target)))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()