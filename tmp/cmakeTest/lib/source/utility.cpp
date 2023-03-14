#include "utility.hpp"
#include "round.hpp"
#include <sdbus-c++/sdbus-c++.h>

bool callMethod_NameHasOwner(const std::string& name)
{
    doNothing();
    const char* destinationName = "org.freedesktop.DBus";
    const char* objectPath = "/org/freedesktop/DBus";
    auto concatenatorProxy = sdbus::createProxy(destinationName, objectPath);

    const char* interfaceName = "org.freedesktop.DBus";

    auto method = concatenatorProxy->createMethodCall(interfaceName, "NameHasOwner");
    method << name;
    auto reply = concatenatorProxy->callMethod(method);
    bool result;
    reply >> result;
    return result;
}