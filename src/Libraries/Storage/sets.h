#pragma once

#include "Storage/genericcontainer.h"

#include "Support/noncopyable.h"

#include <string>
#include <unordered_set>

namespace okts {
namespace stor {

class Sets : public GenericContainer<std::unordered_set<std::string>>
{
  using Container = std::unordered_set<std::string>;
  using Base      = GenericContainer<Container>;

 public:
  DISABLE_EVIL_CONSTRUCTOR(Sets);

  size_t add(const std::string&                   aName,
             const std::vector<std::string_view>& aValues);

  size_t cardinality(const std::string& aName);

  std::unordered_set<std::string>
  diff(const std::vector<std::string_view>& aNames);

  Sets();
};

} // namespace stor
} // namespace okts