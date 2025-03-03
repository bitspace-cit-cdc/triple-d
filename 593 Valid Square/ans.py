
points = [list(map(int, input().split())) for _ in range(4)]
if sum(p[0] for p in points) or sum(p[1] for p in points):
    print("false")
    exit()
d = []
for i in range(4):
    for j in range(i+1,4):
        dx = points[i][0] - points[j][0]
        dy = points[i][1] - points[j][1]
        d.append(dx*dx+dy*dy)
d.sort()
print("true" if d[0] > 0 and d[0]==d[1]==d[2]==d[3] and d[4]==d[5] and d[4]==2*d[0] else "false")
