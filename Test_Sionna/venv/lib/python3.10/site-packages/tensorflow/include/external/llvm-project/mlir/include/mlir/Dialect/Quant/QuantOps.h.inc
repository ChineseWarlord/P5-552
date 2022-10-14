/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#if defined(GET_OP_CLASSES) || defined(GET_OP_FWD_DEFINES)
#undef GET_OP_FWD_DEFINES
namespace mlir {
namespace quant {
class ConstFakeQuant;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class ConstFakeQuantPerAxis;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class CoupledRefOp;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class DequantizeCastOp;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class QuantizeCastOp;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class QuantizeRegionOp;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class ReturnOp;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class StatisticsOp;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class StatisticsRefOp;
} // namespace quant
} // namespace mlir
namespace mlir {
namespace quant {
class StorageCastOp;
} // namespace quant
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::ConstFakeQuant declarations
//===----------------------------------------------------------------------===//

class ConstFakeQuantAdaptor {
public:
  ConstFakeQuantAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ConstFakeQuantAdaptor(ConstFakeQuant op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getInputs();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::FloatAttr getMinAttr();
  ::llvm::APFloat getMin();
  ::mlir::FloatAttr getMaxAttr();
  ::llvm::APFloat getMax();
  ::mlir::IntegerAttr getNumBitsAttr();
  uint64_t getNumBits();
  ::mlir::BoolAttr getNarrowRangeAttr();
  bool getNarrowRange();
  ::mlir::BoolAttr getIsSignedAttr();
  bool getIsSigned();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ConstFakeQuant : public ::mlir::Op<ConstFakeQuant, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ConstFakeQuantAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("is_signed"), ::llvm::StringRef("max"), ::llvm::StringRef("min"), ::llvm::StringRef("narrow_range"), ::llvm::StringRef("num_bits")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getIsSignedAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getIsSignedAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getMaxAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getMaxAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getMinAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getMinAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getNarrowRangeAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getNarrowRangeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr getNumBitsAttrName() {
    return getAttributeNameForIndex(4);
  }

  static ::mlir::StringAttr getNumBitsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 4);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.const_fake_quant");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getInputs();
  ::mlir::MutableOperandRange getInputsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getOutputs();
  ::mlir::FloatAttr getMinAttr();
  ::llvm::APFloat getMin();
  ::mlir::FloatAttr getMaxAttr();
  ::llvm::APFloat getMax();
  ::mlir::IntegerAttr getNumBitsAttr();
  uint64_t getNumBits();
  ::mlir::BoolAttr getNarrowRangeAttr();
  bool getNarrowRange();
  ::mlir::BoolAttr getIsSignedAttr();
  bool getIsSigned();
  void setMinAttr(::mlir::FloatAttr attr);
  void setMaxAttr(::mlir::FloatAttr attr);
  void setNumBitsAttr(::mlir::IntegerAttr attr);
  void setNarrowRangeAttr(::mlir::BoolAttr attr);
  void setIsSignedAttr(::mlir::BoolAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type outputs, ::mlir::Value inputs, ::mlir::FloatAttr min, ::mlir::FloatAttr max, ::mlir::IntegerAttr num_bits, ::mlir::BoolAttr narrow_range, ::mlir::BoolAttr is_signed);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value inputs, ::mlir::FloatAttr min, ::mlir::FloatAttr max, ::mlir::IntegerAttr num_bits, ::mlir::BoolAttr narrow_range, ::mlir::BoolAttr is_signed);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value inputs, ::mlir::FloatAttr min, ::mlir::FloatAttr max, ::mlir::IntegerAttr num_bits, ::mlir::BoolAttr narrow_range, ::mlir::BoolAttr is_signed);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type outputs, ::mlir::Value inputs, ::llvm::APFloat min, ::llvm::APFloat max, uint64_t num_bits, bool narrow_range = false, bool is_signed = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value inputs, ::llvm::APFloat min, ::llvm::APFloat max, uint64_t num_bits, bool narrow_range = false, bool is_signed = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value inputs, ::llvm::APFloat min, ::llvm::APFloat max, uint64_t num_bits, bool narrow_range = false, bool is_signed = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultAttrs(const ::mlir::RegisteredOperationName &opName, ::mlir::NamedAttrList &attributes);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 5 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::ConstFakeQuant)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::ConstFakeQuantPerAxis declarations
