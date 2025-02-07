/*******************************************************************************
//
//  SYCL 2020 Conformance Test Suite
//
//  Provides tests for reductions with identity parameter for arithmetic
//  scalar types.
//
*******************************************************************************/
#include "../common/disabled_for_test_case.h"
#include "catch2/catch_test_macros.hpp"

// FIXME: re-enable when sycl::reduction is implemented in hipSYCL and
// ComputeCpp
#if !SYCL_CTS_COMPILING_WITH_HIPSYCL && !SYCL_CTS_COMPILING_WITH_COMPUTECPP
#include "reduction_with_identity_param.h"
#endif

namespace reduction_with_identity_param_core {

// FIXME: re-enable when sycl::reduction is implemented in hipSYCL and
// ComputeCpp
DISABLED_FOR_TEST_CASE(ComputeCpp, hipSYCL)
("reduction_with_identity_param_core", "[reduction]")({
  auto queue = sycl_cts::util::get_cts_object::queue();

  for_all_types<reduction_with_identity_param::run_test_for_type>(
      reduction_common::scalar_types, queue);
});
}  // namespace reduction_with_identity_param_core
