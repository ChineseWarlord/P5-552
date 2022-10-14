/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Definitions                                                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_LIST
#undef GET_ATTRDEF_LIST

::mlir::spirv::CooperativeMatrixPropertiesNVAttr,
::mlir::spirv::DeviceTypeAttr,
::mlir::spirv::EntryPointABIAttr,
::mlir::spirv::ExtensionAttr,
::mlir::spirv::ResourceLimitsAttr,
::mlir::spirv::VendorAttr

#endif  // GET_ATTRDEF_LIST

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES

static ::mlir::OptionalParseResult generatedAttributeParser(::mlir::AsmParser &parser, ::llvm::StringRef *mnemonic, ::mlir::Type type, ::mlir::Attribute &value) {
  return ::mlir::AsmParser::KeywordSwitch<::mlir::OptionalParseResult>(parser)
    .Case(::mlir::spirv::CooperativeMatrixPropertiesNVAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::spirv::CooperativeMatrixPropertiesNVAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::spirv::DeviceTypeAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::spirv::DeviceTypeAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::spirv::EntryPointABIAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::spirv::EntryPointABIAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::spirv::ExtensionAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::spirv::ExtensionAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::spirv::ResourceLimitsAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::spirv::ResourceLimitsAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Case(::mlir::spirv::VendorAttr::getMnemonic(), [&](llvm::StringRef, llvm::SMLoc) {
      value = ::mlir::spirv::VendorAttr::parse(parser, type);
      return ::mlir::success(!!value);
    })
    .Default([&](llvm::StringRef keyword, llvm::SMLoc) {
      *mnemonic = keyword;
      return llvm::None;
    });
}

static ::mlir::LogicalResult generatedAttributePrinter(::mlir::Attribute def, ::mlir::AsmPrinter &printer) {
  return ::llvm::TypeSwitch<::mlir::Attribute, ::mlir::LogicalResult>(def)    .Case<::mlir::spirv::CooperativeMatrixPropertiesNVAttr>([&](auto t) {
      printer << ::mlir::spirv::CooperativeMatrixPropertiesNVAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::spirv::DeviceTypeAttr>([&](auto t) {
      printer << ::mlir::spirv::DeviceTypeAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::spirv::EntryPointABIAttr>([&](auto t) {
      printer << ::mlir::spirv::EntryPointABIAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::spirv::ExtensionAttr>([&](auto t) {
      printer << ::mlir::spirv::ExtensionAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::spirv::ResourceLimitsAttr>([&](auto t) {
      printer << ::mlir::spirv::ResourceLimitsAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Case<::mlir::spirv::VendorAttr>([&](auto t) {
      printer << ::mlir::spirv::VendorAttr::getMnemonic();
t.print(printer);
      return ::mlir::success();
    })
    .Default([](auto) { return ::mlir::failure(); });
}

namespace mlir {
namespace spirv {
namespace detail {
struct CooperativeMatrixPropertiesNVAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<int, int, int, mlir::Type, mlir::Type, mlir::Type, mlir::Type, mlir::spirv::ScopeAttr>;
  CooperativeMatrixPropertiesNVAttrStorage(int m_size, int n_size, int k_size, mlir::Type a_type, mlir::Type b_type, mlir::Type c_type, mlir::Type result_type, mlir::spirv::ScopeAttr scope) : ::mlir::AttributeStorage(), m_size(m_size), n_size(n_size), k_size(k_size), a_type(a_type), b_type(b_type), c_type(c_type), result_type(result_type), scope(scope) {}

  bool operator==(const KeyTy &tblgenKey) const {
    return (m_size == std::get<0>(tblgenKey)) && (n_size == std::get<1>(tblgenKey)) && (k_size == std::get<2>(tblgenKey)) && (a_type == std::get<3>(tblgenKey)) && (b_type == std::get<4>(tblgenKey)) && (c_type == std::get<5>(tblgenKey)) && (result_type == std::get<6>(tblgenKey)) && (scope == std::get<7>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey), std::get<5>(tblgenKey), std::get<6>(tblgenKey), std::get<7>(tblgenKey));
  }

  static CooperativeMatrixPropertiesNVAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto m_size = std::get<0>(tblgenKey);
    auto n_size = std::get<1>(tblgenKey);
    auto k_size = std::get<2>(tblgenKey);
    auto a_type = std::get<3>(tblgenKey);
    auto b_type = std::get<4>(tblgenKey);
    auto c_type = std::get<5>(tblgenKey);
    auto result_type = std::get<6>(tblgenKey);
    auto scope = std::get<7>(tblgenKey);
    return new (allocator.allocate<CooperativeMatrixPropertiesNVAttrStorage>()) CooperativeMatrixPropertiesNVAttrStorage(m_size, n_size, k_size, a_type, b_type, c_type, result_type, scope);
  }

  int m_size;
  int n_size;
  int k_size;
  mlir::Type a_type;
  mlir::Type b_type;
  mlir::Type c_type;
  mlir::Type result_type;
  mlir::spirv::ScopeAttr scope;
};
} // namespace detail
CooperativeMatrixPropertiesNVAttr CooperativeMatrixPropertiesNVAttr::get(::mlir::MLIRContext *context, int m_size, int n_size, int k_size, mlir::Type a_type, mlir::Type b_type, mlir::Type c_type, mlir::Type result_type, mlir::spirv::ScopeAttr scope) {
  return Base::get(context, m_size, n_size, k_size, a_type, b_type, c_type, result_type, scope);
}

::mlir::Attribute CooperativeMatrixPropertiesNVAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::mlir::FailureOr<int> _result_m_size;
  ::mlir::FailureOr<int> _result_n_size;
  ::mlir::FailureOr<int> _result_k_size;
  ::mlir::FailureOr<mlir::Type> _result_a_type;
  ::mlir::FailureOr<mlir::Type> _result_b_type;
  ::mlir::FailureOr<mlir::Type> _result_c_type;
  ::mlir::FailureOr<mlir::Type> _result_result_type;
  ::mlir::FailureOr<mlir::spirv::ScopeAttr> _result_scope;
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse parameter struct
  bool _seen_m_size = false;
  bool _seen_n_size = false;
  bool _seen_k_size = false;
  bool _seen_a_type = false;
  bool _seen_b_type = false;
  bool _seen_c_type = false;
  bool _seen_result_type = false;
  bool _seen_scope = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_m_size && _paramKey == "m_size") {
        _seen_m_size = true;

        // Parse variable 'm_size'
        _result_m_size = ::mlir::FieldParser<int>::parse(odsParser);
        if (::mlir::failed(_result_m_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'm_size' which is to be a `int`");
          return {};
        }
      } else if (!_seen_n_size && _paramKey == "n_size") {
        _seen_n_size = true;

        // Parse variable 'n_size'
        _result_n_size = ::mlir::FieldParser<int>::parse(odsParser);
        if (::mlir::failed(_result_n_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'n_size' which is to be a `int`");
          return {};
        }
      } else if (!_seen_k_size && _paramKey == "k_size") {
        _seen_k_size = true;

        // Parse variable 'k_size'
        _result_k_size = ::mlir::FieldParser<int>::parse(odsParser);
        if (::mlir::failed(_result_k_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'k_size' which is to be a `int`");
          return {};
        }
      } else if (!_seen_a_type && _paramKey == "a_type") {
        _seen_a_type = true;

        // Parse variable 'a_type'
        _result_a_type = ::mlir::FieldParser<mlir::Type>::parse(odsParser);
        if (::mlir::failed(_result_a_type)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'a_type' which is to be a `mlir::Type`");
          return {};
        }
      } else if (!_seen_b_type && _paramKey == "b_type") {
        _seen_b_type = true;

        // Parse variable 'b_type'
        _result_b_type = ::mlir::FieldParser<mlir::Type>::parse(odsParser);
        if (::mlir::failed(_result_b_type)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'b_type' which is to be a `mlir::Type`");
          return {};
        }
      } else if (!_seen_c_type && _paramKey == "c_type") {
        _seen_c_type = true;

        // Parse variable 'c_type'
        _result_c_type = ::mlir::FieldParser<mlir::Type>::parse(odsParser);
        if (::mlir::failed(_result_c_type)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'c_type' which is to be a `mlir::Type`");
          return {};
        }
      } else if (!_seen_result_type && _paramKey == "result_type") {
        _seen_result_type = true;

        // Parse variable 'result_type'
        _result_result_type = ::mlir::FieldParser<mlir::Type>::parse(odsParser);
        if (::mlir::failed(_result_result_type)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'result_type' which is to be a `mlir::Type`");
          return {};
        }
      } else if (!_seen_scope && _paramKey == "scope") {
        _seen_scope = true;

        // Parse variable 'scope'
        _result_scope = ::mlir::FieldParser<mlir::spirv::ScopeAttr>::parse(odsParser);
        if (::mlir::failed(_result_scope)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_CooperativeMatrixPropertiesNVAttr parameter 'scope' which is to be a `mlir::spirv::ScopeAttr`");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    for (unsigned odsStructIndex = 0; odsStructIndex < 8; ++odsStructIndex) {
      ::llvm::StringRef _paramKey;
      if (odsParser.parseKeyword(&_paramKey)) {
        odsParser.emitError(odsParser.getCurrentLocation(),
                           "expected a parameter name in struct");
        return {};
      }
      if (!_loop_body(_paramKey)) return {};
      if ((odsStructIndex != 8 - 1) && odsParser.parseComma())
        return {};
    }
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  assert(::mlir::succeeded(_result_m_size));
  assert(::mlir::succeeded(_result_n_size));
  assert(::mlir::succeeded(_result_k_size));
  assert(::mlir::succeeded(_result_a_type));
  assert(::mlir::succeeded(_result_b_type));
  assert(::mlir::succeeded(_result_c_type));
  assert(::mlir::succeeded(_result_result_type));
  assert(::mlir::succeeded(_result_scope));
  return CooperativeMatrixPropertiesNVAttr::get(odsParser.getContext(),
      int((*_result_m_size)),
      int((*_result_n_size)),
      int((*_result_k_size)),
      mlir::Type((*_result_a_type)),
      mlir::Type((*_result_b_type)),
      mlir::Type((*_result_c_type)),
      mlir::Type((*_result_result_type)),
      mlir::spirv::ScopeAttr((*_result_scope)));
}

void CooperativeMatrixPropertiesNVAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  {
    bool _firstPrinted = true;
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "m_size = ";
    odsPrinter.printStrippedAttrOrType(getMSize());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "n_size = ";
    odsPrinter.printStrippedAttrOrType(getNSize());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "k_size = ";
    odsPrinter.printStrippedAttrOrType(getKSize());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "a_type = ";
    odsPrinter.printStrippedAttrOrType(getAType());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "b_type = ";
    odsPrinter.printStrippedAttrOrType(getBType());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "c_type = ";
    odsPrinter.printStrippedAttrOrType(getCType());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "result_type = ";
    odsPrinter.printStrippedAttrOrType(getResultType());
    if (!_firstPrinted) odsPrinter << ", ";
    _firstPrinted = false;
    odsPrinter << "scope = ";
    odsPrinter.printStrippedAttrOrType(getScope());
  }
  odsPrinter << ">";
}

int CooperativeMatrixPropertiesNVAttr::getMSize() const {
  return getImpl()->m_size;
}

int CooperativeMatrixPropertiesNVAttr::getNSize() const {
  return getImpl()->n_size;
}

int CooperativeMatrixPropertiesNVAttr::getKSize() const {
  return getImpl()->k_size;
}

mlir::Type CooperativeMatrixPropertiesNVAttr::getAType() const {
  return getImpl()->a_type;
}

mlir::Type CooperativeMatrixPropertiesNVAttr::getBType() const {
  return getImpl()->b_type;
}

mlir::Type CooperativeMatrixPropertiesNVAttr::getCType() const {
  return getImpl()->c_type;
}

mlir::Type CooperativeMatrixPropertiesNVAttr::getResultType() const {
  return getImpl()->result_type;
}

mlir::spirv::ScopeAttr CooperativeMatrixPropertiesNVAttr::getScope() const {
  return getImpl()->scope;
}

} // namespace spirv
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::spirv::CooperativeMatrixPropertiesNVAttr)
namespace mlir {
namespace spirv {
namespace detail {
struct DeviceTypeAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::spirv::DeviceType>;
  DeviceTypeAttrStorage(::mlir::spirv::DeviceType value) : ::mlir::AttributeStorage(), value(value) {}

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static DeviceTypeAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto value = std::get<0>(tblgenKey);
    return new (allocator.allocate<DeviceTypeAttrStorage>()) DeviceTypeAttrStorage(value);
  }

  ::mlir::spirv::DeviceType value;
};
} // namespace detail
DeviceTypeAttr DeviceTypeAttr::get(::mlir::MLIRContext *context, ::mlir::spirv::DeviceType value) {
  return Base::get(context, value);
}

::mlir::Attribute DeviceTypeAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::mlir::FailureOr<::mlir::spirv::DeviceType> _result_value;
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::spirv::DeviceType> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::spirv::symbolizeDeviceType(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::mlir::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::spirv::DeviceType" << " to be one of: " << "Other" << ", " << "IntegratedGPU" << ", " << "DiscreteGPU" << ", " << "CPU" << ", " << "Unknown")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_DeviceTypeAttr parameter 'value' which is to be a `::mlir::spirv::DeviceType`");
    return {};
  }
  assert(::mlir::succeeded(_result_value));
  return DeviceTypeAttr::get(odsParser.getContext(),
      ::mlir::spirv::DeviceType((*_result_value)));
}

void DeviceTypeAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << ' ';
  odsPrinter << stringifyDeviceType(getValue());
}

::mlir::spirv::DeviceType DeviceTypeAttr::getValue() const {
  return getImpl()->value;
}

} // namespace spirv
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::spirv::DeviceTypeAttr)
namespace mlir {
namespace spirv {
namespace detail {
struct EntryPointABIAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<DenseIntElementsAttr>;
  EntryPointABIAttrStorage(DenseIntElementsAttr local_size) : ::mlir::AttributeStorage(), local_size(local_size) {}

  bool operator==(const KeyTy &tblgenKey) const {
    return (local_size == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static EntryPointABIAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto local_size = std::get<0>(tblgenKey);
    return new (allocator.allocate<EntryPointABIAttrStorage>()) EntryPointABIAttrStorage(local_size);
  }

  DenseIntElementsAttr local_size;
};
} // namespace detail
EntryPointABIAttr EntryPointABIAttr::get(::mlir::MLIRContext *context, DenseIntElementsAttr local_size) {
  return Base::get(context, local_size);
}

::mlir::Attribute EntryPointABIAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::mlir::FailureOr<DenseIntElementsAttr> _result_local_size;
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse parameter struct
  bool _seen_local_size = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_local_size && _paramKey == "local_size") {
        _seen_local_size = true;

        // Parse variable 'local_size'
        _result_local_size = ::mlir::FieldParser<DenseIntElementsAttr>::parse(odsParser);
        if (::mlir::failed(_result_local_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_EntryPointABIAttr parameter 'local_size' which is to be a `DenseIntElementsAttr`");
          return {};
        }
        if (::mlir::succeeded(_result_local_size) && !*_result_local_size) {
          odsParser.emitError(odsParser.getCurrentLocation(), "expected a value for parameter 'local_size'");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    ::llvm::StringRef _paramKey;
    if (!odsParser.parseOptionalKeyword(&_paramKey)) {
      if (!_loop_body(_paramKey)) return {};
      while (!odsParser.parseOptionalComma()) {
        ::llvm::StringRef _paramKey;
        if (odsParser.parseKeyword(&_paramKey)) {
          odsParser.emitError(odsParser.getCurrentLocation(),
                             "expected a parameter name in struct");
          return {};
        }
        if (!_loop_body(_paramKey)) return {};
      }
    }
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  return EntryPointABIAttr::get(odsParser.getContext(),
      DenseIntElementsAttr((_result_local_size.value_or(DenseIntElementsAttr()))));
}

void EntryPointABIAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  {
    bool _firstPrinted = true;
    if ((getLocalSize())) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "local_size = ";
      if ((getLocalSize())) {
        odsPrinter.printStrippedAttrOrType(getLocalSize());
      }
    }
  }
  odsPrinter << ">";
}

DenseIntElementsAttr EntryPointABIAttr::getLocalSize() const {
  return getImpl()->local_size;
}

} // namespace spirv
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::spirv::EntryPointABIAttr)
namespace mlir {
namespace spirv {
namespace detail {
struct ExtensionAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::spirv::Extension>;
  ExtensionAttrStorage(::mlir::spirv::Extension value) : ::mlir::AttributeStorage(), value(value) {}

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static ExtensionAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto value = std::get<0>(tblgenKey);
    return new (allocator.allocate<ExtensionAttrStorage>()) ExtensionAttrStorage(value);
  }

  ::mlir::spirv::Extension value;
};
} // namespace detail
ExtensionAttr ExtensionAttr::get(::mlir::MLIRContext *context, ::mlir::spirv::Extension value) {
  return Base::get(context, value);
}

::mlir::Attribute ExtensionAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::mlir::FailureOr<::mlir::spirv::Extension> _result_value;
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::spirv::Extension> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::spirv::symbolizeExtension(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::mlir::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::spirv::Extension" << " to be one of: " << "SPV_KHR_16bit_storage" << ", " << "SPV_KHR_8bit_storage" << ", " << "SPV_KHR_device_group" << ", " << "SPV_KHR_float_controls" << ", " << "SPV_KHR_physical_storage_buffer" << ", " << "SPV_KHR_multiview" << ", " << "SPV_KHR_no_integer_wrap_decoration" << ", " << "SPV_KHR_post_depth_coverage" << ", " << "SPV_KHR_shader_atomic_counter_ops" << ", " << "SPV_KHR_shader_ballot" << ", " << "SPV_KHR_shader_clock" << ", " << "SPV_KHR_shader_draw_parameters" << ", " << "SPV_KHR_storage_buffer_storage_class" << ", " << "SPV_KHR_subgroup_vote" << ", " << "SPV_KHR_variable_pointers" << ", " << "SPV_KHR_vulkan_memory_model" << ", " << "SPV_KHR_expect_assume" << ", " << "SPV_KHR_integer_dot_product" << ", " << "SPV_KHR_bit_instructions" << ", " << "SPV_KHR_fragment_shading_rate" << ", " << "SPV_KHR_workgroup_memory_explicit_layout" << ", " << "SPV_KHR_ray_query" << ", " << "SPV_KHR_ray_tracing" << ", " << "SPV_KHR_subgroup_uniform_control_flow" << ", " << "SPV_KHR_linkonce_odr" << ", " << "SPV_EXT_demote_to_helper_invocation" << ", " << "SPV_EXT_descriptor_indexing" << ", " << "SPV_EXT_fragment_fully_covered" << ", " << "SPV_EXT_fragment_invocation_density" << ", " << "SPV_EXT_fragment_shader_interlock" << ", " << "SPV_EXT_physical_storage_buffer" << ", " << "SPV_EXT_shader_stencil_export" << ", " << "SPV_EXT_shader_viewport_index_layer" << ", " << "SPV_EXT_shader_atomic_float_add" << ", " << "SPV_EXT_shader_atomic_float_min_max" << ", " << "SPV_EXT_shader_image_int64" << ", " << "SPV_EXT_shader_atomic_float16_add" << ", " << "SPV_AMD_gpu_shader_half_float_fetch" << ", " << "SPV_AMD_shader_ballot" << ", " << "SPV_AMD_shader_explicit_vertex_parameter" << ", " << "SPV_AMD_shader_fragment_mask" << ", " << "SPV_AMD_shader_image_load_store_lod" << ", " << "SPV_AMD_texture_gather_bias_lod" << ", " << "SPV_GOOGLE_decorate_string" << ", " << "SPV_GOOGLE_hlsl_functionality1" << ", " << "SPV_GOOGLE_user_type" << ", " << "SPV_INTEL_device_side_avc_motion_estimation" << ", " << "SPV_INTEL_media_block_io" << ", " << "SPV_INTEL_shader_integer_functions2" << ", " << "SPV_INTEL_subgroups" << ", " << "SPV_INTEL_vector_compute" << ", " << "SPV_INTEL_float_controls2" << ", " << "SPV_INTEL_function_pointers" << ", " << "SPV_INTEL_inline_assembly" << ", " << "SPV_INTEL_variable_length_array" << ", " << "SPV_INTEL_fpga_memory_attributes" << ", " << "SPV_INTEL_unstructured_loop_controls" << ", " << "SPV_INTEL_fpga_loop_controls" << ", " << "SPV_INTEL_arbitrary_precision_integers" << ", " << "SPV_INTEL_arbitrary_precision_floating_point" << ", " << "SPV_INTEL_kernel_attributes" << ", " << "SPV_INTEL_fpga_memory_accesses" << ", " << "SPV_INTEL_fpga_cluster_attributes" << ", " << "SPV_INTEL_loop_fuse" << ", " << "SPV_INTEL_fpga_buffer_location" << ", " << "SPV_INTEL_arbitrary_precision_fixed_point" << ", " << "SPV_INTEL_usm_storage_classes" << ", " << "SPV_INTEL_io_pipes" << ", " << "SPV_INTEL_blocking_pipes" << ", " << "SPV_INTEL_fpga_reg" << ", " << "SPV_INTEL_long_constant_composite" << ", " << "SPV_INTEL_optnone" << ", " << "SPV_INTEL_debug_module" << ", " << "SPV_INTEL_fp_fast_math_mode" << ", " << "SPV_NV_compute_shader_derivatives" << ", " << "SPV_NV_cooperative_matrix" << ", " << "SPV_NV_fragment_shader_barycentric" << ", " << "SPV_NV_geometry_shader_passthrough" << ", " << "SPV_NV_mesh_shader" << ", " << "SPV_NV_ray_tracing" << ", " << "SPV_NV_sample_mask_override_coverage" << ", " << "SPV_NV_shader_image_footprint" << ", " << "SPV_NV_shader_sm_builtins" << ", " << "SPV_NV_shader_subgroup_partitioned" << ", " << "SPV_NV_shading_rate" << ", " << "SPV_NV_stereo_view_rendering" << ", " << "SPV_NV_viewport_array2" << ", " << "SPV_NV_bindless_texture" << ", " << "SPV_NV_ray_tracing_motion_blur" << ", " << "SPV_NVX_multiview_per_view_attributes")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_ExtensionAttr parameter 'value' which is to be a `::mlir::spirv::Extension`");
    return {};
  }
  assert(::mlir::succeeded(_result_value));
  return ExtensionAttr::get(odsParser.getContext(),
      ::mlir::spirv::Extension((*_result_value)));
}

void ExtensionAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << ' ';
  odsPrinter << stringifyExtension(getValue());
}

