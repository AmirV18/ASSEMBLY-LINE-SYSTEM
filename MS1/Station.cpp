/*
	NAME: AMIR VASSELL
	SENECA EMAIL: ARVASSELL@MYSENECA.CA
	STUDENT ID: 154737209
	DATE: November 13. 2022
	NOTE: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
using namespace std;

namespace sdds {

	size_t Station::id_generator = 0;

	size_t Station::m_widthField = 0;

	Station::Station(const std::string& record)
	{
		Utilities util{};
		m_id = ++id_generator;
		size_t position = 0;
		bool more = true;
		m_itemName = util.extractToken(record, position, more);
		m_nextSerialNumber = stoi(util.extractToken(record, position, more));
		m_numOfInStockItems = stoi(util.extractToken(record, position, more));
		if (util.getFieldWidth() > m_widthField)
			m_widthField = util.getFieldWidth();
		
		m_stationDescription = util.extractToken(record, position, more);
	}

	const std::string& Station::getItemName() const {
		return m_itemName;
	}

	size_t Station::getNextSerialNumber() {
		return m_nextSerialNumber++;
	}

	size_t Station::getQuantity() const {
		return m_numOfInStockItems;
	}

	void Station::updateQuantity()
	{
		if (m_numOfInStockItems > 0)
			m_numOfInStockItems--;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		string delimiter = " | ";
		os << right << setw(3) << setfill('0') << m_id << delimiter;
		os << left << setw(15) << setfill(' ') << m_itemName << delimiter;
		os << right << setw(6) << setfill('0') << m_nextSerialNumber << delimiter;
		if (full)
		{
			os << right << setw(4) << setfill(' ') << m_numOfInStockItems << delimiter;
			os << m_stationDescription;
		}
		os << endl;
	}
}
