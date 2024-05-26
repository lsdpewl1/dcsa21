#include "./Utility/Utility.hpp"
#include "Routers.hpp"
#include <thread>
#include <map>
#include <mutex>
#include <iostream>
using namespace std;

class Client {
    public:
        int id;
        string client;
        string data;
        string pass;
        string who;


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
std::string current_user="";

void route::RegisterResources(hv::HttpService &router)
{

    router.GET("/hello", [](HttpRequest *req, HttpResponse *resp)
    {
        auto basic_auth = req->GetHeader("Authorization");

        if (!basic_auth.empty())
        {
            auto splited_header = utils::Split(basic_auth, " ");

            if (splited_header.size() == 2 && splited_header.front() == "Basic")
            {
                
                auto decode = utils::DecodeBase64(splited_header.back());
                auto splited_auth = utils::Split(decode, ":");

                if (splited_auth.size() == 2)
                {
                    //std::cout<<"aaaaaaaaaaaaaaaaa"<<std::endl;
                    
                }
            }
        }

        nlohmann::json response
        {
            {"msg", "Hello world"}
        };

        resp->SetBody(response.dump());
        resp->content_type = APPLICATION_JSON;

        return 200;
    });

//sign in
router.POST("/login", [](HttpRequest *req, HttpResponse *resp)     

{
    nlohmann::json request;
    nlohmann::json response;


    unique_lock<mutex> lock(mtx);

    string name;
    string pass;

    try
    {

            auto basic_auth = req->GetHeader("Authorization");

        if (!basic_auth.empty())
        {
            auto splited_header = utils::Split(basic_auth, " ");

            if (splited_header.size() == 2 && splited_header.front() == "Basic")
            {
                
                auto decode = utils::DecodeBase64(splited_header.back());
                auto splited_auth = utils::Split(decode, ":");

                if (splited_auth.size() == 2)
                {
                    
                    name=splited_auth.front();
                    pass=splited_auth.back();

                }
            }
        }
            auto it = std::find_if(Clients.begin(), Clients.end(), [&name] (const std::pair<int, Client>& pair) {
                    return pair.second.client == name;
                });


            if(it != Clients.end())
            {

                if(it->second.pass == pass)
                {

                    response["msg"] = "Login successful";

                    

                    response["id"]= it->second.id;
                }
                else
                {
                    response["msg"] = "Incorrect password";
                }
            }
            else
            {
                response["msg"] = "User does not exist";
            }

    }
    catch(const exception& e)
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

//add user
    router.POST("/user", [](HttpRequest *req, HttpResponse *resp)

    {


        string name;
        string pass;

        nlohmann::json request;
        nlohmann::json response;

        unique_lock<mutex> lock(mtx);

        try
        {
            request = nlohmann::json::parse(req->body);

            auto basic_auth = req->GetHeader("Authorization");

        if (!basic_auth.empty())
        {
            auto splited_header = utils::Split(basic_auth, " ");

            if (splited_header.size() == 2 && splited_header.front() == "Basic")
            {
                
                auto decode = utils::DecodeBase64(splited_header.back());
                auto splited_auth = utils::Split(decode, ":");

                if (splited_auth.size() == 2)
                {
                    
                    name=splited_auth.front();
                    pass=splited_auth.back();

                }
            }
        }
            if(/*request.contains("client")&&request.contains("pass")&&*/request.contains("who")&&request.contains("data")){


                auto it = std::find_if(Clients.begin(), Clients.end(), [&name] (const std::pair<int, Client>& pair) {
                    return pair.second.client == name;
                });

           if(it != Clients.end())
           {

               response["msg"] = "User already exists";
               resp->SetBody(response.dump());
               resp->content_type = APPLICATION_JSON;
               return 400;
           }

                Client client;
                
                 client.id = id;
                 client.client = name;
                 client.pass = pass;
                 client.who = request["who"].get<string>();
                client.data = request["data"].get<string>();
                Clients[id++] = client;
            }
            else{
                throw exception();
            }

            response["msg"] = "Client added successfully";

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

    //find one user
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
                //cout<<response["client"]<<endl;
                response["who"] = Clients[userId].who;
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

//find all users
    router.GET("/users",[](HttpRequest *req, HttpResponse *resp)
    {


        nlohmann::json response;

        unique_lock<mutex> lock(mtx);

        try{
            if(Clients.empty()){
                // nlohmann::json userJson;
                // userJson["data"] = "";
                // response.push_back(userJson);
                return 404;
            }
            else{
                        for (auto &user : Clients)
                {
                    nlohmann::json userJson;
                    userJson["id"] = user.second.id;
                    userJson["client"] = user.second.client;
                    userJson["who"] = user.second.who;
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

//delete one user
    router.Delete("/user/{userId}", [](HttpRequest *req, HttpResponse *resp)
    {
        nlohmann::json response;
        
        unique_lock<mutex> lock(mtx);

        string cur_id;

        try{
            int userId = std::stoi(req->GetParam("userId"));

            auto basic_auth = req->GetHeader("Authorization");

        if (!basic_auth.empty())
        { 
            auto splited_header = utils::Split(basic_auth, " ");

            if (splited_header.size() == 2 && splited_header.front() == "Basic")
            {
                
                auto decode = utils::DecodeBase64(splited_header.back());
                auto splited_auth = utils::Split(decode, ":");

                if (splited_auth.size() == 2)
                {
                    
                    cur_id=splited_auth.front();


                }
            }
        }
                cout<<Clients[atoi(cur_id.c_str())].who<<endl;
                cout<<atoi(cur_id.c_str())<<endl;
                cout<<Clients[atoi(cur_id.c_str())].client<<endl;
                cout<<Clients[userId].client<<endl;
                if (Clients[atoi(cur_id.c_str())].who == "admin" || Clients[atoi(cur_id.c_str())].client == Clients[userId].client)
                {

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
                else{
                        response["error"] = "Access denied";
                        resp->SetBody(response.dump());
                        resp->content_type = APPLICATION_JSON;
                        return 403;

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


//change
        router.PUT("/user/{userId}", [](HttpRequest *req, HttpResponse *resp)
        {
        nlohmann::json request;
        nlohmann::json response;
        unique_lock<mutex> lock(mtx);

    string name;
    string pass;

        try
        {
            int userId = std::stoi(req->GetParam("userId"));
            request = nlohmann::json::parse(req->body);


            auto basic_auth = req->GetHeader("Authorization");

                    if (!basic_auth.empty())
                    {
                        auto splited_header = utils::Split(basic_auth, " ");

                        if (splited_header.size() == 2 && splited_header.front() == "Basic")
                        {
                            
                            auto decode = utils::DecodeBase64(splited_header.back());
                            auto splited_auth = utils::Split(decode, ":");

                            if (splited_auth.size() == 2)
                            {
                                
                                name=splited_auth.front();
                                pass=splited_auth.back();

                            }
                        }
                    }

            if (Clients[atoi(request["id"].get<string>().c_str())].who == "admin" || Clients[atoi(request["id"].get<string>().c_str())].client == Clients[userId].client)
            {
                if(/*request.contains("client") && request.contains("pass") && */request.contains("who")&& request.contains("data"))
                {
                    


                    if (Clients.find(userId) != Clients.end())
                    {

                        Clients[userId].client = name;
                        Clients[userId].pass = pass;
                        Clients[userId].who = request["who"].get<string>();
                        Clients[userId].data = request["data"].get<string>();
                        response["msg"] = "Client updated successfully";
                        
                    }

                    else
                    {
                        response["error"] = "Client not found";
                        resp->SetBody(response.dump());
                        resp->content_type = APPLICATION_JSON;
                    return 404;
                    }
                }
                else
                {
                    throw std::exception();
                }
            }
            else
            {
                response["error"] = "Access denied";
                resp->SetBody(response.dump());
                resp->content_type = APPLICATION_JSON;
                return 403;
            }
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


}

