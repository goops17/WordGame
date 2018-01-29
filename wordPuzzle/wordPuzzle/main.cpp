#include <iostream>
#include "wordPuzzle.h"
#include<fstream>
#include <string.h>
using namespace std;
#define UNASSIGNED 0
#define N 4
int getType();
void createFile();
int main()
{
    //cout<<"Puzzle: "<<endl;
    bool exit=false;
    int optType;
    int x;
    int y;
    int value;
    //createFile();
    //optType=getType();
    //cout<<optType;
    int content[5]={NULL,2,3,4,5};
    int content2[5]={0,2,4,6,8};
    puzzle p1(content);
    p1.menu();
    
    while(!exit)
    {
        cout<<"\nPlease enter x co-ordinate: ";
        cin>>x;
        cout<<"\nPlease enter y co-ordinate: ";
        cin>>y;
        cout<<"\nPlease enter value: ";
        cin>>value;
        if(!p1.getContent(x, y, value))
        {
            cout<<"\nYou used hint's space, please \nchoose other co-ordinates!\n";
        }
    }
    return 0;
}

int getType()
{
    int optType;
    cout<<"\n----Type----"<<endl;
    cout<<"1. WORDS"<<endl;
    cout<<"2. NUMBER"<<endl;
    do
    {
        cout<<"\nPlease select your option (1/2): "<<endl;
        cin>>optType;
        if(optType!=1 || optType !=2)
        {
            cout<<"Invalid choice!\n";
        }
    }while(optType>2);
    return optType;
}
void createFile()
{
    ofstream outf2;
    ofstream outf;
    ifstream inf;
    int a[20]={
        1234,4567,7891,1357,2435,
        9653,1362,2538,1938,3695,
        5163,7913,8426, 2458,9145,
        3456,4567,5678,6789,7891
    };
    string b[20]={
        "scar","isa","badl","ions","king",
        "zuck","hack","face","book","cuba",
        "elon","love","cars","mars","venu",
        "rifu","nelu","moti","gops","roti"
    };
    inf.open("string.dll");
    outf.open("a.out");
    outf.open("b.out");
    string n;
    if(!inf)
    {
        cout<<"file found";
    }
    
    while (inf >> n)
    {
        cout<<n<<endl;
    }
    for(int i=0; i<20; i++)
    {
        outf<<a[i]<<endl;
        outf2<<a[i]<<endl;
    }
    
    //inf.close();
    outf.close();
    outf2.close();
    cout<<"written successful!"<<endl;
}
template <class foo>
foo getContentFromFile(foo arr[5])
{
    foo n;
    ifstream inf;
    while (inf >> n)
    {
        cout<<n<<endl;
    }
}
