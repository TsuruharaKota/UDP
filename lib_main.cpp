#include"send_lib.h"
#include<iostream>
int main(){
    ARRC::UDP *myUDP = ARRC::UDP::getInstance();
    myUDP->Init("172.16.93.156"); 
    float send_data{};
    float receive_data{};
    while(1){
        if(send_data > 1000.0f)send_data = 0.0f;
        send_data += 0.1f;
        myUDP->send(send_data);
        std::cout << send_data << std::endl;
    }
}