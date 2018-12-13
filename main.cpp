// Course:  CS213 - Programming II  - 2018
// Title:   Assignment 4
// Program: CS213-2018-A4
// Author1: Mostafa Khaled - 20170288 - G8
// Author2: Ola Sameh - 20170165 - G8
// Author3: Radwa Ahmed - 20170104 - G8
#include <iostream>
#include <bits/stdc++.h>
#include <Sequence.h>
#include <DNA.h>
#include <RNA.h>
#include <Protein.h>
#include <CodonsTable.h>
#include <conio.h>
using namespace std;

int main()
{
    //CodonsTable table;
    //table.print();
    //cout << table.getAminoAcid(const_cast<char *>("AUA")).AminoAcid;

    int length;
    int choice;
    char* seq2 = new char [length];
    while (true)
    {
        cout<<"1)write DNA sequence to build the complemantary strand \n" "2)convert DNA to RNA \n"  "3)convert RNA to DNA \n" "4)convert RNA to Protein \n"  "5)check if a sequence equal to another one \n" "6)check if a sequence not equal to another one \n" "7 make sequence equal another sequence\n" "8)EXIT \n";
        cin>>choice;
        if (choice == 8)
        {
            cout<<"Bye:D"<<endl;
            return 0;
        }
        else if (choice == 1)
        {
            cout<<"Enter the length of the sequence: ";
            cin>>length;
            char* seq = new char [length];
            cout<<"write your sequence: ";
            try
            {
                for (int i = 0 ; i< length ; i++)
                {
                    cin>> seq[i];
                    if (seq[i]!= 'A' && seq[i]!= 'C' && seq[i]!='G' && seq[i]!='T')
                    {
                        throw 2;
                    }

                }
            }
            catch(...)
            {
                cout<<"invalid Sequence"<<endl<<"DNA sequence must contain A C G T letters only"<<endl;
                return 0;
            }
            DNA c(seq,promoter,length);
            c.BuildComplementaryStrand();
            c.Print();
        }
        else if (choice == 2)
        {
            DNA c;
            cin>>c;
            c.ConvertToRNA();
            c.Print();
        }

        else if (choice==3)
        {
            RNA c;
            cin>>c;
            c.ConvertToDNA();
            c.Print();
        }
        else if (choice == 4)
        {
            RNA p;
            p.ConvertToProtein();
            p.Print();
        }
        else if (choice == 7)
        {
            DNA ob1,ob2;
            cin>>ob1;
            cin>>ob2;
            ob1=ob2;
            cout<<ob1<<endl;
            cout<<ob2<<endl;

        }
        else if (choice == 5)
        {
            DNA ob1,ob2;
            cin>>ob1;
            cin>>ob2;
            cout<<(ob1==ob2)<<endl;
        }
        else if (choice == 6)
        {
            DNA ob1,ob2;
            cin>>ob1;
            cin>>ob2;
            cout<<(ob1!=ob2)<<endl;
        }

        else
        {
            cout << "Wrong choice, please re-choose a number"<<endl;
        }
        cout << "\nPress any key to continue... ";
        getch();
        system("cls");

    }
}

