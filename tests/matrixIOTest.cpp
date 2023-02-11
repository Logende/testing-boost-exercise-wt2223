#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Configuration.hpp"
#include "MatrixSolver.hpp"
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(openData)
{

  auto expected = MatrixXd(3, 3);
  expected << 0, -1, 2,
      4, 100, 0,
      -3, 2, 1.5;
  auto actual = matrixIO::openData("testmatrix.csv", 3);
  BOOST_TEST(expected(0, 0) == actual(0, 0));
  BOOST_TEST(expected(0, 1) == actual(0, 1));
  BOOST_TEST(expected(0, 2) == actual(0, 2));
  BOOST_TEST(expected(1, 0) == actual(1, 0));
  BOOST_TEST(expected(1, 1) == actual(1, 1));
  BOOST_TEST(expected(1, 2) == actual(1, 2));
  BOOST_TEST(expected(2, 0) == actual(2, 0));
  BOOST_TEST(expected(2, 1) == actual(2, 1));
  BOOST_TEST(expected(2, 2) == actual(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()
