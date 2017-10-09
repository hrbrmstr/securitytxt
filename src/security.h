#ifndef SECURITY_CPP_H
#define SECURITY_CPP_H

#include <sstream>
#include <unordered_map>
#include <vector>

namespace SecTxt {

    class SecurityText {

    public:

      // Create a security.txt data structure from a utf-8-encoded string.
      SecurityText(const std::string& content);

      std::string rawFile();
      std::vector<std::string> sectxtKeys();
      std::vector<std::string> sectxtVals();

      // Return the security.txt URL corresponding to the provided URL.
      static std::string securityUrl(const std::string& url);

    private:

      static void strip(std::string& string);

      static bool getpair(std::istringstream& stream, std::string& key, std::string& value);

      std::vector<std::string> st_keys;
      std::vector<std::string> st_vals;
      std::string orig_file;

    };
}

#endif
