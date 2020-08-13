n = int(input())
b = input()
g = input()
c = 0
for i in b:
   if i not in g:
       break
   for j in g:
       if i == j:
           a = b.find(f"{i}")
           b = b[0 : a : ] + b[a + 1 : :]
           a = g.find(f"{j}")
           g = g[0 : a : ] + g[a + 1 : :]
           c += 1
           break
       
       elif i != j:
           a = g.find(f"{j}")
           g = g[0 : a : ] + g[a + 1 : :]
           g = g + f"{j}"

print(n-c)