#include <iostream> //ANLOLOGY like ATM 
#include <string>
using namespace std;
class Server {  // Abstract server interface
public:
    virtual void process_request(const string& request) = 0;
};
class RealServer : public Server { // Real Server (RealSubject)
public:
    void process_request(const string& request) override {
        cout << "Real Server processing request: " << request << endl;
    }
};
class ProxyServer : public Server { // Proxy Server (Proxy)
private:
    RealServer realServer; // The actual server
public: //// Add proxy-specific functionality
    void process_request(const string& request) override {
        cout << "Proxy Server: Validating request...\n";
        cout << "Proxy Server: Forwarding request to Real Server...\n";
        realServer.process_request(request);
    }
};
int main() {// Client
    ProxyServer proxy;
    proxy.process_request("Retrieve Backup Data");
    return 0;
}