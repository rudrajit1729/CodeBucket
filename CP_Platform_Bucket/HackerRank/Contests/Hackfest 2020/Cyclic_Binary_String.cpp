#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'maximumPower' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int maximumPower(string s) {
    int a=0, b=0, c=0;
    int k=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            a++;
            if(a==n){
                return -1;
            }
        }
        else{
            break;
        }       
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            b++;
        }
        else{
            break;
        }
    }
    for(int i=a;i<n-b;i++){
        if(s[i]=='0'){
            c++;
        }
        else{
           if(c>k){
               k=c;
           }
            c=0;
        }
    }
    c=k;
    k=(a+b);
    if(k>c){
        return k;
    }
    else{
        return c;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = maximumPower(s);

    fout << result << "\n";

    fout.close();

    return 0;
}