#include <QtTest>

// add necessary includes here

class testconwaysequence : public QObject
{
    Q_OBJECT

public:
    testconwaysequence();
    ~testconwaysequence();

private slots:
    void test_case1();

};

testconwaysequence::testconwaysequence()
{

}

testconwaysequence::~testconwaysequence()
{

}

void testconwaysequence::test_case1()
{

}

QTEST_APPLESS_MAIN(testconwaysequence)

#include "tst_testconwaysequence.moc"
