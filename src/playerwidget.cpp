#include "playerwidget.h"
#include "mainwindow.h"
//#include <phonon/mediaobject.h>
//#include <AL/al.h>
//#include <AL/alc.h>

PlayerWidget::PlayerWidget(MainWindow *parent, Data *data) : QWidget(parent)
{
    // Adapter
    // Constructor in PlayerWidget adapted
    this->mainWindow = parent;
    this->data = data;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSizeConstraint(QLayout::SetMinimumSize);

    string nameLabelStr = string("<b>");
    nameLabelStr.append(data->name);
    nameLabelStr.append("</b>");
    QLabel *nameLabel = new QLabel(QString::fromStdString(nameLabelStr));
    nameLabel->setTextFormat(Qt::RichText);
    nameLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
//    nameLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
//    nameLabel->adjustSize();

//    nameLabel->setFrameShape(QFrame::Box);
//    nameLabel->setFrameShadow(QFrame::Raised);

    layout->addWidget(nameLabel);

    QFrame* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    layout->addWidget(line);


    TextView *textView = new TextView(data);
//    textView->setAlignment(Qt::AlignTop); //doesnt work
    textView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(textView);

    QPushButton *button = new QPushButton("&Translate");
//    button->focusPolicy(Qt::NoFocus);
    QObject::connect(button, SIGNAL(clicked()), textView, SLOT(translateText()));
    layout->addWidget(button);

    setLayout(layout);

    player = new QMediaPlayer(this);
//    connect(ui->but_play, &QToolButton::clicked, m_player, &QMediaPlayer::play);
//    connect(ui->but_pause, &QToolButton::clicked, m_player, &QMediaPlayer::pause);
//    ui->label->setText(data->text);
}

void PlayerWidget::play() {
//    player->setVolume(70);
////    QBuffer *buffer = new QBuffer(player);
////    buffer->setData(data->audio);
//    QBuffer *testBuffer = new QBuffer();
//    qDebug() << testBuffer->errorString();

//    buffer = new QBuffer(&data->audio);
////    qDebug() << buffer->errorString();
//    buffer->open(QIODevice::ReadOnly); //needed?
//    qDebug() << "buf size" << buffer->size();
//    qDebug() << "audio size" << data->audio.size();
//    qDebug() << "in play" << buffer->errorString();
//    QMediaContent content(QUrl(QString("http://www.slow-chinese.com/podcasts/Slow_Chinese_150.mp3")));
//    qDebug() << content.isNull();
//    qDebug() << player->mediaStatus();
//    player->setMedia(content, buffer);
//    qDebug() << player->availability() << player->mediaStatus();
//    player->play();
//    qDebug() << "in play" << player->error() << player->mediaStatus();
//    playing = true;

//    decoder = new QAudioDecoder();
//    decoder->setAudioFormat(desiredFormat);
//    decoder->setSourceFilename("sample.mp3");
//    connect(decoder, SIGNAL(bufferReady()), this, SLOT(readBuffer()));
//    decoder->start();
}

void PlayerWidget::updateStatus() {
    RemoteData *remoteData = dynamic_cast<RemoteData *>(data); //static?
//    qDebug() << "updateStatus in playerWidget";
    double playThreshold = 0.2;
    if (remoteData->audioDownloadedPercent > playThreshold && !playing) {
        playing = true;
        PlayerThread *playerThread = new PlayerThread(remoteData);
        connect(playerThread, SIGNAL(finished()), playerThread, SLOT(deleteLater()));
        playerThread->start();
        qDebug() << "Started playing";
    }

//    if (player->state() == QMediaPlayer::PlayingState) {
//        qDebug() << "playing";
//    } else {
//        if ((!playing) && (remoteData->audioDownloadedPercent > 0.2)) {
//            qDebug() << player->state();
//            qDebug() << "not playing, init " << remoteData->audioDownloadedPercent;
//            play();
//            qDebug() << "play() completed";
//        }
//    }
//    if (remoteData->audioDownloadedPercent == 1) {
//        qDebug() << "audiodp = 1 " << player->state();
//        qDebug() << "audiodp = 1 " << player->error();
//        qDebug() << "in play" << player->mediaStatus();
//        qDebug() << "in play" << player->isAudioAvailable();
//        qDebug() << "in play" << player->duration();
//    }
}

PlayerWidget::~PlayerWidget()
{
	delete(player);
	delete(buffer);
    delete(mainWindow);
    delete(data);

}
