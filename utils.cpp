#include "utils.hpp"
#include <QCommandLineParser>
#include <memory>
#include <exception>
#include <algorithm>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QList>
#include <QMutableStringListIterator>
#include <QRegularExpression>
#include <QApplication>


QCommandLineParser *setupParser() {
    QCommandLineParser* parser = new QCommandLineParser;
    parser->setApplicationDescription("Colorview is a simple app written to show hex color swatches in a table.");
    parser->addHelpOption();
    parser->addVersionOption();
    parser->addOptions({
                           {{"f", "file"},"File of hex color values", "file"},
                           {{"c", "color"}, "hex color value(s). They may be comma separated. You may also omit the # character as a convenience.", "color"}
                       });
    return parser;
}

static const QRegularExpression re("^#?[0-9a-g]{2,6}$");

QStringList removeInvalidColors(QStringList colors) {
    return colors.filter(re);
}

QStringList processColorsFromString(const QString &line) {

    QStringList colors = line.split(",");
    std::transform(colors.begin(), colors.end(), colors.begin(),
                   [](QString color) {
        color = color.simplified();
        if(color[0] != '#') {color = color.prepend('#'); }
        return color;
    });
    return colors;
}

QStringList parseColorsFromFile(const QString &filename) {
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << "ERROR: unable to read" << filename;
        throw std::exception();
    }

    QStringList ret_list;
    // read the file, one line at a time. For each line, extract a
    // list of qstrings representing color
    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        auto strs = processColorsFromString(line);
        qDebug() << "processColorsFromString returned" << strs;
        ret_list += strs;
    }
    file.close();

    ret_list.removeDuplicates();
    ret_list.sort();
    return ret_list;
}

QStringList processArgs( QCommandLineParser *const parser, const QApplication &a) {
    // process arguments
    parser->process(a);

    QString file = parser->value("file");
    auto color = parser->value("color");

    qDebug() << "file:" << file;
    qDebug() << "color:" << color;

    // process colors, either from the command line or a file.
    QStringList colors;
    if (file != "") {
        colors += removeInvalidColors( parseColorsFromFile(file) );
        qDebug() << "colors" << colors;
    }
    if (color != "") {
        qDebug() << "passing" << colors << "to parseColorsFromFile" << endl;
        colors += removeInvalidColors( processColorsFromString(color) );
    }
    return colors;
}
