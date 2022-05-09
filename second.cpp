#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Json library is taken from the github below, and explanations of how to use it
// are mostly taken from the website below.
// https://champlnx.blogspot.com/2017/12/json-for-c-create-json-objects-read.html
// https://github.com/nlohmann/json
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

                // Stream classes for strings
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
 

// Printing 

for( map<string,map<string,string> >::const_iterator ptr=storageMap.begin();ptr!=storageMap.end(); ptr++) {
    cout << "     " <<ptr->first << "   ::::::   "<< "\n";
    for( map<string,string>::const_iterator eptr=ptr->second.begin();eptr!=ptr->second.end(); eptr++){
        cout << eptr->first << "   -----   " << eptr->second << endl;

    }
}



// Creating a JSON object

json j;
for( map<string,map<string,string> >::const_iterator ptr=storageMap.begin();ptr!=storageMap.end(); ptr++) {
    cout << "     " <<ptr->first << "   ::::::   "<< "\n";
    for( map<string,string>::const_iterator eptr=ptr->second.begin();eptr!=ptr->second.end(); eptr++){
       j[ptr->first][eptr->first] = eptr->second;

    }

}

// Write JSON to here
std::ofstream o("Temp_Siemens/pretty2.json");
o << std::setw(4) << j << std::endl;

    return 0; 
}


