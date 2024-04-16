n, s = map(int, input().split())
arr = list(map(int, input().split()))
arr.append(0)

answer = 1000000
i = j = 0
sum = arr[0]

while j != n:
    if sum < s:
        j += 1
        sum += arr[j]
    else:
        sum -= arr[i]
        answer = min(answer, j - i + 1)
        i += 1
        
if answer == 1000000:
    answer = 0
print(answer)