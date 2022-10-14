/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* AttrDef Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_ATTRDEF_CLASSES
#undef GET_ATTRDEF_CLASSES


namespace mlir {
class AsmParser;
class AsmPrinter;
} // namespace mlir
namespace mlir {
namespace spirv {
class CooperativeMatrixPropertiesNVAttr;
class DeviceTypeAttr;
class EntryPointABIAttr;
class ExtensionAttr;
class ResourceLimitsAttr;
class VendorAttr;
namespace detail {
struct CooperativeMatrixPropertiesNVAttrStorage;
} // namespace detail
class CooperativeMatrixPropertiesNVAttr : public ::mlir::Attribute::AttrBase<CooperativeMatrixPropertiesNVAttr, ::mlir::Attribute, detail::CooperativeMatrixPropertiesNVAttrStorage> {
public:
  using Base::Base;
public:
  static CooperativeMatrixPropertiesNVAttr get(::mlir::MLIRContext *context, int m_size, int n_size, int k_size, mlir::Type a_type, mlir::Type b_type, mlir::Type c_type, mlir::Type result_type, mlir::spirv::ScopeAttr scope);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"coop_matrix_props"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  int getMSize() const;
  int getNSize() const;
  int getKSize() const;
  mlir::Type getAType() const;
  mlir::Type getBType() const;
  mlir::Type getCType() const;
  mlir::Type getResultType() const;
  mlir::spirv::ScopeAttr getScope() const;
};
namespace detail {
struct DeviceTypeAttrStorage;
} // namespace detail
class DeviceTypeAttr : public ::mlir::Attribute::AttrBase<DeviceTypeAttr, ::mlir::Attribute, detail::DeviceTypeAttrStorage> {
public:
  using Base::Base;
public:
  static DeviceTypeAttr get(::mlir::MLIRContext *context, ::mlir::spirv::DeviceType value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"device_type"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::spirv::DeviceType getValue() const;
};
namespace detail {
struct EntryPointABIAttrStorage;
} // namespace detail
class EntryPointABIAttr : public ::mlir::Attribute::AttrBase<EntryPointABIAttr, ::mlir::Attribute, detail::EntryPointABIAttrStorage> {
public:
  using Base::Base;
public:
  static EntryPointABIAttr get(::mlir::MLIRContext *context, DenseIntElementsAttr local_size);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"entry_point_abi"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  DenseIntElementsAttr getLocalSize() const;
};
namespace detail {
struct ExtensionAttrStorage;
} // namespace detail
class ExtensionAttr : public ::mlir::Attribute::AttrBase<ExtensionAttr, ::mlir::Attribute, detail::ExtensionAttrStorage> {
public:
  using Base::Base;
public:
  static ExtensionAttr get(::mlir::MLIRContext *context, ::mlir::spirv::Extension value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"ext"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::spirv::Extension getValue() const;
};
namespace detail {
struct ResourceLimitsAttrStorage;
} // namespace detail
class ResourceLimitsAttr : public ::mlir::Attribute::AttrBase<ResourceLimitsAttr, ::mlir::Attribute, detail::ResourceLimitsAttrStorage> {
public:
  using Base::Base;
public:
  static ResourceLimitsAttr get(::mlir::MLIRContext *context, int max_compute_shared_memory_size, int max_compute_workgroup_invocations, ArrayAttr max_compute_workgroup_size, int subgroup_size, ArrayAttr cooperative_matrix_properties_nv);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"resource_limits"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  int getMaxComputeSharedMemorySize() const;
  int getMaxComputeWorkgroupInvocations() const;
  ArrayAttr getMaxComputeWorkgroupSize() const;
  int getSubgroupSize() const;
  ArrayAttr getCooperativeMatrixPropertiesNv() const;
};
namespace detail {
struct VendorAttrStorage;
} // namespace detail
class VendorAttr : public ::mlir::Attribute::AttrBase<VendorAttr, ::mlir::Attribute, detail::VendorAttrStorage> {
public:
  using Base::Base;
public:
  static VendorAttr get(::mlir::MLIRContext *context, ::mlir::spirv::Vendor value);
  static constexpr ::llvm::StringLiteral getMnemonic() {
    return {"vendor"};
  }

  static ::mlir::Attribute parse(::mlir::AsmParser &odsParser, ::mlir::Type odsType);
  void print(::mlir::AsmPrinter &odsPrinter) const;
  ::mlir::spirv::Vendor getValue() const;
};
} // namespace spirv
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::spirv::CooperativeMatrixPropertiesNVAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::spirv::DeviceTypeAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::spirv::EntryPointABIAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::spirv::ExtensionAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::spirv::ResourceLimitsAttr)
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::spirv::VendorAttr)

#endif  // GET_ATTRDEF_CLASSES

