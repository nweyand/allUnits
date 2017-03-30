# allUnits
The intention of this minimal project is to provide a uniform way of calling the tests contained in multiple Qt Unit Test classes.

## Usage
* Implement your test classes using the [Qt Test framework](http://doc.qt.io/qt-5/qtest-overview.html).
* Add them to the test queue using `AllUnits::addTest( QObject* pTest )`
* Run the tests using `AllUnits::run( int argc, char *argv[] )`

  Voilà: All previously added test objects will be executed via [QTest::qExec](http://doc.qt.io/qt-5/qtest.html#qExec).