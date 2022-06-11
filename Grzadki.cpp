#include <iostream>

using namespace std;

struct warz{
    string naz;
	float zak;
	int odl;
	int mies;
};

int main()
{   
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    int n;
    int bufi;     
    float buf;
	
	do{
		cin>>n;
	}while(n<1||n>1000000);
	
	int *tab = new int[3];
    warz *korz = new warz[n];
	warz *niekorz = new warz[n];
	warz tabpom;
	
    int f = 0;
	cin>>tab[0]>>tab[1]>>tab[2];
	
    for(int i = 0; i<3; i++){	// уменьшает значения 
		f = tab[i];
		tab[i]=--f;
    }
	
	cin>>korz[0].naz>>korz[0].zak>>korz[0].odl>>korz[0].mies;
	
	if(tab[0]==0){
		for(int i = 1;i<n;i++){
			cin>>korz[i].naz>>korz[i].zak>>korz[i].odl>>korz[i].mies;
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].zak)<(korz[bufi].zak)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[0]==1){
		for(int i = 1;i<n;i++){
			cin>>korz[i].naz>>korz[i].zak>>korz[i].odl>>korz[i].mies;
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].odl)<(korz[bufi].odl)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[0]==2){
		for(int i = 1;i<n;i++){
			cin>>korz[i].naz>>korz[i].zak>>korz[i].odl>>korz[i].mies;
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].mies)<(korz[bufi].mies)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	//-------------------------	
	
	cin>>niekorz[0].naz>>niekorz[0].zak>>niekorz[0].odl>>niekorz[0].mies;
	
	if(tab[0]==0){
		for(int i = 1;i<n;i++){
			cin>>niekorz[i].naz>>niekorz[i].zak>>niekorz[i].odl>>niekorz[i].mies;
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].zak)<(niekorz[bufi].zak)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	else if(tab[0]==1){
		for(int i = 1;i<n;i++){
			cin>>niekorz[i].naz>>niekorz[i].zak>>niekorz[i].odl>>niekorz[i].mies;
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].odl)<(niekorz[bufi].odl)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}

	else if(tab[0]==2){
		for(int i = 1;i<n;i++){
			cin>>niekorz[i].naz>>niekorz[i].zak>>niekorz[i].odl>>niekorz[i].mies;
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].mies)<(niekorz[bufi].mies)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}

	//--------------------
	
	if(tab[1]==0&&tab[2]==1){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].zak<korz[bufi].zak)&&(korz[bufi-1].mies)==(korz[bufi].mies)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].odl<korz[bufi].odl)&&(korz[bufi-1].zak)==(korz[bufi].zak)&&(korz[bufi-1].mies)==(korz[bufi].mies)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}

	else if(tab[1]==0&&tab[2]==2){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].zak<korz[bufi].zak)&&(korz[bufi-1].odl)==(korz[bufi].odl)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].mies<korz[bufi].mies)&&(korz[bufi-1].zak)==(korz[bufi].zak)&&(korz[bufi-1].odl)==(korz[bufi].odl)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[1]==1&&tab[2]==0){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].odl<korz[bufi].odl)&&(korz[bufi-1].mies)==(korz[bufi].mies)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].zak<korz[bufi].zak)&&(korz[bufi-1].odl)==(korz[bufi].odl)&&(korz[bufi-1].mies)==(korz[bufi].mies)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[1]==1&&tab[2]==2){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].odl<korz[bufi].odl)&&(korz[bufi-1].zak)==(korz[bufi].zak)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].mies<korz[bufi].mies)&&(korz[bufi-1].odl)==(korz[bufi].odl)&&(korz[bufi-1].zak)==(korz[bufi].zak)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[1]==2&&tab[2]==0){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].mies<korz[bufi].mies)&&(korz[bufi-1].odl)==(korz[bufi].odl)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].zak<korz[bufi].zak)&&(korz[bufi-1].mies)==(korz[bufi].mies)&&(korz[bufi-1].odl)==(korz[bufi].odl)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}

	else if(tab[1]==2&&tab[2]==1){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].mies<korz[bufi].mies)&&(korz[bufi-1].zak)==(korz[bufi].zak)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(korz[bufi-1].odl<korz[bufi].odl)&&(korz[bufi-1].mies)==(korz[bufi].mies)&&(korz[bufi-1].zak)==(korz[bufi].zak)){
				tabpom = korz[bufi];
				korz[bufi] = korz[bufi-1];
				korz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	//-------------------
	
	if(tab[1]==0&&tab[2]==1){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].zak<niekorz[bufi].zak)&&(niekorz[bufi-1].mies)==(niekorz[bufi].mies)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].odl<niekorz[bufi].odl)&&(niekorz[bufi-1].zak)==(niekorz[bufi].zak)&&(niekorz[bufi-1].mies)==(niekorz[bufi].mies)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}

	else if(tab[1]==0&&tab[2]==2){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].zak<niekorz[bufi].zak)&&(niekorz[bufi-1].odl)==(niekorz[bufi].odl)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].mies<niekorz[bufi].mies)&&(niekorz[bufi-1].zak)==(niekorz[bufi].zak)&&(niekorz[bufi-1].odl)==(niekorz[bufi].odl)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[1]==1&&tab[2]==0){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].odl<niekorz[bufi].odl)&&(niekorz[bufi-1].mies)==(niekorz[bufi].mies)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].zak<niekorz[bufi].zak)&&(niekorz[bufi-1].odl)==(niekorz[bufi].odl)&&(niekorz[bufi-1].mies)==(niekorz[bufi].mies)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[1]==1&&tab[2]==2){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].odl<niekorz[bufi].odl)&&(niekorz[bufi-1].zak)==(niekorz[bufi].zak)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].mies<niekorz[bufi].mies)&&(niekorz[bufi-1].odl)==(niekorz[bufi].odl)&&(niekorz[bufi-1].zak)==(niekorz[bufi].zak)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	else if(tab[1]==2&&tab[2]==0){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].mies<niekorz[bufi].mies)&&(niekorz[bufi-1].odl)==(niekorz[bufi].odl)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].zak<niekorz[bufi].zak)&&(niekorz[bufi-1].mies)==(niekorz[bufi].mies)&&(niekorz[bufi-1].odl)==(niekorz[bufi].odl)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}

	else if(tab[1]==2&&tab[2]==1){
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].mies<niekorz[bufi].mies)&&(niekorz[bufi-1].zak)==(niekorz[bufi].zak)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
		for(int i = 1;i<n; i++){
			bufi = i;
			while(bufi>=1&&(niekorz[bufi-1].odl<niekorz[bufi].odl)&&(niekorz[bufi-1].mies)==(niekorz[bufi].mies)&&(niekorz[bufi-1].zak)==(niekorz[bufi].zak)){
				tabpom = niekorz[bufi];
				niekorz[bufi] = niekorz[bufi-1];
				niekorz[bufi-1] = tabpom;
				bufi--;
			}
		}
	}
	
	//----------------------
	
	for(int i = 0;i<n;i++){
		cout<<korz[i].naz<<"-"<<niekorz[i].naz<<" ";
    }
	
	delete[] tab;
	delete[] korz;
	delete[] niekorz;
    return 0;
}