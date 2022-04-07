#include "Input.h"

bool Input(unsigned& var)
{
    bool success = true;

    cin >> var;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(2048, '\n');

        success = false;
        var = 0;
    }

    return success;
}

bool InputBool(unsigned& var)
{
    bool success = true;

    cin >> var;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(2048, '\n');

        success = false;
        var = 0;
    }
    else
    {
        var = (var > 0 ? 1 : 0);
    }

    return success;
}