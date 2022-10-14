/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Dialect Declarations                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace gml_st {

class GmlStDialect : public ::mlir::Dialect {
  explicit GmlStDialect(::mlir::MLIRContext *context);

  void initialize();
  friend class ::mlir::MLIRContext;
public:
  ~GmlStDialect() override;
  static constexpr ::llvm::StringLiteral getDialectNamespace() {
    return ::llvm::StringLiteral("gml_st");
  }

  /// Parse a type registered to this dialect.
  ::mlir::Type parseType(::mlir::DialectAsmParser &parser) const override;

  /// Print a type registered to this dialect.
  void printType(::mlir::Type type,
                 ::mlir::DialectAsmPrinter &os) const override;
};
} // namespace gml_st
} // namespace mlir
MLIR_DECLARE_EXPLICIT_TYPE_ID(::mlir::gml_st::GmlStDialect)
