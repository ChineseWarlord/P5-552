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
namespace tensor {
class CastOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class CollapseShapeOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class DimOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class ExpandShapeOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class ExtractOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class ExtractSliceOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class FromElementsOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class GenerateOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class InsertOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class InsertSliceOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class PadOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class ParallelInsertSliceOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class RankOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class ReshapeOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class SplatOp;
} // namespace tensor
} // namespace mlir
namespace mlir {
namespace tensor {
class YieldOp;
} // namespace tensor
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::CastOp declarations
//===----------------------------------------------------------------------===//

class CastOpAdaptor {
public:
  CastOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  CastOpAdaptor(CastOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class CastOp : public ::mlir::Op<CastOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::CastOpInterface::Trait, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = CastOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.cast");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::MutableOperandRange getSourceMutable();
  ::mlir::MutableOperandRange sourceMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getDest();
  ::mlir::Value dest();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type dest, ::mlir::Value source);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  static bool areCastCompatible(::mlir::TypeRange inputs, ::mlir::TypeRange outputs);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::CastOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::CollapseShapeOp declarations
//===----------------------------------------------------------------------===//

class CollapseShapeOpAdaptor {
public:
  CollapseShapeOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  CollapseShapeOpAdaptor(CollapseShapeOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSrc();
  ::mlir::Value src();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getReassociationAttr();
  ::mlir::ArrayAttr getReassociation();
  ::mlir::ArrayAttr reassociationAttr();
  ::mlir::ArrayAttr reassociation();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class CollapseShapeOp : public ::mlir::Op<CollapseShapeOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = CollapseShapeOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("reassociation")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getReassociationAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getReassociationAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr reassociationAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr reassociationAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.collapse_shape");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSrc();
  ::mlir::Value src();
  ::mlir::MutableOperandRange getSrcMutable();
  ::mlir::MutableOperandRange srcMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  ::mlir::ArrayAttr getReassociationAttr();
  ::mlir::ArrayAttr getReassociation();
  ::mlir::ArrayAttr reassociationAttr();
  ::mlir::ArrayAttr reassociation();
  void setReassociationAttr(::mlir::ArrayAttr attr);
  void reassociationAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value src, ArrayRef<ReassociationIndices> reassociation, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value src, ArrayRef<ReassociationExprs> reassociation, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type resultType, Value src, ArrayRef<ReassociationIndices> reassociation, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type resultType, Value src, ArrayRef<ReassociationExprs> reassociation, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value src, ::mlir::ArrayAttr reassociation);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value src, ::mlir::ArrayAttr reassociation);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
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
  static StringRef getReassociationAttrStrName() { return "reassociation"; }
  SmallVector<AffineMap, 4> getReassociationMaps();
  SmallVector<ReassociationExprs, 4> getReassociationExprs();
  SmallVector<ReassociationIndices, 4> getReassociationIndices() {
    SmallVector<ReassociationIndices, 4> reassociationIndices;
    for (auto attr : getReassociation())
      reassociationIndices.push_back(llvm::to_vector<2>(
          llvm::map_range(attr.cast<ArrayAttr>(), [&](Attribute indexAttr) {
            return indexAttr.cast<IntegerAttr>().getInt();
          })));
    return reassociationIndices;
  };
  RankedTensorType getSrcType() {
    return getSrc().getType().cast<RankedTensorType>();
  }
  RankedTensorType getResultType() {
    return getResult().getType().cast<RankedTensorType>();
  }
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::CollapseShapeOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::DimOp declarations
//===----------------------------------------------------------------------===//

class DimOpAdaptor {
public:
  DimOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  DimOpAdaptor(DimOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getIndex();
  ::mlir::Value index();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class DimOp : public ::mlir::Op<DimOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::IndexType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DimOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.dim");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getIndex();
  ::mlir::Value index();
  ::mlir::MutableOperandRange getSourceMutable();
  ::mlir::MutableOperandRange sourceMutable();
  ::mlir::MutableOperandRange getIndexMutable();
  ::mlir::MutableOperandRange indexMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, int64_t index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::Value index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value source, ::mlir::Value index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value index);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
  /// Helper function to get the index as a simple integer if it is constant.
  Optional<int64_t> getConstantIndex();
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::DimOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::ExpandShapeOp declarations
//===----------------------------------------------------------------------===//

class ExpandShapeOpAdaptor {
public:
  ExpandShapeOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ExpandShapeOpAdaptor(ExpandShapeOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSrc();
  ::mlir::Value src();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getReassociationAttr();
  ::mlir::ArrayAttr getReassociation();
  ::mlir::ArrayAttr reassociationAttr();
  ::mlir::ArrayAttr reassociation();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ExpandShapeOp : public ::mlir::Op<ExpandShapeOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ExpandShapeOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("reassociation")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getReassociationAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getReassociationAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr reassociationAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr reassociationAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.expand_shape");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSrc();
  ::mlir::Value src();
  ::mlir::MutableOperandRange getSrcMutable();
  ::mlir::MutableOperandRange srcMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  ::mlir::ArrayAttr getReassociationAttr();
  ::mlir::ArrayAttr getReassociation();
  ::mlir::ArrayAttr reassociationAttr();
  ::mlir::ArrayAttr reassociation();
  void setReassociationAttr(::mlir::ArrayAttr attr);
  void reassociationAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type resultType, Value src, ArrayRef<ReassociationIndices> reassociation, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type resultType, Value src, ArrayRef<ReassociationExprs> reassociation, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value src, ::mlir::ArrayAttr reassociation);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value src, ::mlir::ArrayAttr reassociation);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
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
  static StringRef getReassociationAttrStrName() { return "reassociation"; }
  SmallVector<AffineMap, 4> getReassociationMaps();
  SmallVector<ReassociationExprs, 4> getReassociationExprs();
  SmallVector<ReassociationIndices, 4> getReassociationIndices() {
    SmallVector<ReassociationIndices, 4> reassociationIndices;
    for (auto attr : getReassociation())
      reassociationIndices.push_back(llvm::to_vector<2>(
          llvm::map_range(attr.cast<ArrayAttr>(), [&](Attribute indexAttr) {
            return indexAttr.cast<IntegerAttr>().getInt();
          })));
    return reassociationIndices;
  };
  RankedTensorType getSrcType() {
    return getSrc().getType().cast<RankedTensorType>();
  }
  RankedTensorType getResultType() {
    return getResult().getType().cast<RankedTensorType>();
  }
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::ExpandShapeOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::ExtractOp declarations
//===----------------------------------------------------------------------===//

class ExtractOpAdaptor {
public:
  ExtractOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ExtractOpAdaptor(ExtractOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getTensor();
  ::mlir::Value tensor();
  ::mlir::ValueRange getIndices();
  ::mlir::ValueRange indices();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ExtractOp : public ::mlir::Op<ExtractOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ExtractOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.extract");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getTensor();
  ::mlir::Value tensor();
  ::mlir::Operation::operand_range getIndices();
  ::mlir::Operation::operand_range indices();
  ::mlir::MutableOperandRange getTensorMutable();
  ::mlir::MutableOperandRange tensorMutable();
  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange indicesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value tensor, ValueRange indices = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tensor, ::mlir::ValueRange indices);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor, ::mlir::ValueRange indices);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::ExtractOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::ExtractSliceOp declarations
//===----------------------------------------------------------------------===//

class ExtractSliceOpAdaptor {
public:
  ExtractSliceOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ExtractSliceOpAdaptor(ExtractSliceOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::ValueRange getOffsets();
  ::mlir::ValueRange offsets();
  ::mlir::ValueRange getSizes();
  ::mlir::ValueRange sizes();
  ::mlir::ValueRange getStrides();
  ::mlir::ValueRange strides();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getStaticOffsetsAttr();
  ::mlir::ArrayAttr getStaticOffsets();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr getStaticSizesAttr();
  ::mlir::ArrayAttr getStaticSizes();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr getStaticStridesAttr();
  ::mlir::ArrayAttr getStaticStrides();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ExtractSliceOp : public ::mlir::Op<ExtractSliceOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::ReifyRankedShapedTypeOpInterface::Trait, ::mlir::OffsetSizeAndStrideOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ExtractSliceOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("operand_segment_sizes"), ::llvm::StringRef("static_offsets"), ::llvm::StringRef("static_sizes"), ::llvm::StringRef("static_strides")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr operand_segment_sizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr operand_segment_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getStaticOffsetsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getStaticOffsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr static_offsetsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr static_offsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getStaticSizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getStaticSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr static_sizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr static_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getStaticStridesAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getStaticStridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr static_stridesAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr static_stridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.extract_slice");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Operation::operand_range getOffsets();
  ::mlir::Operation::operand_range offsets();
  ::mlir::Operation::operand_range getSizes();
  ::mlir::Operation::operand_range sizes();
  ::mlir::Operation::operand_range getStrides();
  ::mlir::Operation::operand_range strides();
  ::mlir::MutableOperandRange getSourceMutable();
  ::mlir::MutableOperandRange sourceMutable();
  ::mlir::MutableOperandRange getOffsetsMutable();
  ::mlir::MutableOperandRange offsetsMutable();
  ::mlir::MutableOperandRange getSizesMutable();
  ::mlir::MutableOperandRange sizesMutable();
  ::mlir::MutableOperandRange getStridesMutable();
  ::mlir::MutableOperandRange stridesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  ::mlir::ArrayAttr getStaticOffsetsAttr();
  ::mlir::ArrayAttr getStaticOffsets();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr getStaticSizesAttr();
  ::mlir::ArrayAttr getStaticSizes();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr getStaticStridesAttr();
  ::mlir::ArrayAttr getStaticStrides();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  void setStaticOffsetsAttr(::mlir::ArrayAttr attr);
  void static_offsetsAttr(::mlir::ArrayAttr attr);
  void setStaticSizesAttr(::mlir::ArrayAttr attr);
  void static_sizesAttr(::mlir::ArrayAttr attr);
  void setStaticStridesAttr(::mlir::ArrayAttr attr);
  void static_stridesAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, ArrayRef<OpFoldResult> offsets, ArrayRef<OpFoldResult> sizes, ArrayRef<OpFoldResult> strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, RankedTensorType resultType, Value source, ArrayRef<OpFoldResult> offsets, ArrayRef<OpFoldResult> sizes, ArrayRef<OpFoldResult> strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, ValueRange offsets, ValueRange sizes, ValueRange strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, RankedTensorType resultType, Value source, ValueRange offsets, ValueRange sizes, ValueRange strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  ::mlir::LogicalResult reifyResultShapes(::mlir::OpBuilder &builder, ::mlir::ReifiedRankedShapedTypeDims &reifiedReturnShapes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  /// Returns the dynamic sizes for this subview operation if specified.
  ::mlir::Operation::operand_range getDynamicSizes() { return getSizes(); }

  /// Return the list of Range (i.e. offset, size, stride). Each
  /// Range entry contains either the dynamic value or a ConstantIndexOp
  /// constructed with `b` at location `loc`.
  ::mlir::SmallVector<::mlir::Range, 8> getOrCreateRanges(
      ::mlir::OpBuilder &b, ::mlir::Location loc) {
    return ::mlir::getOrCreateRanges(*this, b, loc);
  }

  /// Returns the type of the base tensor operand.
  RankedTensorType getSourceType() {
    return getSource().getType().cast<RankedTensorType>();
  }

  /// The result of an extract_slice is always a tensor.
  RankedTensorType getType() {
    return getResult().getType().cast<RankedTensorType>();
  }

  /// Compute the rank-reduction mask that can be applied to map the source
  /// tensor type to the result tensor type by dropping unit dims.
  llvm::Optional<llvm::SmallDenseSet<unsigned>>
  computeRankReductionMask() {
    return ::mlir::computeRankReductionMask(getSourceType().getShape(), 
                                            getType().getShape());
  };

  /// An extract_slice result type can be inferred, when it is not
  /// rank-reduced, from the source type and the static representation of 
  /// offsets, sizes and strides. Special sentinels encode the dynamic case.
  static RankedTensorType inferResultType(
    ShapedType sourceShapedTensorType,
    ArrayRef<int64_t> staticOffsets,
    ArrayRef<int64_t> staticSizes,
    ArrayRef<int64_t> staticStrides);
  static RankedTensorType inferResultType(
    ShapedType sourceShapedTensorType,
    ArrayRef<OpFoldResult> staticOffsets,
    ArrayRef<OpFoldResult> staticSizes,
    ArrayRef<OpFoldResult> staticStrides);

  /// If the rank is reduced (i.e. the desiredResultRank is smaller than the
  /// number of sizes), drop as many size 1 as needed to produce an inferred type
  /// with the desired rank.
  ///
  /// Note that there may be multiple ways to compute this rank-reduced type:
  ///   e.g. 1x6x1 can rank-reduce to either 1x6 or 6x1 2-D tensors.
  ///
  /// To disambiguate, this function always drops the first 1 sizes occurrences.
  static RankedTensorType inferCanonicalRankReducedResultType(
    unsigned resultRank,
    RankedTensorType sourceRankedTensorType,
    ArrayRef<int64_t> staticOffsets,
    ArrayRef<int64_t> staticSizes,
    ArrayRef<int64_t> staticStrides);
  static RankedTensorType inferCanonicalRankReducedResultType(
    unsigned resultRank,
    RankedTensorType sourceRankedTensorType,
    ArrayRef<OpFoldResult> staticOffsets,
    ArrayRef<OpFoldResult> staticSizes,
    ArrayRef<OpFoldResult> staticStrides);

  /// Return the expected rank of each of the`static_offsets`, `static_sizes`
  /// and `static_strides` attributes.
  std::array<unsigned, 3> getArrayAttrMaxRanks() {
    unsigned rank = getSourceType().getRank();
    return {rank, rank, rank};
  }

  /// Return the number of leading operands before the `offsets`, `sizes` and
  /// and `strides` operands.
  static unsigned getOffsetSizeAndStrideStartOperandIndex() { return 1; }

  /// Return the dimensions of the source that are dropped in the
  /// result when the result is rank-reduced.
  llvm::SmallBitVector getDroppedDims();
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::ExtractSliceOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::FromElementsOp declarations
//===----------------------------------------------------------------------===//

class FromElementsOpAdaptor {
public:
  FromElementsOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  FromElementsOpAdaptor(FromElementsOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange getElements();
  ::mlir::ValueRange elements();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class FromElementsOp : public ::mlir::Op<FromElementsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = FromElementsOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.from_elements");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range getElements();
  ::mlir::Operation::operand_range elements();
  ::mlir::MutableOperandRange getElementsMutable();
  ::mlir::MutableOperandRange elementsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type resultType, ValueRange elements);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ValueRange elements);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::FromElementsOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::GenerateOp declarations
//===----------------------------------------------------------------------===//

class GenerateOpAdaptor {
public:
  GenerateOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  GenerateOpAdaptor(GenerateOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange getDynamicExtents();
  ::mlir::ValueRange dynamicExtents();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::RegionRange getRegions();
  ::mlir::Region &getBody();
  ::mlir::Region &body();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class GenerateOp : public ::mlir::Op<GenerateOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::SingleBlockImplicitTerminator<mlir::tensor::YieldOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::OpTrait::HasRecursiveSideEffects, ::mlir::ReifyRankedShapedTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = GenerateOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.generate");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range getDynamicExtents();
  ::mlir::Operation::operand_range dynamicExtents();
  ::mlir::MutableOperandRange getDynamicExtentsMutable();
  ::mlir::MutableOperandRange dynamicExtentsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  ::mlir::Region &getBody();
  ::mlir::Region &body();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type resultTy, ValueRange dynamicExtents, function_ref<void(OpBuilder &, Location, ValueRange)> odsArg2);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::ValueRange dynamicExtents);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  ::mlir::LogicalResult verifyRegions();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::LogicalResult reifyResultShapes(::mlir::OpBuilder &builder, ::mlir::ReifiedRankedShapedTypeDims &reifiedReturnShapes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::GenerateOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::InsertOp declarations
//===----------------------------------------------------------------------===//

class InsertOpAdaptor {
public:
  InsertOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  InsertOpAdaptor(InsertOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getScalar();
  ::mlir::Value scalar();
  ::mlir::Value getDest();
  ::mlir::Value dest();
  ::mlir::ValueRange getIndices();
  ::mlir::ValueRange indices();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class InsertOp : public ::mlir::Op<InsertOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = InsertOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.insert");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getScalar();
  ::mlir::Value scalar();
  ::mlir::Value getDest();
  ::mlir::Value dest();
  ::mlir::Operation::operand_range getIndices();
  ::mlir::Operation::operand_range indices();
  ::mlir::MutableOperandRange getScalarMutable();
  ::mlir::MutableOperandRange scalarMutable();
  ::mlir::MutableOperandRange getDestMutable();
  ::mlir::MutableOperandRange destMutable();
  ::mlir::MutableOperandRange getIndicesMutable();
  ::mlir::MutableOperandRange indicesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value scalar, Value dest, ValueRange indices = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value scalar, ::mlir::Value dest, ::mlir::ValueRange indices);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value scalar, ::mlir::Value dest, ::mlir::ValueRange indices);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::InsertOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::InsertSliceOp declarations
//===----------------------------------------------------------------------===//

class InsertSliceOpAdaptor {
public:
  InsertSliceOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  InsertSliceOpAdaptor(InsertSliceOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getDest();
  ::mlir::Value dest();
  ::mlir::ValueRange getOffsets();
  ::mlir::ValueRange offsets();
  ::mlir::ValueRange getSizes();
  ::mlir::ValueRange sizes();
  ::mlir::ValueRange getStrides();
  ::mlir::ValueRange strides();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getStaticOffsetsAttr();
  ::mlir::ArrayAttr getStaticOffsets();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr getStaticSizesAttr();
  ::mlir::ArrayAttr getStaticSizes();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr getStaticStridesAttr();
  ::mlir::ArrayAttr getStaticStrides();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class InsertSliceOp : public ::mlir::Op<InsertSliceOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OffsetSizeAndStrideOpInterface::Trait, ::mlir::ReifyRankedShapedTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = InsertSliceOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("operand_segment_sizes"), ::llvm::StringRef("static_offsets"), ::llvm::StringRef("static_sizes"), ::llvm::StringRef("static_strides")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr operand_segment_sizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr operand_segment_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getStaticOffsetsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getStaticOffsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr static_offsetsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr static_offsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getStaticSizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getStaticSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr static_sizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr static_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getStaticStridesAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getStaticStridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr static_stridesAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr static_stridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.insert_slice");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getDest();
  ::mlir::Value dest();
  ::mlir::Operation::operand_range getOffsets();
  ::mlir::Operation::operand_range offsets();
  ::mlir::Operation::operand_range getSizes();
  ::mlir::Operation::operand_range sizes();
  ::mlir::Operation::operand_range getStrides();
  ::mlir::Operation::operand_range strides();
  ::mlir::MutableOperandRange getSourceMutable();
  ::mlir::MutableOperandRange sourceMutable();
  ::mlir::MutableOperandRange getDestMutable();
  ::mlir::MutableOperandRange destMutable();
  ::mlir::MutableOperandRange getOffsetsMutable();
  ::mlir::MutableOperandRange offsetsMutable();
  ::mlir::MutableOperandRange getSizesMutable();
  ::mlir::MutableOperandRange sizesMutable();
  ::mlir::MutableOperandRange getStridesMutable();
  ::mlir::MutableOperandRange stridesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  ::mlir::ArrayAttr getStaticOffsetsAttr();
  ::mlir::ArrayAttr getStaticOffsets();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr getStaticSizesAttr();
  ::mlir::ArrayAttr getStaticSizes();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr getStaticStridesAttr();
  ::mlir::ArrayAttr getStaticStrides();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  void setStaticOffsetsAttr(::mlir::ArrayAttr attr);
  void static_offsetsAttr(::mlir::ArrayAttr attr);
  void setStaticSizesAttr(::mlir::ArrayAttr attr);
  void static_sizesAttr(::mlir::ArrayAttr attr);
  void setStaticStridesAttr(::mlir::ArrayAttr attr);
  void static_stridesAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, Value dest, ArrayRef<OpFoldResult> offsets, ArrayRef<OpFoldResult> sizes, ArrayRef<OpFoldResult> strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, Value dest, ValueRange offsets, ValueRange sizes, ValueRange strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::Value dest, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value dest, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  ::mlir::LogicalResult reifyResultShapes(::mlir::OpBuilder &builder, ::mlir::ReifiedRankedShapedTypeDims &reifiedReturnShapes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  /// Returns the dynamic sizes for this subview operation if specified.
  ::mlir::Operation::operand_range getDynamicSizes() { return getSizes(); }

  /// Return the list of Range (i.e. offset, size, stride). Each
  /// Range entry contains either the dynamic value or a ConstantIndexOp
  /// constructed with `b` at location `loc`.
  ::mlir::SmallVector<::mlir::Range, 8> getOrCreateRanges(
      ::mlir::OpBuilder &b, ::mlir::Location loc) {
    return ::mlir::getOrCreateRanges(*this, b, loc);
  }

  /// Returns the type of the base tensor operand.
  RankedTensorType getSourceType() {
    return getSource().getType().cast<RankedTensorType>();
  }

  /// The result of a insert_slice is always a tensor.
  RankedTensorType getType() {
    return getResult().getType().cast<RankedTensorType>();
  }

  /// The `dest` type is the same as the result type.
  RankedTensorType getDestType() {
    return getType();
  }

  /// Return the expected rank of each of the`static_offsets`, `static_sizes`
  /// and `static_strides` attributes.
  std::array<unsigned, 3> getArrayAttrMaxRanks() {
    unsigned rank = getType().getRank();
    return {rank, rank, rank};
  }

  /// Return the number of leading operands before the `offsets`, `sizes` and
  /// and `strides` operands.
  static unsigned getOffsetSizeAndStrideStartOperandIndex() { return 2; }
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::InsertSliceOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::PadOp declarations
//===----------------------------------------------------------------------===//

class PadOpAdaptor {
public:
  PadOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  PadOpAdaptor(PadOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::ValueRange getLow();
  ::mlir::ValueRange low();
  ::mlir::ValueRange getHigh();
  ::mlir::ValueRange high();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getStaticLowAttr();
  ::mlir::ArrayAttr getStaticLow();
  ::mlir::ArrayAttr static_lowAttr();
  ::mlir::ArrayAttr static_low();
  ::mlir::ArrayAttr getStaticHighAttr();
  ::mlir::ArrayAttr getStaticHigh();
  ::mlir::ArrayAttr static_highAttr();
  ::mlir::ArrayAttr static_high();
  ::mlir::UnitAttr getNofoldAttr();
  bool getNofold();
  ::mlir::UnitAttr nofoldAttr();
  bool nofold();
  ::mlir::RegionRange getRegions();
  ::mlir::Region &getRegion();
  ::mlir::Region &region();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class PadOp : public ::mlir::Op<PadOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::SingleBlockImplicitTerminator<mlir::tensor::YieldOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PadOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("nofold"), ::llvm::StringRef("operand_segment_sizes"), ::llvm::StringRef("static_high"), ::llvm::StringRef("static_low")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getNofoldAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getNofoldAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr nofoldAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr nofoldAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr operand_segment_sizesAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr operand_segment_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getStaticHighAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getStaticHighAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr static_highAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr static_highAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getStaticLowAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getStaticLowAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr static_lowAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr static_lowAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.pad");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Operation::operand_range getLow();
  ::mlir::Operation::operand_range low();
  ::mlir::Operation::operand_range getHigh();
  ::mlir::Operation::operand_range high();
  ::mlir::MutableOperandRange getSourceMutable();
  ::mlir::MutableOperandRange sourceMutable();
  ::mlir::MutableOperandRange getLowMutable();
  ::mlir::MutableOperandRange lowMutable();
  ::mlir::MutableOperandRange getHighMutable();
  ::mlir::MutableOperandRange highMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  ::mlir::Region &getRegion();
  ::mlir::Region &region();
  ::mlir::ArrayAttr getStaticLowAttr();
  ::mlir::ArrayAttr getStaticLow();
  ::mlir::ArrayAttr static_lowAttr();
  ::mlir::ArrayAttr static_low();
  ::mlir::ArrayAttr getStaticHighAttr();
  ::mlir::ArrayAttr getStaticHigh();
  ::mlir::ArrayAttr static_highAttr();
  ::mlir::ArrayAttr static_high();
  ::mlir::UnitAttr getNofoldAttr();
  bool getNofold();
  ::mlir::UnitAttr nofoldAttr();
  bool nofold();
  void setStaticLowAttr(::mlir::ArrayAttr attr);
  void static_lowAttr(::mlir::ArrayAttr attr);
  void setStaticHighAttr(::mlir::ArrayAttr attr);
  void static_highAttr(::mlir::ArrayAttr attr);
  void setNofoldAttr(::mlir::UnitAttr attr);
  void nofoldAttr(::mlir::UnitAttr attr);
  ::mlir::Attribute removeNofoldAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, ArrayRef<int64_t> staticLow, ArrayRef<int64_t> staticHigh, ValueRange low, ValueRange high, bool nofold = false, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, ValueRange low, ValueRange high, bool nofold = false, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Type resultType, Value source, ArrayRef<OpFoldResult> low, ArrayRef<OpFoldResult> high, bool nofold = false, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::ValueRange low, ::mlir::ValueRange high, ::mlir::ArrayAttr static_low, ::mlir::ArrayAttr static_high, /*optional*/::mlir::UnitAttr nofold);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::ValueRange low, ::mlir::ValueRange high, ::mlir::ArrayAttr static_low, ::mlir::ArrayAttr static_high, /*optional*/::mlir::UnitAttr nofold);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::ValueRange low, ::mlir::ValueRange high, ::mlir::ArrayAttr static_low, ::mlir::ArrayAttr static_high, /*optional*/bool nofold);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::ValueRange low, ::mlir::ValueRange high, ::mlir::ArrayAttr static_low, ::mlir::ArrayAttr static_high, /*optional*/bool nofold);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  ::mlir::LogicalResult verifyRegions();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  static StringRef getStaticLowAttrStrName() {
    return "static_low";
  }

  static StringRef getStaticHighAttrStrName() {
    return "static_high";
  }

  RankedTensorType getSourceType() {
    return getSource().getType().cast<RankedTensorType>();
  }
  RankedTensorType getResultType() {
    return getResult().getType().cast<RankedTensorType>();
  }

  // Infer the shape of the result tensor given the type of the source tensor
  // and paddings. Known result dimensions that cannot necessarily be inferred
  // from low/high padding sizes can be optionally specified. Those will be
  // considered when computing the result type.
  static RankedTensorType inferResultType(
                              RankedTensorType sourceType,
                              ArrayRef<int64_t> staticLow,
                              ArrayRef<int64_t> staticHigh,
                              ArrayRef<int64_t> resultShape = {});

  // Return the pad value if it is a constant. Return null value otherwise.
  Value getConstantPaddingValue();

  // Return a vector of all the static or dynamic values (low/high padding) of
  // the op.
  inline SmallVector<OpFoldResult> getMixedPadImpl(ArrayAttr staticAttrs,
                                                   ValueRange values) {
    SmallVector<OpFoldResult> res;
    unsigned numDynamic = 0;
    unsigned count = staticAttrs.size();
    for (unsigned idx = 0; idx < count; ++idx) {
      if (ShapedType::isDynamic(staticAttrs[idx].cast<IntegerAttr>().getInt()))
        res.push_back(values[numDynamic++]);
      else
        res.push_back(staticAttrs[idx]);
    }
    return res;
  }
  SmallVector<OpFoldResult> getMixedLowPad() {
    return getMixedPadImpl(getStaticLow(), getLow());
  }
  SmallVector<OpFoldResult> getMixedHighPad() {
    return getMixedPadImpl(getStaticHigh(), getHigh());
  }
  // Return true if low padding is guaranteed to be 0.
  bool hasZeroLowPad() {
    return llvm::all_of(getMixedLowPad(), [](OpFoldResult ofr) {
      return getConstantIntValue(ofr) == static_cast<int64_t>(0);
    });
  }
  // Return true if high padding is guaranteed to be 0.
  bool hasZeroHighPad() {
    return llvm::all_of(getMixedHighPad(), [](OpFoldResult ofr) {
      return getConstantIntValue(ofr) == static_cast<int64_t>(0);
    });
  }
  /// Return the dimensions with a non-zero low or high padding.
  llvm::SmallBitVector getPaddedDims();
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::PadOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::ParallelInsertSliceOp declarations
//===----------------------------------------------------------------------===//

class ParallelInsertSliceOpAdaptor {
public:
  ParallelInsertSliceOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ParallelInsertSliceOpAdaptor(ParallelInsertSliceOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getDest();
  ::mlir::Value dest();
  ::mlir::ValueRange getOffsets();
  ::mlir::ValueRange offsets();
  ::mlir::ValueRange getSizes();
  ::mlir::ValueRange sizes();
  ::mlir::ValueRange getStrides();
  ::mlir::ValueRange strides();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr getStaticOffsetsAttr();
  ::mlir::ArrayAttr getStaticOffsets();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr getStaticSizesAttr();
  ::mlir::ArrayAttr getStaticSizes();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr getStaticStridesAttr();
  ::mlir::ArrayAttr getStaticStrides();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ParallelInsertSliceOp : public ::mlir::Op<ParallelInsertSliceOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<2>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::OffsetSizeAndStrideOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ParallelInsertSliceOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("operand_segment_sizes"), ::llvm::StringRef("static_offsets"), ::llvm::StringRef("static_sizes"), ::llvm::StringRef("static_strides")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr getOperandSegmentSizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr getOperandSegmentSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr operand_segment_sizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr operand_segment_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr getStaticOffsetsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr getStaticOffsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr static_offsetsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr static_offsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr getStaticSizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr getStaticSizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr static_sizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr static_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr getStaticStridesAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr getStaticStridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  ::mlir::StringAttr static_stridesAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr static_stridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.parallel_insert_slice");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getDest();
  ::mlir::Value dest();
  ::mlir::Operation::operand_range getOffsets();
  ::mlir::Operation::operand_range offsets();
  ::mlir::Operation::operand_range getSizes();
  ::mlir::Operation::operand_range sizes();
  ::mlir::Operation::operand_range getStrides();
  ::mlir::Operation::operand_range strides();
  ::mlir::MutableOperandRange getSourceMutable();
  ::mlir::MutableOperandRange sourceMutable();
  ::mlir::MutableOperandRange getDestMutable();
  ::mlir::MutableOperandRange destMutable();
  ::mlir::MutableOperandRange getOffsetsMutable();
  ::mlir::MutableOperandRange offsetsMutable();
  ::mlir::MutableOperandRange getSizesMutable();
  ::mlir::MutableOperandRange sizesMutable();
  ::mlir::MutableOperandRange getStridesMutable();
  ::mlir::MutableOperandRange stridesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::ArrayAttr getStaticOffsetsAttr();
  ::mlir::ArrayAttr getStaticOffsets();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr getStaticSizesAttr();
  ::mlir::ArrayAttr getStaticSizes();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr getStaticStridesAttr();
  ::mlir::ArrayAttr getStaticStrides();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  void setStaticOffsetsAttr(::mlir::ArrayAttr attr);
  void static_offsetsAttr(::mlir::ArrayAttr attr);
  void setStaticSizesAttr(::mlir::ArrayAttr attr);
  void static_sizesAttr(::mlir::ArrayAttr attr);
  void setStaticStridesAttr(::mlir::ArrayAttr attr);
  void static_stridesAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, Value dest, ArrayRef<OpFoldResult> offsets, ArrayRef<OpFoldResult> sizes, ArrayRef<OpFoldResult> strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value source, Value dest, ValueRange offsets, ValueRange sizes, ValueRange strides, ArrayRef<NamedAttribute> attrs = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value source, ::mlir::Value dest, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value dest, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::LogicalResult fold(::llvm::ArrayRef<::mlir::Attribute> operands, ::llvm::SmallVectorImpl<::mlir::OpFoldResult> &results);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  Type yieldedType() { return getDest().getType(); }

  RankedTensorType getSourceType() {
    return getSource().getType().cast<RankedTensorType>();
  }

  RankedTensorType getDestType() {
    return getDest().getType().cast<RankedTensorType>();
  }

  ParallelCombiningOpInterface getParallelCombiningParent() {
    return dyn_cast<ParallelCombiningOpInterface>(
      getOperation()->getParentOp());
  }

  /// Return the expected rank of each of the `static_offsets`, `static_sizes`
  /// and `static_strides` attributes.
  std::array<unsigned, 3> getArrayAttrMaxRanks() {
    unsigned rank = getDestType().getRank();
    return {rank, rank, rank};
  }

  /// Return the number of leading operands before `offsets`, `sizes` and
  /// `strides` operands.
  static unsigned getOffsetSizeAndStrideStartOperandIndex() { return 1; }

  /// Return the OpResult of the enclosing ForeachThreadOp that is
  /// corresponding to this ParallelInsertSliceOp.
  OpResult getTiedOpResult();
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::ParallelInsertSliceOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::RankOp declarations
//===----------------------------------------------------------------------===//

class RankOpAdaptor {
public:
  RankOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  RankOpAdaptor(RankOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getTensor();
  ::mlir::Value tensor();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class RankOp : public ::mlir::Op<RankOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::IndexType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = RankOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.rank");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getTensor();
  ::mlir::Value tensor();
  ::mlir::MutableOperandRange getTensorMutable();
  ::mlir::MutableOperandRange tensorMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type resultType0, ::mlir::Value tensor);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tensor);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tensor);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::RankOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::ReshapeOp declarations
//===----------------------------------------------------------------------===//

class ReshapeOpAdaptor {
public:
  ReshapeOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ReshapeOpAdaptor(ReshapeOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getShape();
  ::mlir::Value shape();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ReshapeOp : public ::mlir::Op<ReshapeOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ReshapeOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.reshape");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getSource();
  ::mlir::Value source();
  ::mlir::Value getShape();
  ::mlir::Value shape();
  ::mlir::MutableOperandRange getSourceMutable();
  ::mlir::MutableOperandRange sourceMutable();
  ::mlir::MutableOperandRange getShapeMutable();
  ::mlir::MutableOperandRange shapeMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getResult();
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, TensorType resultType, Value operand, Value shape);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::Value shape);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value shape);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
  TensorType getResultType() { return getResult().getType().cast<TensorType>(); }
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::ReshapeOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::SplatOp declarations
//===----------------------------------------------------------------------===//

class SplatOpAdaptor {
public:
  SplatOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  SplatOpAdaptor(SplatOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getInput();
  ::mlir::Value input();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class SplatOp : public ::mlir::Op<SplatOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::TensorType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = SplatOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.splat");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getInput();
  ::mlir::Value input();
  ::mlir::MutableOperandRange getInputMutable();
  ::mlir::MutableOperandRange inputMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value getAggregate();
  ::mlir::Value aggregate();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, Value element, Type aggregateType);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type aggregate, ::mlir::Value input);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value input);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::OpFoldResult fold(::llvm::ArrayRef<::mlir::Attribute> operands);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::SplatOp)

namespace mlir {
namespace tensor {

//===----------------------------------------------------------------------===//
// ::mlir::tensor::YieldOp declarations
//===----------------------------------------------------------------------===//

class YieldOpAdaptor {
public:
  YieldOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  YieldOpAdaptor(YieldOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value getValue();
  ::mlir::Value value();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class YieldOp : public ::mlir::Op<YieldOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::HasParent<::mlir::tensor::GenerateOp, ::mlir::tensor::PadOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::ReturnLike, ::mlir::OpTrait::IsTerminator> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = YieldOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tensor.yield");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value getValue();
  ::mlir::Value value();
  ::mlir::MutableOperandRange getValueMutable();
  ::mlir::MutableOperandRange valueMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value value);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value value);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace tensor
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tensor::YieldOp)


#endif  // GET_OP_CLASSES

