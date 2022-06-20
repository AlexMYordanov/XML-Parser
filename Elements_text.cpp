#include "Elements_text.h"

Elements_text::Elements_text()
:element(""), text(""){}

Elements_text::Elements_text(std::string _element, std::string _text)
:element(_element), text(_text){}

std::string Elements_text::get_element()const
{
    return element;
}
std::string Elements_text::get_text()const
{
    return text;
}

std::ostream& operator<<(std::ostream& os, Elements_text& other)
 {
     os<<"<"<<other.get_element()<<">"<<other.get_text()<<
                                  "</"<<other.get_element()<<">\n";
     return os;
 }
