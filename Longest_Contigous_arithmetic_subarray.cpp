/*
An Arithmetic array is an array that contains at atleast two integers and the difference between consecutive integers is equal,
Ex: [3,3], [9,10,11], [9,7,5,3] are arithmetic arrays and [2,1,2] is not a arithmetic array.

Find out the length of the Longest_Contigous_arithmetic_subarray from given array of size n.

*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int maxl = 2;
    int cl = 2;
    int pd = 0;
    for(int i=1;i<n;i++){
       if(a[i]-a[i-1] == pd){
           cl+=1;
       }
       else{
           pd = a[i]-a[i-1];
           cl = 2;
       }
       if(cl>maxl){
           maxl = cl;
       }
    }
    cout << maxl;
	return 0;
}
