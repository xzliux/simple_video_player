#include "AudioThread.h"
#include "AVRender.h"
#include "VideoThread.h"
#include <string>

int main(int argc, char* argv[]) {
    const char* url = "/root/project/video_player/test.mp4";
    //实例化渲染器
    AVRender* render = new AVRender();

    //初始化视频线程
    VideoThread *videoThread = new VideoThread();
    videoThread->setRender(render);
    videoThread->setUrl(url);


    //初始化音频线程
    AudioThread *audioThread = new AudioThread();
    audioThread->setRender(render);
    audioThread->setUrl(url);

    //开启音视频线程
    videoThread->start();
    audioThread->start();

    //事件循环
    render->loopEvent();

}