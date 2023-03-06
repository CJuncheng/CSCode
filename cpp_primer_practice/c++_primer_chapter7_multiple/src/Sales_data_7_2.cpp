#include "Sales_data_7_2.h"


SalesData72&
SalesData72::combine (const SalesData72& rhs)
{
    unites_sold += rhs.unites_sold;
    sale_price = ( rhs.sale_price * rhs.unites_sold + sale_price * unites_sold);
    if (selling_price != 0)
        discount = sale_price / selling_price;
    return *this;
}