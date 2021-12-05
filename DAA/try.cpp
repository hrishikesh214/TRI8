#include <iostream>
#include "../PrettyTable.h"
using namespace std;

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
//     caller([](string s)
//            { cout << s + " lol" << endl; });

//     gg x;
//     x("gg");
//     x("leol");
//     cout << x.count << endl;
//     return 0;
// }

int main()
{
    gg x;
    auto [a, b] = x.get();
    cout << a << b << endl;
    return 0;
}