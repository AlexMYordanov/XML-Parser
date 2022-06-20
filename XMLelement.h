#ifndef XMLELEMENT_H_INCLUDED
#define XMLELEMENT_H_INCLUDED

#include <iostream>
#include <string>
#include "Attributes_values.h"
#include "Elements_text.h"

class XMLelement
{
private:
    int id;
    static int next_id;

    Attributes_values* attributes=nullptr;
    int at_size;

    Elements_text* elements=nullptr;
    int el_size;

    void alloc(int , int);
    void cpy(const XMLelement&);

public:
    static int depth;
    XMLelement();
    XMLelement( Attributes_values*,int,Elements_text*,int);
    XMLelement(const XMLelement& );
    XMLelement& operator=(const XMLelement&);

	int get_id() const;
	int get_a_size() const;
	int get_e_size() const;
	Attributes_values& get_att(int);
	Elements_text& get_el(int);
	Elements_text* get_elements()const;
	friend std::ostream& operator<<(std::ostream& , XMLelement&);
	void print();
    ~XMLelement();
};

#endif // XMLELEMENT_H_INCLUDED
