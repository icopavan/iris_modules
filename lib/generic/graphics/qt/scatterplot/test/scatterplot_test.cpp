/**
 * \file lib/generic/modulation/Crc_test.cpp
 * \version 1.0
 *
 * \section COPYRIGHT
 *
 * Copyright 2012-2013 The Iris Project Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution
 * and at http://www.softwareradiosystems.com/iris/copyright.html.
 *
 * \section LICENSE
 *
 * This file is part of the Iris Project.
 *
 * Iris is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Iris is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * A copy of the GNU Lesser General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 * \section DESCRIPTION
 *
 * Main test file for scatterplot class.
 */

#define BOOST_TEST_MODULE Scatterplot_Test

#include "Scatterplot.h"

#include <boost/scoped_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/progress.hpp>
#include <boost/bind.hpp>
#include <qapplication.h>
#include <cstdlib>
#include <complex>
#include <vector>
#include <boost/test/unit_test.hpp>

typedef std::complex<float> Cplx;
typedef std::vector<Cplx>   CplxVec;

template<class T>
void getPoints(T* real, T* imag, int numPoints)
{
  for(int i=0;i<numPoints;i++)
  {
    real[i] = 2*((T)rand()/RAND_MAX)-1;
    imag[i] = 2*((T)rand()/RAND_MAX)-1;
  }
}

template<class Iterator>
void getPoints(Iterator begin, Iterator end)
{
  for(;begin!=end;begin++)
  {
    begin->real() = 2*((double)rand()/RAND_MAX)-1;
    begin->imag() = 2*((double)rand()/RAND_MAX)-1;
  }
}

void threadMain1()
{
  Scatterplot plot;

  float real[1024];
  float imag[1024];

  for(int i=0;i<10;i++)
  {
    getPoints(real, imag, 1024);
    plot.plotNewData(real, imag, 1024);
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }
}

void threadMain2()
{
  Scatterplot plot;
  double real[1024];
  double imag[1024];

  for(int i=0;i<10;i++)
  {
    getPoints(real, imag, 1024);
    plot.plotNewData(real, imag, 1024);
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }
}

void threadMain3()
{
  Scatterplot plot;
  CplxVec v(1024);

  for(int i=0;i<10;i++)
  {
    getPoints(v.begin(), v.end());
    plot.plotNewData(v.begin(), v.end());
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }
}

BOOST_AUTO_TEST_SUITE (Scatterplot_Test)

BOOST_AUTO_TEST_CASE(Scatterplot_Basic_Test)
{
  int argc = 1;
  char* argv[] = { const_cast<char *>("Scatterplot_Basic_Test"), NULL };
  QApplication a(argc, argv);

  boost::scoped_ptr< boost::thread > thread1_;
  boost::scoped_ptr< boost::thread > thread2_;
  boost::scoped_ptr< boost::thread > thread3_;

  thread1_.reset( new boost::thread( &threadMain1 ) );
  thread2_.reset( new boost::thread( &threadMain2 ) );
  thread3_.reset( new boost::thread( &threadMain3 ) );

  qApp->exec();
}

BOOST_AUTO_TEST_SUITE_END()
