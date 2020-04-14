#ifndef FCIVECTOR_H
#define FCIVECTOR_H
#include "Course.h"
#include<iostream>
#include "Student.h"
using namespace std;

template<typename T>

class FciVector
{
    private:
        T* elements;
        int capacity;
        int numOfElements;

    public:
        void Resize(int n){ ///resizing FCIVECTOR
            if(n>capacity){
                capacity=n;
                T* tmp=new T[capacity];
                for(int i=0;i<numOfElements;i++)
                    tmp[i]=elements[i];
                numOfElements=n;
                elements=new T[capacity];
                for(int i=0;i<capacity;i++)
                    elements[i]=tmp[i];
                   /// 5 1 1 1 1 1 1 1 1 1 1 1 1
            }
            else numOfElements=n;

        }
        FciVector(){ ///resizing FCIVECTOR
            capacity=0;
            numOfElements=0;
        }

        void PushBack(T &newElement){ ///add element in FCIVECTOR
            if(capacity==0)
                capacity++;
            else if(capacity==numOfElements)
                capacity*=2;

                T* tmp=new T[capacity];
                for(int i=0;i<numOfElements;i++)
                    tmp[i]=elements[i];
                elements=new T[capacity];
                for(int i=0;i<capacity;i++)
                    elements[i]=tmp[i];
                elements[numOfElements]=newElement;
                numOfElements++;

        }


        void PopBack(){ ///remove last element in FCIVECTOR

            if(numOfElements==0) throw -1;
            numOfElements--;

        }

        T& operator[](int index){ ///Operator in FCIVECTOR

            if(index<0 || index>=numOfElements) throw -1;

            return *(elements+index);

        }

        T* Begin(){ ///iterator to first element in FCIVECTOR

                if(numOfElements)
                    return elements;
                else throw -1;

        }
        T& Front(){ ///value of first element in FCIVECTOR

                if(numOfElements>0)
                    return *elements;
                else throw -1;


        }
        T& Back(){ ///value of last element in FCIVECTOR

                if(numOfElements>0)
                    return *(elements+numOfElements-1);
                else throw -1;

        }
        void Insert(T* position,T val){ ///insert element in certain position in FCIVECTOR

                int index=distance(elements,position);
                if(capacity==0)
                    capacity++;
                else if(capacity==numOfElements)
                    capacity*=2;

                T* tmp=new T[capacity];
                for(int i=0;i<numOfElements;i++)
                    tmp[i]=elements[i];
                elements=new T[capacity];
                for(int i=index;i<numOfElements;i++){
                    elements[i+1]=tmp[i];
                }
                elements[index]=val;
                for(int i=0;i<index;i++){
                    elements[i]=tmp[i];
                }
                numOfElements++;

        }

        void Erase(T* position){ ///erase element of certain position in FCIVECTOR

                int index=distance(elements,position);
                if(index<0 || index>=numOfElements){
                    throw -1;
                }
                for(int i=index+1;i<numOfElements;i++)
                    elements[i-1]=elements[i];
                numOfElements--;

        }

        int Size(){
            return numOfElements;
        }
        int Capacity(){
            return capacity;
        }
        bool Empty(){
            return (numOfElements==0);
        }
        void Clear(){
            numOfElements=0;
        }

    protected:

    private:
};
#endif // FCIVECTOR_H
