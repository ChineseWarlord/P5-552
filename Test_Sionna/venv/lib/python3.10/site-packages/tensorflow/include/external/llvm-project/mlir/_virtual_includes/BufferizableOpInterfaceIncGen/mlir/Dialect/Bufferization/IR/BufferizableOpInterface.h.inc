/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
namespace bufferization {
class BufferizableOpInterface;
namespace detail {
struct BufferizableOpInterfaceInterfaceTraits {
  struct Concept {
    bool (*bufferizesToAllocation)(const Concept *impl, ::mlir::Operation *, OpResult);
    bool (*bufferizesToMemoryRead)(const Concept *impl, ::mlir::Operation *, OpOperand &, const AnalysisState &);
    bool (*bufferizesToMemoryWrite)(const Concept *impl, ::mlir::Operation *, OpOperand &, const AnalysisState &);
    bool (*isMemoryWrite)(const Concept *impl, ::mlir::Operation *, OpResult, const AnalysisState &);
    bool (*mustBufferizeInPlace)(const Concept *impl, ::mlir::Operation *, OpOperand &, const AnalysisState &);
    SmallVector<OpResult> (*getAliasingOpResult)(const Concept *impl, ::mlir::Operation *, OpOperand &, const AnalysisState &);
    SmallVector<OpOperand *> (*getAliasingOpOperand)(const Concept *impl, ::mlir::Operation *, OpResult, const AnalysisState &);
    BufferRelation (*bufferRelation)(const Concept *impl, ::mlir::Operation *, OpResult, const AnalysisState &);
    LogicalResult (*resolveConflicts)(const Concept *impl, ::mlir::Operation *, RewriterBase &, const AnalysisState &);
    LogicalResult (*bufferize)(const Concept *impl, ::mlir::Operation *, RewriterBase &, const BufferizationOptions &);
    bool (*isWritable)(const Concept *impl, ::mlir::Operation *, Value, const AnalysisState &);
    bool (*isNotConflicting)(const Concept *impl, ::mlir::Operation *, OpOperand *, OpOperand *, const AnalysisState &);
    LogicalResult (*verifyAnalysis)(const Concept *impl, ::mlir::Operation *, const AnalysisState &);
    FailureOr<BaseMemRefType> (*getBufferType)(const Concept *impl, ::mlir::Operation *, BlockArgument, const BufferizationOptions &);
    FailureOr<unsigned> (*getMemorySpace)(const Concept *impl, ::mlir::Operation *, OpResult);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::bufferization::BufferizableOpInterface;
    Model() : Concept{bufferizesToAllocation, bufferizesToMemoryRead, bufferizesToMemoryWrite, isMemoryWrite, mustBufferizeInPlace, getAliasingOpResult, getAliasingOpOperand, bufferRelation, resolveConflicts, bufferize, isWritable, isNotConflicting, verifyAnalysis, getBufferType, getMemorySpace} {}

    static inline bool bufferizesToAllocation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult);
    static inline bool bufferizesToMemoryRead(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline bool bufferizesToMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline bool isMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state);
    static inline bool mustBufferizeInPlace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline SmallVector<OpResult> getAliasingOpResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline SmallVector<OpOperand *> getAliasingOpOperand(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state);
    static inline BufferRelation bufferRelation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state);
    static inline LogicalResult resolveConflicts(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const AnalysisState & state);
    static inline LogicalResult bufferize(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const BufferizationOptions & options);
    static inline bool isWritable(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, Value value, const AnalysisState & state);
    static inline bool isNotConflicting(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand * uRead, OpOperand * uWrite, const AnalysisState & state);
    static inline LogicalResult verifyAnalysis(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, const AnalysisState & state);
    static inline FailureOr<BaseMemRefType> getBufferType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, BlockArgument bbArg, const BufferizationOptions & options);
    static inline FailureOr<unsigned> getMemorySpace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::bufferization::BufferizableOpInterface;
    FallbackModel() : Concept{bufferizesToAllocation, bufferizesToMemoryRead, bufferizesToMemoryWrite, isMemoryWrite, mustBufferizeInPlace, getAliasingOpResult, getAliasingOpOperand, bufferRelation, resolveConflicts, bufferize, isWritable, isNotConflicting, verifyAnalysis, getBufferType, getMemorySpace} {}

