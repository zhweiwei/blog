#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
	public:
	int stringIndex(const string& str1,const string& str2){
	if(str1.empty() || str2.empty())
	return -1;
	
	vector<int > next(str2.size(),-1);
	getVector(str2,next);

	int i,j;

	i = 0;
	j = 0;
   cout<<endl;
   for(auto begin = next.begin();begin != next.end();begin++)
   cout << *begin<<" ";
   cout << endl;
	while(i <str1.length() && j < str2.length()){
		if(str1[i] == str2[j]){
			i++;
			j++;
		}else{
			if(next[j] == -1){
			i++;
			}else{
			j = next[j];
			}
			
			}
	}
	return j == str2.length() ? i-j:-1;
	}

	private:
	void getVector(const string& str,vector<int> & next){
		int j = 0;
		while(j < next.size()){
			if(j == 0)
			next[j] = -1;
			else if(j == 1)
			next[j] = 0;
			else{
				int tmp = j-1;
				while(tmp>=0 && str[next[tmp]] != str[j-1]){
					tmp = next[tmp];
				}
				
				if(tmp == -1)
				next[j] = 0;
				else
				next[j] = next[tmp]+1;
			}
			j++;
		}
	}
};

int main(){
	Solution s;
	cout <<s.stringIndex("adasaasfd","aas")<<endl;
}
