#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t sdds::Station::m_widthField = 0;
int sdds::Station::id_generator = 0;

sdds::Station::Station(const string& record) 
{
    Utilities utilities;
    size_t next_pos = 0;

    bool more = true;
    
    m_id = ++id_generator;

    m_itemName = utilities.extractToken(record, next_pos, more);
    m_nextSerialNumber = stoi(utilities.extractToken(record, next_pos, more));
    m_numOfInStockItems = stoi(utilities.extractToken(record, next_pos, more));

    m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
    m_stationDescription = utilities.extractToken(record, next_pos, more);
}

const string& sdds::Station::getItemName() const {
    return m_itemName;
}

size_t sdds::Station::getNextSerialNumber(){
    return m_nextSerialNumber++;
}

size_t sdds::Station::getQuantity() const {
    return m_numOfInStockItems;
}

void sdds::Station::updateQuantity(){
    if (m_numOfInStockItems > 0) 
    {
        m_numOfInStockItems--;
    }
}

void sdds::Station::display(ostream& os, bool m_full) const {
    os << std::right;
    os << setw(3) << setfill('0') << m_id << " | ";
    os << left << setfill(' ') << setw(m_widthField + 1) << m_itemName << " | ";
    os << right << setw(6) << setfill('0') << m_nextSerialNumber << " | ";

    if (m_full)
    {
        os << setfill(' ');
        os << right;
        os << setw(4) << m_numOfInStockItems << " | " << m_stationDescription;
    }

    os << endl;
}