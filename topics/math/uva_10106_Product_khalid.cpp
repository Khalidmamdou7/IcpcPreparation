// Problem Source: https://onlinejudge.org/index.php
// the nice idea: using reversed arrays to store big integers
// this idea is explained here https://youtu.be/Syx2qDjj7TE?t=644




#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> x(251, -1);
    vector<int> y(251, -1);
    string s1, s2;
    while(cin >> s1 >> s2){
        for(int i = 0; i < s1.length();i++){
            x[i] = s1[s1.length()- 1 - i] - '0';
        }
        for(int i = 0; i < s2.length();i++){
            y[i] = s2[s2.length()- 1 - i] - '0';
        }
        vector<int> ans(501, 0);
        for (int i = 0; i < s1.length();i++){
            for (int j = 0; j< s2.length();j++){
                ans[i+j] += x[i]*y[j];
            }
        }
        int i =0;
        string s3;
        while (i < 501){
            ans[i+1] += ans[i]/10;
            ans[i] = ans[i] %10;
            s3.insert(0,1,  ans[i] + '0');
            i++;
        }
        s3. erase(0, min(s3.find_first_not_of('0'), s3.size()-1));
        cout << s3 << endl;





    }


    return 0;
}
