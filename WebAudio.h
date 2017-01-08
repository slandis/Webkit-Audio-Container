#ifndef WEBAUDIO_H
#define WEBAUDIO_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class WebAudio : public QWidget {
  Q_OBJECT

public:
  WebAudio(QWidget *parent = 0);
  ~WebAudio();

public slots:
  /* QMediaPlayer Functions */
  int bufferStatus();
  QString currentMedia();
  qint64 duration();
  QMediaPlayer::Error error();
  QString errorString();
  bool isAudioAvailable();
  bool isMetaDataAvailable();
  bool isMuted();
  bool isSeekable();
  QString media();
  QMediaPlayer::MediaStatus mediaStatus();
  QString metaData();
  int notifyInterval();
  qreal playbackRate();
  QStringList playlist();
  qint64 position();
  QMediaPlayer::State state();
  int volume();

  /* QMediaPlaylist Functions */
  bool addMedia(const QString &media);
  void clear();
  int currentIndex();
  bool insertMedia(int index, const QString &media);
  bool isEmpty();
  bool isReadOnly();
  QString media(int index);
  int mediaCount();
  int nextIndex(int steps);
  QMediaPlaylist::PlaybackMode playbackMode();
  int previousIndex(int steps);
  bool removeMedia(int index);
  void setPlaybackMode(QMediaPlaylist::PlaybackMode mode);

  /* QMediaPlayer Slots */
  void pause();
  void play();
  void setMedia(const QStringList &list);
  void setMuted(bool muted);
  void setNotifyInterval(int millis);
  void setPlaybackRate(qreal rate);
  void setPlaylist(const QStringList &list);
  void setPosition(qint64 position);
  void setVolume(int volume);
  void stop();

  /* QMediaPlaylist Slots */
  void next();
  void previous();
  void setCurrentIndex(int index);
  void shuffle();

private:
  QMediaPlayer *_player;
  QMediaPlaylist *_playlist;

private slots:
  /* QMediaPlayer Events */
  void audioAvailableChanged(bool available);
  void bufferStatusChanged(int percent);
  void currentMediaChanged(const QMediaContent &media);
  void durationChanged(qint64 duration);
  void error(QMediaPlayer::Error error);
  void mediaChanged(const QMediaContent &media);
  void mediaStatusChanged(QMediaPlayer::MediaStatus status);
  void metaDataChanged();
  void metaDataAvailableChanged(bool available);
  void mutedChanged(bool muted);
  void notifyIntervalChanged(int milliseconds);
  void playbackRateChanged(qreal rate);
  void positionChanged(qint64 position);
  void seekableChanged(bool seekable);
  void stateChanged(QMediaPlayer::State state);
  void volumeChanged(int volume);

  /* QMediaPlaylist Events */
  void currentIndexChanged(int position);
  void mediaAboutToBeInserted(int start, int end);
  void mediaAboutToBeRemoved(int start, int end);
  void mediaInserted(int start, int end);
  void mediaRemoved(int start, int end);
  void playbackModeChanged(QMediaPlaylist::PlaybackMode mode);

signals:
  /* QMediaPlayer Signals */
  void onAudioAvailableChanged(bool available);
  void onBufferStatusChanged(int percent);
  void onCurrentMediaChanged(QString media);
  void onDurationChanged(qint64 duration);
  void onError(QString error);
  void onMediaChanged(QString media);
  void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
  void onMetaDataChanged();
  void onMetaDataAvailableChanged(bool available);
  void onMutedChanged(bool muted);
  void onNotifyIntervalChanged(int milliseconds);
  void onPlaybackRateChanged(qreal rate);
  void onPositionChanged(qint64 position);
  void onSeekableChanged(bool seekable);
  void onVolumeChanged(int volume);

  /* QMediaPlayer Virtual Signals */
  void onPaused();
  void onPlaying();
  void onStopped();

  /* QMediaPlaylist Signals */
  void onCurrentIndexChanged(int index);
  void onMediaAboutToBeInserted(int start, int end);
  void onMediaAboutToBeRemoved(int start, int end);
  void onMediaInserted(int start, int end);
  void onMediaRemoved(int start, int end);
  void onPlaybackModeChanged(QMediaPlaylist::PlaybackMode mode);
};

#endif