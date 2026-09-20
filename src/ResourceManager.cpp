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

void ResourceManager::sortResourcesByName() {
	
	if (resources.empty()) {
		cout << "No resources to sort." << endl;
	}
	else {
		/* SWITCHING TO BUBBLE SORT FOR SIMPLICITY
		// Quick sort by resource name
		Resource& pivot = resources.back();
		int i = -1;
		for (int j = 0; j < resources.size() - 2; j++) {
			// Compare jth and pivot
			if (resources[j].getResourceName() < pivot.getResourceName()) {
				i++;
				if (i != j) {
					// Swap ith and jth
					Resource temp = resources[j];
					resources[j] = resources[i];
					resources[i] = temp;
				}
			}
		}
		// Move pivot to i+1
		resources.insert(resources.begin() + i+1, resources.back());
		resources.pop_back();
		*/
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