#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

#include "json1.hpp"

using json = nlohmann::json;
int main ( ) {

 
    std::ifstream inputFile;

    inputFile.open("ZBE70001.txt") ;
    
    if(!inputFile.is_open())
	{
		std::cout<<"Unable to open the file."<<std::endl;
		return 0;
	}

     // std::vector < Machine> Machines; 
    std::string headers = "" ;
    std::string information = "" ;
    std::string machineName = "" ; 
    std::string machineName2 = "" ; 

    std::string previousMachineName = "#" ; 
    std::string line1 = "" ; 
    std::string line2 = "" ; 
    std::map<std::string, std::map< std::string, std::string>> storageMap ; 

    while (std::getline(inputFile,line1)){
        

        if ( line1[0] == '*'){


        std::getline(inputFile,line2);



        if ( line2[0] == '#'){



    
        std::stringstream ss1(line1);
        std::stringstream ss2(line2);
        std::getline(ss1, machineName, ';');
        std::getline(ss2, machineName, ';');
        machineName.erase(0,1);
                std::string substr1;
                std::string substr2;

            while (ss1.good()) {

                std::getline(ss1, substr1, ';');
                std::getline(ss2, substr2, ';');
                std::map<std::string, std::string> inner;
                storageMap[machineName] [substr1 ] =substr2 ;         
                
    
                   }

              
        }

        else {
        
        std::stringstream ss1(line1);
        std::stringstream ss2(line2);
        std::getline(ss1, machineName, ';');
        std::getline(ss2, machineName2, ';');

        machineName.erase(0,1);
        machineName2.erase(0,1);
        std::string substr1;
                std::string substr2;


        while (ss1.good()) {

                std::getline(ss1, substr1, ';');
                std::getline(ss2, substr2, ';');

                
                storageMap[machineName] [substr1 ] = ""; 
                storageMap[machineName2] [substr2 ] = "" ;        
                
    
                   }



        }
    
        }

    }

    inputFile.close();
    

/*
    for (std::pair<std::string, std::pair<std::string,std::string> element : u) {
       std::cout << element.first << " :: " << (element.second).first << (element.second).second <<std::endl;
    }
*/

for( map<string,map<string,string> >::const_iterator ptr=storageMap.begin();ptr!=storageMap.end(); ptr++) {
    cout << "     " <<ptr->first << "   ::::::   "<< "\n";
    for( map<string,string>::const_iterator eptr=ptr->second.begin();eptr!=ptr->second.end(); eptr++){
        cout << eptr->first << "   -----   " << eptr->second << endl;

    }

}
    std::cout<< "Hello World" << std::endl ;


json j;
for( map<string,map<string,string> >::const_iterator ptr=storageMap.begin();ptr!=storageMap.end(); ptr++) {
    cout << "     " <<ptr->first << "   ::::::   "<< "\n";
    for( map<string,string>::const_iterator eptr=ptr->second.begin();eptr!=ptr->second.end(); eptr++){
       j[ptr->first][eptr->first] = eptr->second;

    }

}

std::ofstream o("Temp_Siemens/pretty2.json");
o << std::setw(4) << j << std::endl;






/*

json j;

j["pi"] = 3.141;

j["happy"] = true;

j["name"] = "Niels";

j["nothing"] = nullptr;

j["answer"]["everything"] = 42;

j["list"] = { 1, 0, 2 };

j["object"] = { {"currency", "USD"}, {"value", 42.99} };

json j2 = {
  {"pi", 3.141},
  {"happy", true},
  {"name", "Niels"},
  {"nothing", nullptr},
  {"answer", {
    {"everything", 42}
  }},
  {"list", {1, 0, 2}},
  {"object", {
    {"currency", "USD"},
    {"value", 42.99}
  }}
};

std::ofstream o("pretty.json");
o << std::setw(4) << j << std::endl;




















/*
    std::string str = "1,2,3,4,5,6";
    std::vector<std::string> v;
 
    std::stringstream ss(str);
 
    while (ss.good()) {
        std::string substr;
        std::getline(ss, substr, ',');
        v.push_back(substr);
    }
 
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;


*/

    return 0; 
}


