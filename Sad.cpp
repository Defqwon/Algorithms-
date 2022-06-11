#include <iostream>

using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n,m;
	int k,p;
	do{
		cin>>n;
	}while(1>n||n>10000);
		
	do{
		cin>>m;
	}while(1>m||m>1000);
	
	int ** tab = new int *[2];
	tab[0] = new int[m];
	tab[1] = new int[m];
	for(int i = 0; i<m; i++){
		cin>>tab[0][i];
	}
	
	for(int o = 0; o<n-1; o++){
		for(int i = 0; i<m; i++){
			cin>>tab[1][i];
			if(i == 0){
				if(tab[0][i]>tab[0][i+1]){
					tab[1][i] = tab[1][i] + tab[0][i];
				}
				else{
					tab[1][i] = tab[1][i] + tab[0][i+1];
				}
			}
			else if(i == m-1){
				if(tab[0][i-1]>tab[0][i]){
					tab[1][i] = tab[1][i] + tab[0][i-1];
				}
				else{
					tab[1][i] = tab[1][i] + tab[0][i];
				}
			}
			else{
				k = tab[0][i-1];
				if(k<tab[0][i]){
					k = tab[0][i];
				}
				if(k<tab[0][i+1]){
					k = tab[0][i+1];
				}
				tab[1][i] = tab[1][i]+k;
			}
		}
		for(int l = 0; l<m; l++){
			tab[0][l] = tab[1][l];
		}
	}
	
	k = tab[0][0];
	p = 0;
	for(int i = 1; i<m; i++){
		if(k<tab[0][i]){
			k = tab[0][i];
			p = i;
		}
	}
	cout<<p<<" "<<k;
	delete[] tab[0];
	delete[] tab[1];
	delete[] tab;
	
	return 0;