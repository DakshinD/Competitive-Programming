bool isPrime(int n) { 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    if(prime[n]) return true;
    return false;
} 
