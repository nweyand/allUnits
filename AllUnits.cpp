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

#include "AllUnits.h"

AllUnits AllUnits::instance = AllUnits();

AllUnits::AllUnits()
{
}

AllUnits::~AllUnits()
{
	if ( vTests.size() )
	{
		QObject **pTests = &vTests[0];
		for ( uint i = 0; i < vTests.size(); ++i )
		{
			delete pTests[i];
		}
	}
}

void AllUnits::addTest(QObject *pTest)
{
	instance.vTests.push_back( pTest );
}

int AllUnits::run( int argc, char **argv )
{
	int nReturn = 0;

	std::vector<QObject*>::size_type nSize = instance.vTests.size();
	if ( nSize )
	{
		QObject **pTests = &instance.vTests[0];
		for ( uint i = 0; i < nSize; ++i )
		{
			nReturn += QTest::qExec(pTests[i], argc, argv);
		}
	}

	qDeleteAll( instance.vTests );
	instance.vTests.clear();

	return nReturn;
}
