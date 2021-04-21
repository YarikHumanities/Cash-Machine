#include "Check.h"

Check::Check() 
{
    list_of_names = "";
    sum = 0;
}

void Check::print_receipt()
{
    cout << "Check:\n";
    cout << list_of_names;
    cout << "Sum\t" << sum << endl;
}