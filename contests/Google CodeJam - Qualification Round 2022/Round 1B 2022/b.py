def read():
    nums = input().split()
    return [int(num) for num in nums]

def solve(N, P, X):
    ans = 0
    pressure = 0
    for i in range(N):
      
        X[i].sort()

        if X[i][0] < pressure < X[i][-1]:
            if pressure - X[i][0] <= X[i][-1] - pressure:
                ans += (pressure - X[i][0]) + (X[i][-1] - X[i][0])
                pressure = X[i][-1]
            else:
                ans += (X[i][-1] - pressure) + (X[i][-1] - X[i][0])
                pressure = X[i][0]
        else:
            if pressure < X[i][-1]:
                ans += X[i][-1] - pressure
                pressure = X[i][-1]
            else:
                ans += pressure - X[i][0]
                pressure = X[i][0]
    return ans

def main():
    T = int(input())
    for case in range(1, T+1):
        N, P = read()
        X = []
        for _ in range(N):
            X.append(read())
        ans = solve(N, P, X)
        print(f"Case #{case}: {ans}")

main()