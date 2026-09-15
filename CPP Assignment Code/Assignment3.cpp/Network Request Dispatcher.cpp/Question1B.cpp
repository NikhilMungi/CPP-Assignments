#include <iostream>
#include <string>
#include <vector>
using namespace std;

using Header = pair<string, string>;
using HeaderList = vector<Header>;
using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers)
{
    cout << "Headers:" << endl;

    for (const auto& header : headers)
    {
        cout << " " << header.first
             << " : " << header.second << endl;
    }
}

int main()
{
    RequestId requestId = 1748293847;

    Port serverPort = 8080;

    IPAddress serverIP = "192.168.1.10";

    HeaderList headers;

    headers.push_back({"Content-Type", "application/json"});
    headers.push_back({"Authorization", "Bearer token123"});
    headers.push_back({"Accept-Language", "en-US"});

    cout << "Request ID : "
         << requestId << endl;

    cout << "Server Port : "
         << serverPort << endl;

    cout << "Server IP : "
         << serverIP << endl;

    printHeaders(headers);

    return 0;
}