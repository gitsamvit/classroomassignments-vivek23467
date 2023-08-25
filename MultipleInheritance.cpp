#include <iostream>
using namespace std;

class Device{};
class Iprinter
{
    public:
    virtual void print() const=0;

};
class IScanner
{
public:
virtual void scan()const = 0;


};
class Printer:public virtual Device,public Iprinter{
    public:
    void print() const
    {}
};
class Scanner:virtual public Device,public IScanner{

public:
void scan () const
{

cout <<"I am scanned";

}

};
class PrintScanner:public Iprinter,public IScanner{
Printer pObj;
Scanner sObj;
public:
void print()const
{
    pObj.print();
}

void scan()const
{
    sObj.scan();
}



};
void printJob(const Iprinter &pref){pref.print();}
void scanJob(const IScanner & scannerref){scannerref.scan();}


int main()
{

    Printer pObj;
    Scanner sObj;
    PrintScanner psObj;
    printJob(psObj);
    scanJob(psObj);
    
}