/*
Name: Moaz Basheer Anwar
ID:20180285
G-14
*/
#include <bits/stdc++.h>
#include"Student.h"
#include"FciVector.h"
using namespace std;
int GetChoice(int l,int r){
    int ch; cin>>ch;
    while(ch<l || ch>r){
        cin>>ch;
    }
    return ch;
}
int Menu(){ ///choose type of FCIVECTOR
    cout<<"Insert type of vector you would like to create: \n";
    cout<<"1. list of integer \n";
    cout<<"2. list of character \n";
    cout<<"3. list of string \n";
    cout<<"4. list of float \n";
    cout<<"5. list of students \n";
    cout<<"6. Exit\n";
    int choice=GetChoice(1,6);
    return choice;
}
template<typename T>
void ModifyVector(FciVector<T>& vec,int choice){ ///do operations on FCIVECTOR
    if(choice==1){
        cout<<"Please Enter an element\n";
        T element;
        cin>>element;
        vec.PushBack(element);
    }else if(choice==2){
        if(vec.Size()>0){
            vec.PopBack();
            cout<<"Removed successfully!\n";
        }else cout<<"Vector is empty\n";
    }else if(choice==3){
        cout<<"Enter Position\n1-based\n";
        int position ;
        cin>>position;
        cout<<"Enter value\n";
        T value ;
        cin>>value;
        if(position<=vec.Size()+1 && position>=1)
            vec.Insert(vec.Begin()+position-1,value);
        else cout<<"Invalid Operation\n";

    }else if(choice==4){
        cout<<"Enter Position\n1-based\n";
        int position ;
        cin>>position;
        if(position<=vec.Size() && position>=1)
            vec.Erase(vec.Begin()+position-1);
        else cout<<"Invalid Operation\n";
    }else if(choice==5){
        vec.Clear();
        cout<<"Cleared successfully!\n";
    }else if(choice==6){
        if(vec.Size())
            cout<<vec.Front()<<"\n";
        else cout<<"Not Valid Operation\n";
    }else if(choice==7){
        if(vec.Size())
            cout<<vec.Back()<<"\n";
        else cout<<"Not Valid Operation\n";
    }else if(choice==8){
        cout<<"Enter Position\n1-based\n";
        int position ;
        cin>>position;
        if(position<=vec.Size() && position>=1)
            cout<<vec[position-1]<<"\n";
        else cout<<"Invalid Operation\n";
    }else if(choice==9){
        cout<<"Size is ";
        cout<<vec.Size()<<"\n";
    }else if(choice==10){
        cout<<"Capacity is ";
        cout<<vec.Capacity()<<"\n";
    }else if(choice==11){
        if(vec.Empty()){
            cout<<"Vector is empty\n";
        }else cout<<"Vector is not empty\n";
    }
}

template<class T>
void Run(FciVector<T>& vec){  ///choose operation on FCIVECTOR
    while(true){
        cout<<"Do you want to continue???(Y/N)\n";
        char ch; cin>>ch;
        if(tolower(ch)=='n') break;
        cout<<"What kind of operation would you like to perform? \n"
            <<"1. Add element.\n"
            <<"2. Remove last element. \n"
            <<"3. Insert element at certain position. \n"
            <<"4. Erase element from a certain position. \n"
            <<"5. Clear. \n"
            <<"6. Display first element. \n"
            <<"7. Display last element. \n"
            <<"8. Display element at certain position. \n"
            <<"9. Display vector size. \n"
            <<"10. Display vector capacity. \n"
            <<"11. Is empty?\n"
            <<"Choice is :  ";
        int choice=GetChoice(1,11);
        ModifyVector(vec,choice);
    }
}
void ExecuteChoice(int choice){ ///use a certain type of FCIVECTOR
    if(choice==1){
        FciVector<int> vec;
        Run(vec);
    }else if(choice==2){
        FciVector<char> vec;
        Run(vec);
    }else if(choice==3){
        FciVector<string> vec;
        Run(vec);
    }else if(choice==4){
        FciVector<float> vec;
        Run(vec);
    }else if(choice==5){
        FciVector<Student> vec;
        Run(vec);
    }else if(choice==6){
        exit(0);
    }
}
int main()
{
    while(true){
        int choice=Menu();
        ExecuteChoice(choice);
    }
    return 0;
}
