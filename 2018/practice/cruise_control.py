from collections import namedtuple

Horse = namedtuple('Horse', ['position', 'speed'])

def read_integer():
    return int(input())

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def read_horse():
    return Horse(*read_space_separated_integers())

def time_taken(horse, destination):
    return (destination - horse.position) / horse.speed

def do_test_case(case):
    destination, num_horses = read_space_separated_integers()
    horses = [read_horse() for _ in range(num_horses)]
    times_taken = [time_taken(horse, destination) for horse in horses]
    print("Case #{0}: {1}".format(case, destination / max(times_taken)), flush=True)

def main():
    for case in range(read_integer()):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()