#include "XMLgroup.h"
#include <iomanip>

XMLelement* XMLgroup::alloc(int s)
{
    XMLelement* res = new XMLelement[s];
    if(!res)
      {
        std::cout<<"Can't allocate!";
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
              os<<other.group[i];
            }

    os<<"</"<<other.title<<">\n";
    return os;
}


std::string XMLgroup::select(unsigned _id, std::string a)
{
    std::string res;
    for(int i=0; i<g_size; ++i)
    {
        if(_id==(unsigned)(group[i].get_id()))
        {
            int cur=group[i].get_a_size();
            for(int k=1; k<=cur; ++k)
               {
                   if(group[i].get_att(k).get_attribute()==a)
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

 void XMLgroup::set(unsigned _id, std::string key, std::string res)
 {
     for(int i=0;i<g_size;++i)
     {
         if((unsigned)(group[i].get_id())==_id)
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

 std::string* XMLgroup::children(unsigned _id, int& cnt)
 {
     for(int i=0;i<g_size;++i)
      {
         if((unsigned)(group[i].get_id())==_id)
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
      int index=0;
      for(int i=0;i<g_size;++i)
      {
         if((unsigned)(group[i].get_id())==_id)
          {
              for(int k=1;k<=group[i].get_a_size();++k)
              {
                  id_atts[index++]=group[i].get_att(k).get_attribute();
              }
              break;
          }
      }

      return id_atts;         /////DELETE MEMORY IN MAIN
 }

 std::string XMLgroup::child(unsigned _id ,unsigned n)
 {
     bool flag=false;
     std::string res;
     for(int i=0;i<g_size;++i)
      {
         if((unsigned)(group[i].get_id())==_id)
          {
              if((unsigned)(group[i].get_a_size()+1)>=n)
                {
                   if(n==1)
                     res="id";
                   else
                   res=group[i].get_att(n-1).get_attribute();
                }
              else
                std::cout<<"No such child exists!\n";
            flag=true;
             break;
          }
      }
      if(flag==false)
         std::cout<<"No element with such id!\n";
      return res;
 }




 std::string* XMLgroup::text(unsigned _id,int& cnt)
 {

     for(int i=0;i<g_size;++i)
      {
         if((unsigned)(group[i].get_id())==_id)
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
      int index=0;
      for(int i=0;i<g_size;++i)
      {
         if((unsigned)(group[i].get_id())==_id)
          {
              for(int k=1;k<=group[i].get_e_size();++k)
              {
                  id_text[index++]=group[i].get_el(k).get_text();
              }
              break;
          }
      }

      return id_text;         /////DELETE MEMORY IN MAIN
 }
 void XMLgroup::delete_att(unsigned _id,std::string key)
 {
     for(int i=0; i<g_size; ++i)
      {
        if(_id==(unsigned)(group[i].get_id()))
          {
            int cur=group[i].get_a_size();
             for(int k=1; k<=cur; ++k)
                {
                   if(group[i].get_att(k).get_attribute()==key)
                    {
                        group[i].get_att(k).set_attribute("");
                        break;
                    }
                }
                break;
          }
      }
 }



void XMLgroup::operator/(std::string key) const
{
      for(int i=0;i<g_size;++i)
      {
         for(int k=1;k<=group[i].get_a_size();++k)
              {
                 std::string curr = group[i].get_el(k).get_text();
                 if(curr==key)
                  {
                      std::cout<<curr<<"\n";
                  }
              }
      }
}

void XMLgroup::operator[](std::string key) const
{
     for(int k=1;k<=group[0].get_a_size();++k)
              {
                  if(group[0].get_el(k).get_element()==key)
                  {
                      std::cout<<group[0].get_el(k).get_element();
                      break;
                  }
              }
}

void XMLgroup::operator%(std::string str)const
{
    for(int i=0;i<g_size;++i)
      {
         std::cout<<group[i].get_id()<<"\n";
      }
}

void XMLgroup::operator=(std::string _text)const
{
    for(int i=0;i<g_size;++i)
      {
          for(int k=1;i<=group[i].get_e_size();++k)
              {
                  std::string curr = group[i].get_el(k).get_text();
                  if(curr==_text)
                    std::cout<<curr<<"\n";
              }
      }
}

void XMLgroup::print()const
{
    int depth=12;
    int new_depth=depth-6;
    std::cout<<'<'<<title<<">\n";
          for(int i=0; i<g_size; ++i)
               {

                    std::cout << std::setw(new_depth);
                    std::cout<<"<"<<group[i].get_el(1).get_element()<<" "<<"id="<<'"'<<group[i].get_id()<<'"';
                    int a=group[i].get_a_size();

                    for(int k=1;k<=a;++k)
                        std::cout<<group[i].get_att(k);
                    std::cout<<'>'<<std::endl;
                    int e=group[i].get_e_size();
                    for(int l=2;l<=e;++l)
                       {
                           std::cout << std::setw(depth);
                           std::cout<<group[i].get_el(l);
                       }
                    std::cout << std::setw(new_depth+1);
                    std::cout<<"</"<<group[i].get_el(1).get_element()<<'>'<<'\n';
              }
    std::cout<<"</"<<title<<">\n";
}
