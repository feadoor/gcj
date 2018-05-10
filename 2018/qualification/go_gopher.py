import sys

class Orchard:

    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.covered_squares = set()
        self.to_cover = [[9 for _ in range(width - 2)] for _ in range(height - 2)]
        self.missing_squares = set()
        self.most_missing = -1

    def get_best_square(self):
        if len(self.missing_squares) == 0:
            self._list_missing_squares()
        for square in self.missing_squares:
            return square[0] + 2, square[1] + 2

    def update(self, x, y):
        if (x - 1, y - 1) in self.covered_squares:
            return
        self.covered_squares.add((x - 1, y - 1))
        for n_x, n_y in self._neighbours(x - 1, y - 1):
            self._update_square(n_x, n_y)

    def _neighbours(self, x, y):
        return filter(lambda c: 1 <= c[0] < self.height - 1 and 1 <= c[1] < self.width - 1, [
            (x - 1, y - 1), (x, y - 1), (x + 1, y - 1), (x + 1, y),
            (x + 1, y + 1), (x, y + 1), (x - 1, y + 1), (x - 1, y),
            (x, y),
        ])

    def _update_square(self, x, y):
        if self.to_cover[x - 1][y - 1] == self.most_missing:
            self.missing_squares.remove((x - 1, y - 1))
        self.to_cover[x - 1][y - 1] -= 1

    def _list_missing_squares(self):
        self.most_missing = max(max(x) for x in self.to_cover)
        self.missing_squares = set((x, y) for x in range(self.height - 2) for y in range(self.width - 2) if self.to_cover[x][y] == self.most_missing)

def get_orchard_size(area):
    for w in range(3, 15):
        if w * w <= area < (w + 1) * (w + 1):
            if w * (w + 1) < area:
                return (w, w + 2)
            elif w * w < area:
                return (w, w + 1)
            else: return (w, w)

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def do_test_case():
    area = int(input())
    orchard = Orchard(*get_orchard_size(area))

    while True:
        out_x, out_y = orchard.get_best_square()
        print(out_x, out_y, flush=True)
        in_x, in_y = read_space_separated_integers()
        if in_x == in_y == -1:
            sys.exit(1)
        elif in_x == in_y == 0:
            break
        else:
            orchard.update(in_x, in_y)

def main():
    for _ in range(int(input())):
        do_test_case()

if __name__ == "__main__":
    main()
