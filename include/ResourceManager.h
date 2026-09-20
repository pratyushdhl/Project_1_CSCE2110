#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <string>
#include "../include/Resource.h"

using namespace std;

class ResourceManager
{
    private:
        vector<Resource> resources;
    
    public:
        // Load resource from resources.txt
        bool loadResources(const string& filename);

		// Sort resources by name
		void sortResourcesByName();

        //Display all resources
        void displayResources() const;

        // Display resource availability
        void displayResourceAvailability() const;
};

#endif
