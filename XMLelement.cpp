#include "XMLelement.h"
#include <iomanip>

int XMLelement::next_id=0;
int XMLelement::depth=6;

void XMLelement::alloc(int attributeSize, int elementsSize)
{
  attributes = new Attributes_values[attributeSize];
  elements = new Elements_text[elementsSize];
  if(!attributes || !elements)
          {
              throw("Can't allocate!");
          }
}

void XMLelement::cpy(const XMLelement& other)
{
    if(attributes!=nullptr)
    {
        delete[] attributes;
    }
    if(elements!=nullptr)
    {
        delete[] elements;
    }

    at_size=other.at_size;
    el_size=other.el_size;

    alloc(at_size,el_size);
    for(int i=0; i<at_size;++i)
        {
            attributes[i]=other.attributes[i];
        }

    for(int i=0; i<el_size;++i)
        {
            elements[i]=other.elements[i];
        }
}

XMLelement::XMLelement()
: attributes(nullptr), at_size(0), elements(nullptr), el_size(0)
{
    id=++next_id;
}

XMLelement::XMLelement( Attributes_values* _attr, int _at_s, Elements_text* _elems, int _el_s)
:  at_size(_at_s), el_size(_el_s)
{
    id=++next_id;

    alloc(_at_s,_el_s);
    for(int i=0; i<_at_s;++i)
        {
            attributes[i]=_attr[i];
        }

     for(int i=0; i<_el_s;++i)
        {
            elements[i]=_elems[i];
        }
}
XMLelement::XMLelement(const XMLelement& other)
{
    cpy(other);
}
XMLelement& XMLelement::operator=(const XMLelement& other)
{
    if(this!=&other)
    {
        cpy(other);
    }
    return *this;
}

int XMLelement::get_id() const
{
    return id;
}

int XMLelement::get_a_size() const
{
    return at_size;
}
int XMLelement::get_e_size() const
{
    return el_size;
}

Attributes_values& XMLelement::get_att(int index)
{
    return attributes[index-1];
}
Elements_text& XMLelement::get_el(int index)
{
    return elements[index-1];
}

Elements_text* XMLelement::get_elements()const
{
    return elements;
}

std::ostream& operator<<(std::ostream& os, XMLelement& unit)
{

    os<<"<"<<unit.get_el(1).get_element()<<" "<<"id="<<'"'<<unit.get_id()<<'"';
    int a=unit.get_a_size();

    for(int i=1;i<=a;++i)
      os<<unit.get_att(i);

     os<<">\n";
     int e=unit.get_e_size();
     for(int i=2;i<=e;++i)
       {
           os << std::setw(6) << " ";

           os<<unit.get_el(i);

       }
    os<<"</"<<unit.get_el(1).get_element()<<'>'<<'\n';
    return os;
}

void XMLelement::print()
{
    int new_depth=depth-6;
    std::cout << std::setw(new_depth);
    std::cout<<"<"<<get_el(1).get_element()<<" "<<"id="<<'"'<<get_id()<<'"';
    int a=get_a_size();

    for(int i=1;i<=a;++i)
        std::cout<<get_att(i);

     std::cout<<'>'<<std::endl;
     int e=get_e_size();
     for(int i=2;i<=e;++i)
       {
           std::cout << std::setw(depth);
           std::cout<<get_el(i);
       }
   std::cout << std::setw(new_depth);
   std::cout<<"</"<<get_el(1).get_element()<<'>'<<'\n';

}

XMLelement::~XMLelement()
 {
     delete[] attributes;
     attributes=nullptr;
     delete[] elements;
     elements=nullptr;
 }


