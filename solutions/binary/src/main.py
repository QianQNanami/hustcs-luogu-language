import bisect

class BS:
    def __init__(self, v):
        self.d = sorted(v)

    def upper_bound(self, n):
        pos = bisect.bisect_right(self.d, n)
        return pos

    def lower_bound(self, n):
        return bisect.bisect_left(self.d, n)

    def equal(self, n):
        pos = bisect.bisect_left(self.d, n)
        cnt = 0
        while pos < len(self.d) and self.d[pos] == n:
            cnt += 1
            pos += 1
        return cnt

def main():
    data = input().split()
    m = int(data[1])
    v = list(map(int, input().split()))
    bs = BS(v)
    
    for _ in range(m):
        s = list(map(int, input().split()))
        res=0
        if s[0] == 1:
            res = bs.equal(s[1])
        elif s[0] == 2:
            x, y = s[1], s[2]
            lb = bs.lower_bound(x)
            ub = bs.upper_bound(y)
            res = ub - lb
        elif s[0] == 3:
            x, y = s[1], s[2]
            cnt = bs.equal(y)
            lb = bs.lower_bound(x)
            ub = bs.upper_bound(y)
            res = ub - lb - cnt
        elif s[0] == 4:
            x, y = s[1], s[2]
            cnt = bs.equal(x)
            lb = bs.lower_bound(x)
            ub = bs.upper_bound(y)
            res = ub - lb - cnt
        elif s[0] == 5:
            cnt = bs.equal(s[1]) + bs.equal(s[2])
            x, y = s[1], s[2]
            lb = bs.lower_bound(x)
            ub = bs.upper_bound(y)
            res = ub - lb - cnt
        if res < 0:
            res = 0
        print(res)

if __name__ == "__main__":
    main()
