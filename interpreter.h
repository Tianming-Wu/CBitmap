#pragma once

#include "cbitmap.h"

class Interpreter
{
public:
    Interpreter(CBitmap* cbitmap);

    enum CodeMode { ContinuousCodeMode, PaddedCodeMode, PaddedVerticalCodeMode };

    QString toString(CodeMode mode);
    QString parseString(const QString& ref, CodeMode mode);

    QString toStringPadded();
    QString parseStringPadded(const QString& ref);


    QString toStringPaddedVertical();

private:
    CBitmap* cbitmap;
};

