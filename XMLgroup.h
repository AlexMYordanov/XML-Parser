#ifndef XMLGROUP_H_INCLUDED
#define XMLGROUP_H_INCLUDED
#include "XMLelement.h"

class XMLgroup
{
private:
    std::string title;
    XMLelement* group=nullptr;
    int g_size;

    XMLelement* alloc(int);
public:
    XMLgroup();
    XMLgroup(std::string,const XMLelement*, const int);
    XMLgroup(const XMLgroup&);
    ~XMLgroup();

    void operator=(std::string)const;
    void operator/(std::string)const;
    void operator[](std::string)const;
    void operator%(std::string)const;
    friend std::ostream& operator<<(std::ostream&, XMLgroup&);

    std::string select(unsigned, std::string);
    void set(unsigned, std::string, std::string);
    std::string* children(unsigned,int&);
    std::string child(unsigned , unsigned);
    std::string* text(unsigned,int&);
    void delete_att(unsigned,std::string);
    void print()const;
};

#endif // XMLGROUP_H_INCLUDED
