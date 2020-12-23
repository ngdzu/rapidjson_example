
#include "rapidjson/document.h"
#include "rapidjson/writer.h"

#include <iostream>
#include <string>

using namespace rapidjson;

int main()
{
    const char json[] = "[1, 2, 3, 4]";
    StringStream s(json);

    Document d;
    d.ParseStream(s);

    StringBuffer buffer;
    Writer writer(buffer);
    d.Accept(writer);

    const char *output = buffer.GetString();
    std::string outStr = buffer.GetString();

    std::cout << outStr << std::endl;

    return 0;
}
