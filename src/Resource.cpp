#include "../include/Resource.h"
#include <iostream>

using namespace std;

Resource:: Resource(string id, string name, string type, bool status)

{
    resourceID = id;
    resourceName = name;
    resourceType = type;
    available = status;

}

//Getters
string Resource :: getResourceID() const
{
    return resourceID;
}

string Resource :: getResourceName() const
{
    return resourceName;
}

string Resource :: getResourceType() const
{
    return resourceType;
}

bool Resource :: isAvailable() const
{
    return available;
}

//Setters

void Resource :: setResourceName(string name)
{
    resourceName = name;
}

void Resource :: setResourceType(string type)
{
    resourceType = type;
}

void Resource :: setAvailability(bool status)
{
    available = status;
}

// Display info
void Resource :: display() const
{
    cout << "Resource ID: " << resourceID << endl;
    cout << "Resource Name: " << resourceName << endl;
    cout << "Resource Type: " << resourceType << endl;
    cout << "Availability: ";
    if (available)
    {
        cout << "Available"<< endl;
    }
    else
    {
        cout << "Unavailable" << endl;
    }
}
