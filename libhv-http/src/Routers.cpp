//#include "HTTPServer.hpp"

#include "Routers.hpp"

#include <thread>

#include <map>

#include <mutex>

using namespace std;



class Client {
    public:
        int id;
        string client;
        string data;


    // Client(int id_cl, string name, string info)
    // {
    //     id=id_cl;
    //     client = name;
    //     data = info;
    // }
};

int id=0;
std::map<int, Client> Clients;
mutex mtx;

void route::RegisterResources(hv::HttpService &router)
{
    router.POST("/user", [](HttpRequest *req, HttpResponse *resp)

    {
        nlohmann::json request;
        nlohmann::json response;

        unique_lock<mutex> lock(mtx);

        try
        {
            request = nlohmann::json::parse(req->body);

            if(request.contains("client")&&request.contains("data")){
                Client client;
                
                 client.id = id;
                 client.client =  request["client"].get<string>();
                 client.data = request["data"].get<string>();
                Clients[id++] = client;
            }
            else{
                throw exception();
            }

            //int id = users.size(); // присваиваем ID на основе размера map
            //users[id] = request; // Добавляем пользователя в map
            response["msg"] = "Client added successfully";
            //response["id"] = id;
        }

        catch(const std::exception& e)
        {
            response["error"] = "Invalid JSON";
            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;
            return 400;
        }
        resp->SetBody(response.dump());
        resp->content_type = APPLICATION_JSON;
        return 200;

    });
    router.GET("/user/{userId}",[](HttpRequest *req, HttpResponse *resp)
    {
        nlohmann::json response;

        unique_lock<mutex> lock(mtx);

        try{
            int userId = std::stoi(req->GetParam("userId"));

            if (Clients.find(userId) != Clients.end())
            {
                response["id"] = Clients[userId].id;
                response["client"] = Clients[userId].client;
                response["data"] = Clients[userId].data;
            }

            else
            {
                response["error"] = "Client not found";
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 404;
            }
        }
        catch(const exception &e){
            response["error"] = "Invalid data";
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 400;
        }
        
        

        resp->SetBody(response.dump());
        resp->content_type = APPLICATION_JSON;
        return 200;

    });

    router.GET("/users",[](HttpRequest *req, HttpResponse *resp)
    {
        nlohmann::json response;

        unique_lock<mutex> lock(mtx);

        try{
            if(Clients.empty()){
                nlohmann::json userJson;
                userJson["data"] = "";
                response.push_back(userJson);
            }
            else{
                        for (auto &user : Clients)
                {
                    nlohmann::json userJson;
                    userJson["id"] = user.second.id;
                    userJson["client"] = user.second.client;
                    userJson["data"] = user.second.data;
                    response.push_back(userJson);
                }
            }
        }
        catch(const exception& e){
            response["error"] = "Invalid data";
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 400;
        }

        
        resp->SetBody(response.dump());
        resp->content_type = APPLICATION_JSON;
        return 200;
    });

    router.Delete("/user/{userId}", [](HttpRequest *req, HttpResponse *resp)
    {
        nlohmann::json response;
        
        unique_lock<mutex> lock(mtx);

        try{
            int userId = std::stoi(req->GetParam("userId"));

                    if (Clients.find(userId) != Clients.end())
                    {
                        Clients.erase(userId);
                        response["msg"] = "Client deleted successfully";
                    }

                    else
                    {
                        response["error"] = "Client not found";
                        resp->SetBody(response.dump());
                        resp->content_type = APPLICATION_JSON;
                        return 404;
                    }
        }
        catch(const exception& e){
            response["error"] = "Invalid data";
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 400;
        }

        

        resp->SetBody(response.dump());
        resp->content_type = APPLICATION_JSON;
        return 200;

    });
}