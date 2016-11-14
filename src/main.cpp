//
//  main.cpp
//  Inna1
//
//  Created by Inna Korzhovska on 11/8/16.
//  Copyright © 2016 Inna Korzhovska. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <array>
#include <cstdlib>
using namespace std;
const int n=1000;
double x[n][n];
int id1, id2;



int main()
{
    
    string ch;
    int  count=0;
 
//array is all 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            x[i][j]=0;
        }
    }

// open working file "batch_payment.txt" and extract ID1 and ID2
    cout<<"The past transactions are between: "<<'\n';
    ifstream  workfile;
    workfile.open("paymo_input/batch_payment.txt") ;
    if (workfile.fail()) {
        cerr<<"are you sure you did it right?"<<endl;
    }
    
    if(workfile.is_open())
    {
        char ch, comma;
        while (workfile.get(ch))
        {
            if (ch==',')
            {
                workfile>>id1>>comma>>id2;
                cout<<id1<<" and "<<id2<<'\n';
                count ++;
                x[id1][id2]=1;
                x[id2][id1]=1;
                workfile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
//just counting number of transactions
    cout<<"number of transactions= "<<count<<'\n';
    
//output the array of transaction as a table of 0 and 1
    cout<<"transaction original matrix is: "<<'\n';
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << x[i][j]<<" ";
        }
        cout<<endl;
    }

    //buiding the second order connection
    for (int j=1; j<n; ++j )
    {
        for (int i=2; (i<n); ++i)
        {
            if (i>j)
            {if (x[i][j]==1)
            {
                for (int t=1; t<n; ++t)
                {
                    if (t!=j)
                        if(x[t][i]==1)
                        {
                            if (x[t][j]!=1)
                              {
                                x[t][j]=2;
                                x[j][t]=2;
                                            for (int r=1; r<n; ++r)
                                            {
                                                if (x[r][t]==1)
                                                {
                                                    if ((x[r][j]!=1)&&x[r][j]!=2)
                                                    {
                                                    x[r][j]=3;
                                                    x[j][r]=3;//symmetrizing matrix
                                                        for (int w=1; w<n; ++w)
                                                        {
                                                           if (x[w][r]==1)
                                                           {
                                                               if ((x[w][j]!=1)||(x[w][j]!=2)||(x[w][j]!=3))
                                                               {
                                                                   x[w][j]=4;
                                                                   x[j][w]=4;
                                                               }
                                                           }
                                                        }
                                                            
                                                    }
                                                                
                                                }
                                            }
                              }
                        }
                }
            }
                
            }
        }
    }
    
    
    cout<< "after:"<<endl;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << x[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    
//open the stream.txt and extract ID1 and ID2: if x[id1][id2]=0 -> there was a transaction before and we write this into resultfile 1.
    ifstream  taskfile;
    taskfile.open("paymo_input/stream_payment.txt");
    ofstream allowed1, allowed2, allowed3;
    allowed1.open("paymo_output/output1.txt");
    allowed2.open("paymo_output/output2.txt");
    allowed3.open("paymo_output/output3.txt");
    
    if (taskfile.fail())
      {
        cerr<<"are you sure you did it right?"<<endl;
      }
      cout<<"the attempted transactions are between the following: "<<'\n';
      if(taskfile.is_open())
      {
        char ch, comma;
        while (taskfile.get(ch))
        {
            if (ch==',')
            {
                //extract id1 and id2 here and compare with the  matrix element of past transaction x[id1][id2]
                taskfile>>id1>>comma>>id2;
                cout<<id1<<" "<<id2<<'\n';
                
                
                    //getting the order of connection between the attempting customers
                    if (x[id1][id2]==1)
                    {
                    // if there was a transaction then write to result1.txt file "yes", otherwise "no"
                      cout <<"the transaction between customer "<<id1<<" and customer "<<id2<<" allowed as 1st order"<<'\n';
                      allowed1<<id1<<" and "<<id2<<" yes"<<endl;
                      allowed2<<id1<<" and "<<id2<<" yes"<<endl;
                      allowed3<<id1<<" and "<<id2<<" yes"<<endl;
                    }
                    else
                    {   allowed1<<id1<<" and "<<id2<<" no"<<endl;
                      // if there is second order connection then write to result2.txt file "yes", otherwise "no"
                       if (x[id1][id2]==2)
                        {
                          cout <<"the transaction between customer "<<id1<<" and customer "<<id2<<" allowed as up to 2nd order"<<'\n';
                          allowed2<<id1<<" and "<<id2<<" yes"<<endl;
                          allowed3<<id1<<" and "<<id2<<" yes"<<endl;
                        }
                        else
                         {  allowed2<<id1<<" and "<<id2<<" no"<<endl;
                          if ((x[id1][id2]==3)||(x[id1][id2]==4))
                           {
                           // if there is a connection up to 4rd order then write to result3.txt file "yes", otherwise "no"
                            cout <<"the transaction between customer "<<id1<<" and customer "<<id2<<" allowed as up to 4th order"<<'\n';
                            allowed3<<id1<<" and "<<id2<<" yes"<<endl;
                           }
                           else
                               allowed3<<id1<<" and "<<id2<<" no"<<endl;
                         }
                  }
                


                taskfile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
      }
    
    
    
    return 0;
}
