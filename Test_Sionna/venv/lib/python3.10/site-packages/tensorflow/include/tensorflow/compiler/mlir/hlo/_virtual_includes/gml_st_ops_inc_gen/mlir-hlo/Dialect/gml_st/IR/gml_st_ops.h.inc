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
namespace gml_st {
class DropDimsOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class DynamicBroadcastInDimOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class ForOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class GatherOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class LoopOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class MaterializeOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class OffsetOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class ParallelOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class PointOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class ScatterOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class SetYieldOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class SizeOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class SpaceOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class StrideOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class TileOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class TransposeDimsOp;
} // namespace gml_st
} // namespace mlir
namespace mlir {
namespace gml_st {
class YieldOp;
} // namespace gml_st
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::DropDimsOp declarations
//===----------------------------------------------------------------------===//

class DropDimsOpAdaptor {
public:
  DropDimsOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  DropDimsOpAdaptor(DropDimsOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::DenseI64ArrayAttr remaining_dimsAttr();
  ::llvm::ArrayRef<int64_t> remaining_dims();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class DropDimsOp : public ::mlir::Op<DropDimsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait, ::mlir::gml_st::ComposeSetInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DropDimsOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("remaining_dims")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr remaining_dimsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr remaining_dimsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.drop_dims");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::MutableOperandRange supersetMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::DenseI64ArrayAttr remaining_dimsAttr();
  ::llvm::ArrayRef<int64_t> remaining_dims();
  void remaining_dimsAttr(::mlir::DenseI64ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value superset, ::mlir::DenseI64ArrayAttr remaining_dims);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value superset, ::mlir::DenseI64ArrayAttr remaining_dims);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value superset, ::mlir::DenseI64ArrayAttr remaining_dims);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  ::mlir::Value compose(OpBuilder&builder);
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
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::DropDimsOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::DynamicBroadcastInDimOp declarations
//===----------------------------------------------------------------------===//

class DynamicBroadcastInDimOpAdaptor {
public:
  DynamicBroadcastInDimOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  DynamicBroadcastInDimOpAdaptor(DynamicBroadcastInDimOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value operand();
  ::mlir::Value init();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::DenseI64ArrayAttr broadcast_dimensionsAttr();
  ::llvm::ArrayRef<int64_t> broadcast_dimensions();
  ::mlir::DenseI64ArrayAttr known_expanding_dimensionsAttr();
  ::llvm::Optional<::llvm::ArrayRef<int64_t>> known_expanding_dimensions();
  ::mlir::DenseI64ArrayAttr known_nonexpanding_dimensionsAttr();
  ::llvm::Optional<::llvm::ArrayRef<int64_t>> known_nonexpanding_dimensions();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class DynamicBroadcastInDimOp : public ::mlir::Op<DynamicBroadcastInDimOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::gml_st::FusionInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = DynamicBroadcastInDimOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("broadcast_dimensions"), ::llvm::StringRef("known_expanding_dimensions"), ::llvm::StringRef("known_nonexpanding_dimensions")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr broadcast_dimensionsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr broadcast_dimensionsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr known_expanding_dimensionsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr known_expanding_dimensionsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr known_nonexpanding_dimensionsAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr known_nonexpanding_dimensionsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.dynamic_broadcast_in_dim");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value operand();
  ::mlir::Value init();
  ::mlir::MutableOperandRange operandMutable();
  ::mlir::MutableOperandRange initMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range result();
  ::mlir::DenseI64ArrayAttr broadcast_dimensionsAttr();
  ::llvm::ArrayRef<int64_t> broadcast_dimensions();
  ::mlir::DenseI64ArrayAttr known_expanding_dimensionsAttr();
  ::llvm::Optional<::llvm::ArrayRef<int64_t>> known_expanding_dimensions();
  ::mlir::DenseI64ArrayAttr known_nonexpanding_dimensionsAttr();
  ::llvm::Optional<::llvm::ArrayRef<int64_t>> known_nonexpanding_dimensions();
  void broadcast_dimensionsAttr(::mlir::DenseI64ArrayAttr attr);
  void known_expanding_dimensionsAttr(::mlir::DenseI64ArrayAttr attr);
  void known_nonexpanding_dimensionsAttr(::mlir::DenseI64ArrayAttr attr);
  ::mlir::Attribute removeKnown_expanding_dimensionsAttr();
  ::mlir::Attribute removeKnown_nonexpanding_dimensionsAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange result, ::mlir::Value operand, ::mlir::Value init, ::mlir::DenseI64ArrayAttr broadcast_dimensions, /*optional*/::mlir::DenseI64ArrayAttr known_expanding_dimensions, /*optional*/::mlir::DenseI64ArrayAttr known_nonexpanding_dimensions);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  ::mlir::Value fuse(::mlir::Location loc, ::mlir::Value subset, OpBuilder&builder);
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
  unsigned getNumInputs() {
    return this->getOperation()->getNumOperands() - getNumOutputs();
  };
  unsigned getNumOutputs() { return 1; };
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::DynamicBroadcastInDimOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::ForOp declarations
//===----------------------------------------------------------------------===//

class ForOpAdaptor {
public:
  ForOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ForOpAdaptor(ForOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange lowerBound();
  ::mlir::ValueRange upperBound();
  ::mlir::ValueRange step();
  ::mlir::ValueRange outputs();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::RegionRange getRegions();
  ::mlir::Region &region();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ForOp : public ::mlir::Op<ForOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::SingleBlockImplicitTerminator<gml_st::SetYieldOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::LoopLikeOpInterface::Trait, ::mlir::OpTrait::HasRecursiveSideEffects> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ForOpAdaptor;
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
    return ::llvm::StringLiteral("gml_st.for");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range lowerBound();
  ::mlir::Operation::operand_range upperBound();
  ::mlir::Operation::operand_range step();
  ::mlir::Operation::operand_range outputs();
  ::mlir::MutableOperandRange lowerBoundMutable();
  ::mlir::MutableOperandRange upperBoundMutable();
  ::mlir::MutableOperandRange stepMutable();
  ::mlir::MutableOperandRange outputsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range results();
  ::mlir::Region &region();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, TypeRange resultTypes, ValueRange lowerBounds, ValueRange upperBounds, ValueRange steps, ValueRange outputs, function_ref<void (OpBuilder &, Location, /*ivs=*/ValueRange,/*outputs=*/ValueRange)> bodyBuilderFn = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange results, ::mlir::ValueRange lowerBound, ::mlir::ValueRange upperBound, ::mlir::ValueRange step, ::mlir::ValueRange outputs);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  ::mlir::Region &getLoopBody();
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  /// Number of loops
  unsigned getNumLoops() { return step().size(); }

