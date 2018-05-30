#include "listviewfeeder.h"

FileObject::FileObject(QObject *parent) : QObject(parent) {
}

FileObject::FileObject( const QString &icon, const QString &type, const QString &fileName, const QString &fileExt,
                        const QString &fileSize, const QString &fileDate, const QString &fileAttr, QObject *parent)
                      : QObject(parent),
                        m_icon(icon),
                        m_type(type),
                        m_fileName(fileName),
                        m_fileExt(fileExt),
                        m_fileSize(fileSize),
                        m_fileDate(fileDate),
                        m_fileAttr(fileAttr)
{
}

QString FileObject::icon() const {
    return m_icon;
}
QString FileObject::type() const {
    return m_type;
}
QString FileObject::fileName() const {
    return m_fileName;
}
QString FileObject::fileExt() const {
    return m_fileExt;
}
QString FileObject::fileSize() const {
    return m_fileSize;
}
QString FileObject::fileDate() const {
    return m_fileDate;
}
QString FileObject::fileAttr() const {
    return m_fileAttr;
}

void FileObject::setIcon(const QString &icon) {
    if (icon != m_icon) {
        m_icon = icon;
        emit iconChanged();
    }
}
void FileObject::setType(const QString &type) {
    if (type != m_type) {
        m_type = type;
        emit typeChanged();
    }
}
void FileObject::setFileName(const QString &fileName) {
    if (fileName != m_fileName) {
        m_fileName = fileName;
        emit fileNameChanged();
    }
}
void FileObject::setFileExt(const QString &fileExt) {
    if (fileExt != m_fileExt) {
        m_fileExt = fileExt;
        emit fileExtChanged();
    }
}
void FileObject::setFileSize(const QString &fileSize) {
    if (fileSize != m_fileSize) {
        m_fileSize = fileSize;
        emit fileSizeChanged();
    }
}
void FileObject::setFileDate(const QString &fileDate) {
    if (fileDate != m_fileDate) {
        m_fileDate = fileDate;
        emit fileDateChanged();
    }
}
void FileObject::setFileAttr(const QString &fileAttr) {
    if (fileAttr != m_fileAttr) {
        m_fileAttr = fileAttr;
        emit fileAttrChanged();
    }
}
