#include <iostream>
#include "../PrettyTable.h"
using namespace std;


int main()
{
    PrettyTable *table = new PrettyTable({"Name Person", "Age", "Height"});
    table 
        ->add_row({"Hrishi", "20", "5'10"})
        ->add_row({"gg", std::to_string(10), "710"})
        ->print();
    return 0;
}
