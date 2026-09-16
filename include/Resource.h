#ifndef RESOURCE_H
#define RESOURCE_H

#include<string>
using namespace std;

class Resource {

    private:
        string resourceID;
        string resourceName;
        string resourceType;
        bool available;
    public:
    //Constructor
    Resource(string id, string name, string type, bool status);

    //Getters
    string getResourceID() const;
    string getResourceName() const;
    string getResourceType() const;
    bool isAvailable() const;

    //Setters
    void setResourceName(string name);
    void setResourceType(string type);
    void setAvailability(bool status);


    // Display resource information
    void display() const;
};

#endif