  /// Number of operands controlling the loop: lbs, ubs, steps
  unsigned getNumControlOperands() { return 3 * getNumLoops(); }

  ValueRange getInductionVars() {
    return getBody()->getArguments().take_front(getNumLoops());
  }

  /// Return whether the op has no output tensors.
  bool hasBufferSemantics() {
    return this->getOperation()->getNumResults() == 0;
  }

  /// Return terminator of the loop body.
  SetYieldOp getTerminator();

  /// Number of output operands
  unsigned getNumOutputs() { return outputs().size(); }

  /// Get the region output args.
  Block::BlockArgListType getRegionOutputArgs() {
    return getBody()->getArguments().take_back(getNumOutputs());
  }

  /// Get the region output arg that corresponds to an OpOperand.
  BlockArgument getRegionOutputArgForOpOperand(OpOperand &opOperand) {
    assert(opOperand.getOperandNumber() >= getNumControlOperands() &&
           "expected an output args operand");
    assert(opOperand.getOwner() == getOperation() &&
           "opOperand does not belong to this gml_st::ForOp operation");
    return getBody()->getArgument(opOperand.getOperandNumber() -
                                  getNumControlOperands() + getNumLoops());
  }

  /// Get the OpOperand& that corresponds to a region output arg.
  OpOperand &getOpOperandForRegionOutputArg(BlockArgument bbArg) {
    assert(bbArg.getArgNumber() >= getNumLoops() &&
           "expected a bbArg that is not an induction variable");
    assert(bbArg.getOwner()->getParentOp() == getOperation() &&
           "bbArg does not belong to the gml_st::ForOp body");
    return getOperation()->getOpOperand(
      getNumControlOperands() + bbArg.getArgNumber() - getNumLoops());
  }

  /// Get the OpResult that corresponds to an OpOperand.
  OpResult getResultForOpOperand(OpOperand &opOperand) {
    assert(opOperand.getOperandNumber() >= getNumControlOperands() &&
           "expected an output args operand");
    assert(opOperand.getOwner() == getOperation() &&
           "opOperand does not belong to this gml_st::ForOp operation");
    return getOperation()->getResult(
      opOperand.getOperandNumber() - getNumControlOperands());
  }

