#include <deque>
#include <vector>
#include <iostream>

using namespace std;

void getValue(const vector<int> val,int size,vector<int>& reval){
	deque<int> tmp;
	
	if(val.size() <size)
	return ;

	for(int i = 0;i < val.size();i++){
		while(!tmp.empty() && val[tmp.back()] < val[i])
		tmp.pop_back();

		tmp.push_back(i);
		if(i - tmp.front()>= size)
		tmp.pop_front();

		if(i < size-1)
		continue;

		reval.push_back(val[tmp.front()]);
	}
}

int main(){
	vector<int> a{1,2,5,3,6,56,7,4,6,6,3,3,3,7,7,8};
	vector<int> b;
	getValue(a,3,b);
	
	for(auto val : b)
	cout <<val<<" "; 
}