#include "playerthread.h"

PlayerThread::PlayerThread(RemoteData *data)
{
    this->remoteData = data;
}

void PlayerThread::run() {
    int err;
    off_t frame_offset;
    unsigned char *audio;
    size_t done;
    ao_sample_format format;
    int channels, encoding;
    long rate;

    mpg123_handle *mh = NULL;
    ao_device *dev = NULL;

    ao_initialize();
    mpg123_init();
    mh = mpg123_new(NULL, NULL);
    mpg123_open_feed(mh);

    qDebug() << "audioDownloadedPercent > 0.2";
//        mpg123_feed(mh, (const unsigned char*) (data->audio.data()), data->audio.size());
    mpg123_feed(mh, (const unsigned char*) (remoteData->audio.data()), remoteData->totalAudio);
//        qDebug() << "before the loop: " << mpg123_strerror(mh);
    do {
        err = mpg123_decode_frame(mh, &frame_offset, &audio, &done);
//        qDebug() << "loop iteration after decoding a frame";
        switch(err) {
        case MPG123_NEW_FORMAT:
//            qDebug() << "MPG123_NEW_FORMAT ";
            mpg123_getformat(mh, &rate, &channels, &encoding);
            format.bits = mpg123_encsize(encoding) * 8;
            format.rate = rate;
            format.channels = channels;
            format.byte_format = AO_FMT_NATIVE;
            format.matrix = 0;
            dev = ao_open_live(ao_default_driver_id(), &format, NULL);
            break; //remote this break to play the first frame?
        case MPG123_OK:
//            qDebug() << "MPG123_OK " << done;
            ao_play(dev, (char *) audio, done);
            break;
        case MPG123_NEED_MORE:
            qDebug() << "MPG123_NEED_MORE ";
            break;
        default:
            qDebug() << "some error: " << mpg123_strerror(mh);
            break;
        }
    } while(done > 0 || err == MPG123_NEW_FORMAT);
}
