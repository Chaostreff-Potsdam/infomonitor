#include "wilappost.h"

#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>


WilapPost::WilapPost(QObject *parent) : QObject(parent)
{
    m_id=0;
    m_array = QJsonArray();
    m_qnam = new QNetworkAccessManager();
    m_request = QNetworkRequest(QUrl("https://forum.wilap.de/posts.json"));
    m_reply = m_qnam->get(m_request);
    connect(m_qnam, &QNetworkAccessManager::finished, this, [this](){this->updateData();});
}

void WilapPost::requestPosts()
{
    m_request = QNetworkRequest(QUrl("https://forum.wilap.de/posts.json"));
    m_reply = m_qnam->get(m_request);
    connect(m_qnam, &QNetworkAccessManager::finished, this, [this](){this->updateData();});
}

void WilapPost::next()
{
    if(m_id > 10)
    {
        m_id = 0;
        requestPosts();
    }
    m_id++;
    updateData();
}

QString WilapPost::avatarUrl() const
{
    return m_avatarUrl;
}

QString WilapPost::user() const
{
    return m_user;
}

QString WilapPost::text() const
{
    return m_text;
}

QString WilapPost::title() const
{
    return m_title;
}

void WilapPost::updateData()
{

    if(m_array.isEmpty()) {
        QByteArray raw_reply = m_reply->readAll();
        QJsonParseError e;
        m_jsondoc = QJsonDocument::fromJson(raw_reply, &e);
        qDebug() << e.error;
        qDebug() << e.errorString();
        m_array = m_jsondoc.object()["latest_posts"].toArray();
    }
    m_title = m_array[m_id].toObject()["topic_html_title"].toString();
    emit titleChanged();
    m_user = m_array[m_id].toObject()["username"].toString();
    emit userChanged();
    m_text = m_array[m_id].toObject()["raw"].toString();
    emit textChanged();
    m_avatarUrl = m_array[m_id].toObject()["avatar_template"].toString().replace("{size}", "45");
    emit avatarUrlChanged();
}






