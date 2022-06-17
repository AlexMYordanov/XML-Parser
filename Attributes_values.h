#ifndef ATTRIBUTES_VALUES_H_INCLUDED
#define ATTRIBUTES_VALUES_H_INCLUDED

#include <iostream>
#include <string>
class Attributes_values
{
private:
    std::string attribute;
    std::string value;
public:
    Attributes_values();
    Attributes_values(std::string,std::string);
    Attributes_values(const Attributes_values&);
    std::string get_attribute()const;
    std::string get_value()const;
    void set_value(std::string);
    friend std::ostream& operator<<(std::ostream&, Attributes_values&);
};

#endif // ATTRIBUTES_VALUES_H_INCLUDED
