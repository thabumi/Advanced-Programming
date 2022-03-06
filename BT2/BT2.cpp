#include <iostream>


using namespace std;
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    double a{5};
    cout << a;
//   
//    cin >> s;
//    vector<pair<long long, char>> v;
//    int cnt = 1;
//    for (int i = 1; i < s.size(); i++) {
//        if (s[i] != s[i - 1]) {
//            v.push_back({cnt, s[i - 1]});
//            cnt = 1;
//        }
//        else {
//            cnt++;
//        }
//    }
//    
//    if (cnt) {
//        v.push_back({cnt, s[s.size() - 1]});
//    }
//    //v[0]={2, a} v[1] = {1, c} v[2] = {1, a}...
//    long long res = 0;
//    for (int i = 0; i < v.size(); i++) {
//        res += (v[i].first >= 2);        
//    }
//    // k * (k-1) / 2
//    res += 1LL * v.size() * (v.size() - 1) / 2;
//    for (int i = 1; i < v.size() - 1; i++) {
//        if (v[i].first == 1 && v[i - 1].second == v[i + 1].second) {
//            res--;
//        }
//    }
//    cout << res;
//    return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//string ltrim(const string &);
//string rtrim(const string &);
//vector<string> split(const string &);
//
///*
// * Complete the 'solve' function below.
// *
// * The function is expected to return an INTEGER.
// * The function accepts 2D_INTEGER_ARRAY steps as parameter.
// */
//
//long long solve(vector<vector<int>> steps) {
//    long long mn = 1e9;
//    long long Mn = 1e9;
//    for (int i = 0; i < steps.size(); i++) {
//        mn = min(mn, 1LL * steps[i][0]);
//        Mn = min(Mn, 1LL * steps[i][1]);
//    }
//    return mn * Mn;
//}
//
//int main()
//{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string n_temp;
//    getline(cin, n_temp);
//
//    int n = stoi(ltrim(rtrim(n_temp)));
//
//    vector<vector<int>> steps(n);
//
//    for (int i = 0; i < n; i++) {
//        steps[i].resize(2);
//
//        string steps_row_temp_temp;
//        getline(cin, steps_row_temp_temp);
//
//        vector<string> steps_row_temp = split(rtrim(steps_row_temp_temp));
//
//        for (int j = 0; j < 2; j++) {
//            int steps_row_item = stoi(steps_row_temp[j]);
//
//            steps[i][j] = steps_row_item;
//        }
//    }
//
//    long long result = solve(steps);
//
//    fout << result << "\n";
//
//    fout.close();
//
//    return 0;
//}
//
//string ltrim(const string &str) {
//    string s(str);
//
//    s.erase(
//        s.begin(),
//        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//    );
//
//    return s;
//}
//
//string rtrim(const string &str) {
//    string s(str);
//
//    s.erase(
//        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//        s.end()
//    );
//
//    return s;
//}
//
//vector<string> split(const string &str) {
//    vector<string> tokens;
//
//    string::size_type start = 0;
//    string::size_type end = 0;
//
//    while ((end = str.find(" ", start)) != string::npos) {
//        tokens.push_back(str.substr(start, end - start));
//
//        start = end + 1;
//    }
//
//    tokens.push_back(str.substr(start));
//
//    return tokens;
//}
