#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H

#include <string>
#include <vector>
#include <iostream>

#include "Workstation.h"

using namespace std;

namespace sdds 
{
    class LineManager 
    {
        std::vector<Workstation*> m_activeLine;                // the collection of workstations for the current assembly line
        size_t                    m_cntCustomerOrder{ 0u }; // the total number of CustomerOrder objects
        Workstation* m_firstStation{}; // points to the first active station on the current line
        // Workstation*              m_firstStation { nullptr}; // points to the first active station on the current line

    public:

        LineManager(const string& file, const vector<Workstation*>& stations);

        void reorderStations();
        void display(ostream& os) const;
        bool run(ostream& os);

    };
};

#endif