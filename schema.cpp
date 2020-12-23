
#include "rapidjson/document.h"
#include "rapidjson/schema.h"

#include <iostream>

const char schemaJson[] = R"###(
{
  "$id": "https://example.com/person.schema.json",
  "$schema": "http://json-schema.org/draft-07/schema#",
  "title": "Person",
  "type": "object",
  "properties": {
    "firstName": {
      "type": "string",
      "description": "The person's first name."
    },
    "lastName": {
      "type": "string",
      "description": "The person's last name."
    },
    "age": {
      "description": "Age in years which must be equal to or greater than zero.",
      "type": "integer",
      "minimum": 0
    }
  }
}
)###";

const char personJson[] = R"###(
{
  "firstName": "John",
  "lastName": "Doe",
  "age": 21
}
)###";

using namespace rapidjson;

int main()
{
    Document sd;
    if (sd.Parse(schemaJson).HasParseError())
    {
        // the schema is not a valid JSON
        // ...
    }

    SchemaDocument schema(sd); // sd is no longer needed

    Document d;
    if (d.Parse(personJson).HasParseError())
    {
        // the personJson is not a valid JSON
        // ...
    }

    SchemaValidator validator(schema);
    if (!d.Accept(validator))
    {
        // Input JSON is invalid according to the schema
        // Output diagnostic information
        StringBuffer sb;
        validator.GetInvalidSchemaPointer().StringifyUriFragment(sb);
        printf("Invalid schema: %s\n", sb.GetString());
        printf("Invalid keyword: %s\n", validator.GetInvalidSchemaKeyword());

        sb.Clear();
        validator.GetInvalidDocumentPointer().StringifyUriFragment(sb);
        printf("Invalid document: %s\n", sb.GetString());
    }

    return 0;
}
