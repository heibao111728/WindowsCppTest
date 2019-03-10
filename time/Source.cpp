#include <stdio.h>
#include <time.h>
#include <winsock2.h>
#include <windows.h>

class dtime
{
public:
    dtime() 
    {
        time_t nowtime;
        nowtime = time(NULL);
        struct tm *local, *gm;
        local = localtime(&nowtime);

        if (local)
        {
            m_hour = local->tm_hour;
            m_min = local->tm_min;
            m_sec = local->tm_sec;
        }

    };

    ~dtime() {};

    // get second;
    int operator-(dtime& t) const
    {
        int hour = 0;
        int min = 0;
        int second = 0;

        hour = m_hour - t.m_hour;
        min = m_min - t.m_min;
        second = m_sec - t.m_sec;

        if (hour > 0)
        {
            second += hour * 3600;
        }
        if (min > 0)
        {
            second += min * 60;
        }

        return second;
    }
private:
    int m_hour;
    int m_min;
    int m_sec;
};

class dtimmer
{
public:
    dtimmer()
    {
        reset();
    }


    void reset()
    {
        m_time = clock();
    }

    long  elapsed()
    {
        return (clock() - m_time) /1000;
    }
private:
    long m_time;
};

int main()
{
    //long a = 0;
    //long b = 0;
    dtimmer timmer;
    //a = timmer.elapsed();
    //Sleep(5);
    //b = timmer.elapsed();

    int interval = 5;

    while(1)
    {
        int b = timmer.elapsed();
        if (b > interval)
        {
            printf("%d\n", b);
            timmer.reset();
        }
        Sleep(1);
    }
}