import itertools
my = list(itertools.product([0,1,2], repeat=10))
ans = 0
for l in my:
	for i in range(1, len(l)-1):
		if l[i-1] < l[i] and l[i+1] < l[i]:
			ans += 1
		elif l[i-1] > l[i] and l[i+1] > l[i]:
			ans += 1

print(ans)