::mlir::spirv::Extension ExtensionAttr::getValue() const {
  return getImpl()->value;
}

} // namespace spirv
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::spirv::ExtensionAttr)
namespace mlir {
namespace spirv {
namespace detail {
struct ResourceLimitsAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<int, int, ArrayAttr, int, ArrayAttr>;
  ResourceLimitsAttrStorage(int max_compute_shared_memory_size, int max_compute_workgroup_invocations, ArrayAttr max_compute_workgroup_size, int subgroup_size, ArrayAttr cooperative_matrix_properties_nv) : ::mlir::AttributeStorage(), max_compute_shared_memory_size(max_compute_shared_memory_size), max_compute_workgroup_invocations(max_compute_workgroup_invocations), max_compute_workgroup_size(max_compute_workgroup_size), subgroup_size(subgroup_size), cooperative_matrix_properties_nv(cooperative_matrix_properties_nv) {}

  bool operator==(const KeyTy &tblgenKey) const {
    return (max_compute_shared_memory_size == std::get<0>(tblgenKey)) && (max_compute_workgroup_invocations == std::get<1>(tblgenKey)) && (max_compute_workgroup_size == std::get<2>(tblgenKey)) && (subgroup_size == std::get<3>(tblgenKey)) && (cooperative_matrix_properties_nv == std::get<4>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey), std::get<1>(tblgenKey), std::get<2>(tblgenKey), std::get<3>(tblgenKey), std::get<4>(tblgenKey));
  }

