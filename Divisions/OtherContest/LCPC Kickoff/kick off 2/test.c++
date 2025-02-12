#include <bits/stdc++.h>
using namespace std;

int main(){
	int c; cin>>c;
	vector<int> v1(c) , v2(c);
	for(int i = 0 ; i < c ; i++){
		int t; cin>>t;
		v1[i] = t;
		v2[i] = t;
	}
	sort(v1.begin(), v1.end());
	int res = 0;
	vector<int> index;
	for(int i = 0 ; i < c ; i++){
		if(v1[i] != v2[i]){
			res++;
			index.push_back(i);
		}
	}
		
	if(res == 2){
		int ind1 = index[0];
		int ind2 = index[1];
		int k = v2[ind1];
		v2[ind1] = v2[ind2];
		v2[ind2] = k;
		if(v1 == v2) cout<<"Jamhoor"<<endl;
		else cout<<"Farhat"<<endl;
	}else{
		cout<<"Farhat"<<endl;
	}
	return 0;
}