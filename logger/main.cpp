#include "logger.h"

#include <stdio.h>

int main()
{

    bsm_logger::set_log_type(log_type_file);
    if (!bsm_logger::get_instance()->init_logger("E://bsm.log"))
    {
        return -1;
    }

    LOG("hello\n");
    LOG("%s", "hello ---------\n");
    int a = 3;

    LOG("a = %d\n", a);
    bsm_logger::get_instance()->uninit_logger();
}