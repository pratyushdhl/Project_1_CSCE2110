#include "../include/ResourceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool ResourceManager::loadResources(const string& filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "Error: Could not open " << filename << endl;
        return false;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        string id;
        string name;
        string type;
        string availability;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, availability, '|');

        bool isAvailable;

        if (availability == "1")
        {
            isAvailable = true;
        }
        else
        {
            isAvailable = false;
        }

        Resource resource(id, name, type, isAvailable);

        resources.push_back(resource);
    }

    file.close();
}

void ResourceManager::displayResources() const
{
    cout << "\n===== All Resources =====" << endl;

    for (const Resource& resource : resources)
    {
        resource.display();
    }
}


void ResourceManager::displayResourceAvailability() const
{
    cout << "\n===== Resource Availability =====" << endl;

    for (const Resource& resource : resources)
    {
        cout << "Resource ID: " << resource.getResourceID()
             << " | ";
         if (resource.isAvailable())
        {
            cout << "Available";
        }
        else
        {
            cout << "Unavailable";
        }
        cout << endl;
    }
}