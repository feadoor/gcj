from collections import defaultdict
from copy import copy, deepcopy

def read_space_separated_integers():
    return [int(x) for x in input().strip().split(' ')]

def read_single_recipe(n_elements):
    recipe = defaultdict(int)
    for element in read_space_separated_integers():
        recipe[element - 1] = 1
    return recipe

def read_recipes(n_elements):
    return [read_single_recipe(n_elements) for _ in range(n_elements)]

def find_debt(supplies):
    return min((x for x in range(len(supplies)) if supplies[x] < 0), default=-1)

def do_payoff(supplies, recipes, debt_idx):
    if recipes[debt_idx][debt_idx] > 0:
        return False
    else:
        for ingredient, amount in recipes[debt_idx].items():
            supplies[ingredient] += amount * supplies[debt_idx]
        for recipe in recipes:
            if recipe[debt_idx] > 0:
                for ingredient, amount in recipes[debt_idx].items():
                    recipe[ingredient] += amount * recipe[debt_idx]
                del recipe[debt_idx]
        supplies[debt_idx] = 0
        return True

def can_make_lead(amount, supplies, recipes):
    supplies, recipes = copy(supplies), deepcopy(recipes)
    supplies[0] -= amount

    while True:
        debt_idx = find_debt(supplies)
        if debt_idx == -1:
            return True
        else:
            if not do_payoff(supplies, recipes, debt_idx):
                return False

def maximum_lead(supplies, recipes):
    lower, upper = 0, sum(supplies)
    while lower != upper:
        mid = (lower + upper + 1) // 2
        if can_make_lead(mid, supplies, recipes):
            lower = mid
        else:
            upper = mid - 1
    return lower

def do_test_case(case):
    n_elements = int(input())
    recipes, supplies = read_recipes(n_elements), read_space_separated_integers()
    print('Case #{0}: {1}'.format(case, maximum_lead(supplies, recipes)))

def main():
    for case in range(int(input())):
        do_test_case(case + 1)

if __name__ == '__main__':
    main()