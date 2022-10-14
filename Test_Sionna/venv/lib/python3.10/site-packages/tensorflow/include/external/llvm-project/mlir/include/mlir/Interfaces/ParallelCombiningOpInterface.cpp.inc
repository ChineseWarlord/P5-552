/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

::mlir::OpResult mlir::ParallelCombiningOpInterface::getParentResult(int64_t idx) {
      return getImpl()->getParentResult(getImpl(), getOperation(), idx);
  }
::llvm::iterator_range<Block::iterator> mlir::ParallelCombiningOpInterface::getYieldingOps() {
      return getImpl()->getYieldingOps(getImpl(), getOperation());
  }
::llvm::SmallVector<::mlir::Type> mlir::ParallelCombiningOpInterface::getYieldedTypes() {
      return getImpl()->getYieldedTypes(getImpl(), getOperation());
  }
