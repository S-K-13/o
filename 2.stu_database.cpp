#include<iostream>
#include<string>
using namespace std;

class stu_database
{
    string name;
    int rollno;
    string classname;
    char division;
    string DOB;
    string bloodgrp;
    string address;
    string telephone;
    string licenseNo;
public:
    static int studentcount;
    stu_database() //default constructor
    {
        this-> name ="";
        this-> rollno =0;
        this-> classname="";
        this-> division=' ';
        this-> DOB="";
        this-> bloodgrp="";
        this-> address="";
        this-> telephone="";
        this-> licenseNo="";
        studentcount++;
        
    }
    
     stu_database(string n,int roll,string cn,char divs,string dob,string bld,string addrs,string tele,string licns) //paramaterized constructor
    {
        this-> name =n;
        this-> rollno = roll;
        this-> classname=cn;
        this-> division=divs;
        this-> DOB=dob;
        this-> bloodgrp=bld;
        this-> address=addrs;
        this-> telephone=tele;
        this-> licenseNo=licns;
        studentcount++;
    }
    
    stu_database(const stu_database &s) //copy constructor
    {
        this-> name =s.name;
        this-> rollno =s.rollno;
        this-> classname=s.classname;
        this-> division=s.division;
        this-> DOB=s.DOB;
        this-> bloodgrp=s.bloodgrp;
        this-> address=s.address;
        this-> telephone=s.telephone;
        this-> licenseNo=s.licenseNo;
        studentcount++;
    }
        
    ~stu_database()
    {
        studentcount--;
    }
    
    void setvalue()
    {
        cout<<"Enter the name:";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the roll number:";
        cin>>rollno;
        cout<<"Enter the class name:";
        cin.ignore();
        getline(cin,classname);
        cout<<"Enter the division:";
        cin>>division;
        cout<<"Enter  the DOB:";
        cin.ignore();
        getline(cin,DOB);
        cout<<"Enter the bloodgroup:";
        cin.ignore();
        getline(cin,bloodgrp);
        cout<<"Enter the address:";
        cin.ignore();
        getline(cin,address);
        cout<<"Enter the telephone no:";
        cin.ignore();
        getline(cin,telephone);
        cout<<"Enter the driving license no:";
        cin.ignore();
        getline(cin,licenseNo);
    }
    
    void displayvalue()
    {
        cout<<"name:"<<this-> name ;
        cout<<"rollno:"<<this-> rollno ;
        cout<<"classname:"<<this-> classname;
        cout<<"division:"<<this-> division;
        cout<<"DOB(dd/mm/yyyy):"<<this-> DOB;
        cout<<"bloodgroup:"<<this-> bloodgrp;
        cout<<"address:"<<this-> address;
        cout<<"telephone:"<<this-> telephone;
        cout<<"license number:"<<this-> licenseNo;
    }
};
int stu_database::studentcount=0;
int main()
{
    int no;
    cout<<"Enter the no of students:";
    cin>>no;
    
    stu_database* students = new stu_database[no];
    for(int i=0;i<no;i++)
    {
        cout<<"Enter the student "<<(i+1)<<" details "<<endl;
        students[i].setvalue();
    }
    
    cout<<"Student details:"<<endl;
    for(int i=0;i<no;i++)
    {
        cout<<"student "<<(i+1)<<" details "<<endl;
        students[i].displayvalue();
    }
    
    delete[] students;
    return 0;
}
