#include <iostream>

using namespace std;

#include "httplib.h"

using namespace httplib;

#include "json.hpp"

using json = nlohmann::json;

int main() {

    Server svr;

    svr.Get("/", [](const Request &req, Response &rsp) {
        rsp.set_content("home", "text/plain");
    });

    svr.Get("/js", [](const Request &req, Response &rsp) {

        json j = {
                {"a", 1},
                {"b", 2}
        };
        rsp.set_content(j.dump(), "application/json");
    });

    svr.listen("::", 8080);

    return 0;
}