  /// Get the OpOperand& that corresponds to an OpResultOpOperand.
  OpOperand &getOpOperandForResult(OpResult opResult) {
    assert(opResult.getDefiningOp() == getOperation() &&
           "opResult does not belong to the gml_st::ForOp operation");
    return getOperation()->getOpOperand(
      getNumControlOperands() + opResult.getResultNumber());
  }
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::ForOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::GatherOp declarations
//===----------------------------------------------------------------------===//

class GatherOpAdaptor {
public:
  GatherOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  GatherOpAdaptor(GatherOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value operand();
  ::mlir::Value start_indices();
  ::mlir::Value init();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class GatherOp : public ::mlir::Op<GatherOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = GatherOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.gather");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value operand();
  ::mlir::Value start_indices();
  ::mlir::Value init();
  ::mlir::MutableOperandRange operandMutable();
  ::mlir::MutableOperandRange start_indicesMutable();
  ::mlir::MutableOperandRange initMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange result, ::mlir::Value operand, ::mlir::Value start_indices, ::mlir::Value init);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
  unsigned getNumInputs() {
    return this->getOperation()->getNumOperands() - getNumOutputs();
  };
  unsigned getNumOutputs() { return 1; };
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::GatherOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::LoopOp declarations
//===----------------------------------------------------------------------===//

class LoopOpAdaptor {
public:
  LoopOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  LoopOpAdaptor(LoopOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange lowerBound();
  ::mlir::ValueRange upperBound();
  ::mlir::ValueRange step();
  ::mlir::ValueRange inputs();
  ::mlir::ValueRange outputs();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr iterator_typesAttr();
  ::mlir::ArrayAttr iterator_types();
  ::mlir::ArrayAttr distribution_typesAttr();
  ::llvm::Optional< ::mlir::ArrayAttr > distribution_types();
  ::mlir::RegionRange getRegions();
  ::mlir::Region &region();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class LoopOp : public ::mlir::Op<LoopOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::SingleBlockImplicitTerminator<gml_st::YieldOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::LoopLikeOpInterface::Trait, ::mlir::OpTrait::HasRecursiveSideEffects> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = LoopOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("distribution_types"), ::llvm::StringRef("iterator_types"), ::llvm::StringRef("operand_segment_sizes")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr distribution_typesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr distribution_typesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr iterator_typesAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr iterator_typesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr operand_segment_sizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr operand_segment_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.loop");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range lowerBound();
  ::mlir::Operation::operand_range upperBound();
  ::mlir::Operation::operand_range step();
  ::mlir::Operation::operand_range inputs();
  ::mlir::Operation::operand_range outputs();
  ::mlir::MutableOperandRange lowerBoundMutable();
  ::mlir::MutableOperandRange upperBoundMutable();
  ::mlir::MutableOperandRange stepMutable();
  ::mlir::MutableOperandRange inputsMutable();
  ::mlir::MutableOperandRange outputsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range results();
  ::mlir::Region &region();
  ::mlir::ArrayAttr iterator_typesAttr();
  ::mlir::ArrayAttr iterator_types();
  ::mlir::ArrayAttr distribution_typesAttr();
  ::llvm::Optional< ::mlir::ArrayAttr > distribution_types();
  void iterator_typesAttr(::mlir::ArrayAttr attr);
  void distribution_typesAttr(::mlir::ArrayAttr attr);
  ::mlir::Attribute removeDistribution_typesAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ValueRange lowerBounds, ValueRange upperBounds, ValueRange steps, ValueRange inputs, ValueRange outputs, ArrayAttr iteratorTypes, Optional<ArrayAttr> distributionTypes, function_ref<void (OpBuilder &, Location, /*ivs=*/ValueRange,/*inputs=*/ValueRange, /*outputs=*/ValueRange)> bodyBuilderFn = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ValueRange lowerBounds, ValueRange upperBounds, ValueRange steps, ValueRange inputs, ValueRange outputs, ArrayAttr iteratorTypes, function_ref<void (OpBuilder &, Location, /*ivs=*/ValueRange,/*inputs=*/ValueRange, /*outputs=*/ValueRange)> bodyBuilderFn = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange results, ::mlir::ValueRange lowerBound, ::mlir::ValueRange upperBound, ::mlir::ValueRange step, ::mlir::ValueRange inputs, ::mlir::ValueRange outputs, ::mlir::ArrayAttr iterator_types, /*optional*/::mlir::ArrayAttr distribution_types);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
  ::mlir::LogicalResult fold(::llvm::ArrayRef<::mlir::Attribute> operands, ::llvm::SmallVectorImpl<::mlir::OpFoldResult> &results);
  ::mlir::Region &getLoopBody();
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 3 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
   /// Number of loops
   unsigned getNumLoops() { return step().size(); }

   /// Number of input operands
   unsigned getNumInputs() { return inputs().size(); }

   /// Number of output operands
   unsigned getNumOutputs() { return outputs().size(); }

   /// Number of operands controlling the loop: lbs, ubs, steps
   unsigned getNumControlOperands() { return 3 * getNumLoops(); }

