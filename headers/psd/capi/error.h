
#pragma once

#ifdef __cplusplus
#include <exception>
#include <cstdlib>

namespace PSD::capi {
extern "C" {
#endif

typedef struct {
  const int   status;
  const char *message;
} psd_error;

#ifdef __cplusplus
} // extern "C"
namespace detail {
namespace {

template <typename F>
psd_error HandleError(F function) {
  try {
    function();
  } catch(const std::exception &error) {
    return psd_error{EXIT_FAILURE, error.what()};
  }
  return psd_error{EXIT_SUCCESS, nullptr};
}
} // namespace
} // namespace detail
} // namespace PSD::capi
#endif
