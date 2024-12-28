def candyDistribution(N,candies):
    if sum(candies)%N!=0:
        return False
    target_candies=sum(candies) // N
    for i in range(N):
        d=target_candies-candies[i]
        if d%2!=0 or d<0:
            return False
    return True

t=int(input())
for i in range (t):
    N=int(input())
    candies=list(map(int,input().split()))
    result=candyDistribution(N,candies)
    if(result):
        print("YES")
    else:
        print("No")