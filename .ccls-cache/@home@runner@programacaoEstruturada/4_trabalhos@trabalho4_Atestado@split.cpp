#include <bits/stdc++.h>
using namespace std;
 
void splitstr(string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    while (end != -1) {
        cout << str.substr(start, end - start) << endl;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    cout << str.substr(start, end - start);
}
int main()
{
    string s = "This&&is&&an&&Article&&at&&OpenGenus"; // Take any string with any delimiter 
    splitstr(s, "&&");
    cout << endl;
 
    return 0;
}