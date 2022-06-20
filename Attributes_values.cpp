#include "Attributes_values.h"

Attributes_values::Attributes_values()
:attribute(""), value(""){}

Attributes_values::Attributes_values(std::string _attribute, std::string _value)
:attribute(_attribute), value(_value){}

std::string Attributes_values::get_attribute()const
{
    return attribute;
}
std::string Attributes_values::get_value()const
{
    return value;
}

std::ostream& operator<<(std::ostream& os, Attributes_values& other)
 {
     os<<" "<<other.get_attribute()<<"="<<'"'<<other.get_value()<<'"';
     return os;
 }

 void Attributes_values::set_value(std::string _value)
 {
     value=_value;
 }
 void Attributes_values::set_attribute(std::string _attribute)
 {
     attribute=_attribute;
 }
