#pragma once
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include<iostream>
#include<string>
#include <sstream>

class PathManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)

 public:
  explicit PathManager(QObject *parent = nullptr)
      : QObject(parent), m_path("M 0 384 C 144 96, 336 96, 480 384") {}

  QString path() const { return m_path; }

 public slots:
  void setPath(const QString &path);
  void changePath(int ind, double x, double y);

 signals:
  void pathChanged();

 private:
  QString m_path;
};
