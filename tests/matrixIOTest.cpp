#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Configuration.hpp"
#include "MatrixSolver.hpp"
#include "matrixIO.hpp"

BOOST_AUTO_TEST_SUITE(matrixIOTest)

BOOST_AUTO_TEST_CASE(openData)
{

  A = MatrixXd(3, 3);
  A << 1, 2, 3,
      4, 5, 6,
      7, 8, 9;
  matrixIO::saveData("test.csv", A);
  const Eigen::MatrixXd result = matrixIO::openData("test.csv", 3);

  BOOST_TEST(A == result);
}

BOOST_AUTO_TEST_SUITE_END()
