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


    void add_unit(XMLelement*);
    //XMLgroup& operator=();
     XMLgroup& operator/(const XMLgroup&);
    //XMLgroup& operator[]();
    //XMLgroup& operator@();
    friend std::ostream& operator<<(std::ostream&, XMLgroup&);

    std::string select(int, std::string);
    void set(int, std::string, std::string);
    std::string* children(int,int);
    XMLelement child(int ,int);
    std::string* text(int,int);
    void delete_att(int,std::string);
    XMLgroup newchild(int _id);
};

#endif // XMLGROUP_H_INCLUDED