  static ResourceLimitsAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto max_compute_shared_memory_size = std::get<0>(tblgenKey);
    auto max_compute_workgroup_invocations = std::get<1>(tblgenKey);
    auto max_compute_workgroup_size = std::get<2>(tblgenKey);
    auto subgroup_size = std::get<3>(tblgenKey);
    auto cooperative_matrix_properties_nv = std::get<4>(tblgenKey);
    return new (allocator.allocate<ResourceLimitsAttrStorage>()) ResourceLimitsAttrStorage(max_compute_shared_memory_size, max_compute_workgroup_invocations, max_compute_workgroup_size, subgroup_size, cooperative_matrix_properties_nv);
  }

  int max_compute_shared_memory_size;
  int max_compute_workgroup_invocations;
  ArrayAttr max_compute_workgroup_size;
  int subgroup_size;
  ArrayAttr cooperative_matrix_properties_nv;
};
} // namespace detail
ResourceLimitsAttr ResourceLimitsAttr::get(::mlir::MLIRContext *context, int max_compute_shared_memory_size, int max_compute_workgroup_invocations, ArrayAttr max_compute_workgroup_size, int subgroup_size, ArrayAttr cooperative_matrix_properties_nv) {
  return Base::get(context, max_compute_shared_memory_size, max_compute_workgroup_invocations, max_compute_workgroup_size, subgroup_size, cooperative_matrix_properties_nv);
}

