#include <iostream>

using namespace std;

void sort(char ** t, char ** t1, int n, int z){
    int lo = 0;
    int lx = n-1;
    for (int i = 0; i<n; i++) {
        if (t[i][z] == 'o'){
            lo++;
        }
    }

    for (int i = n-1; i>=0; i--) {
        if (t[i][z] == 'o'){
            t1[lo-1] = t[i];
            lo--;
        }
        else{
            t1[lx] = t[i];
            lx--;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n,k,m,z;
    cin>>n>>k>>m;
    z = k-1;
    char ** res;
    char ** tab = new char*[n];
    char ** t1 = new char*[n];
    for(int i = 0; i < n; i++){
        tab[i] = new char[k];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin>>tab[i][j];
        }
    }

    for(int i = 0; i<k/2; i++){
        sort(tab,t1,n,z);
        z-=1;
        sort(t1,tab,n,z);
        z-=1;
    }
    if(k%2!=0){
        sort(tab,t1,n,z);
        res = t1;
    }
    else{
        res = tab;
    }

    for(int i = n-1; i >= n-m; i--){
        for(int j = 0; j < k; j++){
            cout<<res[i][j]; 
        }
        cout<<'\n';
    }
    return 0;
}