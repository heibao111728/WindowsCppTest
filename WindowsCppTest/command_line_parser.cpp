#include "command_line_parser.h"

command_line_parser::command_line_parser()
{
}

command_line_parser::~command_line_parser()
{
}

int command_line_parser::get_cardinality()
{
    return m_cardinality;
}

bool command_line_parser::parse(char* schema, char* args[], int argc)
{
    char _schema[1000] = {0};
    if (schema && args[0])
    {
        sprintf(_schema, "%s", schema);

        char* temp_schema = strtok(_schema, ",");
        while (temp_schema)
        {
            if ('\0' == temp_schema[1])
            {
                m_bool_value_map[temp_schema[0]] = false;
            }
            else if ('#' == temp_schema[1])
            {
                m_int_value_map[temp_schema[0]] = 0;
            }
            else if ('*' == temp_schema[1])
            {
                m_string_value_map[temp_schema[0]] = NULL;
            }

            temp_schema = strtok(NULL, ",");
        }

        for (int i = 0; i < argc; i++)
        {
            if (args[i][0] == '-')
            {
                m_cardinality++;
                map<char, bool>::iterator it_bool = m_bool_value_map.find(args[i][1]);
                if (m_bool_value_map.end() == it_bool)
                {
                    //do nothing 
                }
                else
                {
                    it_bool->second = true;
                    continue;
                }

                map<char, int>::iterator it_int = m_int_value_map.find(args[i][1]);
                if (m_int_value_map.end() == it_int)
                {
                    //do nothing 
                }
                else
                {
                    if ('-' != args[i + 1][0])
                    {
                        it_int->second = atoi(args[i + 1]);
                    }
                    continue;
                }

                map<char, char*>::iterator it_string = m_string_value_map.find(args[i][1]);
                if (m_string_value_map.end() == it_string)
                {
                    //do nothing 
                }
                else
                {
                    if ('-' != args[i + 1][0])
                    {
                        it_string->second = (args[i + 1]);
                    }
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
    }

    return false;
}

bool command_line_parser::get_bool_param_value(char param)
{
    map<char, bool>::iterator it = m_bool_value_map.find(param);
    if (m_bool_value_map.end() == it)
    {
        return false;
    }
    else
    {
        return it->second;
    }
}

int command_line_parser::get_int_param_value(char param)
{
    map<char, int>::iterator it = m_int_value_map.find(param);
    if (m_int_value_map.end() == it)
    {
        return -1;
    }
    else
    {
        return it->second;
    }
}

char* command_line_parser::get_string_param_value(char param)
{
    map<char, char*>::iterator it = m_string_value_map.find(param);
    if (m_string_value_map.end() == it)
    {
        return 0;
    }
    else
    {
        return it->second;
    }
}

void command_line_parser::printf_param_values()
{
    printf("cardinality = %d\n", get_cardinality());

    map<char, bool>::iterator it_bool = m_bool_value_map.begin();
    for (; m_bool_value_map.end() != it_bool; it_bool++)
    {
        printf("%c:%s\n", it_bool->first, (it_bool->second ? "true" : "false"));
    }

    map<char, int>::iterator it_int = m_int_value_map.begin();
    for (; m_int_value_map.end() != it_int; it_int++)
    {
        printf("%c:%d\n", it_int->first, it_int->second);
    }

    map<char, char*>::iterator it_string = m_string_value_map.begin();
    for (; m_string_value_map.end() != it_string; it_string++)
    {
        printf("%c:%s\n", it_string->first, it_string->second);
    }
}