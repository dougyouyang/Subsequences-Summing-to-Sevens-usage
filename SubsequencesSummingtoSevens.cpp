//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
long long prefix[50050], pol[10], por[10];

int main()
{
    int n, p1, p2, comp, comp2;
    int i;
    
    cin >> n;
    p1=0, p2=n;
    for(i=1;i<=n;i++){
        cin >> prefix[i];
        if(i!=1)
            prefix[i]+=prefix[i-1];
    }
    for(i=1;i<=n;i++){
        prefix[i]%=7;
    }
    while(p1!=p2){
        comp=comp2=0;
        if(pol[prefix[p1]]==0){
            pol[prefix[p1]]=p1;
        }
        if(por[prefix[p2]]==0){
            por[prefix[p2]]=p2;
        }
        if(pol[prefix[p2]]!=0){
            comp=p2-pol[prefix[p2]];
        }
        if(por[prefix[p1]]!=0){
            comp2=por[prefix[p1]]-p1;
        }
        if(comp || comp2){
            if(comp>comp2){
                cout << comp << endl;
                return 0;
            }
            else{
                cout << comp2 << endl;
                return 0;
            }
        }
        p1++, p2--;
    }
    
    return 0;
}
