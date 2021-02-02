#include <QtTest>
#include "ConwaySequence.h"

// add necessary includes here

class TestConwaySequence : public QObject
{
    Q_OBJECT

public:
    TestConwaySequence();
    ~TestConwaySequence();

private slots:
    void testExeption();
    void testSequenceStart();
    void testSequence();

};

TestConwaySequence::TestConwaySequence()
{

}
TestConwaySequence::~TestConwaySequence()
{

}
void TestConwaySequence::testSequenceStart()
{
    ConwaySequence a;
    a.startVector();
    QCOMPARE(a.Sequence(1), 13);
}
void TestConwaySequence::testExeption()
{
    int loops = 10;
    ConwaySequence a;
    a.startVector();
    QVERIFY_EXCEPTION_THROWN(a.Sequence(loops), out_of_range);
}
void TestConwaySequence::testSequence()
{
    ConwaySequence a;
    a.startVector();
    QCOMPARE(a.Sequence(2), 1113);
}

QTEST_APPLESS_MAIN(TestConwaySequence)

#include "tst_testconwaysequence.moc"
