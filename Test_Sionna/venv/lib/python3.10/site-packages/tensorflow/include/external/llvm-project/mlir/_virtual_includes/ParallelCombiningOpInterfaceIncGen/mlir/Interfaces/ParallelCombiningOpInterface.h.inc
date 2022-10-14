/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
class ParallelCombiningOpInterface;
namespace detail {
struct ParallelCombiningOpInterfaceInterfaceTraits {
  struct Concept {
    ::mlir::OpResult (*getParentResult)(const Concept *impl, ::mlir::Operation *, int64_t);
    ::llvm::iterator_range<Block::iterator> (*getYieldingOps)(const Concept *impl, ::mlir::Operation *);
    ::llvm::SmallVector<::mlir::Type> (*getYieldedTypes)(const Concept *impl, ::mlir::Operation *);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::ParallelCombiningOpInterface;
    Model() : Concept{getParentResult, getYieldingOps, getYieldedTypes} {}

    static inline ::mlir::OpResult getParentResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, int64_t idx);
    static inline ::llvm::iterator_range<Block::iterator> getYieldingOps(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::llvm::SmallVector<::mlir::Type> getYieldedTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::ParallelCombiningOpInterface;
    FallbackModel() : Concept{getParentResult, getYieldingOps, getYieldedTypes} {}

    static inline ::mlir::OpResult getParentResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, int64_t idx);
    static inline ::llvm::iterator_range<Block::iterator> getYieldingOps(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
    static inline ::llvm::SmallVector<::mlir::Type> getYieldedTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};template <typename ConcreteOp>
struct ParallelCombiningOpInterfaceTrait;

} // namespace detail
class ParallelCombiningOpInterface : public ::mlir::OpInterface<ParallelCombiningOpInterface, detail::ParallelCombiningOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<ParallelCombiningOpInterface, detail::ParallelCombiningOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::ParallelCombiningOpInterfaceTrait<ConcreteOp> {};
  ::mlir::OpResult getParentResult(int64_t idx);
  ::llvm::iterator_range<Block::iterator> getYieldingOps();
  ::llvm::SmallVector<::mlir::Type> getYieldedTypes();
};
namespace detail {
  template <typename ConcreteOp>
  struct ParallelCombiningOpInterfaceTrait : public ::mlir::OpInterface<ParallelCombiningOpInterface, detail::ParallelCombiningOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    static ::mlir::LogicalResult verifyTrait(::mlir::Operation *op) {
      return verifyParallelCombiningOpInterface(op);
    }
  };
}// namespace detail
template<typename ConcreteOp>
::mlir::OpResult detail::ParallelCombiningOpInterfaceInterfaceTraits::Model<ConcreteOp>::getParentResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, int64_t idx) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getParentResult(idx);
}
template<typename ConcreteOp>
::llvm::iterator_range<Block::iterator> detail::ParallelCombiningOpInterfaceInterfaceTraits::Model<ConcreteOp>::getYieldingOps(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getYieldingOps();
}
template<typename ConcreteOp>
::llvm::SmallVector<::mlir::Type> detail::ParallelCombiningOpInterfaceInterfaceTraits::Model<ConcreteOp>::getYieldedTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getYieldedTypes();
}
template<typename ConcreteOp>
::mlir::OpResult detail::ParallelCombiningOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getParentResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, int64_t idx) {
  return static_cast<const ConcreteOp *>(impl)->getParentResult(tablegen_opaque_val, idx);
}
template<typename ConcreteOp>
::llvm::iterator_range<Block::iterator> detail::ParallelCombiningOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getYieldingOps(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getYieldingOps(tablegen_opaque_val);
}
template<typename ConcreteOp>
::llvm::SmallVector<::mlir::Type> detail::ParallelCombiningOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getYieldedTypes(const Concept *impl, ::mlir::Operation *tablegen_opaque_val) {
  return static_cast<const ConcreteOp *>(impl)->getYieldedTypes(tablegen_opaque_val);
}
} // namespace mlir
