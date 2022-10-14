/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

::mlir::Block*mlir::omp::OutlineableOpenMPOpInterface::getAllocaBlock() {
      return getImpl()->getAllocaBlock(getImpl(), getOperation());
  }
::mlir::SmallVector<::mlir::Value> mlir::omp::ReductionClauseInterface::getReductionVars() {
      return getImpl()->getReductionVars(getImpl(), getOperation());
  }
