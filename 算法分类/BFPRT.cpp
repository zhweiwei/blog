#include<iostream>
#include<algorithm>
using namespace std;

int InsertSort(int  array[], int left, int right);                 //插入排序，返回中位数下标
int GetPivotIndex(int  array[], int left, int right);              //返回中位数的中位数下标
int Partition(int array[], int left, int right, int pivot_index);  //利用中位数的中位数的下标进行划分，返回分界线下标
int BFPRT(int array[], int left, int right, const int & k);        //求第k小，返回其位置的下标
void printarray(int array[],int left,int right){
    cout<<"+++++++++"<<endl;
    for(;left<= right;left++)
    cout <<array[left]<<" ";

    cout<<endl<<"                    ++++++++++"<<endl;
}
int main()
{
    int k = 5;
    int array[10] = { 1,1,2,3,1,5,-1,7,8,-10 };
 
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";
    cout << endl;

    cout  << array[BFPRT(array, 0, 9, k)] << endl;


    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}

/* 插入排序，返回中位数下标 */
int InsertSort(int array[], int left, int right)
{
     printarray(array,0,9);
    int temp;
    int j;
    for (int i = left + 1; i <= right; i++)
    {
        temp = array[i];
        j = i - 1;
        for(;j >= left && array[j] > temp;j--)
            array[j + 1] = array[j];
        array[j + 1] = temp;
    }
printarray(array,0,9);
    cout<<endl;

    return ((right - left) >> 1) + left;
}

/* 返回中位数的中位数下标 */
int GetPivotIndex(int array[], int left, int right)
{
   
    if (right - left < 5)
        return InsertSort(array, left, right);

    int sub_right = left - 1;
    for (int i = left; i + 4 <= right; i += 5)
    {
        int index = InsertSort(array, i, i + 4);  //找到五个元素的中位数的下标
        ++sub_right;
        swap(array[sub_right], array[index]);   //依次放在左侧
    }

    return BFPRT(array, left, sub_right, ((sub_right - left + 1) >> 1)+1);
    
}

/* 利用中位数的中位数的下标进行划分，返回分界线下标 */
int Partition(int array[], int left, int right, int pivot_index)
{
    
    cout<<endl<<"<"<<array[pivot_index]<<">"<<endl;
    swap(array[pivot_index], array[right]);  //把基准放置于末尾

    int divide_index = left;  //跟踪划分的分界线
    for (int i = left; i < right; i++)
    {
        if (array[i] < array[right])
            swap(array[divide_index], array[i]),divide_index++;  //比基准小的都放在左侧
    }

    swap(array[divide_index], array[right]);  //最后把基准换回来
    
    return divide_index;
}

int BFPRT(int array[], int left, int right, const int & k)
{
    int pivot_index = GetPivotIndex(array, left, right);            //得到中位数的中位数下标
    int divide_index = Partition(array, left, right, pivot_index);  //进行划分，返回划分边界
    int num = divide_index - left + 1;
    if (num == k)
        return divide_index;
    else if (num > k)
        return BFPRT(array, left, divide_index - 1, k);
    else
        return BFPRT(array, divide_index + 1, right, k - num);
}