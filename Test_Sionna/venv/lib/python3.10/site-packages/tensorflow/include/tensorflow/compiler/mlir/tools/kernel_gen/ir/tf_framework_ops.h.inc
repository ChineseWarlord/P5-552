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
namespace kernel_gen {
namespace tf_framework {
class IsValidMemRefOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class JITCompileFromStrOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class JITCompileOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class JITCompileYieldOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class JITExecuteOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class NullContextOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class NullMemRefOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class ReportErrorOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class TFAllocOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class TFAssertOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
namespace mlir {
namespace kernel_gen {
namespace tf_framework {
class TFDeallocOp;
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::IsValidMemRefOp declarations
//===----------------------------------------------------------------------===//

class IsValidMemRefOpAdaptor {
public:
  IsValidMemRefOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  IsValidMemRefOpAdaptor(IsValidMemRefOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value arg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class IsValidMemRefOp : public ::mlir::Op<IsValidMemRefOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::IntegerType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = IsValidMemRefOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.is_valid_memref");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value arg();
  ::mlir::MutableOperandRange argMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value arg);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::IsValidMemRefOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::JITCompileFromStrOp declarations
//===----------------------------------------------------------------------===//

class JITCompileFromStrOpAdaptor {
public:
  JITCompileFromStrOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  JITCompileFromStrOpAdaptor(JITCompileFromStrOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::StringAttr codeAttr();
  ::llvm::StringRef code();
  ::mlir::ArrayAttr tileSizesAttr();
  ::mlir::ArrayAttr tileSizes();
  ::mlir::ArrayAttr unrollFactorsAttr();
  ::mlir::ArrayAttr unrollFactors();
  ::mlir::IntegerAttr maxSupportedRankAttr();
  uint64_t maxSupportedRank();
  ::mlir::BoolAttr enableFtzAttr();
  bool enableFtz();
  ::mlir::BoolAttr index64BitAttr();
  bool index64Bit();
  ::mlir::BoolAttr cpuCodegenAttr();
  bool cpuCodegen();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class JITCompileFromStrOp : public ::mlir::Op<JITCompileFromStrOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = JITCompileFromStrOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("code"), ::llvm::StringRef("cpuCodegen"), ::llvm::StringRef("enableFtz"), ::llvm::StringRef("index64Bit"), ::llvm::StringRef("maxSupportedRank"), ::llvm::StringRef("tileSizes"), ::llvm::StringRef("unrollFactors")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr codeAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr codeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr cpuCodegenAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr cpuCodegenAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr enableFtzAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr enableFtzAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr index64BitAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr index64BitAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr maxSupportedRankAttrName() {
    return getAttributeNameForIndex(4);
  }

  static ::mlir::StringAttr maxSupportedRankAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 4);
  }

  ::mlir::StringAttr tileSizesAttrName() {
    return getAttributeNameForIndex(5);
  }

  static ::mlir::StringAttr tileSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 5);
  }

  ::mlir::StringAttr unrollFactorsAttrName() {
    return getAttributeNameForIndex(6);
  }

  static ::mlir::StringAttr unrollFactorsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 6);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.jit_compile_from_str");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::MutableOperandRange ctxMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::StringAttr codeAttr();
  ::llvm::StringRef code();
  ::mlir::ArrayAttr tileSizesAttr();
  ::mlir::ArrayAttr tileSizes();
  ::mlir::ArrayAttr unrollFactorsAttr();
  ::mlir::ArrayAttr unrollFactors();
  ::mlir::IntegerAttr maxSupportedRankAttr();
  uint64_t maxSupportedRank();
  ::mlir::BoolAttr enableFtzAttr();
  bool enableFtz();
  ::mlir::BoolAttr index64BitAttr();
  bool index64Bit();
  ::mlir::BoolAttr cpuCodegenAttr();
  bool cpuCodegen();
  void codeAttr(::mlir::StringAttr attr);
  void tileSizesAttr(::mlir::ArrayAttr attr);
  void unrollFactorsAttr(::mlir::ArrayAttr attr);
  void maxSupportedRankAttr(::mlir::IntegerAttr attr);
  void enableFtzAttr(::mlir::BoolAttr attr);
  void index64BitAttr(::mlir::BoolAttr attr);
  void cpuCodegenAttr(::mlir::BoolAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, /*optional*/::mlir::Value ctx, ::mlir::StringAttr code, ::mlir::ArrayAttr tileSizes, ::mlir::ArrayAttr unrollFactors, ::mlir::IntegerAttr maxSupportedRank, ::mlir::BoolAttr enableFtz, ::mlir::BoolAttr index64Bit, ::mlir::BoolAttr cpuCodegen);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/::mlir::Value ctx, ::mlir::StringAttr code, ::mlir::ArrayAttr tileSizes, ::mlir::ArrayAttr unrollFactors, ::mlir::IntegerAttr maxSupportedRank, ::mlir::BoolAttr enableFtz, ::mlir::BoolAttr index64Bit, ::mlir::BoolAttr cpuCodegen);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, /*optional*/::mlir::Value ctx, ::llvm::StringRef code, ::mlir::ArrayAttr tileSizes, ::mlir::ArrayAttr unrollFactors, uint64_t maxSupportedRank, bool enableFtz, bool index64Bit, bool cpuCodegen);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/::mlir::Value ctx, ::llvm::StringRef code, ::mlir::ArrayAttr tileSizes, ::mlir::ArrayAttr unrollFactors, uint64_t maxSupportedRank, bool enableFtz, bool index64Bit, bool cpuCodegen);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 7 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  static constexpr StringRef kJITEntryFunctionName = "main";
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::JITCompileFromStrOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::JITCompileOp declarations
//===----------------------------------------------------------------------===//

