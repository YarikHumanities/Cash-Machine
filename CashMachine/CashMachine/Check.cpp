#include "Check.h"

Check::Check() 
{
    list_of_names = "";
    sum = 0;
}

void Check::print_recipe()
{
    cout << "Goods: " << list_of_names << endl;
    cout << "Sum: " << sum << endl;
}