    static inline bool bufferizesToAllocation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult);
    static inline bool bufferizesToMemoryRead(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline bool bufferizesToMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline bool isMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state);
    static inline bool mustBufferizeInPlace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline SmallVector<OpResult> getAliasingOpResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state);
    static inline SmallVector<OpOperand *> getAliasingOpOperand(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state);
    static inline BufferRelation bufferRelation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state);
    static inline LogicalResult resolveConflicts(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const AnalysisState & state);
    static inline LogicalResult bufferize(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const BufferizationOptions & options);
    static inline bool isWritable(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, Value value, const AnalysisState & state);
    static inline bool isNotConflicting(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand * uRead, OpOperand * uWrite, const AnalysisState & state);
    static inline LogicalResult verifyAnalysis(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, const AnalysisState & state);
    static inline FailureOr<BaseMemRefType> getBufferType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, BlockArgument bbArg, const BufferizationOptions & options);
    static inline FailureOr<unsigned> getMemorySpace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
    bool bufferizesToAllocation(::mlir::Operation *tablegen_opaque_val, OpResult opResult) const;
    bool bufferizesToMemoryRead(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const;
    bool bufferizesToMemoryWrite(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const;
    bool isMemoryWrite(::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState &state) const;
    bool mustBufferizeInPlace(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const;
    SmallVector<OpResult> getAliasingOpResult(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const;
    SmallVector<OpOperand *> getAliasingOpOperand(::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState &state) const;
    BufferRelation bufferRelation(::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState &state) const;
    LogicalResult resolveConflicts(::mlir::Operation *tablegen_opaque_val, RewriterBase &rewriter, const AnalysisState &state) const;
    LogicalResult bufferize(::mlir::Operation *tablegen_opaque_val, RewriterBase &rewriter, const BufferizationOptions &options) const;
    bool isWritable(::mlir::Operation *tablegen_opaque_val, Value value, const AnalysisState &state) const;
    bool isNotConflicting(::mlir::Operation *tablegen_opaque_val, OpOperand *uRead, OpOperand *uWrite, const AnalysisState &state) const;
    LogicalResult verifyAnalysis(::mlir::Operation *tablegen_opaque_val, const AnalysisState &state) const;
    FailureOr<BaseMemRefType> getBufferType(::mlir::Operation *tablegen_opaque_val, BlockArgument bbArg, const BufferizationOptions &options) const;
    FailureOr<unsigned> getMemorySpace(::mlir::Operation *tablegen_opaque_val, OpResult opResult) const;
  };
};template <typename ConcreteOp>
struct BufferizableOpInterfaceTrait;

} // namespace detail
class BufferizableOpInterface : public ::mlir::OpInterface<BufferizableOpInterface, detail::BufferizableOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<BufferizableOpInterface, detail::BufferizableOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::BufferizableOpInterfaceTrait<ConcreteOp> {};
  bool bufferizesToAllocation(OpResult opResult);
  bool bufferizesToMemoryRead(OpOperand & opOperand, const AnalysisState & state);
  bool bufferizesToMemoryWrite(OpOperand & opOperand, const AnalysisState & state);
  bool isMemoryWrite(OpResult opResult, const AnalysisState & state);
  bool mustBufferizeInPlace(OpOperand & opOperand, const AnalysisState & state);
  SmallVector<OpResult> getAliasingOpResult(OpOperand & opOperand, const AnalysisState & state);
  SmallVector<OpOperand *> getAliasingOpOperand(OpResult opResult, const AnalysisState & state);
  BufferRelation bufferRelation(OpResult opResult, const AnalysisState & state);
  LogicalResult resolveConflicts(RewriterBase & rewriter, const AnalysisState & state);
  LogicalResult bufferize(RewriterBase & rewriter, const BufferizationOptions & options);
  bool isWritable(Value value, const AnalysisState & state);
  bool isNotConflicting(OpOperand * uRead, OpOperand * uWrite, const AnalysisState & state);
  LogicalResult verifyAnalysis(const AnalysisState & state);
  FailureOr<BaseMemRefType> getBufferType(BlockArgument bbArg, const BufferizationOptions & options);
  FailureOr<unsigned> getMemorySpace(OpResult opResult);

    /// Resolve out-of-place tensor OpOperands with explicit allocations in the
    /// form of `bufferization.alloc_tensor` ops.
    LogicalResult resolveTensorOpOperandConflicts(
        RewriterBase &rewriter, const AnalysisState &state);

    /// Return `true` if the given OpOperand creates an alias but does neither
    /// read nor write. This implies that `bufferizesToMemoryRead` and
    /// `bufferizesToMemoryWrite` must return `false`. This method will never
    /// be called on OpOperands that do not have a tensor type.
    ///
    /// Examples of such ops are `tensor.extract_slice` and `tensor.cast`.
    bool bufferizesToAliasOnly(OpOperand &opOperand,
                               const AnalysisState &state) {
      auto bufferizableOp =
          cast<BufferizableOpInterface>(getOperation());
      return !bufferizableOp.bufferizesToMemoryRead(opOperand, state)
          && !bufferizableOp.bufferizesToMemoryWrite(opOperand, state)
          && !bufferizableOp.getAliasingOpResult(opOperand, state).empty();
    }
  
};
namespace detail {
  template <typename ConcreteOp>
  struct BufferizableOpInterfaceTrait : public ::mlir::OpInterface<BufferizableOpInterface, detail::BufferizableOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
    bool bufferizesToAllocation(OpResult opResult) {
      return false;
    }
    bool bufferizesToMemoryRead(OpOperand & opOperand, const AnalysisState & state) {
      // Does not have to be implemented for ops without tensor OpOperands.
          llvm_unreachable("bufferizesToMemoryRead not implemented");
    }
    bool bufferizesToMemoryWrite(OpOperand & opOperand, const AnalysisState & state) {
      // Does not have to be implemented for ops without tensor OpOperands.
          // Does not have to be implemented for OpOperands that do not have an
          // aliasing OpResult.
          llvm_unreachable("bufferizesToMemoryWrite not implemented");
    }
    bool isMemoryWrite(OpResult opResult, const AnalysisState & state) {
      auto bufferizableOp =
                cast<BufferizableOpInterface>((*static_cast<ConcreteOp *>(this)).getOperation());
            SmallVector<OpOperand*> opOperands =
              bufferizableOp.getAliasingOpOperand(opResult, state);
            if (opOperands.empty())
              return true;
            return llvm::any_of(
                opOperands,
                [&](OpOperand *operand) {
                  return bufferizableOp.bufferizesToMemoryWrite(*operand,
                                                                state);
                });
    }
    bool mustBufferizeInPlace(OpOperand & opOperand, const AnalysisState & state) {
      return false;
    }
    SmallVector<OpResult> getAliasingOpResult(OpOperand & opOperand, const AnalysisState & state) {
      // Does not have to be implemented for ops without tensor OpOperands.
          llvm_unreachable("getAliasingOpResult not implemented");
    }
    SmallVector<OpOperand *> getAliasingOpOperand(OpResult opResult, const AnalysisState & state) {
      assert(opResult.getType().isa<TensorType>() &&
                 "expected OpResult with tensor type");
          SmallVector<OpOperand *> result;
          auto bufferizableOp =
              cast<BufferizableOpInterface>((*static_cast<ConcreteOp *>(this)).getOperation());
          for (OpOperand &opOperand : (*static_cast<ConcreteOp *>(this)).getOperation()->getOpOperands()) {
            if (!opOperand.get().getType().isa<TensorType>())
              continue;
            SmallVector<OpResult> aliasingOpResults =
                bufferizableOp.getAliasingOpResult(opOperand, state);
            if (llvm::is_contained(aliasingOpResults, opResult))
              result.push_back(&opOperand);
          }
          return result;
    }
    BufferRelation bufferRelation(OpResult opResult, const AnalysisState & state) {
      // Does not have to be implemented for ops without tensor OpResults
          // that have an aliasing OpOperand.
          llvm_unreachable("bufferRelation not implemented");
    }
    LogicalResult resolveConflicts(RewriterBase & rewriter, const AnalysisState & state) {
      auto bufferizableOp =
              cast<BufferizableOpInterface>((*static_cast<ConcreteOp *>(this)).getOperation());
          return bufferizableOp.resolveTensorOpOperandConflicts(
              rewriter, state);
    }
    LogicalResult bufferize(RewriterBase & rewriter, const BufferizationOptions & options) {
      llvm_unreachable("bufferize not implemented");
          return failure();
    }
    bool isWritable(Value value, const AnalysisState & state) {
      return value.isa<OpResult>();
    }
    bool isNotConflicting(OpOperand * uRead, OpOperand * uWrite, const AnalysisState & state) {
      return false;
    }
    LogicalResult verifyAnalysis(const AnalysisState & state) {
      return success();
    }
    FailureOr<BaseMemRefType> getBufferType(BlockArgument bbArg, const BufferizationOptions & options) {
      assert(bbArg.getOwner()->getParentOp() == (*static_cast<ConcreteOp *>(this)) &&
                 "bbArg must belong to this op");
          assert(bbArg.getType().isa<TensorType>() &&
                 "expected tensor type");
          return bufferization::getMemRefType(bbArg, options);
    }
    FailureOr<unsigned> getMemorySpace(OpResult opResult) {
      assert(cast<BufferizableOpInterface>((*static_cast<ConcreteOp *>(this)).getOperation())
                     .bufferizesToAllocation(opResult)
                 && "expected allocation");
          return failure();
    }
  };
}// namespace detail
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::bufferizesToAllocation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).bufferizesToAllocation(opResult);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::bufferizesToMemoryRead(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).bufferizesToMemoryRead(opOperand, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::bufferizesToMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).bufferizesToMemoryWrite(opOperand, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::isMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).isMemoryWrite(opResult, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::mustBufferizeInPlace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).mustBufferizeInPlace(opOperand, state);
}
template<typename ConcreteOp>
SmallVector<OpResult> detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::getAliasingOpResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getAliasingOpResult(opOperand, state);
}
template<typename ConcreteOp>
SmallVector<OpOperand *> detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::getAliasingOpOperand(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getAliasingOpOperand(opResult, state);
}
template<typename ConcreteOp>
BufferRelation detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::bufferRelation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).bufferRelation(opResult, state);
}
template<typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::resolveConflicts(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).resolveConflicts(rewriter, state);
}
template<typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::bufferize(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const BufferizationOptions & options) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).bufferize(rewriter, options);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::isWritable(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, Value value, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).isWritable(value, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::isNotConflicting(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand * uRead, OpOperand * uWrite, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).isNotConflicting(uRead, uWrite, state);
}
template<typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::verifyAnalysis(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, const AnalysisState & state) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).verifyAnalysis(state);
}
template<typename ConcreteOp>
FailureOr<BaseMemRefType> detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::getBufferType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, BlockArgument bbArg, const BufferizationOptions & options) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getBufferType(bbArg, options);
}
template<typename ConcreteOp>
FailureOr<unsigned> detail::BufferizableOpInterfaceInterfaceTraits::Model<ConcreteOp>::getMemorySpace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getMemorySpace(opResult);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::bufferizesToAllocation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult) {
  return static_cast<const ConcreteOp *>(impl)->bufferizesToAllocation(tablegen_opaque_val, opResult);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::bufferizesToMemoryRead(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->bufferizesToMemoryRead(tablegen_opaque_val, opOperand, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::bufferizesToMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->bufferizesToMemoryWrite(tablegen_opaque_val, opOperand, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::isMemoryWrite(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->isMemoryWrite(tablegen_opaque_val, opResult, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::mustBufferizeInPlace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->mustBufferizeInPlace(tablegen_opaque_val, opOperand, state);
}
template<typename ConcreteOp>
SmallVector<OpResult> detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getAliasingOpResult(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand & opOperand, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->getAliasingOpResult(tablegen_opaque_val, opOperand, state);
}
template<typename ConcreteOp>
SmallVector<OpOperand *> detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getAliasingOpOperand(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->getAliasingOpOperand(tablegen_opaque_val, opResult, state);
}
template<typename ConcreteOp>
BufferRelation detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::bufferRelation(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->bufferRelation(tablegen_opaque_val, opResult, state);
}
template<typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::resolveConflicts(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->resolveConflicts(tablegen_opaque_val, rewriter, state);
}
template<typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::bufferize(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, RewriterBase & rewriter, const BufferizationOptions & options) {
  return static_cast<const ConcreteOp *>(impl)->bufferize(tablegen_opaque_val, rewriter, options);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::isWritable(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, Value value, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->isWritable(tablegen_opaque_val, value, state);
}
template<typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::isNotConflicting(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpOperand * uRead, OpOperand * uWrite, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->isNotConflicting(tablegen_opaque_val, uRead, uWrite, state);
}
template<typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::verifyAnalysis(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, const AnalysisState & state) {
  return static_cast<const ConcreteOp *>(impl)->verifyAnalysis(tablegen_opaque_val, state);
}
template<typename ConcreteOp>
FailureOr<BaseMemRefType> detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getBufferType(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, BlockArgument bbArg, const BufferizationOptions & options) {
  return static_cast<const ConcreteOp *>(impl)->getBufferType(tablegen_opaque_val, bbArg, options);
}
template<typename ConcreteOp>
FailureOr<unsigned> detail::BufferizableOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getMemorySpace(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, OpResult opResult) {
  return static_cast<const ConcreteOp *>(impl)->getMemorySpace(tablegen_opaque_val, opResult);
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::bufferizesToAllocation(::mlir::Operation *tablegen_opaque_val, OpResult opResult) const {
return false;
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::bufferizesToMemoryRead(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const {
// Does not have to be implemented for ops without tensor OpOperands.
          llvm_unreachable("bufferizesToMemoryRead not implemented");
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::bufferizesToMemoryWrite(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const {
// Does not have to be implemented for ops without tensor OpOperands.
          // Does not have to be implemented for OpOperands that do not have an
          // aliasing OpResult.
          llvm_unreachable("bufferizesToMemoryWrite not implemented");
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::isMemoryWrite(::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState &state) const {
auto bufferizableOp =
                cast<BufferizableOpInterface>((llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOperation());
            SmallVector<OpOperand*> opOperands =
              bufferizableOp.getAliasingOpOperand(opResult, state);
            if (opOperands.empty())
              return true;
            return llvm::any_of(
                opOperands,
                [&](OpOperand *operand) {
                  return bufferizableOp.bufferizesToMemoryWrite(*operand,
                                                                state);
                });
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::mustBufferizeInPlace(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const {
return false;
}
template<typename ConcreteModel, typename ConcreteOp>
SmallVector<OpResult> detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getAliasingOpResult(::mlir::Operation *tablegen_opaque_val, OpOperand &opOperand, const AnalysisState &state) const {
// Does not have to be implemented for ops without tensor OpOperands.
          llvm_unreachable("getAliasingOpResult not implemented");
}
template<typename ConcreteModel, typename ConcreteOp>
SmallVector<OpOperand *> detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getAliasingOpOperand(::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState &state) const {
assert(opResult.getType().isa<TensorType>() &&
                 "expected OpResult with tensor type");
          SmallVector<OpOperand *> result;
          auto bufferizableOp =
              cast<BufferizableOpInterface>((llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOperation());
          for (OpOperand &opOperand : (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOperation()->getOpOperands()) {
            if (!opOperand.get().getType().isa<TensorType>())
              continue;
            SmallVector<OpResult> aliasingOpResults =
                bufferizableOp.getAliasingOpResult(opOperand, state);
            if (llvm::is_contained(aliasingOpResults, opResult))
              result.push_back(&opOperand);
          }
          return result;
}
template<typename ConcreteModel, typename ConcreteOp>
BufferRelation detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::bufferRelation(::mlir::Operation *tablegen_opaque_val, OpResult opResult, const AnalysisState &state) const {
// Does not have to be implemented for ops without tensor OpResults
          // that have an aliasing OpOperand.
          llvm_unreachable("bufferRelation not implemented");
}
template<typename ConcreteModel, typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::resolveConflicts(::mlir::Operation *tablegen_opaque_val, RewriterBase &rewriter, const AnalysisState &state) const {
auto bufferizableOp =
              cast<BufferizableOpInterface>((llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOperation());
          return bufferizableOp.resolveTensorOpOperandConflicts(
              rewriter, state);
}
template<typename ConcreteModel, typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::bufferize(::mlir::Operation *tablegen_opaque_val, RewriterBase &rewriter, const BufferizationOptions &options) const {
llvm_unreachable("bufferize not implemented");
          return failure();
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::isWritable(::mlir::Operation *tablegen_opaque_val, Value value, const AnalysisState &state) const {
return value.isa<OpResult>();
}
template<typename ConcreteModel, typename ConcreteOp>
bool detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::isNotConflicting(::mlir::Operation *tablegen_opaque_val, OpOperand *uRead, OpOperand *uWrite, const AnalysisState &state) const {
return false;
}
template<typename ConcreteModel, typename ConcreteOp>
LogicalResult detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::verifyAnalysis(::mlir::Operation *tablegen_opaque_val, const AnalysisState &state) const {
return success();
}
template<typename ConcreteModel, typename ConcreteOp>
FailureOr<BaseMemRefType> detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getBufferType(::mlir::Operation *tablegen_opaque_val, BlockArgument bbArg, const BufferizationOptions &options) const {
assert(bbArg.getOwner()->getParentOp() == (llvm::cast<ConcreteOp>(tablegen_opaque_val)) &&
                 "bbArg must belong to this op");
          assert(bbArg.getType().isa<TensorType>() &&
                 "expected tensor type");
          return bufferization::getMemRefType(bbArg, options);
}
template<typename ConcreteModel, typename ConcreteOp>
FailureOr<unsigned> detail::BufferizableOpInterfaceInterfaceTraits::ExternalModel<ConcreteModel, ConcreteOp>::getMemorySpace(::mlir::Operation *tablegen_opaque_val, OpResult opResult) const {
assert(cast<BufferizableOpInterface>((llvm::cast<ConcreteOp>(tablegen_opaque_val)).getOperation())
                     .bufferizesToAllocation(opResult)
                 && "expected allocation");
          return failure();
}
} // namespace bufferization
} // namespace mlir
