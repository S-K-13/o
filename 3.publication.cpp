#include<iostream>
#include<string>
#include<exception>
using namespace std;

class publication
{
    string title;
    float price;
public:
    publication()
    {
        title="";
        price=0.0;
    }
    
    void getdata()
    {
        try
        {
         cout<<"Enter the title:";
         cin.ignore();
         getline(cin,title);
         cout<<"Enter the price:";
         cin>>price;
         if(cin.fail() || price<0)
         {
             throw "Invalid input!!";
         }
        }
        catch(const char *msg)
        {
            cout<<msg<<endl;
            title="";
            price=0.0;
        }
    }
    
    void displaydata()
    {
        cout<<"Title:"<<title<<endl;
        cout<<"Price:"<<price<<endl;
    }
        
};

class book : public publication
{
    int pagecount;
public:
    book()
    {
        pagecount=0;
    }
    
    void getdata()
    {
        try
        {
            publication::getdata();
            cout<<"Enter the pagecount:";
            cin>>pagecount;
            if(cin.fail() || pagecount<0)
            {
                throw "Invalid input!!!";
            }
        }
        catch(const char *msg)
        {
            cout<<msg<<endl;
            pagecount=0;
        }
    }
    
    void displaydata()
    {
        publication::displaydata();
        cout<<"Pagecount:"<<pagecount<<endl;

    }
};

class tape : public publication
{
    float time;
public:
    tape()
    {
        time=0.0;
    }
    
    void getdata()
    {
        try
        {
            publication::getdata();
            cout<<"Enter play time:";
            cin>>time;
            if(cin.fail() || time<0)
            {
                throw "Invalid input!!!";
            }
        }
        catch(const char *msg)
        {
            cout<<msg<<endl;
            time=0.0;
        }
    }
    
    void displaydata()
    {
        publication::displaydata();
        cout<<"Play time:"<<time;
    }
};

int main()
{
    book b;
    tape t;
    cout<<"Enter the book details:"<<endl;
    b.getdata();
    cout<<"Enter the tape details:"<<endl;
    t.getdata();
    cout<<"display book details:"<<endl;
    b.displaydata();
    cout<<"display book details:"<<endl;
    t.displaydata();
    return 0;
}