::mlir::Attribute ResourceLimitsAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::mlir::FailureOr<int> _result_max_compute_shared_memory_size;
  ::mlir::FailureOr<int> _result_max_compute_workgroup_invocations;
  ::mlir::FailureOr<ArrayAttr> _result_max_compute_workgroup_size;
  ::mlir::FailureOr<int> _result_subgroup_size;
  ::mlir::FailureOr<ArrayAttr> _result_cooperative_matrix_properties_nv;
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;
  // Parse literal '<'
  if (odsParser.parseLess()) return {};
  // Parse parameter struct
  bool _seen_max_compute_shared_memory_size = false;
  bool _seen_max_compute_workgroup_invocations = false;
  bool _seen_max_compute_workgroup_size = false;
  bool _seen_subgroup_size = false;
  bool _seen_cooperative_matrix_properties_nv = false;
  {
    const auto _loop_body = [&](::llvm::StringRef _paramKey) -> bool {
      // Parse literal '='
      if (odsParser.parseEqual()) return {};
      if (!_seen_max_compute_shared_memory_size && _paramKey == "max_compute_shared_memory_size") {
        _seen_max_compute_shared_memory_size = true;

        // Parse variable 'max_compute_shared_memory_size'
        _result_max_compute_shared_memory_size = ::mlir::FieldParser<int>::parse(odsParser);
        if (::mlir::failed(_result_max_compute_shared_memory_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_ResourceLimitsAttr parameter 'max_compute_shared_memory_size' which is to be a `int`");
          return {};
        }
        if (::mlir::succeeded(_result_max_compute_shared_memory_size) && !*_result_max_compute_shared_memory_size) {
          odsParser.emitError(odsParser.getCurrentLocation(), "expected a value for parameter 'max_compute_shared_memory_size'");
          return {};
        }
      } else if (!_seen_max_compute_workgroup_invocations && _paramKey == "max_compute_workgroup_invocations") {
        _seen_max_compute_workgroup_invocations = true;

        // Parse variable 'max_compute_workgroup_invocations'
        _result_max_compute_workgroup_invocations = ::mlir::FieldParser<int>::parse(odsParser);
        if (::mlir::failed(_result_max_compute_workgroup_invocations)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_ResourceLimitsAttr parameter 'max_compute_workgroup_invocations' which is to be a `int`");
          return {};
        }
        if (::mlir::succeeded(_result_max_compute_workgroup_invocations) && !*_result_max_compute_workgroup_invocations) {
          odsParser.emitError(odsParser.getCurrentLocation(), "expected a value for parameter 'max_compute_workgroup_invocations'");
          return {};
        }
      } else if (!_seen_max_compute_workgroup_size && _paramKey == "max_compute_workgroup_size") {
        _seen_max_compute_workgroup_size = true;

        // Parse variable 'max_compute_workgroup_size'
        _result_max_compute_workgroup_size = ::mlir::FieldParser<ArrayAttr>::parse(odsParser);
        if (::mlir::failed(_result_max_compute_workgroup_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_ResourceLimitsAttr parameter 'max_compute_workgroup_size' which is to be a `ArrayAttr`");
          return {};
        }
        if (::mlir::succeeded(_result_max_compute_workgroup_size) && !*_result_max_compute_workgroup_size) {
          odsParser.emitError(odsParser.getCurrentLocation(), "expected a value for parameter 'max_compute_workgroup_size'");
          return {};
        }
      } else if (!_seen_subgroup_size && _paramKey == "subgroup_size") {
        _seen_subgroup_size = true;

        // Parse variable 'subgroup_size'
        _result_subgroup_size = ::mlir::FieldParser<int>::parse(odsParser);
        if (::mlir::failed(_result_subgroup_size)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_ResourceLimitsAttr parameter 'subgroup_size' which is to be a `int`");
          return {};
        }
        if (::mlir::succeeded(_result_subgroup_size) && !*_result_subgroup_size) {
          odsParser.emitError(odsParser.getCurrentLocation(), "expected a value for parameter 'subgroup_size'");
          return {};
        }
      } else if (!_seen_cooperative_matrix_properties_nv && _paramKey == "cooperative_matrix_properties_nv") {
        _seen_cooperative_matrix_properties_nv = true;

        // Parse variable 'cooperative_matrix_properties_nv'
        _result_cooperative_matrix_properties_nv = ::mlir::FieldParser<ArrayAttr>::parse(odsParser);
        if (::mlir::failed(_result_cooperative_matrix_properties_nv)) {
          odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_ResourceLimitsAttr parameter 'cooperative_matrix_properties_nv' which is to be a `ArrayAttr`");
          return {};
        }
        if (::mlir::succeeded(_result_cooperative_matrix_properties_nv) && !*_result_cooperative_matrix_properties_nv) {
          odsParser.emitError(odsParser.getCurrentLocation(), "expected a value for parameter 'cooperative_matrix_properties_nv'");
          return {};
        }
      } else {
        odsParser.emitError(odsParser.getCurrentLocation(), "duplicate or unknown struct parameter name: ") << _paramKey;
        return {};
      }
      return true;
    };
    ::llvm::StringRef _paramKey;
    if (!odsParser.parseOptionalKeyword(&_paramKey)) {
      if (!_loop_body(_paramKey)) return {};
      while (!odsParser.parseOptionalComma()) {
        ::llvm::StringRef _paramKey;
        if (odsParser.parseKeyword(&_paramKey)) {
          odsParser.emitError(odsParser.getCurrentLocation(),
                             "expected a parameter name in struct");
          return {};
        }
        if (!_loop_body(_paramKey)) return {};
      }
    }
  }
  // Parse literal '>'
  if (odsParser.parseGreater()) return {};
  return ResourceLimitsAttr::get(odsParser.getContext(),
      int((_result_max_compute_shared_memory_size.value_or(16384))),
      int((_result_max_compute_workgroup_invocations.value_or(128))),
      ArrayAttr((_result_max_compute_workgroup_size.value_or(odsBuilder.getI32ArrayAttr({128, 128, 64})))),
      int((_result_subgroup_size.value_or(32))),
      ArrayAttr((_result_cooperative_matrix_properties_nv.value_or(nullptr))));
}

void ResourceLimitsAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << "<";
  {
    bool _firstPrinted = true;
    if ((getMaxComputeSharedMemorySize() && !(getMaxComputeSharedMemorySize() == 16384))) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "max_compute_shared_memory_size = ";
      if ((getMaxComputeSharedMemorySize() && !(getMaxComputeSharedMemorySize() == 16384))) {
        odsPrinter.printStrippedAttrOrType(getMaxComputeSharedMemorySize());
      }
    }
    if ((getMaxComputeWorkgroupInvocations() && !(getMaxComputeWorkgroupInvocations() == 128))) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "max_compute_workgroup_invocations = ";
      if ((getMaxComputeWorkgroupInvocations() && !(getMaxComputeWorkgroupInvocations() == 128))) {
        odsPrinter.printStrippedAttrOrType(getMaxComputeWorkgroupInvocations());
      }
    }
    if ((getMaxComputeWorkgroupSize() && !(getMaxComputeWorkgroupSize() == odsBuilder.getI32ArrayAttr({128, 128, 64})))) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "max_compute_workgroup_size = ";
      if ((getMaxComputeWorkgroupSize() && !(getMaxComputeWorkgroupSize() == odsBuilder.getI32ArrayAttr({128, 128, 64})))) {
        odsPrinter.printStrippedAttrOrType(getMaxComputeWorkgroupSize());
      }
    }
    if ((getSubgroupSize() && !(getSubgroupSize() == 32))) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "subgroup_size = ";
      if ((getSubgroupSize() && !(getSubgroupSize() == 32))) {
        odsPrinter.printStrippedAttrOrType(getSubgroupSize());
      }
    }
    if ((getCooperativeMatrixPropertiesNv() && !(getCooperativeMatrixPropertiesNv() == nullptr))) {
      if (!_firstPrinted) odsPrinter << ", ";
      _firstPrinted = false;
      odsPrinter << "cooperative_matrix_properties_nv = ";
      if ((getCooperativeMatrixPropertiesNv() && !(getCooperativeMatrixPropertiesNv() == nullptr))) {
        odsPrinter.printStrippedAttrOrType(getCooperativeMatrixPropertiesNv());
      }
    }
  }
  odsPrinter << ">";
}

