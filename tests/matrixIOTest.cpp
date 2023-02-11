#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Configuration.hpp"
#include "MatrixSolver.hpp"
#include "matrixIO.hpp"

using namespace Eigen;

BOOST_AUTO_TEST_SUITE(matrixIOTest)

BOOST_AUTO_TEST_CASE(openData)
{

  expected = MatrixXd(3, 3);
  expected << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;
  matrixIO::saveData("test.csv", expected);
  const Eigen::MatrixXd result = matrixIO::openData("test.csv", 3);
  BOOST_TEST(expected(0, 0) == result(0, 0));
  BOOST_TEST(expected(0, 1) == result(0, 1));
  BOOST_TEST(expected(0, 2) == result(0, 2));
  BOOST_TEST(expected(1, 0) == result(1, 0));
  BOOST_TEST(expected(1, 1) == result(1, 1));
  BOOST_TEST(expected(1, 2) == result(1, 2));
  BOOST_TEST(expected(2, 0) == result(2, 0));
  BOOST_TEST(expected(2, 1) == result(2, 1));
  BOOST_TEST(expected(2, 2) == result(2, 2));
}

BOOST_AUTO_TEST_SUITE_END()
