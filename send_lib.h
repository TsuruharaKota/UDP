#ifndef send_lib_h
#define send_lib_h

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string>

namespace ARRC{
    class UDP{
        public:
            static UDP* getInstance();
            void Init(std::string address);
            ~UDP(){
                close(sock);
            }
            void set_bind();
            bool send(float send_data);
            float receive();
        protected:
            UDP() = default;
        private:
            static UDP *singleton_instance;
            int sock;
            sockaddr_in addr;
    };
};

#endif