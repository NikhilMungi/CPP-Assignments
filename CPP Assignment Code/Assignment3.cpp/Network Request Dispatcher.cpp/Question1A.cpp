#include <iostream>
#include <string>
using namespace std;

enum class HttpStatus
{
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint)
{
    cout << "[" << endpoint << "] -> ";

    switch (static_cast<int>(status))
    {
        case 200:
            cout << "200 OK : Request successful";
            break;

        case 201:
            cout << "201 Created : Resource created";
            break;

        case 400:
            cout << "400 Bad Request : Invalid request";
            break;

        case 401:
            cout << "401 Unauthorized : Authentication required";
            break;

        case 404:
            cout << "404 Not Found : Endpoint does not exist";
            break;

        case 500:
            cout << "500 Server Error : Internal server error";
            break;
    }

    cout << endl;
}

int main()
{
    handleResponse(HttpStatus::OK, "GET /api/users");

    handleResponse(HttpStatus::Unauthorized, "POST /api/login");

    handleResponse(HttpStatus::NotFound, "GET /api/products/99");

    handleResponse(HttpStatus::ServerError, "POST /api/order");

    return 0;
}