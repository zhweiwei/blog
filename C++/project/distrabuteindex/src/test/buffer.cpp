/*
 * @Description: 
 * @Author: ZWW
 * @Date: 2019-02-26 11:12:47
 */

#include <iostream>

#include "../network/buffer.hpp"

using namespace Distrabute;
using namespace std;
int main(){
    Buffer buf;
    buf.Read("sdfhsishbo",8);
    cout <<buf.data()<<endl;
}