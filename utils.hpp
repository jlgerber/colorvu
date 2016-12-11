#pragma once

class QCommandLineParser;
class QStringList;
class QString;
class QApplication;

QCommandLineParser* setupParser();

QStringList removeInvalidColors(QStringList colors);

QStringList processColorsFromString(const QString &line);

QStringList parseColorsFromFile(const QString& filename);

QStringList processArgs(QCommandLineParser * const parser, const QApplication& a);
