#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <sstream>
#include <iostream>
#include <unordered_map>

#include "url.h"

#include "security.h"
#include <Rcpp.h>

namespace SecTxt {

    void SecurityText::strip(std::string& string) {
        string.erase(string.begin(), std::find_if(string.begin(), string.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
        string.erase(std::find_if(string.rbegin(), string.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), string.end());
    }

    bool SecurityText::getpair(std::istringstream& stream, std::string& key, std::string& value) {

        while (getline(stream, key)) {

            size_t index = key.find('#');

            if (index != std::string::npos) key.resize(index);

            // Find the colon and divide it into key and value, skipping malformed lines
            index = key.find(':');
            if (index == std::string::npos) continue;

            value.assign(key.begin() + index + 1, key.end());
            key.resize(index);

            // Strip whitespace off of each
            strip(key);
            strip(value);

            // Lowercase the key
            std::transform(key.begin(), key.end(), key.begin(), ::tolower);

            return true;
        }
        return false;
    }

    SecurityText::SecurityText(const std::string& content) {

        orig_file = content;

        std::istringstream input(content);

        if (content.compare(0, 3, "\xEF\xBB\xBF") == 0) input.ignore(3);

        std::string key, value;

        while (SecurityText::getpair(input, key, value)) {
          st_keys.push_back(key);
          st_vals.push_back(value);
        }

    }

    std::string SecurityText::rawFile() {
      return(orig_file);
    }

    std::vector< std::string > SecurityText::sectxtKeys() {
      return(st_keys);
    }

    std::vector< std::string > SecurityText::sectxtVals() {
      return(st_vals);
    }

    std::string SecurityText::securityUrl(const std::string& url) {
        return Url::Url(url)
            .setUserinfo("")
            .setPath(".well-known/security.txt")
            .setParams("")
            .setQuery("")
            .setFragment("")
            .remove_default_port()
            .str();
    }
}
