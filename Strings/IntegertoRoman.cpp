#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    string result="";
    string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int val[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    for(int i=0;num!=0;i++)
    {
        while(num>=val[i]){
            num-=val[i];
            result+=symbol[i];
        }
    }
    return result;
    }

int main(){
    int num = 3749;
    cout << "The Roman numeral for " << num << " is " << intToRoman(num) << endl;
    return 0;
}