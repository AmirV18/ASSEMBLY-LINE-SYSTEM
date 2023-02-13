#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H

#include "Station.h"

using namespace std;

namespace sdds 
{
    struct Item
    {
        string m_itemName;
        size_t m_serialNumber{0};
        bool m_isFilled{false};

        Item(const string& src) : m_itemName(src) {};
    };

    class CustomerOrder 
    {
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{};
        Item** m_lstItem{}; //check here

        static size_t m_widthField;

        public:
        CustomerOrder();
        CustomerOrder(const string& input);
        CustomerOrder(const CustomerOrder& order);

        CustomerOrder& operator=(const CustomerOrder& order) = delete;

        CustomerOrder(CustomerOrder&& order) noexcept;

        CustomerOrder& operator=(CustomerOrder&& order) noexcept;

        ~CustomerOrder();

        //checks if items are filled
        bool isOrderFilled() const;

        // check if specified items are filled
        bool isItemFilled(const std::string& itemName) const;

        // this modifier fills all items in the current order that the Station specified in the first parameter handles
        void fillItem(Station& station, std::ostream& os);

        // this query displays the state of the current object
        void display(std::ostream& os) const;

    };
};

#endif