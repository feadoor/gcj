from collections import defaultdict, namedtuple

Item = namedtuple('Item', ['size', 'count'])

def read_integer():
    return int(input())

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def split_layer(layer):
    next_items = defaultdict(int)
    for item in layer:
        for size in [(item.size - 1) // 2, item.size // 2]:
            next_items[size] += item.count
    return sorted([Item(key, value) for (key, value) in next_items.items()], reverse=True)

def do_test_case(case):
    stalls, person_index = read_space_separated_integers()
    layers = [[Item(stalls, 1)]]
    while layers[-1][0].size > 1:
        layers.append(split_layer(layers[-1]))
    items = [item for layer in layers for item in layer]

    current_idx, current_item_idx = 0, -1
    while current_idx < person_index:
        current_item_idx += 1
        current_idx += items[current_item_idx].count

    item = items[current_item_idx]
    distances = (item.size // 2, (item.size - 1) // 2)
    print("Case #{0}: {1} {2}".format(case, distances[0], distances[1]))

def main():
    for case in range(read_integer()):
        do_test_case(case + 1)

if __name__ == "__main__":
    main()