int ResourceLimitsAttr::getMaxComputeSharedMemorySize() const {
  return getImpl()->max_compute_shared_memory_size;
}

int ResourceLimitsAttr::getMaxComputeWorkgroupInvocations() const {
  return getImpl()->max_compute_workgroup_invocations;
}

ArrayAttr ResourceLimitsAttr::getMaxComputeWorkgroupSize() const {
  return getImpl()->max_compute_workgroup_size;
}

int ResourceLimitsAttr::getSubgroupSize() const {
  return getImpl()->subgroup_size;
}

ArrayAttr ResourceLimitsAttr::getCooperativeMatrixPropertiesNv() const {
  return getImpl()->cooperative_matrix_properties_nv;
}

} // namespace spirv
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::spirv::ResourceLimitsAttr)
namespace mlir {
namespace spirv {
namespace detail {
struct VendorAttrStorage : public ::mlir::AttributeStorage {
  using KeyTy = std::tuple<::mlir::spirv::Vendor>;
  VendorAttrStorage(::mlir::spirv::Vendor value) : ::mlir::AttributeStorage(), value(value) {}

  bool operator==(const KeyTy &tblgenKey) const {
    return (value == std::get<0>(tblgenKey));
  }

  static ::llvm::hash_code hashKey(const KeyTy &tblgenKey) {
    return ::llvm::hash_combine(std::get<0>(tblgenKey));
  }

