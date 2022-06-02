#include <iostream>
#include <regex>

#include "http-server.h"

// libs
#include "libs/crow/crow_all.h"
// database
#include "database/AuthService/auth-service.h"
#include "database/StatisticAccessor/statistic-accessor.h"
#include "database/Authenticator/autenticator.h"


namespace invasion::http_server {
    using namespace invasion::statistic_base;
    using namespace invasion::database_access;
    using namespace invasion::database_interface;
    using namespace invasion::token_authenticator;

    auto statisticToJson(const UserStatistics &playerStatistic) {
        crow::json::wvalue responseJson;
        responseJson["kills"] = playerStatistic.totalKills;
        responseJson["deaths"] = playerStatistic.totalDeaths;
        responseJson["matches"] = playerStatistic.numberOfMatches;
        responseJson["victories"] = playerStatistic.numberWins;
        return responseJson;
    }

    void HttpServer::start() {
        StatisticAccessor::clear(); // просто очистка БД для debug-режима
        Authenticator::deleteAll();
        DatabaseAccessor::deleteAll();

        thread_ = std::move(std::thread{[]() {
            static const std::regex invalidSymbols(R"([a-zA-Z0-9]*)");

            AuthService::deleteAllUsers();
            crow::SimpleApp app;
            CROW_ROUTE(app, "/register")
                    .methods("POST"_method)
                            ([](const crow::request &rowRequest) {
                                auto requestJson = crow::json::load(rowRequest.body);
                                std::string password = requestJson["password"].s();
                                std::string username = requestJson["username"].s();
                                crow::json::wvalue responseJson;

                                if (!requestJson || username.empty() || password.empty()) {
                                    responseJson["message"] = "Bad request";
                                    return crow::response(400, responseJson);
                                }
								else if (!std::regex_match(password.c_str(), invalidSymbols) ||
										 !std::regex_match(username.c_str(), invalidSymbols)) {
                                    responseJson["message"] = "Invalid Symbols";
                                    return crow::response(500, responseJson);
                                }
								else if (AuthService::tryToRegisterUser(username, password)) {
                                    StatisticAccessor::addOrUpdateLine(StatisticContainer{username});

                                    responseJson["token"] = Authenticator::createNewToken(username);
									responseJson["username"] = username;
                                    responseJson["message"] = "Successful registration!";
                                    
									return crow::response(200, responseJson);
                                }
								else {
                                    responseJson["message"] = "This user already exists in the database!";
                                    return crow::response(400, responseJson);
                                }

                            });
            CROW_ROUTE(app, "/login")
                    .methods("GET"_method)
                            ([](const crow::request &rowRequest) {
                                auto requestJson = crow::json::load(rowRequest.body);
                                crow::json::wvalue responseJson;
                                std::string password = requestJson["password"].s();
                                std::string username = requestJson["username"].s();
                                if (!requestJson || username.empty() || password.empty()) {
                                    responseJson["message"] = "Bad request";
                                    return crow::response(400, responseJson);
                                }
								else if (!std::regex_match(password.c_str(), invalidSymbols) ||
                                           !std::regex_match(username.c_str(), invalidSymbols)) {
                                    responseJson["message"] = "Invalid Symbols";
                                    return crow::response(500, responseJson);
                                }
								else if (AuthService::login(username, password)) {
                                    responseJson["token"] = Authenticator::refreshOldToken(username);
									responseJson["username"] = username;
                                    responseJson["message"] = "Successful login!";
                                    return crow::response(200, responseJson);
                                }
								else {
                                    responseJson["message"] = "Wrong username or password!";
                                    return crow::response(400, responseJson);
                                }
                            });
            CROW_ROUTE(app, "/statistic")  // get player statistic
                    .methods("GET"_method)
                            ([](const crow::request &rowRequest) {
                                auto requestJson = crow::json::load(rowRequest.body);
                                std::string username = requestJson["username"].s();
                                std::string token = requestJson["token"].s();
                                crow::json::wvalue responseJson;
                                if (!requestJson || username.empty() || token.empty()) {
                                    responseJson["message"] = "Bad request";
                                    return crow::response(400, responseJson);
                                }
                                if (!Authenticator::checkTokenMatch(username, token)) {
                                    responseJson["message"] = "Entry not allowed";
                                    return crow::response(403, responseJson);
                                }
                                UserStatistics playerStatistic = StatisticAccessor::getUserStatistic(username);
                                responseJson = statisticToJson(playerStatistic);
                                return crow::response(200, responseJson);
                            });
            CROW_ROUTE(app, "/statistic") // update player statistic
                    .methods("PUT"_method)
                            ([](const crow::request &rowRequest) {
                                auto requestJson = crow::json::load(rowRequest.body);

                                std::string username = requestJson["username"].s();
                                std::string token = requestJson["token"].s();
                                
								crow::json::wvalue responseJson;
                                
								if (!requestJson || username.empty() || token.empty()) {
                                    responseJson["message"] = "Bad request";
                                    return crow::response(400, responseJson);
                                }
                                if (!Authenticator::checkTokenMatch(username, token)) {
                                    responseJson["message"] = "Entry not allowed";
                                    return crow::response(403, responseJson);
                                }
                                StatisticContainer statistic(requestJson);
                                StatisticAccessor::addOrUpdateLine(statistic);
                                responseJson["message"] = "success";
                                return crow::response(200, responseJson);
                            });

            app.port(5555).multithreaded().run();
        }});
        thread_.detach();
    }

    void HttpServer::stop() {
        thread_.join();
    }
}