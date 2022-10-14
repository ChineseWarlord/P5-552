/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace gml_st {
class FusionInterface;
namespace detail {
struct FusionInterfaceInterfaceTraits {
  struct Concept {
    ::mlir::Value (*fuse)(const Concept *impl, ::mlir::Operation *, ::mlir::Location, ::mlir::Value, OpBuilder&);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::gml_st::FusionInterface;
    Model() : Concept{fuse} {}

    static inline ::mlir::Value fuse(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Location loc, ::mlir::Value subset, OpBuilder& builder);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::gml_st::FusionInterface;
    FallbackModel() : Concept{fuse} {}

    static inline ::mlir::Value fuse(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Location loc, ::mlir::Value subset, OpBuilder& builder);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};template <typename ConcreteOp>
struct FusionInterfaceTrait;

} // namespace detail
class FusionInterface : public ::mlir::OpInterface<FusionInterface, detail::FusionInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<FusionInterface, detail::FusionInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::FusionInterfaceTrait<ConcreteOp> {};
  ::mlir::Value fuse(::mlir::Location loc, ::mlir::Value subset, OpBuilder& builder);
};
namespace detail {
  template <typename ConcreteOp>
  struct FusionInterfaceTrait : public ::mlir::OpInterface<FusionInterface, detail::FusionInterfaceInterfaceTraits>::Trait<ConcreteOp> {
  };
}// namespace detail
template<typename ConcreteOp>
::mlir::Value detail::FusionInterfaceInterfaceTraits::Model<ConcreteOp>::fuse(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Location loc, ::mlir::Value subset, OpBuilder& builder) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).fuse(loc, subset, builder);
}
template<typename ConcreteOp>
::mlir::Value detail::FusionInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::fuse(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::mlir::Location loc, ::mlir::Value subset, OpBuilder& builder) {
  return static_cast<const ConcreteOp *>(impl)->fuse(tablegen_opaque_val, loc, subset, builder);
}
} // namespace gml_st
} // namespace mlir
