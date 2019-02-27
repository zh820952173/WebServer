//
// Created by marvinle on 2019/2/1 12:18 PM.
//

#include "../include/Util.h"

#include <string>
#include <fcntl.h>


std::string& ltrim(std::string &str) {
    if (str.empty()) {
        return str;
    }

    str.erase(0, str.find_first_not_of(" \t"));
    return str;
}

std::string& rtrim(std::string &str) {
    if (str.empty()) {
        return str;
    }
    str.erase(str.find_last_not_of(" \t")+1);
    return str;
}

std::string& trim(std::string& str) {
    if (str.empty()) {
        return str;
    }

    ltrim(str);
    rtrim(str);
    return str;
}

int setnonblocking(int fd) {
    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_option);
    return old_option;
}



