#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

using namespace sdds;
using namespace std;

LineManager::LineManager(const string& file, const vector<Workstation*>& stations)
{
    Utilities utility;

	ifstream input(file);

	if (!input.is_open())
	{
		throw string("Unable to open file.");
	}
		

	string m_data;

	while (!input.eof())
	{
		getline(input, m_data);

        size_t pos = 0;
        bool m_more = true;

		string curStation, nextStation;

		curStation = utility.extractToken(m_data, pos, m_more);

		if (m_more) 
		{
			nextStation = utility.extractToken(m_data, pos, m_more);
		}

		Workstation* curWorkstation = nullptr;
		Workstation* nextWorkstation = nullptr;

		for_each(stations.begin(), stations.end(), [&curWorkstation, &nextWorkstation, curStation, nextStation](Workstation* ws) 
			{
			if (ws->getItemName() == curStation) 
			{
				curWorkstation = ws;
			} else if (ws->getItemName() == nextStation)
			{
				nextWorkstation = ws;
			}
		});

		if (m_activeLine.size() == 0)
		{
			m_firstStation = curWorkstation;
		}

		curWorkstation->setNextStation(nextWorkstation);

		m_activeLine.push_back(curWorkstation);
	}

	input.close();

}

void LineManager::reorderStations() 
{
	vector<Workstation*> newStations;
	Workstation* lastStation = nullptr;

	unsigned int count = 0;
	while (count < m_activeLine.size()) 
	{
		for (unsigned int i = 0; i < m_activeLine.size(); i++) 
		{
			if (m_activeLine[i]->getNextStation() == lastStation) 
			{
				newStations.push_back(m_activeLine[i]);
				lastStation = m_activeLine[i];
				count++;
				break;
			}
		}
	}

	reverse(newStations.begin(), newStations.end());
	m_firstStation = newStations[0];
	m_activeLine = newStations;
}

bool LineManager::run(ostream& os) 
{
    static int count = 0;
    count++;

	os << "Line Manager Iteration: " << count << endl;

	if (!g_pending.empty()) {
		(*m_firstStation) += move(g_pending.front());
		g_pending.pop_front();
	}

	for (unsigned int i = 0; i < m_activeLine.size(); i++) {
		m_activeLine[i]->fill(os);
	}

	for (unsigned int i = 0; i < m_activeLine.size(); i++){
		m_activeLine[i]->attemptToMoveOrder();
	}

	bool isEmpty = true;

	for (unsigned int i = 0; i < m_activeLine.size(); i++)
	{
		if (!m_activeLine[i]->empty()) 
		{
			isEmpty = false;
			break;
		}
	}

    return isEmpty;
}

void LineManager::display(ostream& os) const 
{
	for (unsigned int i = 0; i < m_activeLine.size(); i++) {
		m_activeLine[i]->display(os);
	}
}