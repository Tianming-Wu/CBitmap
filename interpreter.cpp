#include "interpreter.h"

#include <QRegularExpression>

Interpreter::Interpreter(CBitmap *cbitmap)
    : cbitmap(cbitmap)
{}

QString Interpreter::toString(CodeMode mode)
{
    switch(mode) {
    case ContinuousCodeMode:
        return "";
    case PaddedCodeMode:
        return toStringPadded();
    case PaddedVerticalCodeMode:
        return "";
    }
}

QString Interpreter::parseString(const QString &ref, CodeMode mode)
{
    switch(mode) {
    case ContinuousCodeMode:
        return "";
    case PaddedCodeMode:
        return parseStringPadded(ref);
    case PaddedVerticalCodeMode:
        return "";
    }
}

QString Interpreter::toStringPadded()
{
    QString code;
    QByteArray byteArray = cbitmap->exportToByteArrayPadded();
    QSize size = cbitmap->bitmapSize();

    code += QString("const uint8_t frame_%1x%2[] = {\n    ").arg(size.width()).arg(size.height());

    for (int i = 0; i < byteArray.size(); i++) {
        code += QString("0x%1, ").arg(byteArray.at(i), 2, 16, QLatin1Char('0'));
    }

    code.chop(2);
    code += "\n};";

    return code;
}

// interpreter.cpp
QString Interpreter::parseStringPadded(const QString &code)
{
    if(code.isEmpty()) return "Empty content";

    QRegularExpression arrayRegex(
        R"(^(?:const\s+)?(?:unsigned\s+char|uint8_t)\s+(\w+)_(\d+)x(\d*)\[\d*\]\s*=\s*\{([^}]+)\};)",
        QRegularExpression::MultilineOption | QRegularExpression::DotMatchesEverythingOption
    );

    // QRegularExpression arrayRegex(
    //     R"(^(?:const\s+)?(?:unsigned\s+char|uint8_t)\s+(\w+?)_(\d+)x(\d+)\s*\[\s*\d*\s*\]\s*=\s*\{([^}]+)\};)",
    //     QRegularExpression::MultilineOption | QRegularExpression::DotMatchesEverythingOption
    //     );

    QRegularExpressionMatch match = arrayRegex.match(code);
    if (!match.hasMatch()) {
        return "Invalid array format";
    }

    // 解析类型和尺寸
    QString arrayName = match.captured(1);
    int width = match.captured(2).toInt();
    int height = match.captured(3).toInt();
    QString dataStr = match.captured(4);

    // 验证类型
    QRegularExpression typeRegex(R"(\b(unsigned char|uint8_t)\b)");
    if (!typeRegex.match(code).hasMatch()) {
        return QString("Unknown type: %1").arg(
            code.section(QRegularExpression(R"(\s+(\w+)\[)"), 1, 1));
    }

    // 解析字节数据
    QVector<uint8_t> byteArray;
    QRegularExpression hexRegex(R"(\b0x([0-9a-fA-F]{1,2})\b)");
    QRegularExpressionMatchIterator iter = hexRegex.globalMatch(dataStr);

    while (iter.hasNext()) {
        QRegularExpressionMatch hexMatch = iter.next();
        bool ok;
        uint8_t byte = hexMatch.captured(1).toUShort(&ok, 16);
        if (!ok) return "Invalid hex format: " + hexMatch.captured();
        byteArray.append(byte);
    }

    // 验证数据量
    int expectedBytes = ((width + 7) / 8) * height;
    if (byteArray.size() != expectedBytes) {
        return QString("Data size mismatch. Expected %1 bytes, got %2")
                .arg(expectedBytes).arg(byteArray.size());
    }

    // 转换为位图
    CBitmap::Frame frame;
    frame.size = QSize(width, height);
    frame.data.resize(width * height);

    // 转换字节数据到位图
    const int bytesPerRow = (width + 7) / 8;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int byteIdx = y * bytesPerRow + x / 8;
            int bitIdx = 7 - (x % 8);
            bool value = (byteArray[byteIdx] & (1 << bitIdx));
            frame.data[y * width + x] = value;
        }
    }

    // 加载到CBitmap
    if (!cbitmap->loadFrame(frame)) {
        return "Failed to load frame data";
    }

    return "";
}

QString Interpreter::toStringPaddedVertical()
{
    QString code;
    QByteArray byteArray = cbitmap->exportToByteArrayPadded();
    QSize size = cbitmap->bitmapSize();

    // code += QString("const uint8_t frame_%1x%2[] = {\n    ").arg(size.width()).arg(size.height());

    // for (int i = 0; i < byteArray.size(); i++) {
    //     code += QString("0x%1, ").arg(byteArray.at(i), 2, 16, QLatin1Char('0'));
    // }

    // code.chop(2);
    // code += "\n};";

    return code;
}
