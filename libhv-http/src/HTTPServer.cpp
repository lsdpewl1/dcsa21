#include "HTTPServer.hpp"

#include <thread>

HttpServer::HttpServer()
{
    _server = std::make_unique<hv::HttpServer>();
    route::RegisterResources(_router);
    _server->registerHttpService(&_router);
}

void HttpServer::Start(int port)
{
    _server->setPort(port);
    _server->setThreadNum(std::thread::hardware_concurrency());
    _server->run();
}
/*
void HttpServer::Delete(const std::string& path, const hv::HttpServer::HttpHandler& handler) {
    _server->del(path, handler);
}*/

HttpServer::~HttpServer()
{
    _server->stop();
}