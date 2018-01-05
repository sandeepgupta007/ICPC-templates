def modpow(a,x,p):
    res = 1
    while(x > 0):
        if(x%2 != 0):
            res = (res*a)%p
        a = (a*a)%p
        x = x//2
    return res
    
def modinverse(a,p):
    return modpow(a,p-2,p)
