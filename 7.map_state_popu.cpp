#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
int flag=1;
while(flag==1)
{
    map<string,int>state;
    
    state.insert(pair<string,int>("MAHARASHTRA",99999));
    state.insert(pair<string,int>("GOA",88888));
    state.insert(pair<string,int>("KERALA",77777));
    
    
    string userinput;
    cout<<"Enter the name of the state whose populationis to be found out:"<<endl;
    cin>>userinput;
    
    bool isPresent=false;
    
    for(auto i : state)
    {
        if(i.first==userinput)
        {
            isPresent=true;
            cout<<"the population of the state "<<i.first<<" is "<<i.second<<endl;
            break;
        }
    }
    if(!isPresent)
    {
        cout<<"State not found in database!!!"<<endl;
    }
    cout<<"press 1 to continue and 0 to stop:";
    cin>>flag;
}
    return 0;
}
