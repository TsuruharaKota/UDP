#include"send_lib.h"
#include<cstring>
#include<string>
#include<cmath>

namespace ARRC{
    UDP* UDP::singleton_instance = nullptr;
    UDP* UDP::getInstance(){
        if(singleton_instance == nullptr){
            singleton_instance = new UDP;
        }
        return singleton_instance;
    }
    void UDP::Init(std::string address){
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(address.c_str());
        addr.sin_port = htons(12345);        
    }
    void UDP::set_bind(){
        bind(sock, (struct sockaddr *)&addr, sizeof(addr));
    }
    bool UDP::send(float send_data){
        std::string send_s = std::to_string(std::round(send_data * 10) / 10);
        sendto(sock, send_s.c_str(), send_s.size(), 0, (struct sockaddr *)&addr, sizeof(addr));
        return true;
    }
    float UDP::receive(){
        char buf[2048];
        memset(buf, 0, sizeof(buf));
        recv(sock, buf, sizeof(buf), 0);
        return std::round(std::stof(buf) * 10) / 10;
    }
}