   ValueRange getInductionVars() {
     return getBody()->getArguments().take_front(getNumLoops());
   }
   ValueRange getRegionInputArgs() {
     return getBody()->getArguments().slice(getNumLoops(), inputs().size());
   }
   ValueRange getRegionOutputArgs() {
     return getBody()->getArguments().take_back(outputs().size());
   }

   void setDistributionTypes(Builder& b, ArrayRef<StringRef> types) {
     assert(types.size() == getNumLoops() &&
            "expected distribution type for every dimension");
     distribution_typesAttr(b.getStrArrayAttr(types));
   }

   void setLowerBounds(ValueRange lowerBounds) {
     unsigned numLoops = getNumLoops();
     assert(lowerBounds.size() == numLoops &&
            "expected lower bounds for every loop dimension");
     for (unsigned i = 0; i < numLoops; ++i)
       setOperand(i, lowerBounds[i]);
   }

   void setUpperBounds(ValueRange upperBounds) {
     unsigned numLoops = getNumLoops();
     assert(upperBounds.size() == numLoops &&
            "expected upper bounds for every loop dimension");
     for (unsigned i = 0, pos = numLoops; i < numLoops; ++i, ++pos)
       setOperand(pos, upperBounds[i]);
   }

   void setSteps(ValueRange steps) {
     unsigned numLoops = getNumLoops();
     assert(steps.size() == numLoops &&
            "expected upper bounds for every loop dimension");
     for (unsigned i = 0, pos = 2 * numLoops; i < numLoops; ++i, ++pos)
       setOperand(pos, steps[i]);
   }

   /// Operand that corresponds to the `bbArg` block argument.
   OpOperand& getTiedOperand(BlockArgument& bbArg) {
     return getOperation()->getOpOperand(getNumControlOperands() +
                                         bbArg.getArgNumber() - getNumLoops());
   }

   /// Block argument that corresponds to the `input` or `output` operand.
   BlockArgument getTiedBlockArgument(OpOperand& operand) {
     auto operandIndex = operand.getOperandNumber();
     assert(
         operandIndex >= getNumControlOperands() &&
         operandIndex < getNumOperands() &&
         "tied block arg is defined only for `input` and `output` arguments");
     return getBody()->getArgument(operandIndex - 2 * getNumLoops());
   }

  /// Result that corresponds to the `outputs` argument of tensor type.
  OpResult getTiedOpResult(OpOperand& opOperand) {
     // No result can correspond to a memref argument.
     if (opOperand.get().getType().isa<MemRefType>()) return OpResult();

     // Check whether the operand index is in bounds of `outputs()` arg.
     int operandIndex = opOperand.getOperandNumber();
     int outputIndexStart =
         getNumControlOperands() + inputs().size();
     int outputIndexEnd = outputIndexStart + outputs().size();
     if (operandIndex < outputIndexStart || operandIndex >= outputIndexEnd)
       return OpResult();

     // Count tensor arguments in `outputs` to compute the result index.
     int tensorId = -1;
     for (int i = outputIndexStart; i <= operandIndex; ++i)
       tensorId += getOperand(i).getType().isa<RankedTensorType>();
     return getOperation()->getResult(tensorId);
   }

   /// Append `operand` to the `input` arguments.
   OpOperand& appendInputOperand(OpBuilder& builder, Value operand) {
     int numLoops = getNumLoops();
     int numInputs = getNumInputs();
     int numOutputs = getNumOutputs();

     getOperation()->insertOperands(getNumControlOperands() + numInputs,
                                    operand);
     getBody()->insertArgument(numLoops + numInputs, operand.getType(),
                               getLoc());
     getOperation()->setAttr(
         LoopOp::getOperandSegmentSizeAttr(),
         builder.getI32VectorAttr(
             {numLoops, numLoops, numLoops, numInputs + 1, numOutputs}));
     return getOperation()->getOpOperand(getNumControlOperands() + numInputs);
   }

   /// Append `operand` to the `output` arguments.
   OpOperand& appendOutputOperand(OpBuilder& builder, Value operand) {
     int numLoops = getNumLoops();
     int numInputs = getNumInputs();
     int numOutputs = getNumOutputs();

     getOperation()->insertOperands(
         getNumControlOperands() + numInputs + numOutputs, operand);
     getBody()->insertArgument(numLoops + numInputs + numOutputs,
                               operand.getType(), getLoc());
     getOperation()->setAttr(
         LoopOp::getOperandSegmentSizeAttr(),
         builder.getI32VectorAttr(
             {numLoops, numLoops, numLoops, numInputs, numOutputs + 1}));
     return getOperation()->getOpOperand(getNumControlOperands() + numInputs +
                                         numOutputs);
   }

