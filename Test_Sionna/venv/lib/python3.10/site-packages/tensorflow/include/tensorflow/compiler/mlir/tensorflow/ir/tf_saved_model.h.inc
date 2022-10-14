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
namespace tf_saved_model {
class AssetOp;
} // namespace tf_saved_model
} // namespace mlir
namespace mlir {
namespace tf_saved_model {
class GlobalTensorOp;
} // namespace tf_saved_model
} // namespace mlir
namespace mlir {
namespace tf_saved_model {
class SessionInitializerOp;
} // namespace tf_saved_model
} // namespace mlir
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace mlir {
namespace tf_saved_model {

//===----------------------------------------------------------------------===//
// ::mlir::tf_saved_model::AssetOp declarations
//===----------------------------------------------------------------------===//

class AssetOpAdaptor {
public:
  AssetOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  AssetOpAdaptor(AssetOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::StringAttr sym_nameAttr();
  ::llvm::StringRef sym_name();
  ::mlir::StringAttr filenameAttr();
  ::llvm::StringRef filename();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class AssetOp : public ::mlir::Op<AssetOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants, ::mlir::SymbolOpInterface::Trait> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = AssetOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("filename"), ::llvm::StringRef("sym_name")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr filenameAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr filenameAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr sym_nameAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr sym_nameAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_saved_model.asset");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::StringAttr sym_nameAttr();
  ::llvm::StringRef sym_name();
  ::mlir::StringAttr filenameAttr();
  ::llvm::StringRef filename();
  void sym_nameAttr(::mlir::StringAttr attr);
  void filenameAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::StringAttr sym_name, ::mlir::StringAttr filename);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::StringAttr sym_name, ::mlir::StringAttr filename);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::StringRef sym_name, ::llvm::StringRef filename);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::llvm::StringRef sym_name, ::llvm::StringRef filename);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
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
} // namespace tf_saved_model
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tf_saved_model::AssetOp)

namespace mlir {
namespace tf_saved_model {

//===----------------------------------------------------------------------===//
// ::mlir::tf_saved_model::GlobalTensorOp declarations
//===----------------------------------------------------------------------===//

class GlobalTensorOpAdaptor {
public:
  GlobalTensorOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  GlobalTensorOpAdaptor(GlobalTensorOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::StringAttr sym_nameAttr();
  ::llvm::StringRef sym_name();
  ::mlir::ElementsAttr valueAttr();
  ::mlir::ElementsAttr value();
  ::mlir::TypeAttr typeAttr();
  ::mlir::Type type();
  ::mlir::UnitAttr is_mutableAttr();
  bool is_mutable();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class GlobalTensorOp : public ::mlir::Op<GlobalTensorOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = GlobalTensorOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("is_mutable"), ::llvm::StringRef("sym_name"), ::llvm::StringRef("type"), ::llvm::StringRef("value")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr is_mutableAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr is_mutableAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  ::mlir::StringAttr sym_nameAttrName() {
    return getAttributeNameForIndex(1);
  }

  static ::mlir::StringAttr sym_nameAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 1);
  }

  ::mlir::StringAttr typeAttrName() {
    return getAttributeNameForIndex(2);
  }

  static ::mlir::StringAttr typeAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 2);
  }

  ::mlir::StringAttr valueAttrName() {
    return getAttributeNameForIndex(3);
  }

  static ::mlir::StringAttr valueAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 3);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_saved_model.global_tensor");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::StringAttr sym_nameAttr();
  ::llvm::StringRef sym_name();
  ::mlir::ElementsAttr valueAttr();
  ::mlir::ElementsAttr value();
  ::mlir::TypeAttr typeAttr();
  ::mlir::Type type();
  ::mlir::UnitAttr is_mutableAttr();
  bool is_mutable();
  void sym_nameAttr(::mlir::StringAttr attr);
  void valueAttr(::mlir::ElementsAttr attr);
  void typeAttr(::mlir::TypeAttr attr);
  void is_mutableAttr(::mlir::UnitAttr attr);
  ::mlir::Attribute removeIs_mutableAttr();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::StringAttr sym_name, ::mlir::ElementsAttr value, ::mlir::TypeAttr type, /*optional*/::mlir::UnitAttr is_mutable);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::StringAttr sym_name, ::mlir::ElementsAttr value, ::mlir::TypeAttr type, /*optional*/::mlir::UnitAttr is_mutable);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::StringRef sym_name, ::mlir::ElementsAttr value, ::mlir::Type type, /*optional*/bool is_mutable);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::llvm::StringRef sym_name, ::mlir::ElementsAttr value, ::mlir::Type type, /*optional*/bool is_mutable);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
private:
  ::mlir::StringAttr getAttributeNameForIndex(unsigned index) {
    return getAttributeNameForIndex((*this)->getName(), index);
  }

  static ::mlir::StringAttr getAttributeNameForIndex(::mlir::OperationName name, unsigned index) {
    assert(index < 4 && "invalid attribute index");
    return name.getRegisteredInfo()->getAttributeNames()[index];
  }

public:
};
} // namespace tf_saved_model
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tf_saved_model::GlobalTensorOp)

namespace mlir {
namespace tf_saved_model {

//===----------------------------------------------------------------------===//
// ::mlir::tf_saved_model::SessionInitializerOp declarations
//===----------------------------------------------------------------------===//

class SessionInitializerOpAdaptor {
public:
  SessionInitializerOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr, ::mlir::RegionRange regions = {});

  SessionInitializerOpAdaptor(SessionInitializerOp op);

  ::mlir::ValueRange getOperands();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::DictionaryAttr getAttributes();
  ::mlir::ArrayAttr initializersAttr();
  ::mlir::ArrayAttr initializers();
  ::mlir::LogicalResult verify(::mlir::Location loc);
private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
  ::mlir::RegionRange odsRegions;
  ::llvm::Optional<::mlir::OperationName> odsOpName;
};
class SessionInitializerOp : public ::mlir::Op<SessionInitializerOp, ::mlir::OpTrait::ZeroRegions, ::mlir::OpTrait::ZeroResults, ::mlir::OpTrait::ZeroSuccessors, ::mlir::OpTrait::ZeroOperands, ::mlir::OpTrait::OpInvariants> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = SessionInitializerOpAdaptor;
public:
  static ::llvm::ArrayRef<::llvm::StringRef> getAttributeNames() {
    static ::llvm::StringRef attrNames[] = {::llvm::StringRef("initializers")};
    return ::llvm::makeArrayRef(attrNames);
  }

  ::mlir::StringAttr initializersAttrName() {
    return getAttributeNameForIndex(0);
  }

  static ::mlir::StringAttr initializersAttrName(::mlir::OperationName name) {
    return getAttributeNameForIndex(name, 0);
  }

  static constexpr ::llvm::StringLiteral getOperationName() {
    return ::llvm::StringLiteral("tf_saved_model.session_initializer");
  }

  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::ArrayAttr initializersAttr();
  ::mlir::ArrayAttr initializers();
  void initializersAttr(::mlir::ArrayAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::ArrayAttr initializers);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ArrayAttr initializers);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  ::mlir::LogicalResult verifyInvariantsImpl();
  ::mlir::LogicalResult verifyInvariants();
  ::mlir::LogicalResult verify();
  static void getCanonicalizationPatterns(::mlir::RewritePatternSet &results, ::mlir::MLIRContext *context);
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
} // namespace tf_saved_model
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::tf_saved_model::SessionInitializerOp)


#endif  // GET_OP_CLASSES

