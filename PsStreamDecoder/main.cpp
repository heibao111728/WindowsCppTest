#include <fstream>
#include "PsDemuxer.h"

using namespace std;

int main(int argc, char* argv[])
{
    CPsDemuxer ps_demuxer;
    ps_demuxer.setup_src_ps_file("E://tmp1.ps");
    ps_demuxer.setup_dst_es_video_file("E://tmp1.h264");

    if (ps_demuxer.open_src_ps_file())
    {
        ps_demuxer.do_prase();
    }

    ps_demuxer.close_src_ps_file();

    return 0;
}
