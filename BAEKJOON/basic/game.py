A = [5,3,1,7]
B = [2,2,6,8]

A.sort()
B.sort()

answer = 0
for i in range(0,len(A)) :
    if B[i] > A[i] : answer = answer + 1

print(answer)