//===----------------------------------------------------------------------===//

class ConstFakeQuantPerAxisAdaptor {
public:
  ConstFakeQuantPerAxisAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ConstFakeQuantPerAxisAdaptor(ConstFakeQuantPerAxis op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getInputs();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getMinAttr();
  ::mlir::ArrayAttr getMin();
  ::mlir::ArrayAttr getMaxAttr();
  ::mlir::ArrayAttr getMax();
  ::mlir::IntegerAttr getAxisAttr();
  uint64_t getAxis();
  ::mlir::IntegerAttr getNumBitsAttr();
  uint64_t getNumBits();
  ::mlir::BoolAttr getNarrowRangeAttr();
  bool getNarrowRange();
  ::mlir::BoolAttr getIsSignedAttr();
  bool getIsSigned();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ConstFakeQuantPerAxis : public ::mlir::Op<ConstFakeQuantPerAxis, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ConstFakeQuantPerAxisAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("axis"), ::llvm::StringRef("is_signed"), ::llvm::StringRef("max"), ::llvm::StringRef("min"), ::llvm::StringRef("narrow_range"), ::llvm::StringRef("num_bits")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getAxisAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getAxisAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getIsSignedAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getIsSignedAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getMaxAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getMaxAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getMinAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getMinAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr getNarrowRangeAttrName() {
    return getAttributeNameForIndex(4);
  }

  static ::mlir::StringAttr getNarrowRangeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 4);
  }

  ::mlir::StringAttr getNumBitsAttrName() {
    return getAttributeNameForIndex(5);
  }

  static ::mlir::StringAttr getNumBitsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 5);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.const_fake_quant_per_axis");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getInputs();
  ::mlir::MutableOperandRange getInputsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getOutputs();
  ::mlir::ArrayAttr getMinAttr();
  ::mlir::ArrayAttr getMin();
  ::mlir::ArrayAttr getMaxAttr();
  ::mlir::ArrayAttr getMax();
  ::mlir::IntegerAttr getAxisAttr();
  uint64_t getAxis();
  ::mlir::IntegerAttr getNumBitsAttr();
  uint64_t getNumBits();
  ::mlir::BoolAttr getNarrowRangeAttr();
  bool getNarrowRange();
  ::mlir::BoolAttr getIsSignedAttr();
  bool getIsSigned();
  void setMinAttr(::mlir::ArrayAttr attr);
  void setMaxAttr(::mlir::ArrayAttr attr);
  void setAxisAttr(::mlir::IntegerAttr attr);
  void setNumBitsAttr(::mlir::IntegerAttr attr);
  void setNarrowRangeAttr(::mlir::BoolAttr attr);
  void setIsSignedAttr(::mlir::BoolAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type outputs, ::mlir::Value inputs, ::mlir::ArrayAttr min, ::mlir::ArrayAttr max, ::mlir::IntegerAttr axis, ::mlir::IntegerAttr num_bits, ::mlir::BoolAttr narrow_range, ::mlir::BoolAttr is_signed);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value inputs, ::mlir::ArrayAttr min, ::mlir::ArrayAttr max, ::mlir::IntegerAttr axis, ::mlir::IntegerAttr num_bits, ::mlir::BoolAttr narrow_range, ::mlir::BoolAttr is_signed);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value inputs, ::mlir::ArrayAttr min, ::mlir::ArrayAttr max, ::mlir::IntegerAttr axis, ::mlir::IntegerAttr num_bits, ::mlir::BoolAttr narrow_range, ::mlir::BoolAttr is_signed);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type outputs, ::mlir::Value inputs, ::mlir::ArrayAttr min, ::mlir::ArrayAttr max, uint64_t axis, uint64_t num_bits, bool narrow_range = false, bool is_signed = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value inputs, ::mlir::ArrayAttr min, ::mlir::ArrayAttr max, uint64_t axis, uint64_t num_bits, bool narrow_range = false, bool is_signed = false);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value inputs, ::mlir::ArrayAttr min, ::mlir::ArrayAttr max, uint64_t axis, uint64_t num_bits, bool narrow_range = false, bool is_signed = false);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void populateDefaultAttrs(const ::mlir::RegisteredOperationName &opName, ::mlir::NamedAttrList &attributes);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 6 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::ConstFakeQuantPerAxis)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::CoupledRefOp declarations
