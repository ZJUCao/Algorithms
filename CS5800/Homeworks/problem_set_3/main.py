import heapq
import bisect

# input N, M, T
N, M, T = map(int, input().split())

# input M edges
buses = [[] for _ in range(200001)]
for _ in range(M):
    x, y, t1, t2 = map(int, input().split())
    buses[x].append((t1, t2, y))

# sort edges by t1
for x in range(1, 200001):
    buses[x].sort()

# prepare depart times for binary search
depart_times = [[] for _ in range(200001)]
for x in range(1, 200001):
    depart_times[x] = [b[0] for b in buses[x]]

# dijkstra
INF = float('inf')
earliest = [INF] * (200001)
earliest[1] = 0

pq = [(0, 1)]  # (time, station)

while pq:
    t, x = heapq.heappop(pq)

    left = bisect.bisect_left(depart_times[x], t)
    right_limit = t + T

    i = left
    while i < len(buses[x]) and buses[x][i][0] <= right_limit:
        t1, t2, y = buses[x][i]

        if t2 < earliest[y]:
            earliest[y] = t2
            heapq.heappush(pq, (t2, y))
        i += 1

if earliest[N] == INF:
    print("NO")
else:
    print("YES", earliest[N])