#include <iostream>
#include <vector>
using namespace std;

//composite design p

class Door {
public:
	virtual void open(){}
	virtual void close(){};
};
class IDoorStateNotifier
{

    public:
    virtual void notify(string status)=0;
};


class SecuredDoor:public Door
{
    IDoorStateNotifier *notifier;
    public:
    SecuredDoor(IDoorStateNotifier *cnotifier):notifier{cnotifier}{};
	virtual void open()override{
     
     this->notifier->notify("open");

    }
	virtual void close()override{ this->notifier->notify("close");};
};
class CompositeNotifier:public IDoorStateNotifier
{
vector<IDoorStateNotifier*> notifiers;
public:
void add(IDoorStateNotifier *notifier)
{
    notifiers.push_back(notifier);
}
void notify(string status)
{
    for(auto notifier:notifiers)
    {
        notifier->notify(status);
    }
}

};
class Buzzer:public IDoorStateNotifier{

public:
	void makeNoise(){}
    void notify(string status)
    {
        cout <<"Buzzer Notified!Door status is ->"<<status<<endl;
        this->makeNoise();
    }
};

class  SMSManager:public IDoorStateNotifier{

	public :void sendNotificationMessage() {

	 }
    void notify(string status)
    {
         cout <<"SmsManager is Notified!Door status is ->"<<status<<endl;
        this->sendNotificationMessage();
    }
};

class VisualizationManager {
	public:void turnVideoOn() {}
	public:void turnVideoOff() {}
           void notify(string status)
    {
        
         cout <<"VisualizationMangaer is Notified!Door status is ->"<<status<<endl;
        this->turnVideoOn();
    }
};


int main()
{
Door *door=new Door();
Buzzer bz;
SecuredDoor sd1(&bz);
SMSManager bz2;
SecuredDoor sd2(&bz2);
CompositeNotifier cmnotifier;
cmnotifier.add(&bz2);
cmnotifier.add(&bz);
SecuredDoor sd3(&cmnotifier);
sd3.open();
sd3.close();

//sd1.open();
//sd1.close();



}