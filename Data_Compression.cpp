#include "Data_Compression.h"

#include "Vector.h"
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void Data_Compression::readingFile(){
    usi val1, val2, time;
    ifstream data("data.txt");
    if(!data)
    {
        cerr<<"file NOT found"<<endl;
        exit(1);
    }
    while(!data.eof())
    {
        data>>val1>>val2>>time;
        init(val1,val2,time);
    }
}

void Data_Compression::init(usi node1,usi node2,usi t)
{
    Vector<firstNode> n1;
    cout <<"okay"<<endl;
    cout<<n1.get_size()<<endl;
    for(int i = 0;i < n1.get_size();i++)
    {
        cout<<"hi"<<endl;
        if(n1[i].value != node1)
        {
            firstNode temp1;
            temp1.value = node1;
            n1.push(temp1);
        }
        for (int j = 0; i< n1[i].child_node.get_size(); i++){
            if (n1[i].child_node[j].value != node2){
                secondNode temp2;
                temp2.value = node2;
                n1[i].child_node.push(temp2);
            }
            for (int k = 0; k< n1[i].child_node[j].time.get_size(); k++)
            if (n1[i].child_node[j].time[k] != t){
                usi temp3;
                temp3 = t;
                n1[i].child_node[j].time.push(temp3);
                cout<<"h"<<endl;
            }

        }
    }
}
