n = input()
a = map(int, raw_input().split())
s = []
for i in a :
	j = i
	while j in s:
		s.remove(j)
		j = j + 1
	s.append(j)
print max(s) + 1 - len(s)

