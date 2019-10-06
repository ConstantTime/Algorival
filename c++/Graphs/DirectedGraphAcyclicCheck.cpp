bool visited[N];
bool restack[N];
bool isCyclicUtil(int i) {
    if(visited[i] == false) {
        visited[i] = true;
        restack[i] = true;
        for(auto j : a[i]) {
            if(!visited[j] && isCyclicUtil(j)) return true;
            else if(restack[j]) return true;
        }
    }
    restack[i] = false;
    return false;
}
bool isCyclic() {
    for(int i = 1 ; i <= n ; i++) {
        if(isCyclicUtil(i)) return true;
    }
    return false;
}

int phi(int n){
    int res = n;
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            res /= i;
            res *= i - 1;
            while(n % i == 0){
                n /= i;
            }
        }
    }
    if(n > 1){
        res /= n;
        res *= n - 1;
    }
    return res;
}