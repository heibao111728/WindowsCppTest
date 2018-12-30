#include "taskSchedual.h"
#include "myfifo.h"
#include "messageDefine.h"
#include "basicClientUserAgent.hxx"

int CTaskSchedual::start()
{
    pthread_attr_t attr; //线程属性结构体，创建线程时加入的参数
    pthread_attr_init(&attr); //初始化

    //create real_paly_thread
    int ret = pthread_create(&m_real_paly_thread_id, &attr, real_paly_thread_proc, NULL);
    if (ret < 0)
    {
        //create real_paly_thread_proc failure
    }

    //create review_thread
    ret = pthread_create(&m_review_thread_id, &attr, review_thread_proc, NULL);
    if (ret < 0)
    {
        //create review_thread_proc failure
    }

    //create ptz_control_thread
    ret = pthread_create(&m_ptz_control_thread_id, &attr, ptz_control_thread_proc, NULL);
    if (ret < 0)
    {
        //create review_thread_proc failure
    }

    //create deal_directory_info_thread
    ret = pthread_create(&m_deal_directory_info_thread_id, &attr, deal_directory_info_thread_proc, NULL);
    if (ret < 0)
    {
        //create review_thread_proc failure
    }
}

void* CTaskSchedual::real_paly_thread_proc(void*)
{
    PLAY_MESSAGE_T message = CMyFifo<PLAY_MESSAGE_T>::get_instance()->pop();
    if (NULL != message.user_id)
    {
        BasicClientUserAgent::getInstance()->doInvite(message.user_id, message.device_id, message.realm,
            message.receive_ip, message.receive_port);
    }
    
}
void* CTaskSchedual::review_thread_proc(void*)
{

}
void* CTaskSchedual::ptz_control_thread_proc(void*)
{

}
void* CTaskSchedual::deal_directory_info_thread_proc(void*)
{

}