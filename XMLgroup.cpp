#include "XMLgroup.h"
#include <iomanip>

XMLelement* XMLgroup::alloc(int s)
{
    XMLelement* res = new XMLelement[s];
    if(!res)
      {
        throw("Can't allocate!");
      }
    return res;
}

XMLgroup::XMLgroup()
:title(""),group(nullptr), g_size(0){}

XMLgroup::XMLgroup(std::string _title, const XMLelement* _group, const int _g_size)
:g_size(_g_size)
{
    title=_title;
    group=alloc(_g_size);
    for(int i=0; i<_g_size;++i)
        group[i]=_group[i];
}

XMLgroup::XMLgroup(const XMLgroup& other)
{
    title=other.title;
    g_size=other.g_size;

    group=alloc(other.g_size);
    for(int i=0; i<g_size;++i)
        group[i]=other.group[i];
}

XMLgroup::~XMLgroup()
{
    delete[] group;
    group=nullptr;
}

std::ostream& operator<<(std::ostream& os, XMLgroup& other)
{

    os<<'<'<<other.title<<">\n";


          for(int i=0; i<other.g_size; ++i)
            {
             // os << std::setw(depth) << " ";
              os<<other.group[i];

            }

    os<<"</"<<other.title<<">\n";
    return os;
}


std::string XMLgroup::select(int _id, std::string a)
{
    std::string res;
    for(int i=0; i<g_size; ++i)
    {
        if(_id==group[i].get_id())
        {
            int cur=group[i].get_a_size();
            for(int k=1; k<=cur; ++k)
               {
                   if(group[i].get_att(k).get_attribute()==a)                    ////////////
                    {
                       res=group[i].get_att(k).get_value();
                       break;
                    }
               }
               break;
        }
    }
    return res;
}

 void XMLgroup::set(int _id, std::string key, std::string res)
 {
     for(int i=0;i<g_size;++i)
     {
         if(group[i].get_id()==_id)
         {
             for(int k=1;k<=group[i].get_a_size();++k)
             {
                 if(group[i].get_att(k).get_attribute()==key)
                 {
                    group[i].get_att(k).set_value(res);
                    break;
                 }
             }
             break;
         }
     }
 }

 std::string* XMLgroup::children(int _id, int cnt)
 {
     for(int i=0;i<g_size;++i)
      {
         if(group[i].get_id()==_id)
          {
              cnt=group[i].get_a_size();
              break;
          }
      }

      std::string* id_atts= new std::string[cnt];
      if(!id_atts)
      {
          throw("Cannot allocate memory!");
      }
      for(int i=0;i<g_size;++i)
      {
         if(group[i].get_id()==_id)
          {
              for(int k=1;k<group[i].get_a_size();++k)
              {
                  id_atts[k-1]=group[i].get_att(k).get_attribute();
              }
              break;
          }
      }

      return id_atts;         /////DELETE MEMORY IN MAIN
 }

 XMLelement XMLgroup::child(int _id ,int n)
 {
     return group[n];
 }

 std::string* XMLgroup::text(int _id,int cnt)
 {

     for(int i=0;i<g_size;++i)
      {
         if(group[i].get_id()==_id)
          {
              cnt=group[i].get_e_size();
              break;
          }
      }

      std::string* id_text= new std::string[cnt];
      if(!id_text)
      {
          throw("Cannot allocate memory!");
      }
      for(int i=0;i<g_size;++i)
      {
         if(group[i].get_id()==_id)
          {
              for(int k=1;k<group[i].get_e_size();++k)
              {
                  id_text[k]=group[i].get_el(k).get_text();
              }
              break;
          }
      }

      return id_text;         /////DELETE MEMORY IN MAIN
 }
 void XMLgroup::delete_att(int _id,std::string key)
 {
     for(int i=0; i<g_size; ++i)
      {
        if(_id==group[i].get_id())
          {
            int cur=group[i].get_a_size();
             for(int k=1; k<=cur; ++k)
                {
                   if(group[i].get_att(k).get_attribute()==key)
                    {
                        group[i].get_att(k).get_attribute()="";
                        break;
                    }
                }
                break;
          }
      }
 }


/*
XMLgroup& XMLgroup::operator/(const XMLgroup& other)
{
    for(int i=0; i<other.g_size; ++i)
    {

    }
}
*/
