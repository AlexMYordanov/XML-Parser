#include <iostream>
#include <fstream>
#include "XMLelement.h"
#include "XMLgroup.h"
#include "Attributes_values.h"
#include "Elements_text.h"

int main()
{
    Attributes_values atr("sex","female");
    Attributes_values atr2("height","184");
    Attributes_values a[2]={atr,atr2};


    Elements_text el("person","");
    Elements_text el2("name","a");
    Elements_text el3("surname","m");
    Elements_text e[3]={el,el2,el3};

    XMLelement A(a,2,e,3);

    Attributes_values b1("auau","fe");
    Attributes_values b2("ht","4");
    Attributes_values b[2]={b1,b2};


    Elements_text eb("peal","");
    Elements_text eb2("ner","wera");
    Elements_text eb3("se","mewqer");
    Elements_text bb[3]={eb,eb2,eb3};

    XMLelement B(b,2,bb,3);

    //B=A;
    XMLelement AB[2]={A,B};
    std::string str="people";
    XMLgroup G(str,AB,2);


   // std::ofstream file("XML", std::ios::app);
    std::ofstream file("XML.txt");
    if (file.is_open() == false)
    {
        std::cout<< "Could not open file to write\n";
        return -1;
    }
    // G.set(4,"ht","AAAAAAAA");  //fail
   // file<<G.select(3,"sex");    //works
   /*
   int cnt=0;
     std::string* sp= G.children(3,cnt);
     for(int i=0;i<cnt;++i)
        file<<sp[i]<<' ';
    delete[] sp;
    */
    /*
    int cnt2=0;
     std::string* tp= G.text(3,cnt2);
     for(int i=0;i<cnt2;++i)
        file<<tp[i]<<' ';
    delete[] tp;
    */
    /*
    G.delete_att(3,"sex");
    file<<G;
    */

    file.close();

    return 0;
}
