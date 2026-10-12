#include "../include/ResourceManager.h"
#include <iostream>
#include <iomanip>
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

        if (availability == "Available")
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

Resource* ResourceManager::getResource(const string& id) {
	
	for (int i = 0; i < resources.size(); i++) {
		cout << resources.at(i).getResourceID() << endl;
		cout << id << endl;
		if (resources.at(i).getResourceID() == id) {
			return &resources.at(i);
		}
	}
	return nullptr;
	
}

void ResourceManager::sortResourcesByName() {
	
	if (resources.empty()) {
		cout << "No resources to sort." << endl;
	}
	else {
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int i = 1; i < resources.size(); i++) {
				// Compare ith to previous
				if (resources[i].getResourceName() < resources[i-1].getResourceName()) {
					Resource temp = resources[i-1];
					resources[i-1] = resources[i];
					resources[i] = temp;
					sorted = false;
				}
			}
		}
	}	
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
	// Table header
    cout << "\n===== Resource Availability =====" << endl;
	cout << setw(5) << left << "ID";
	cout << "|" << setw(25) << "Name";
	cout << "|" << setw(25) << "Type";
	cout << "|Availability" << endl;
	cout << string(5, '-') << '+';
	cout << string(25, '-') << '+';
	cout << string(25, '-') << '+';
	cout << string(15, '-') << endl;
	
	// Table contents
	for (const Resource& resource : resources) {
		cout << setw(5) << resource.getResourceID();
		cout << "|" << setw(25) << resource.getResourceName();
		cout << "|" << setw(25) << resource.getResourceType();
		cout << "|";
		cout << (resource.isAvailable() ? "Available" : "Unavailable") << endl;
	}
	cout << endl;
}

void ResourceManager::displayResourceUtilization() const 
{
	// Table header
	cout << setw(5) << left << "ID";
	cout << "|" << setw(25) << "Name";
	cout << "|Type" << endl;
	cout << string(5, '-') << '+';
	cout << string(25, '-') << '+';
	cout << string(25, '-') << endl;
	
	// Table contents
	int used = 0, unused = 0;
	for (const Resource& resource : resources) {
		if (!resource.isAvailable()) {
			used++;
			cout << setw(5) << resource.getResourceID();
			cout << "|" << setw(25) << resource.getResourceName();
			cout << "|" << setw(25) << resource.getResourceType() << endl;
		}
		else {
			unused++;
		}
	}
	
	// Usage
	cout << "Total resource utilization: " << used << "/" << used+unused << endl;
	
}