   /// Erase `operand` from the `input` or `output` arguments.
   void eraseOperand(OpBuilder& builder, OpOperand& operand) {
     int numInputs = getNumInputs();
     int numLoops = getNumLoops();
     int numOutputs = getNumOutputs();
     int numControlOperands = getNumControlOperands();

     int operandIndex = operand.getOperandNumber();
     assert(operandIndex >= numControlOperands &&
            operandIndex < static_cast<int>(getNumOperands()) &&
            "Can erase only `input` or `output` operand");

     if (operandIndex >= numControlOperands + numInputs)
       --numOutputs;
     else
       --numInputs;

     getOperation()->eraseOperand(operandIndex);
     getBody()->eraseArgument(operandIndex - 2 * numLoops);
     getOperation()->setAttr(
         LoopOp::getOperandSegmentSizeAttr(),
         builder.getI32VectorAttr(
             {numLoops, numLoops, numLoops, numInputs, numOutputs}));
   }

   OpOperand* findInputOperand(Value value) {
     OperandRange::iterator it = llvm::find(inputs(), value);
     if (it == inputs().end()) return nullptr;
     return it.getBase();
   }

   OpOperand* findOutputOperand(Value value) {
     OperandRange::iterator it = llvm::find(outputs(), value);
     if (it == outputs().end()) return nullptr;
     return it.getBase();
   }

   /// Return whether the op has only MemRef input and outputs.
   bool hasBufferSemantics() {
     Operation* op = this->getOperation();
     return op->getNumResults() == 0 &&
            llvm::all_of(op->getOpOperands(), [&](OpOperand & operand) {
              return !operand.get().getType().template isa<ShapedType>() ||
                     operand.get().getType().template isa<MemRefType>();
            });
   }

   static constexpr StringRef getParallelIteratorTypeName() {
     return "parallel";
   }
   static constexpr StringRef getDistributionTypesAttrName() {
     return "distribution_types";
   }
   static constexpr StringRef getIteratorTypesAttrName() {
     return "iterator_types";
   }


   /// Return whether the loop dimension is parallel or not.
   bool isParallelDimension(unsigned dim) {
     StringAttr attr = this->iterator_types()[dim].cast<StringAttr>();
     return attr.getValue() == getParallelIteratorTypeName();
   }
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::LoopOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::MaterializeOp declarations
//===----------------------------------------------------------------------===//

class MaterializeOpAdaptor {
public:
  MaterializeOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  MaterializeOpAdaptor(MaterializeOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value source();
  ::mlir::Value set();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class MaterializeOp : public ::mlir::Op<MaterializeOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MaterializeOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.materialize");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value source();
  ::mlir::Value set();
  ::mlir::MutableOperandRange sourceMutable();
  ::mlir::MutableOperandRange setMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value source, ::mlir::Value set);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value source, ::mlir::Value set);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value source, ::mlir::Value set);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::MaterializeOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::OffsetOp declarations
//===----------------------------------------------------------------------===//

class OffsetOpAdaptor {
public:
  OffsetOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  OffsetOpAdaptor(OffsetOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value tile();
  ::mlir::Value dim();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class OffsetOp : public ::mlir::Op<OffsetOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::IndexType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = OffsetOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.offset");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value tile();
  ::mlir::Value dim();
  ::mlir::MutableOperandRange tileMutable();
  ::mlir::MutableOperandRange dimMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tile, ::mlir::Value dim);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tile, ::mlir::Value dim);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tile, ::mlir::Value dim);
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
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::OffsetOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::ParallelOp declarations
//===----------------------------------------------------------------------===//

class ParallelOpAdaptor {
public:
  ParallelOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ParallelOpAdaptor(ParallelOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange lowerBound();
  ::mlir::ValueRange upperBound();
  ::mlir::ValueRange step();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::RegionRange getRegions();
  ::mlir::Region &region();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ParallelOp : public ::mlir::Op<ParallelOp, ::mlir::OpTrait::OneRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::SingleBlockImplicitTerminator<gml_st::SetYieldOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::LoopLikeOpInterface::Trait, ::mlir::OpTrait::HasRecursiveSideEffects> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ParallelOpAdaptor;
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
    return ::llvm::StringLiteral("gml_st.parallel");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range lowerBound();
  ::mlir::Operation::operand_range upperBound();
  ::mlir::Operation::operand_range step();
  ::mlir::MutableOperandRange lowerBoundMutable();
  ::mlir::MutableOperandRange upperBoundMutable();
  ::mlir::MutableOperandRange stepMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range results();
  ::mlir::Region &region();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, TypeRange resultTypes, ValueRange lowerBounds, ValueRange upperBounds, ValueRange steps, function_ref<void (OpBuilder &, Location, /*ivs=*/ValueRange)> bodyBuilderFn = nullptr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange results, ::mlir::ValueRange lowerBound, ::mlir::ValueRange upperBound, ::mlir::ValueRange step);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  ::mlir::Region &getLoopBody();
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 1 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
  /// Number of loops
  unsigned getNumLoops() { return step().size(); }

