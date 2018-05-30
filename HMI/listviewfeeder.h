#ifndef LISTVIEWFEEDER_H
#define LISTVIEWFEEDER_H

#include <QObject>
#include <QAbstractListModel>
#include <QFileSystemModel>
#include <QFileInfo>
#include <QVariant>

class FileObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString fileExt READ fileExt WRITE setFileExt NOTIFY fileExtChanged)
    Q_PROPERTY(QString fileSize READ fileSize WRITE setFileSize NOTIFY fileSizeChanged)
    Q_PROPERTY(QString fileDate READ fileDate WRITE setFileDate NOTIFY fileDateChanged)
    Q_PROPERTY(QString fileAttr READ fileAttr WRITE setFileAttr NOTIFY fileAttrChanged)

public:
    FileObject(QObject *parent=0);
    FileObject( const QString &icon, const QString &type, const QString &fileName, const QString &fileExt,
                const QString &fileSize, const QString &fileDate, const QString &fileAttr, QObject *parent=0);

    QString icon() const;
    QString type() const;
    QString fileName() const;
    QString fileExt() const;
    QString fileSize() const;
    QString fileDate() const;
    QString fileAttr() const;

    void setIcon(const QString &icon);
    void setType(const QString &type);
    void setFileName(const QString &fileName);
    void setFileExt(const QString &fileExt);
    void setFileSize(const QString &fileSize);
    void setFileDate(const QString &fileDate);
    void setFileAttr(const QString &fileAttr);

signals:

    void iconChanged();
    void typeChanged();
    void fileNameChanged();
    void fileExtChanged();
    void fileSizeChanged();
    void fileDateChanged();
    void fileAttrChanged();

private:
    QString m_icon;
    QString m_type;
    QString m_fileName;
    QString m_fileExt;
    QString m_fileSize;
    QString m_fileDate;
    QString m_fileAttr;
};
#endif // LISTVIEWFEEDER_H
