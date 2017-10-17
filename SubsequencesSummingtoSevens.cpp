/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
