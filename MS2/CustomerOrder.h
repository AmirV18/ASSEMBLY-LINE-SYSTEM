/*
    NAME: AMIR VASSELL
    SENECA EMAIL: ARVASSELL@MYSENECA.CA
    STUDENT ID: 154737209
    DATE: November 26. 2022
    NOTE: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <iostream>
#include "Station.h"

namespace sdds
{
  struct Item {
    std::string m_itemName;
    size_t m_serialNumber{ 0 };
    bool m_isFilled{false} ;

    Item(const std::string &src) : m_itemName(src){};
  };

  class CustomerOrder
  {
      // called instance variables
    std::string m_name{};      
    std::string m_product{}; 
    size_t m_cntItem{};  
    Item** m_lstItem{nullptr};  //must manage this resource....

    // Class Variables
    static size_t m_widthField;         // the maximum width of a field

  public:
    CustomerOrder(){};
    CustomerOrder(const std::string& src);
    CustomerOrder(const CustomerOrder &src); //thorw exception here
    CustomerOrder& operator=(const CustomerOrder& src) = delete;
    CustomerOrder(CustomerOrder&& src) noexcept;
    CustomerOrder& operator=(CustomerOrder &&src) noexcept;
    ~CustomerOrder();

   //checks if items are filled
    bool isOrderFilled() const;

    // check if specified items are filled
    bool isItemFilled(const std::string &itemName) const;

    // this modifier fills all items in the current order that the Station specified in the first parameter handles
    void fillItem(Station &station, std::ostream &os);

    // this query displays the state of the current object
    void display(std::ostream &os) const;
  };
}//namespace sdds
#endif 