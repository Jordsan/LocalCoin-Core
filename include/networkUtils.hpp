// #ifndef NETWORK_UTILS_H_
// #define NETWORK_UTILS_H_

// #include <boost/format.hpp>

// #include <boost/log/core.hpp>
// #include <boost/log/trivial.hpp>
// #include <boost/log/expressions.hpp>
// #include <boost/log/utility/setup/console.hpp>
// #include <boost/log/support/date_time.hpp>
// #include <boost/log/utility/setup/common_attributes.hpp>

// #include <boost/property_tree/ptree.hpp>
// #include <boost/property_tree/json_parser.hpp>

// #include <boost/asio.hpp>
// #include <boost/algorithm/string.hpp>

// #include <string>
// #include <iostream>
// #include <vector>
// #include <map>
// #include <regex>

// using namespace boost::asio;
// using namespace boost::asio::ip;

// using HostInetInfo = tcp::resolver::iterator;

// class NetworkUtils {
//     private:
//         static HostInetInfo queryHostInetInfo();
//         static std::string hostIP(unsigned short family);

//     public:
//         // gets the host IP4 string formatted
//         static std::string hostIP4();

//         // gets the host IP6 string formatted
//         static std::string hostIP6();
//         static std::string hostName();
// };

// #endif