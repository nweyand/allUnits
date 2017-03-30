/*
** This is free and unencumbered software released into the public domain.
**
** Anyone is free to copy, modify, publish, use, compile, sell, or
** distribute this software, either in source code form or as a compiled
** binary, for any purpose, commercial or non-commercial, and by any
** means.
**
** In jurisdictions that recognize copyright laws, the author or authors
** of this software dedicate any and all copyright interest in the
** software to the public domain. We make this dedication for the benefit
** of the public at large and to the detriment of our heirs and
** successors. We intend this dedication to be an overt act of
** relinquishment in perpetuity of all present and future rights to this
** software under copyright law.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
** OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
** OTHER DEALINGS IN THE SOFTWARE.
**
** For more information, please refer to <http://unlicense.org>
**
**
**           **************************************************
**
** Note by the author:
**   Bug reports / suggestions for improvement are greatly appreciated
**   and can be reported here: https://github.com/nweyand/allUnits
*/

#ifndef ALLUNITS_H
#define ALLUNITS_H

#include <vector>
#include <QtTest>

/**
 * @brief The AllUnits class implements a uniform way of calling multiple Qt Unit Test Objects.
 */
class AllUnits
{
public:
	/**
	 * @brief addTest adds a new test to the test queue.
	 * @param pTest The new test to be added.
	 */
	static void addTest(QObject *pTest);

	/**
	 * @brief run executes all queued Qt Unit Test Objects.
	 * Optionally, the command line arguments <code>argc</code> and </code>argv<code> can be
	 * provided. See http://doc.qt.io/qt-5/qtest-overview.html#qt-test-command-line-arguments
	 * for more information.
	 * @return The summed return value of all test objects.
	 */
	static int  run(int argc = 0, char **argv = Q_NULLPTR);


private:
	std::vector<QObject*> vTests;
	static AllUnits instance;

	AllUnits();
	~AllUnits();
};

#endif // ALLUNITS_H
