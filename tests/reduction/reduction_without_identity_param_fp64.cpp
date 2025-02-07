/*******************************************************************************
//
//  SYCL 2020 Conformance Test Suite
//
//  Provides tests for interaction reductions with double variable type without
//  identity param.
//
*******************************************************************************/
#include "../common/disabled_for_test_case.h"
#include "catch2/catch_test_macros.hpp"

// FIXME: re-enable when sycl::reduction is implemented in hipSYCL and
// ComputeCpp
#if !SYCL_CTS_COMPILING_WITH_HIPSYCL && !SYCL_CTS_COMPILING_WITH_COMPUTECPP
#include "reduction_without_identity_param_common.h"
#endif

namespace reduction_without_identity_param_fp64 {

// FIXME: re-enable when compilation failure for reduction with custom type is
// fixed and sycl::reduction is implemented in hipSYCL and ComputeCpp
DISABLED_FOR_TEST_CASE(ComputeCpp, hipSYCL)
("reduction_without_identity_param", "[reduction]")({
  using namespace reduction_without_identity_param_common;

  auto queue = sycl_cts::util::get_cts_object::queue();

  if (!queue.get_device().has(sycl::aspect::fp64)) {
    SKIP("Device does not support double precision floating point operations");
  }

  run_tests_for_all_functors<double, run_test_without_property>()(
      reduction_common::range, queue, "double");
  run_tests_for_all_functors<double, run_test_without_property>()(
      reduction_common::nd_range, queue, "double");
  run_tests_for_all_functors<double, run_test_with_property>()(
      reduction_common::range, queue, "double");
  run_tests_for_all_functors<double, run_test_with_property>()(
      reduction_common::nd_range, queue, "double");
});

}  // namespace reduction_without_identity_param_fp64