  static VendorAttrStorage *construct(::mlir::AttributeStorageAllocator &allocator, const KeyTy &tblgenKey) {
    auto value = std::get<0>(tblgenKey);
    return new (allocator.allocate<VendorAttrStorage>()) VendorAttrStorage(value);
  }

  ::mlir::spirv::Vendor value;
};
} // namespace detail
VendorAttr VendorAttr::get(::mlir::MLIRContext *context, ::mlir::spirv::Vendor value) {
  return Base::get(context, value);
}

::mlir::Attribute VendorAttr::parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType) {
  ::mlir::Builder odsBuilder(odsParser.getContext());
  ::mlir::FailureOr<::mlir::spirv::Vendor> _result_value;
  ::llvm::SMLoc odsLoc = odsParser.getCurrentLocation();
  (void) odsLoc;

  // Parse variable 'value'
  _result_value = [&]() -> ::mlir::FailureOr<::mlir::spirv::Vendor> {
      auto loc = odsParser.getCurrentLocation();
      ::llvm::StringRef enumKeyword;
      if (::mlir::failed(odsParser.parseKeyword(&enumKeyword)))
        return ::mlir::failure();
      auto maybeEnum = ::mlir::spirv::symbolizeVendor(enumKeyword);
      if (maybeEnum)
        return *maybeEnum;
      return {(::mlir::LogicalResult)(odsParser.emitError(loc) << "expected " << "::mlir::spirv::Vendor" << " to be one of: " << "AMD" << ", " << "Apple" << ", " << "ARM" << ", " << "Imagination" << ", " << "Intel" << ", " << "NVIDIA" << ", " << "Qualcomm" << ", " << "SwiftShader" << ", " << "Unknown")};
    }();
  if (::mlir::failed(_result_value)) {
    odsParser.emitError(odsParser.getCurrentLocation(), "failed to parse SPV_VendorAttr parameter 'value' which is to be a `::mlir::spirv::Vendor`");
    return {};
  }
  assert(::mlir::succeeded(_result_value));
  return VendorAttr::get(odsParser.getContext(),
      ::mlir::spirv::Vendor((*_result_value)));
}

void VendorAttr::print(::mlir::AsmPrinter &odsPrinter) const {
  ::mlir::Builder odsBuilder(getContext());
  odsPrinter << ' ';
  odsPrinter << stringifyVendor(getValue());
}

::mlir::spirv::Vendor VendorAttr::getValue() const {
  return getImpl()->value;
}

} // namespace spirv
} // namespace mlir
MLIR_DEFINE_EXPLICIT_TYPE_ID(::mlir::spirv::VendorAttr)

#endif  // GET_ATTRDEF_CLASSES

