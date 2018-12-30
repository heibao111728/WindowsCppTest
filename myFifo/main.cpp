#include "myfifo.h"
#include "messageDefine.h"

int main()
{
    PLAY_MESSAGE_T play_message;
    play_message.device_id = "1010000";
    play_message.play_action = real_time_paly;
    play_message.realm = "1010";
    play_message.receive_ip = "192.168.2.102";
    play_message.receive_port = 10000;
    play_message.user_id = "test1";

    CMyFifo<PLAY_MESSAGE_T>::get_instance()->set_capacity(500);
    CMyFifo<int>::get_instance()->set_capacity(300);

    int a = CMyFifo<PLAY_MESSAGE_T>::get_instance()->get_capacity();
    int b = CMyFifo<PLAY_MESSAGE_T>::get_instance()->get_current_zise();
    int c = CMyFifo<int>::get_instance()->get_capacity();

    CMyFifo<PLAY_MESSAGE_T>::get_instance()->push(play_message);
    CMyFifo<PLAY_MESSAGE_T>::get_instance()->push(play_message);

    PLAY_MESSAGE_T play_message2 = CMyFifo<PLAY_MESSAGE_T>::get_instance()->pop();
    PLAY_MESSAGE_T play_message3 = CMyFifo<PLAY_MESSAGE_T>::get_instance()->pop();
    PLAY_MESSAGE_T play_message4 = CMyFifo<PLAY_MESSAGE_T>::get_instance()->pop();

    system("pause");
    return 0;
}