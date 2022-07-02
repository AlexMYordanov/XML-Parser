#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

#include <iostream>
#include <fstream>
#include "XMLelement.h"
#include "XMLgroup.h"
#include "Attributes_values.h"
#include "Elements_text.h"


class Source
{
private:
    void prtHelp()const;
    void prtOptions()const;
public:
    int print_main()const;
};



void Source::prtHelp()const
{
    std::cout<<"open <file>  -  opens <file>\n"
             <<"close  -   closes currently opened file\n"
             <<"save  -  saves the current open file\n"
             <<"saveas <file>  -  saves the current open file in <file>\n"
             <<"help  -  prints information about all the cpmmands\n"
             <<"exit  -  exists the program\n";
}

void Source::prtOptions()const
{
    std::cout<<"The following commands are supported:\n";
    std::cout<<"1. Help.\n";
    std::cout<<"2. Open.\n";
    std::cout<<"3. Close.\n";
    std::cout<<"4. Save.\n";
    std::cout<<"5. Save as.\n";
    std::cout<<"6. Select - printing the value of attribute.\n";
    std::cout<<"7. Set the value of an attribute.\n";
    std::cout<<"8. Children.\n";
    std::cout<<"9. Child.\n";
    std::cout<<"10. Text of element.\n";
    std::cout<<"11. Delete an attribute.\n";
    std::cout<<"12. Print menu.\n";
    std::cout<<"13. Print XML.\n";
    std::cout<<"14. Exit.\n";

}


int Source::print_main()const
{

    Attributes_values atr("sex","male");
    Attributes_values atr2("height","184sm");
    Attributes_values a[2]= {atr,atr2};


    Elements_text el("person","");
    Elements_text el2("name","Dimitar");
    Elements_text el3("surname","Dimitrov");
    Elements_text e[3]= {el,el2,el3};

    XMLelement A(a,2,e,3);

    Attributes_values b1("hobby","studying");
    Attributes_values b2("weight","135kg");
    Attributes_values b[2]= {b1,b2};


    Elements_text eb("person","");
    Elements_text eb2("name","Ivan");
    Elements_text eb3("surname","Ivanov");
    Elements_text bb[3]= {eb,eb2,eb3};

    XMLelement B(b,2,bb,3);


    XMLelement AB[2]= {A,B};
    std::string str="people";
    XMLgroup G(str,AB,2);



    std::cout<<"The following commands are supported:\n";
    std::cout<<"1. Help.\n";
    std::cout<<"2. Open.\n";
    std::cout<<"3. Close.\n";
    std::cout<<"4. Save.\n";
    std::cout<<"5. Save as.\n";
    std::cout<<"6. Select - printing the value of attribute.\n";
    std::cout<<"7. Set the value of an attribute.\n";
    std::cout<<"8. Children.\n";
    std::cout<<"9. Child.\n";
    std::cout<<"10. Text of element.\n";
    std::cout<<"11. Delete an attribute.\n";
    std::cout<<"12. Print menu.\n";
    std::cout<<"13. Print XML.\n";
    std::cout<<"14. Exit.\n";


    unsigned short choice;
    unsigned id,n;
    int cnt=0;
    std::string input;
    std::string res;

    std::string filename="XML.xml";
    std::ofstream file(filename);

    do
    {
        do
        {
            std::cout<<"\nEnter a command:";
            std::cin>>choice;
        }
        while(choice<1 || choice>14 || !std::cin);


        switch(choice)
        {
        case 1:
        {
            std::cout<<"> help\n\n";
            prtHelp();
        }
        break;

        case 2:
        {
            std::cout<<"> open "<<filename<<'\n';
            if(file.is_open() ==  false)
            {
                std::cout<<"Could not open file!\n";
                return -1;
            }
            std::cout<<"Successfully opened "<<filename<<'\n';
        }
        break;

        case 3:
        {
            std::cout<<"> close\n";
            if(file.is_open() ==  true)
            {
                file.close();
                std::cout<<"Successfully closed!\n";
            }
            else
                std::cout<<"No file is opened!\n";
        }
        break;

        case 4:
        {
            std::cout<<"Command currently not working! :(";
        }
        break;

        case 5:
        {
            std::cout<<"Command currently not working! :(";
        }
        break;

        case 6:
        {
            std::cout<<"This command requires 2 arguments (an id and an attribute):\n";
            std::cout<<"select ";
            std::cin>>id>>input;
            res=G.select(id,input);
            if(res=="id")
                std::cout<<"No such id exists!\n";
            else if(res=="str")
                std::cout<<"No such attribute exists!\n";
            else
            {
                std::cout<<"In element with id="<<id
                         <<" the value of the attribute "
                         <<input<<" is "<<'"'
                         <<G.select(id,input)<<'"'<<"!\n";
            }
        }
        break;

        case 7:
        {
            std::cout<<"This command requires 3 arguments (an id, an attribute and a value):\n";
            std::cout<<"set ";
            std::cin>>id>>input>>res;
            G.set(id,input,res);

        }
        break;

        case 8:
        {
            std::cout<<"This command requires 1 argument (an id):\n";
            std::cout<<"children ";
            std::cin>>id;
            std::string* sp= G.children(id,cnt);
            if(!sp)
                std::cout<<"No such id exists!";
            else
            {
                std::cout<<"The children/child are/is:\n";
                for(int i=0; i<cnt; ++i)
                    std::cout<<sp[i]<<'\n';
                delete[] sp;
            }
        }
        break;

        case 9:
        {
            std::cout<<"This command requires 2 arguments (an id and a number):\n";
            std::cout<<"child ";
            std::cin>>id>>n;
            if(!std::cin)
                std::cout<<"Invalid input!\n";
            else
            {
                res=G.child(id,n);
                std::cout<<res;
            }
        }
        break;

        case 10:
        {
            std::cout<<"This command requires 1 argument (an id):\n";
            std::cout<<"text ";
            std::cin>>id;
            std::string* tp= G.text(id,cnt);
            if(!tp)
                std::cout<<"No such id exists!";
            else
            {
                std::cout<<"The text elements are:";
                for(int i=0; i<cnt; ++i)
                    std::cout<<tp[i]<<'\n';
                delete[] tp;
            }
        }
        break;

        case 11:
        {
            std::cout<<"This command requires 2 arguments (an id and an attribute):\n";
            std::cout<<"delete ";
            std::cin>>id>>input;
            G.delete_att(id,input);
        }
        break;

        case 12:
        {
            prtOptions();
        }
        break;
        case 13:
        {
            std::cout<<"print \n\n";
            G.print();
        }
        break;
        }

    }
    while(choice!=14);
    
    file<<G;

    return 0;
}



#endif // SOURCE_H_INCLUDED