  /// Number of operands controlling the loop: lbs, ubs, steps
  unsigned getNumControlOperands() { return 3 * getNumLoops(); }

  ValueRange getInductionVars() {
    return getBody()->getArguments().take_front(getNumLoops());
  }

  /// Return whether the op has no output tensors.
  bool hasBufferSemantics() {
    return this->getOperation()->getNumResults() == 0;
  }

  /// Return terminator of the loop body.
  SetYieldOp getTerminator();
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::ParallelOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::PointOp declarations
//===----------------------------------------------------------------------===//

class PointOpAdaptor {
public:
  PointOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  PointOpAdaptor(PointOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::ValueRange dynamic_indices();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr static_indicesAttr();
  ::mlir::ArrayAttr static_indices();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class PointOp : public ::mlir::Op<PointOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::gml_st::PointType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::gml_st::ComposeSetInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = PointOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("static_indices")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr static_indicesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr static_indicesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.point");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::Operation::operand_range dynamic_indices();
  ::mlir::MutableOperandRange supersetMutable();
  ::mlir::MutableOperandRange dynamic_indicesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::ArrayAttr static_indicesAttr();
  ::mlir::ArrayAttr static_indices();
  void static_indicesAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value superset, ::mlir::ValueRange dynamic_indices, ::mlir::ArrayAttr static_indices);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value superset, ::mlir::ValueRange dynamic_indices, ::mlir::ArrayAttr static_indices);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value superset, ::mlir::ValueRange dynamic_indices, ::mlir::ArrayAttr static_indices);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  ::mlir::Value compose(OpBuilder&builder);
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
  unsigned getRank() { return static_indices().size(); }
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::PointOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::ScatterOp declarations
//===----------------------------------------------------------------------===//

class ScatterOpAdaptor {
public:
  ScatterOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  ScatterOpAdaptor(ScatterOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value indices();
  ::mlir::Value updates();
  ::mlir::Value init();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class ScatterOp : public ::mlir::Op<ScatterOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<3>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ScatterOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.scatter");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value indices();
  ::mlir::Value updates();
  ::mlir::Value init();
  ::mlir::MutableOperandRange indicesMutable();
  ::mlir::MutableOperandRange updatesMutable();
  ::mlir::MutableOperandRange initMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange result, ::mlir::Value indices, ::mlir::Value updates, ::mlir::Value init);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
  unsigned getNumInputs() {
    return this->getOperation()->getNumOperands() - getNumOutputs();
  };
  unsigned getNumOutputs() { return 1; };
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::ScatterOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::SetYieldOp declarations
//===----------------------------------------------------------------------===//

class SetYieldOpAdaptor {
public:
  SetYieldOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  SetYieldOpAdaptor(SetYieldOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange srcs();
  ::mlir::ValueRange dsts();
  ::mlir::ValueRange sets();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr accumulatorFlagsAttr();
  ::mlir::ArrayAttr accumulatorFlags();
  ::mlir::RegionRange getRegions();
  ::mlir::RegionRange accumulators();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class SetYieldOp : public ::mlir::Op<SetYieldOp, ::mlir::OpTrait::VariadicRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::SingleBlockImplicitTerminator<YieldOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::ReturnLike, ::mlir::OpTrait::IsTerminator> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = SetYieldOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("accumulatorFlags")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr accumulatorFlagsAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr accumulatorFlagsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.set_yield");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range srcs();
  ::mlir::Operation::operand_range dsts();
  ::mlir::Operation::operand_range sets();
  ::mlir::MutableOperandRange srcsMutable();
  ::mlir::MutableOperandRange dstsMutable();
  ::mlir::MutableOperandRange setsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::MutableArrayRef<::mlir::Region> accumulators();
  ::mlir::ArrayAttr accumulatorFlagsAttr();
  ::mlir::ArrayAttr accumulatorFlags();
  void accumulatorFlagsAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ValueRange srcs, ValueRange dsts, ValueRange sets);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ValueRange srcs, ValueRange dsts, ValueRange sets, ArrayAttr accumulatorFlags, ArrayRef<function_ref<void(OpBuilder &, Location, Value, Value)>> combiners);
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
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
  unsigned getNumUpdates() { return srcs().size(); }

