from collections import namedtuple
import string

Party = namedtuple('Party', ['senators', 'name'])

def read_integer():
    return int(input())

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def assign_parties(senators):
    return sorted(map(lambda x: Party(x[0], x[1]), zip(senators, string.ascii_uppercase)), reverse=True)

def get_evacuation_plan(parties):
    plan = []
    plan += [parties[0].name] * (parties[0].senators - parties[1].senators)
    for party in parties[2:]:
        plan += [party.name] * party.senators
    plan += [parties[0].name + parties[1].name] * (parties[1].senators)
    return plan

def do_test_case(case):
    num_parties = read_integer()
    parties = assign_parties(read_space_separated_integers())
    evacuation_plan = get_evacuation_plan(parties)
    print("Case #{0}: {1}".format(case, " ".join(evacuation_plan), flush=True))

def main():
    for case in range(read_integer()):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()