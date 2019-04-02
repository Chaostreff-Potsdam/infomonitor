#ifndef WILAPPOST_H
#define WILAPPOST_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QNetworkAccessManager>



class WilapPost : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString title READ title NOTIFY titleChanged)
    Q_PROPERTY(QString text READ text NOTIFY textChanged)
    Q_PROPERTY(QString user READ user NOTIFY userChanged)
    Q_PROPERTY(QString avatarUrl READ avatarUrl NOTIFY avatarUrlChanged)

public:
    explicit WilapPost(QObject *parent = nullptr);
    void updateToPostID(const int postID);
    void updateData();
    void requestPosts();
    Q_INVOKABLE void next();


    QString title() const;
    QString text() const;
    QString user() const;
    QString avatarUrl() const;

signals:
    void titleChanged();
    void textChanged();
    void userChanged();
    void avatarUrlChanged();

private:
    int m_id;
    QNetworkRequest m_request;
    QNetworkReply *m_reply;
    QNetworkAccessManager *m_qnam;
    QJsonDocument m_jsondoc;
    QJsonArray m_array;

    QString m_title;
    QString m_text;
    QString m_user;
    QString m_avatarUrl;

};

#endif // WILAPPOST_H
