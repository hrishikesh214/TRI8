#include <iostream>
#include "../PrettyTable.h"
using namespace std;

#define debug(x) cout << #x << " = " << x << endl;

// int main()
// {
//     PrettyTable *table = new PrettyTable({"Name Person", "Age", "Height"});
//     table
//         ->add_row({"Hrishi", "20", "5'10"})
//         ->add_row({"gg", std::to_string(10), "710"})
//         ->print();
//     return 0;
// }

void say(string s)
{
    cout << s << endl;
}

void caller(void (*f)(string))
{
    f("Hello");
}

class gg
{
public:
    int count = 0;
    void operator()(string x)
    {
        count++;
        cout << x << endl;
    }
    array<string, 2> get()
    {
        return {"hrishikesh", " vaze"};
    }
};

// int main()
// {
//     // caller([](string s)
//     //        { cout << s + " lol" << endl; });

//     gg x;
//     x("gg");
//     x("leol");
//     cout << x.count << endl;
//     return 0;
// }

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string x = "";
        string selected = "";
        if (s.size() == 1)
            return s;
        if (s.size() == 2)
        {
            if (s[0] == s[1])
                return s;
            else
            {
                x += s[0];
                return x;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            x = check(s, i, i);
            selected = x.size() > selected.size() ? x : selected;
            x = check2(s, i, i + 1);
            selected = x.size() > selected.size() ? x : selected;
        }
        return selected;
    }
    string check2(string s, int start, int end)
    {
        if (s[start] != s[end])
            return "";
        return check(s, start, end);
    }
    string check(string s, int start, int end)
    {
        bool ended = false;
        if (start < 0)
        {
            start++;
            ended = true;
        }
        if (end > s.size())
        {
            end--;
            ended = true;
        }

        if (s[start] != s[end])
            ended = true;

        if (ended)
        {
            return s.substr(start + 1, (end - 1) - (start + 1) + 1);
        }

        return check(s, start - 1, end + 1);
    }
};

int main()
{
    Solution sl;
    cout << sl.longestPalindrome("cbbd") << endl;
    cout << sl.longestPalindrome("babad") << endl;
    cout << sl.longestPalindrome("a") << endl;
    cout << sl.longestPalindrome("bb") << endl;
    cout << sl.longestPalindrome("babadada") << endl;
    cout << sl.longestPalindrome("ac") << endl;
    cout << sl.longestPalindrome("ccc") << endl;
    cout << sl.longestPalindrome("cccc") << endl;

    return 0;
}

// int main()
// {
//     gg x;
//     auto [a, b] = x.get();
//     cout << a << b << endl;
//     return 0;
// }
