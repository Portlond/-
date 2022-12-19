#include <QtTest>
#include "..\Objects\objects.h"


class Test_objects : public QObject
{
    Q_OBJECT

public:
    Test_objects();
    ~Test_objects();

private slots:
    void test_case1();
    void test_bicycle();
    void test_route();
};

Test_objects::Test_objects()
{

}

Test_objects::~Test_objects()
{

}

void Test_objects::test_case1()
{
    Sedan sedan;
    QVERIFY(!sedan.drive(100));
    QCOMPARE(sedan.getFuelLevel(), 0.0);
    sedan.refuel();
    QCOMPARE(sedan.getFuelLevel(),50.0);
    QVERIFY(sedan.drive(100));
    QCOMPARE(sedan.getMilage(),100);
    QCOMPARE(sedan.getFuelLevel(),43.0);
    QVERIFY(!sedan.drive(500));
    QCOMPARE(sedan.getMilage(), 250);
    QCOMPARE(sedan.getFuelLevel(),32.5);
    sedan.refuel();
    QCOMPARE(sedan.getFuelLevel(),50);
    QVERIFY(sedan.drive(500));
    QCOMPARE(sedan.getFuelLevel(),15.0);
}

void Test_objects::test_bicycle()
{
    Bicycle bicycle;
    QVERIFY(bicycle.drive(1000));
    QVERIFY(bicycle.get_mileage() == 1000);
}

void Test_objects::test_route()
{
    Route route;
    RoutePoint rp_1 = RoutePoint(0,0, "Point_1");
    RoutePoint rp_2 = RoutePoint(10,0, "Point_2");

    route.addPoint(rp_1);
    route.addPoint(rp_2);

    Sedan *sedan = new Sedan(50, 8.5);
    sedan->refuel();
    route.run(sedan);
    QVERIFY(sedan->getMilage() == 10);

}

QTEST_APPLESS_MAIN(Test_objects)

//#include "C:\Users\portl\OneDrive\Desktop\Qt\SVP\lr9\build-test-Desktop_Qt_6_4_1_MinGW_64_bit-Debug\debug\tst_test_objects.moc"

#include "tst_test_objects.moc"
