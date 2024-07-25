#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Data{
	public:
		int type;
		int repetition;
		Data(){
			type = 0;
			repetition = 0;
		}
		Data(int atype, int repet){
			type = atype;
			repetition = repet;
		}
};
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	vector<int> result;
	vector<Data> desc;
	int temp;
	for(int i=0;i<num;i++){
		cin>>temp;
		result.push_back(temp);
		// cout<<temp<<endl;
	}	
	std::sort (result.begin(), result.end()); 
	// 	for(int i=0;i<num;i++){
	// 	// cin>>temp;
	// 	// result.push_back(temp);
	// 	cout<<result[i]<<endl;
	// }
	int fav = 0;
	int count = 0;
	int j = 0;
	if (result.size() == 1){
		cout<<1<<endl;
		return 0;
	}
	else{
		// int numbers = num;
		// const int numbers = num;
		// Data desc[numbers];
		for(int i=0;i<num-1;i++){
			if(result[i]==result[i+1]){
				count++;
			}
			else if(result[i]<result[i+1]){
				count++;
				// desc[j] = Data(result[i], count);
				desc.push_back(Data(result[i], count));
				// cout<<count<<endl;
				j++;
				count = 0;
			}
		}
	}
	// cout<<*max_element(desc.begin(), desc.end())<<endl;
	int max = 0;

	for(int a = 0;a<desc.size();a++ ){
		// cout<<*a<<endl;
		if(desc[a].repetition>max){
			max = desc[a].repetition;
			// cout<<max<<endl;
		}
	}
	cout<<max<<endl;
}