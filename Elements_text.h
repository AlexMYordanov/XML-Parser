#ifndef ELEMENTS_TEXT_H_INCLUDED
#define ELEMENTS_TEXT_H_INCLUDED

#include <iostream>
#include <string>
class Elements_text
{
private:
    std::string element;
    std::string text;
public:
    Elements_text();
    Elements_text(std::string,std::string);
    Elements_text(const Elements_text&);
    std::string get_element()const;
    std::string get_text()const;
    friend std::ostream& operator<<(std::ostream&, Elements_text&);
};

#endif // ELEMENTS_TEXT_H_INCLUDED
