#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

string repa(const string &s)
{
    string r = s;
    for (int i = 0; i < r.length(); i++)
        r[i] = tolower(r[i]);
    sort(r.begin(), r.end());
    return r;
}
map<string, int> cnt;
vector<string> words;
int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "#")
            break;
        words.push_back(s);
        string r = repa(s);
        if (!cnt.count(r))
            cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        if (cnt[repa(words[i])] == 1)
            ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}