//===----------------------------------------------------------------------===//

class CoupledRefOpAdaptor {
public:
  CoupledRefOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  CoupledRefOpAdaptor(CoupledRefOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::StringAttr getCoupledKeyAttr();
  ::llvm::StringRef getCoupledKey();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class CoupledRefOp : public ::mlir::Op<CoupledRefOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = CoupledRefOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("coupledKey")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getCoupledKeyAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getCoupledKeyAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.coupled_ref");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::MutableOperandRange getArgMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::StringAttr getCoupledKeyAttr();
  ::llvm::StringRef getCoupledKey();
  void setCoupledKeyAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg, ::mlir::StringAttr coupledKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value arg, ::mlir::StringAttr coupledKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg, ::mlir::StringAttr coupledKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg, ::llvm::StringRef coupledKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value arg, ::llvm::StringRef coupledKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg, ::llvm::StringRef coupledKey);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::CoupledRefOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::DequantizeCastOp declarations
//===----------------------------------------------------------------------===//

class DequantizeCastOpAdaptor {
public:
  DequantizeCastOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  DequantizeCastOpAdaptor(DequantizeCastOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class DequantizeCastOp : public ::mlir::Op<DequantizeCastOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DequantizeCastOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.dcast");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::MutableOperandRange getArgMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::DequantizeCastOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::QuantizeCastOp declarations
//===----------------------------------------------------------------------===//

class QuantizeCastOpAdaptor {
public:
  QuantizeCastOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  QuantizeCastOpAdaptor(QuantizeCastOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class QuantizeCastOp : public ::mlir::Op<QuantizeCastOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = QuantizeCastOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.qcast");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::MutableOperandRange getArgMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::QuantizeCastOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::QuantizeRegionOp declarations
//===----------------------------------------------------------------------===//

class QuantizeRegionOpAdaptor {
public:
  QuantizeRegionOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  QuantizeRegionOpAdaptor(QuantizeRegionOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange getInputs();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getInputSpecsAttr();
  ::mlir::ArrayAttr getInputSpecs();
  ::mlir::ArrayAttr getOutputSpecsAttr();
  ::mlir::ArrayAttr getOutputSpecs();
  ::mlir::StringAttr getLogicalKernelAttr();
  ::llvm::StringRef getLogicalKernel();
  ::mlir::RegionRange getRegions();
  ::mlir::Region &getBody();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class QuantizeRegionOp : public ::mlir::Op<QuantizeRegionOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::SingleBlockImplicitTerminator<ReturnOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::IsIsolatedFromAbove> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = QuantizeRegionOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("input_specs"), ::llvm::StringRef("logical_kernel"), ::llvm::StringRef("output_specs")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getInputSpecsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getInputSpecsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getLogicalKernelAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getLogicalKernelAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getOutputSpecsAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getOutputSpecsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.region");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range getInputs();
  ::mlir::MutableOperandRange getInputsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range getOutputs();
  ::mlir::Region &getBody();
  ::mlir::ArrayAttr getInputSpecsAttr();
  ::mlir::ArrayAttr getInputSpecs();
  ::mlir::ArrayAttr getOutputSpecsAttr();
  ::mlir::ArrayAttr getOutputSpecs();
  ::mlir::StringAttr getLogicalKernelAttr();
  ::llvm::StringRef getLogicalKernel();
  void setInputSpecsAttr(::mlir::ArrayAttr attr);
  void setOutputSpecsAttr(::mlir::ArrayAttr attr);
  void setLogicalKernelAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange outputs, ::mlir::ValueRange inputs, ::mlir::ArrayAttr input_specs, ::mlir::ArrayAttr output_specs, ::mlir::StringAttr logical_kernel);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange outputs, ::mlir::ValueRange inputs, ::mlir::ArrayAttr input_specs, ::mlir::ArrayAttr output_specs, ::llvm::StringRef logical_kernel);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::QuantizeRegionOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::ReturnOp declarations
//===----------------------------------------------------------------------===//

class ReturnOpAdaptor {
public:
  ReturnOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ReturnOpAdaptor(ReturnOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange getResults();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ReturnOp : public ::mlir::Op<ReturnOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::OpInvariants, ::mlir::OpTrait::IsTerminator> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ReturnOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.return");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range getResults();
  ::mlir::MutableOperandRange getResultsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange results);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::ReturnOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::StatisticsOp declarations
//===----------------------------------------------------------------------===//

class StatisticsOpAdaptor {
public:
  StatisticsOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  StatisticsOpAdaptor(StatisticsOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ElementsAttr getLayerStatsAttr();
  ::mlir::ElementsAttr getLayerStats();
  ::mlir::ElementsAttr getAxisStatsAttr();
  ::llvm::Optional< ::mlir::ElementsAttr > getAxisStats();
  ::mlir::IntegerAttr getAxisAttr();
  ::llvm::Optional<uint64_t> getAxis();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class StatisticsOp : public ::mlir::Op<StatisticsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = StatisticsOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("axis"), ::llvm::StringRef("axisStats"), ::llvm::StringRef("layerStats")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getAxisAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getAxisAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getAxisStatsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getAxisStatsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getLayerStatsAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getLayerStatsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.stats");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::MutableOperandRange getArgMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::ElementsAttr getLayerStatsAttr();
  ::mlir::ElementsAttr getLayerStats();
  ::mlir::ElementsAttr getAxisStatsAttr();
  ::llvm::Optional< ::mlir::ElementsAttr > getAxisStats();
  ::mlir::IntegerAttr getAxisAttr();
  ::llvm::Optional<uint64_t> getAxis();
  void setLayerStatsAttr(::mlir::ElementsAttr attr);
  void setAxisStatsAttr(::mlir::ElementsAttr attr);
  void setAxisAttr(::mlir::IntegerAttr attr);
  ::mlir::Attribute removeAxisStatsAttr();
  ::mlir::Attribute removeAxisAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg, ::mlir::ElementsAttr layerStats, /*optional*/::mlir::ElementsAttr axisStats, /*optional*/::mlir::IntegerAttr axis);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value arg, ::mlir::ElementsAttr layerStats, /*optional*/::mlir::ElementsAttr axisStats, /*optional*/::mlir::IntegerAttr axis);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg, ::mlir::ElementsAttr layerStats, /*optional*/::mlir::ElementsAttr axisStats, /*optional*/::mlir::IntegerAttr axis);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::StatisticsOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::StatisticsRefOp declarations
//===----------------------------------------------------------------------===//

class StatisticsRefOpAdaptor {
public:
  StatisticsRefOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  StatisticsRefOpAdaptor(StatisticsRefOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::StringAttr getStatsKeyAttr();
  ::llvm::StringRef getStatsKey();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class StatisticsRefOp : public ::mlir::Op<StatisticsRefOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::OpTrait::SameOperandsAndResultType, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = StatisticsRefOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("statsKey")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getStatsKeyAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getStatsKeyAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.stats_ref");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::MutableOperandRange getArgMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::StringAttr getStatsKeyAttr();
  ::llvm::StringRef getStatsKey();
  void setStatsKeyAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg, ::mlir::StringAttr statsKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value arg, ::mlir::StringAttr statsKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg, ::mlir::StringAttr statsKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg, ::llvm::StringRef statsKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value arg, ::llvm::StringRef statsKey);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg, ::llvm::StringRef statsKey);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::StatisticsRefOp)

namespace mlir {
namespace quant {

//===----------------------------------------------------------------------===//
// ::mlir::quant::StorageCastOp declarations
//===----------------------------------------------------------------------===//

class StorageCastOpAdaptor {
public:
  StorageCastOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  StorageCastOpAdaptor(StorageCastOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class StorageCastOp : public ::mlir::Op<StorageCastOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = StorageCastOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("quant.scast");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getArg();
  ::mlir::MutableOperandRange getArgMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace quant
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::quant::StorageCastOp)


#endif  // GET_OP_CLASSES