  // Methods for `srcs` arguments.
  OpOperand* getSrcOperand(unsigned i) {
    return &getOperation()->getOpOperand(3 * i);
  }

  SmallVector<OpOperand*> getSrcOperands() {
    SmallVector<OpOperand*> operands;
    for (unsigned i = 0, e = getNumOperands(); i < e; i += 3)
      operands.push_back(&getOperation()->getOpOperand(i));
    return operands;
  }

  bool isSrcOperand(OpOperand& operand) {
    return operand.getOperandNumber() % 3 == 0;
  }

  // Methods for `dst` arguments.
  OpOperand* getDstOperand(unsigned i) {
    return &getOperation()->getOpOperand(3 * i + 1);
  }

  SmallVector<OpOperand*> getDstOperands() {
    SmallVector<OpOperand*> operands;
    for (unsigned i = 1, e = getNumOperands(); i < e; i += 3)
      operands.push_back(&getOperation()->getOpOperand(i));
    return operands;
  }

  FailureOr<OpResult> getTiedOpResult(OpOperand &opOperand) {
    if (!isDstOperand(opOperand)) return failure();

    auto parent = getOperation()->getBlock()->getParentOp();
    if (isa<ParallelOp>(parent) || isa<ForOp>(parent)) {
      return parent->getResult(0);
    }
    return failure();
  }

  bool isDstOperand(OpOperand& operand) {
    return operand.getOperandNumber() % 3 == 1;
  }

  // Methods for `set` arguments.
  OpOperand* getSetOperand(unsigned i) {
    return &getOperation()->getOpOperand(3 * i + 2);
  }

  SmallVector<OpOperand*> getSetOperands() {
    SmallVector<OpOperand*> operands;
    for (unsigned i = 2, e = getNumOperands(); i < e; i += 3)
      operands.push_back(&getOperation()->getOpOperand(i));
    return operands;
  }

