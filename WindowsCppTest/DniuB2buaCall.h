#ifndef __DIUCALL_H__
#define __DIUCALL_H__

#include <string>
#include <iostream>
class CDniuB2buaCall
{
public:
    CDniuB2buaCall(std::string data) :m_data(data) {}

    friend std::ostream& operator<<(std::ostream& out, const CDniuB2buaCall& p)
    {
        return out << "------" << p.m_data << std::endl;
    }
private:
    std::string m_data;
};

#endif
