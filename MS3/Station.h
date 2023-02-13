#ifndef STATION_H
#define STATION_H

#include <string>

using namespace std;

namespace sdds 
{
    class Station 
    {
        int m_id;

        std::string m_itemName;
        std::string m_stationDescription;

        unsigned int m_nextSerialNumber;
        unsigned int m_numOfInStockItems;
        
        static size_t m_widthField;
        static int id_generator;

        public:

        Station(const string& record);

        size_t getNextSerialNumber();
        size_t getQuantity() const;

        const string& getItemName() const;
        void updateQuantity();
        void display(ostream& os, bool full) const;
    };
};


#endif