  bool isSetOperand(OpOperand& operand) {
    return operand.getOperandNumber() % 3 == 2;
  }
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::SetYieldOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::SizeOp declarations
//===----------------------------------------------------------------------===//

class SizeOpAdaptor {
public:
  SizeOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  SizeOpAdaptor(SizeOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value tile();
  ::mlir::Value dim();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class SizeOp : public ::mlir::Op<SizeOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::IndexType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = SizeOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.size");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value tile();
  ::mlir::Value dim();
  ::mlir::MutableOperandRange tileMutable();
  ::mlir::MutableOperandRange dimMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tile, ::mlir::Value dim);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tile, ::mlir::Value dim);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tile, ::mlir::Value dim);
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
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::SizeOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::SpaceOp declarations
//===----------------------------------------------------------------------===//

class SpaceOpAdaptor {
public:
  SpaceOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  SpaceOpAdaptor(SpaceOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange dynamic_sizes();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class SpaceOp : public ::mlir::Op<SpaceOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::gml_st::TileType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = SpaceOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("static_sizes")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr static_sizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr static_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.space");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range dynamic_sizes();
  ::mlir::MutableOperandRange dynamic_sizesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  void static_sizesAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::ValueRange dynamic_sizes, ::mlir::ArrayAttr static_sizes);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange dynamic_sizes, ::mlir::ArrayAttr static_sizes);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange dynamic_sizes, ::mlir::ArrayAttr static_sizes);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
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
  unsigned getNumDynamicEntriesUpToIdx(unsigned idx);
  mlir::Value getDynamicSize(unsigned idx);
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::SpaceOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::StrideOp declarations
//===----------------------------------------------------------------------===//

class StrideOpAdaptor {
public:
  StrideOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  StrideOpAdaptor(StrideOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value tile();
  ::mlir::Value dim();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class StrideOp : public ::mlir::Op<StrideOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::IndexType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::NOperands<2>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = StrideOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.stride");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value tile();
  ::mlir::Value dim();
  ::mlir::MutableOperandRange tileMutable();
  ::mlir::MutableOperandRange dimMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value tile, ::mlir::Value dim);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value tile, ::mlir::Value dim);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value tile, ::mlir::Value dim);
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
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::StrideOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::TileOp declarations
//===----------------------------------------------------------------------===//

class TileOpAdaptor {
public:
  TileOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  TileOpAdaptor(TileOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::ValueRange offsets();
  ::mlir::ValueRange sizes();
  ::mlir::ValueRange strides();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class TileOp : public ::mlir::Op<TileOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::gml_st::TileType>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::AtLeastNOperands<1>::Impl, ::mlir::OpTrait::AttrSizedOperandSegments, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OffsetSizeAndStrideOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait, ::mlir::gml_st::ComposeSetInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TileOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("operand_segment_sizes"), ::llvm::StringRef("static_offsets"), ::llvm::StringRef("static_sizes"), ::llvm::StringRef("static_strides")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr operand_segment_sizesAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr operand_segment_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr static_offsetsAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr static_offsetsAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr static_sizesAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr static_sizesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr static_stridesAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr static_stridesAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.tile");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::Operation::operand_range offsets();
  ::mlir::Operation::operand_range sizes();
  ::mlir::Operation::operand_range strides();
  ::mlir::MutableOperandRange supersetMutable();
  ::mlir::MutableOperandRange offsetsMutable();
  ::mlir::MutableOperandRange sizesMutable();
  ::mlir::MutableOperandRange stridesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::ArrayAttr static_offsetsAttr();
  ::mlir::ArrayAttr static_offsets();
  ::mlir::ArrayAttr static_sizesAttr();
  ::mlir::ArrayAttr static_sizes();
  ::mlir::ArrayAttr static_stridesAttr();
  ::mlir::ArrayAttr static_strides();
  void static_offsetsAttr(::mlir::ArrayAttr attr);
  void static_sizesAttr(::mlir::ArrayAttr attr);
  void static_stridesAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value superset, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value superset, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value superset, ::mlir::ValueRange offsets, ::mlir::ValueRange sizes, ::mlir::ValueRange strides, ::mlir::ArrayAttr static_offsets, ::mlir::ArrayAttr static_sizes, ::mlir::ArrayAttr static_strides);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  ::mlir::Value compose(OpBuilder&builder);
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
  /// Return the expected rank of each of the`static_offsets`, `static_sizes`
  /// and `static_strides` attributes.
  std::array<unsigned, 3> getArrayAttrMaxRanks() {
    unsigned rank = superset().getType().cast<TileType>().getRank();
    return {rank, rank, rank};
  }
  /// Return the number of leading operands before the `offsets`, `sizes` and
  /// and `strides` operands.
  static unsigned getOffsetSizeAndStrideStartOperandIndex() { return 1; }
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::TileOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::TransposeDimsOp declarations
//===----------------------------------------------------------------------===//

class TransposeDimsOpAdaptor {
public:
  TransposeDimsOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  TransposeDimsOpAdaptor(TransposeDimsOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::DenseI64ArrayAttr permutationAttr();
  ::llvm::ArrayRef<int64_t> permutation();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class TransposeDimsOp : public ::mlir::Op<TransposeDimsOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::Type>::Impl, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::OneOperand, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::InferTypeOpInterface::Trait, ::mlir::gml_st::ComposeSetInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = TransposeDimsOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("permutation")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr permutationAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr permutationAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.transpose_dims");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value superset();
  ::mlir::MutableOperandRange supersetMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value result();
  ::mlir::DenseI64ArrayAttr permutationAttr();
  ::llvm::ArrayRef<int64_t> permutation();
  void permutationAttr(::mlir::DenseI64ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type result, ::mlir::Value superset, ::mlir::DenseI64ArrayAttr permutation);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Value superset, ::mlir::DenseI64ArrayAttr permutation);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value superset, ::mlir::DenseI64ArrayAttr permutation);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::LogicalResult inferReturnTypes(::mlir::MLIRContext *context, ::llvm::Optional<::mlir::Location> location, ::mlir::ValueRange operands, ::mlir::DictionaryAttr attributes, ::mlir::RegionRange regions, ::llvm::SmallVectorImpl<::mlir::Type>&inferredReturnTypes);
  ::mlir::Value compose(OpBuilder&builder);
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
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::TransposeDimsOp)

namespace mlir {
namespace gml_st {

//===----------------------------------------------------------------------===//
// ::mlir::gml_st::YieldOp declarations
//===----------------------------------------------------------------------===//

class YieldOpAdaptor {
public:
  YieldOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  YieldOpAdaptor(YieldOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange values();
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class YieldOp : public ::mlir::Op<YieldOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::HasParent<::mlir::gml_st::LoopOp, ::mlir::gml_st::SetYieldOp>::Impl, ::mlir::OpTrait::OpInvariants, ::mlir::MemoryEffectOpInterface::Trait, ::mlir::OpTrait::ReturnLike, ::mlir::OpTrait::IsTerminator> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = YieldOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    return {};
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("gml_st.yield");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range values();
  ::mlir::MutableOperandRange valuesMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ValueRange values);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static ::mlir::ParseResult parse(::mlir::OpAsmParser &parser, ::mlir::OperationState &result);
  void print(::mlir::OpAsmPrinter &_odsPrinter);
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &effects);
public:
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::YieldOp)


#endif  // GET_OP_CLASSES

