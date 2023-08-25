#include <iostream>
using namespace std;

class ImageGallery {
	string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg"};
public:
string  share(int index) {
string image1=images[index];
return image1;
}
};
class ICommunicationManager
{
public:
virtual void sendContent(string image)=0;

};
class BluetoothManager:public ICommunicationManager {
public:
	void searchDevices() {}
    void pairdevice(){}
	void sendContent(string image) {
 
 cout <<"you are sending image via bluetooth       "<<image;
    

    }
	void turnOn() {}
	void turnOff(){}

};

class WhatsUpManager:public ICommunicationManager {
    public:
	void sendContent(string image) {

         cout <<"you are sending image via whatsapp      "<<image;
    }
	void joinGroup() {}
	void addMember(){}
	void createGroup() {}


};

class MailManager:public ICommunicationManager {

    public:
	void pullNewMails() {}
	void sendContent(string image) {
         cout <<"you are sending image via Mail    "<<image;
    }
	void composeEmail(){}
	void addAttachement() {}

};
ICommunicationManager* choose( int x)
{
    ICommunicationManager *tr;
switch(x)
{
case 0:
    
    tr=new MailManager();
    return tr;
    break;
case 1:
    tr=new BluetoothManager();
     return tr;
    break;
case 2:
    tr=new  WhatsUpManager();
     return tr;
    break;
default:
 break;
}
return tr;
}



int main() {
	
	ImageGallery* imageMgmt = new  ImageGallery();
	string image=imageMgmt->share(0);
    ICommunicationManager *myobj=choose(1);
    myobj->sendContent(image);
    

    

    
	
}