class JITCompileOpAdaptor {
public:
  JITCompileOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  JITCompileOpAdaptor(JITCompileOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::RegionRange getRegions();
  ::mlir::Region &body();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class JITCompileOp : public ::mlir::Op<JITCompileOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::SingleBlock, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = JITCompileOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.jit_compile");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::MutableOperandRange ctxMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::Region &body();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, /*optional*/::mlir::Value ctx);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/::mlir::Value ctx);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::JITCompileOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::JITCompileYieldOp declarations
//===----------------------------------------------------------------------===//

class JITCompileYieldOpAdaptor {
public:
  JITCompileYieldOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  JITCompileYieldOpAdaptor(JITCompileYieldOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value result();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class JITCompileYieldOp : public ::mlir::Op<JITCompileYieldOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::HasParent<JITCompileOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::ReturnLike, ::mlir::OpTrait::IsTerminator> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = JITCompileYieldOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.jit_compile_yield");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value result();
  ::mlir::MutableOperandRange resultMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value result);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value result);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::JITCompileYieldOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::JITExecuteOp declarations
//===----------------------------------------------------------------------===//

class JITExecuteOpAdaptor {
public:
  JITExecuteOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  JITExecuteOpAdaptor(JITExecuteOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::Value callable();
  ::mlir::ValueRange operands();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class JITExecuteOp : public ::mlir::Op<JITExecuteOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::bufferization::AllocationOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = JITExecuteOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("operand_segment_sizes")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr operand_segment_sizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr operand_segment_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.jit_execute");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::Value callable();
  ::mlir::Operation::operand_range operands();
  ::mlir::MutableOperandRange ctxMutable();
  ::mlir::MutableOperandRange callableMutable();
  ::mlir::MutableOperandRange operandsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, /*optional*/::mlir::Value ctx, ::mlir::Value callable, ::mlir::ValueRange operands);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, /*optional*/::mlir::Value ctx, ::mlir::Value callable, ::mlir::ValueRange operands);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::Optional<::mlir::Operation*> buildDealloc(::mlir::OpBuilder&builder, ::mlir::Value alloc);
  static ::mlir::Optional<::mlir::Value> buildClone(::mlir::OpBuilder&builder, ::mlir::Value alloc);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
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
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::JITExecuteOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::NullContextOp declarations
//===----------------------------------------------------------------------===//

class NullContextOpAdaptor {
public:
  NullContextOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  NullContextOpAdaptor(NullContextOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class NullContextOp : public ::mlir::Op<NullContextOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = NullContextOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.null_context");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::NullContextOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::NullMemRefOp declarations
//===----------------------------------------------------------------------===//

class NullMemRefOpAdaptor {
public:
  NullMemRefOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  NullMemRefOpAdaptor(NullMemRefOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class NullMemRefOp : public ::mlir::Op<NullMemRefOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = NullMemRefOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.null_memref");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::NullMemRefOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::ReportErrorOp declarations
//===----------------------------------------------------------------------===//

class ReportErrorOpAdaptor {
public:
  ReportErrorOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ReportErrorOpAdaptor(ReportErrorOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_codeAttr();
  ::mlir::kernel_gen::tf_framework::ErrorCode error_code();
  ::mlir::StringAttr msgAttr();
  ::llvm::StringRef msg();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ReportErrorOp : public ::mlir::Op<ReportErrorOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ReportErrorOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("error_code"), ::llvm::StringRef("msg")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr error_codeAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr error_codeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr msgAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr msgAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.report_error");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::MutableOperandRange ctxMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_codeAttr();
  ::mlir::kernel_gen::tf_framework::ErrorCode error_code();
  ::mlir::StringAttr msgAttr();
  ::llvm::StringRef msg();
  void error_codeAttr(::mlir::kernel_gen::tf_framework::ErrorCodeAttr attr);
  void msgAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value ctx, ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_code, ::mlir::StringAttr msg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ctx, ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_code, ::mlir::StringAttr msg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value ctx, ::mlir::kernel_gen::tf_framework::ErrorCode error_code, ::llvm::StringRef msg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ctx, ::mlir::kernel_gen::tf_framework::ErrorCode error_code, ::llvm::StringRef msg);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::ReportErrorOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::TFAllocOp declarations
//===----------------------------------------------------------------------===//

class TFAllocOpAdaptor {
public:
  TFAllocOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  TFAllocOpAdaptor(TFAllocOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::ValueRange dyn_sizes();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr input_indicesAttr();
  ::llvm::Optional< ::mlir::ArrayAttr > input_indices();
  ::mlir::IntegerAttr output_indexAttr();
  ::llvm::Optional<uint32_t> output_index();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class TFAllocOp : public ::mlir::Op<TFAllocOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::MemRefType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::bufferization::AllocationOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TFAllocOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("input_indices"), ::llvm::StringRef("output_index")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr input_indicesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr input_indicesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr output_indexAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr output_indexAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.alloc");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::Operation::operand_range dyn_sizes();
  ::mlir::MutableOperandRange ctxMutable();
  ::mlir::MutableOperandRange dyn_sizesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::ArrayAttr input_indicesAttr();
  ::llvm::Optional< ::mlir::ArrayAttr > input_indices();
  ::mlir::IntegerAttr output_indexAttr();
  ::llvm::Optional<uint32_t> output_index();
  void input_indicesAttr(::mlir::ArrayAttr attr);
  void output_indexAttr(::mlir::IntegerAttr attr);
  ::mlir::Attribute removeInput_indicesAttr();
  ::mlir::Attribute removeOutput_indexAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, MemRefType memref_type, Value ctx);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, MemRefType memref_type, Value ctx, ValueRange dyn_sizes);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value ctx, ::mlir::ValueRange dyn_sizes, /*optional*/::mlir::ArrayAttr input_indices, /*optional*/::mlir::IntegerAttr output_index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ctx, ::mlir::ValueRange dyn_sizes, /*optional*/::mlir::ArrayAttr input_indices, /*optional*/::mlir::IntegerAttr output_index);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::Optional<::mlir::Operation*> buildDealloc(::mlir::OpBuilder&builder, ::mlir::Value alloc);
  static ::mlir::Optional<::mlir::Value> buildClone(::mlir::OpBuilder&builder, ::mlir::Value alloc);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  MemRefType getType() { return getResult().getType().cast<MemRefType>(); }
  static constexpr StringRef kReuseOutputAttrName = "reuse_output";
  static constexpr StringRef kReuseInputCandidatesAttrName =
      "reuse_input_candidates";
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::TFAllocOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::TFAssertOp declarations
//===----------------------------------------------------------------------===//

class TFAssertOpAdaptor {
public:
  TFAssertOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  TFAssertOpAdaptor(TFAssertOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::Value arg();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_codeAttr();
  ::mlir::kernel_gen::tf_framework::ErrorCode error_code();
  ::mlir::StringAttr msgAttr();
  ::llvm::StringRef msg();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class TFAssertOp : public ::mlir::Op<TFAssertOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TFAssertOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("error_code"), ::llvm::StringRef("msg")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr error_codeAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr error_codeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr msgAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr msgAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.assert");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::Value arg();
  ::mlir::MutableOperandRange ctxMutable();
  ::mlir::MutableOperandRange argMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_codeAttr();
  ::mlir::kernel_gen::tf_framework::ErrorCode error_code();
  ::mlir::StringAttr msgAttr();
  ::llvm::StringRef msg();
  void error_codeAttr(::mlir::kernel_gen::tf_framework::ErrorCodeAttr attr);
  void msgAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value ctx, ::mlir::Value arg, ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_code, ::mlir::StringAttr msg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ctx, ::mlir::Value arg, ::mlir::kernel_gen::tf_framework::ErrorCodeAttr error_code, ::mlir::StringAttr msg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value ctx, ::mlir::Value arg, ::mlir::kernel_gen::tf_framework::ErrorCode error_code, ::llvm::StringRef msg);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ctx, ::mlir::Value arg, ::mlir::kernel_gen::tf_framework::ErrorCode error_code, ::llvm::StringRef msg);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 2 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::TFAssertOp)

namespace mlir {
namespace kernel_gen {
namespace tf_framework {

//===----------------------------------------------------------------------===//
// ::mlir::kernel_gen::tf_framework::TFDeallocOp declarations
//===----------------------------------------------------------------------===//

class TFDeallocOpAdaptor {
public:
  TFDeallocOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  TFDeallocOpAdaptor(TFDeallocOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::Value memref();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class TFDeallocOp : public ::mlir::Op<TFDeallocOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TFDeallocOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_framework.dealloc");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value ctx();
  ::mlir::Value memref();
  ::mlir::MutableOperandRange ctxMutable();
  ::mlir::MutableOperandRange memrefMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value ctx, ::mlir::Value memref);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value ctx, ::mlir::Value memref);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tf_framework
} // namespace kernel_gen
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::kernel_gen::tf_framework::TFDeallocOp)


#endif  // GET_OP_CLASSES

