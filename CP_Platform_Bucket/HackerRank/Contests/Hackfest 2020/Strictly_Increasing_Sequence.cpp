#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'whoIsTheWinner' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

string whoIsTheWinner(vector<int> arr) {
    // WRITE DOWN YOUR CODE HERE
    map <int, int> m;
    int rep=0, nrep=0;
    for(auto i=arr.begin();i!=arr.end();i++){
        if(m.find(*i)!=m.end()){
            m[*i]++;
            rep++;
            if(m[*i]==2){
                nrep--;
                rep++;
            }
        }
        else{
            m.insert(pair<int,int>(*i,1));
            nrep++;
        }
    }
    //cout<<nrep<<" "<<rep<<endl;
    if(rep==0){
        return "First";
    }
    if(nrep%2==0){
        if((rep-1)%2==0){
            return "First";
        }
        else{
            return "Second";
        }
    }
    else{
        if((rep-1)%2==0){
            return "Second";
        }
        else{
            return "First";
        }
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = whoIsTheWinner(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
