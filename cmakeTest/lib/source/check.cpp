#include "check.hpp"
#include <string> 

bool check()
{
    std::string name = "org.freedesktop.DBus";
    return callMethod_NameHasOwner(name);
}