# CSV_to_JSON_converter
Dynamic CSV Data Converter to JSON in C++
## How to run
You can find the CSV Data in ZBE70001.txt

<pre>
cmake .
make
./main

</pre>

Then JSON data format will be created inside Temp_Siemens directory
then go to that directory and write these commands in your terminal

<pre>
cmake .
make
./JsonPATH

</pre>

It will query specific items with JSONPath in C++

Thanks to Dr. Darko Anicic for the task

References and libraries:

https://champlnx.blogspot.com/2017/12/json-for-c-create-json-objects-read.html

https://github.com/nlohmann/json

https://github.com/danielaparker/jsoncons
