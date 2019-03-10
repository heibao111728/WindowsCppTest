#ifndef __COMMAND_LINE_PARSER_H__
#define __COMMAND_LINE_PARSER_H__

#include <map>
using namespace std;

class command_line_parser
{
public:
    command_line_parser();
    ~command_line_parser();

    bool parse(char* schema, char* args[], int argc);

    int get_cardinality();

    bool get_bool_param_value(char param);
    int get_int_param_value(char param);
    char* get_string_param_value(char param);

    void printf_param_values();
private:
    int m_cardinality;

    map<char, bool> m_bool_value_map;
    map<char, int> m_int_value_map;
    map<char, char*> m_string_value_map;
};

#endif __COMMAND_LINE_PARSER_H__
