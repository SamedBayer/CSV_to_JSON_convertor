#include <iostream>
#include <fstream>
#include <sstream>


#include "jsoncons/json.hpp"
#include "jsoncons_ext/jsonpath/jsonpath.hpp"



using namespace jsoncons;


int main ( ) {



    std::ifstream is("pretty2.json");
    json machines = json::parse(is);
    // std::cout << "(3)\n" << pretty_print(machines) << std::endl;


    json result1 = jsoncons::jsonpath::json_query(machines, "$.CU.BRDCODE");
    std::cout << "(1) " << result1 << std::endl;

    json result2 = jsoncons::jsonpath::json_query(machines, "$.CU.PRGNAME");
    std::cout << "(2) " << result2 << std::endl;


    json result3 = jsoncons::jsonpath::json_query(machines, "$.O.TIX");
    std::cout << "(3) " << result3 << std::endl;

    json result4 = jsoncons::jsonpath::json_query(machines, "$.O.TIY");
    std::cout << "(4) " << result4 << std::endl;

    json result5 = jsoncons::jsonpath::json_query(machines, "$.CU.PRNDIR");
    std::cout << "(5) " << result5 << std::endl;




    json result6 = jsoncons::jsonpath::json_query(machines, "$..PRNVAR2");
    std::cout << "(6) " << result6 << std::endl;

    json result7 = jsoncons::jsonpath::json_query(machines, "$..SQFRCFW");
    std::cout << "(7) " << result7 << std::endl;

    json result8 = jsoncons::jsonpath::json_query(machines, "$..SQFRCBK");
    std::cout << "(8) " << result8 << std::endl;

    json result9 = jsoncons::jsonpath::json_query(machines, "$..SQVELFW");
    std::cout << "(9) " << result9 << std::endl;

    json result10 = jsoncons::jsonpath::json_query(machines, "$..SQVELBK");
    std::cout << "(10) " << result10 << std::endl;



    json result11 = jsoncons::jsonpath::json_query(machines, "$.CU.SEPVEL");
    std::cout << "(11) " << result11 << std::endl;

    json result12 = jsoncons::jsonpath::json_query(machines, "$.CU.SEPWAY");
    std::cout << "(12) " << result12 << std::endl;


    return 0;

}