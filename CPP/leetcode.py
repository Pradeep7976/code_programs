def decrypt(self, code, k):
    ans=[len(code)]
    if(k>=0):
        for i in range(len(code)):
            sum=0
            for j in range(i+1,i+k+1):
                sum+=code[j%(len(code))]
            ans[i]=sum
    else:
        for i in range(len(code)):
            sum=0
            idx=i-1
            for j in range(abs(k)):
                if(idx<0):
                    idx=len(code)-1
                    sum+=code[idx]
                    idx=idx-1
            ans[i]=sum
    return ans