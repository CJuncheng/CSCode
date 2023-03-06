#ifndef SALES_DATA_7_2_H
#define SALES_DATA_7_2_H
#include <string>

class SalesData72 
{   
    public:
        std::string isbn(void) const { return bookNO; }
        SalesData72& combine (const SalesData72& rhs);
        std::istream read (std::istream& is, SalesData72& item);
        std::ostream print (std::ostream& os, const SalesData72& item);
    private:
        std::string bookNO;
        unsigned unites_sold = 0; //销售量
        double selling_price = 0.0; //原始价格
        double sale_price = 0.0; //实售价格
        double discount = 0.0;
};


#endif