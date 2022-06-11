#include <iostream>
#include <vector>

using namespace std;

struct Heap{
	int num;
	int t;
};

void swapi(vector<Heap>& arr, int i, int k){
    Heap y = arr[i];
    arr[i] = arr[k];
    arr[k] = y;
}

void bottom_heap_sort(vector<Heap>& arr, int len){
	int parent = (len-1)/2;
	if(arr[len].t > arr[parent].t || (arr[len].t == arr[parent].t && arr[len].num < arr[parent].num)){
		swapi(arr,len,parent);
		if(parent!=0){
			bottom_heap_sort(arr,parent);
		}
	}
}

void heap_sort(vector<Heap>& arr, int r, int len){
    int left = 2*r + 1;
    int right = 2*r + 2;
    int max = r;
    if(left < len && (arr[left].t > arr[max].t || (arr[left].t == arr[max].t && arr[left].num < arr[max].num)))
        max = left;
	if(right < len && (arr[right].t > arr[max].t || (arr[right].t == arr[max].t && arr[right].num < arr[max].num)))
        max = right;
    if(max != r){
        swapi(arr, max, r);
        heap_sort(arr, max, len);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k;
	vector<Heap> mas(0);
	vector<int> res(0);
	cin>>k;
	for(int i = 0; i<k; i++){
		int l = 0;
		int n;
		int g;
		cin >> n;
		for (int h = 0; h < n; h++){
			cin>>g;
			if(g!=0){
				Heap temp;
				temp.num = h+1;
				temp.t = g;
				mas.push_back(temp);
				bottom_heap_sort(mas,mas.size()-1);
			}
		}
		
		while(mas.size()>1){
			l++;
			Heap  t0 = mas[0];
			Heap  t1;
			mas[0] = mas[mas.size()-1];
			mas.pop_back();
			heap_sort(mas, 0, mas.size()); 
			t1 = mas[0];
			mas[0] = mas[mas.size()-1];
			mas.pop_back();
			heap_sort(mas, 0, mas.size());
			if((t0.num)<=(t1.num)){
				res.push_back(t0.num);
				res.push_back(t1.num);
			}
			else{
				res.push_back(t1.num);
				res.push_back(t0.num);
			}
			(t0.t)--;
			(t1.t)--;
			if((t0.t)>0){
				mas.push_back(t0);
				bottom_heap_sort(mas, mas.size()-1);
			}
			if((t1.t)>0){
				mas.push_back(t1);
				bottom_heap_sort(mas, mas.size()-1);
			}
		}
		cout<<l<<"\n";
		for(int v = 0; v < l; v++){
			cout<<res[2*v]<<" "<<res[(2*v)+1]<<"\n";
		}
		res.clear();
		mas.clear();
	}
	return 0;
}