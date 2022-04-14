#ifndef INVASION_DATABASE_H
#define INVASION_DATABASE_H

#include <string>
#include <sqlite3.h>
#include "sqlite_orm.h"
#include "../../src/bcrypt-for-password/include/bcrypt.h"
#include "../../src/bcrypt-for-password/src/bcrypt_.h"

#include "../../src/bcrypt-for-password/src/openbsd.h"
#include "../../src/bcrypt-for-password/src/node_blf.h"

#include "../../src/bcrypt-for-password/src/blowfish.h"
#include "iostream"

struct User {
    int id;
    std::string nickname;
    std::string password;
};

using namespace sqlite_orm;
namespace {

}

class Database {
private:

    auto &getDatabase() {
        static auto storage_ = make_storage("db.sqlite",
                                            make_table("users",
                                                       make_column("id", &User::id, autoincrement(), primary_key()),
                                                       make_column("nickname", &User::nickname),
                                                       make_column("hashed password", &User::password)));
        return storage_;
    }

public:
    bool tryAddUser(std::string nickname, std::string password) {
        static auto storage_ = getDatabase();
        storage_.sync_schema();
        try {
            auto cntUsers = storage_.get_all<User>().size();
            if (cntUsers == 0) {
                User user{-1, std::move(nickname), bcrypt::generateHash(password)};
                storage_.insert(user);
                return true;
            }
            auto listAllUsers = storage_.get_all<User>(where(c(&User::nickname) != nickname));
            if (listAllUsers.size() == cntUsers) {
                User user{-1, nickname, bcrypt::generateHash(password)};
                storage_.insert(user);
                return true;
            }
            return false;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    bool LoginUser(const std::string &nickname, const std::string &password) {
        static auto storage_ = getDatabase();
        storage_.sync_schema();
        auto tmp = storage_.get_all_pointer<User>(where(c(&User::nickname) == nickname));
        if (!tmp.size()) {
            return false;
        }
        if (bcrypt::validatePassword(password, tmp[0]->password)) {
            return true;
        }
        return false;
    }

    std::vector<User> getArrayUsers() {
        return getDatabase().get_all<User>();
    }

    void printUsers() {
        auto arrayUsers = getArrayUsers();
        for (auto &user: arrayUsers) {
            std::cout << getDatabase().dump(user) << std::endl;
        }
    }

    void deleteAllUsers() {
        getDatabase().sync_schema();
        getDatabase().remove_all<User>();
    }
};


#endif //INVASION_DATABASE_H
