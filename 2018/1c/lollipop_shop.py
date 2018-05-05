def do_test_case():
    n_customers = int(input())
    sold_flavours, seen_flavours = [0] * n_customers, [0] * n_customers
    for _ in range(n_customers):

        customer_prefs = [int(x) for x in input().strip().split(' ')][1:]
        for pref in customer_prefs:
            seen_flavours[pref] += 1

        best_flavour = min(
            (f for f in customer_prefs if sold_flavours[f] == 0),
            key=lambda f: seen_flavours[f], default=-1
        )
        if best_flavour != -1:
            sold_flavours[best_flavour] = 1
        print(best_flavour, flush=True)

def main():
    for _ in range(int(input())):
        do_test_case()

if __name__ == '__main__':
    main()
