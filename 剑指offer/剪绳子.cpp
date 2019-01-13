#include <iostream>

using namespace std;

class Solusion{
    public:
    int maxS(int rope){
        int tmp[rope];
        for(int i = 0 ;i < rope;i++){
            tmp[i] = i;
        }
        
        int tmpmax = 0;
        for(int i = 2; i <= rope;i++){
            for(int j = 1;j <= i;j++){
                tmpmax = Smax(tmpmax,tmp[j]*tmp[i-j]);
                if(tmpmax > tmp[i])
                tmp[i] = tmpmax;
            }
        }

        return tmpmax;
        for(int i = 0;i <= rope;i++){
            cout <<"tmp["<<i<<"] = "<<tmp[i]<<" ";
        }
        cout<<endl;
    }

    int Smax(int i ,int j){
        return (i>j)?i :j;
    }
};

int main()
{
    Solusion s;
    cout <<s.maxS(8) <<endl;
    return 0;
}
