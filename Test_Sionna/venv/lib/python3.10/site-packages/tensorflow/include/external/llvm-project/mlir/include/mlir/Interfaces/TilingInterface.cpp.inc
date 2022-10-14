/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

SmallVector<Value> mlir::TilingInterface::getDestinationOperands(OpBuilder & b) {
      return getImpl()->getDestinationOperands(getImpl(), getOperation(), b);
  }
SmallVector<StringRef> mlir::TilingInterface::getLoopIteratorTypes() {
      return getImpl()->getLoopIteratorTypes(getImpl(), getOperation());
  }
SmallVector<Range> mlir::TilingInterface::getIterationDomain(OpBuilder & b) {
      return getImpl()->getIterationDomain(getImpl(), getOperation(), b);
  }
SmallVector<Operation *> mlir::TilingInterface::getTiledImplementation(OpBuilder & b, ValueRange  dest, ArrayRef<OpFoldResult>  offsets, ArrayRef<OpFoldResult>  sizes, bool  tileDestOperands) {
      return getImpl()->getTiledImplementation(getImpl(), getOperation(), b, dest, offsets, sizes, tileDestOperands);
  }
LogicalResult mlir::TilingInterface::getResultTilePosition(OpBuilder & b, unsigned resultNumber, ArrayRef<OpFoldResult>  offsets, ArrayRef<OpFoldResult>  sizes, SmallVector<OpFoldResult> & resultOffsets, SmallVector<OpFoldResult> & resultSizes) {
      return getImpl()->getResultTilePosition(getImpl(), getOperation(), b, resultNumber, offsets, sizes, resultOffsets, resultSizes);
  }
FailureOr<Value> mlir::TilingInterface::generateResultTileValue(OpBuilder & b, unsigned resultNumber, ValueRange dest, ArrayRef<OpFoldResult> offsets, ArrayRef<OpFoldResult> sizes, bool tileDestOperands) {
      return getImpl()->generateResultTileValue(getImpl(), getOperation(), b, resultNumber, dest, offsets, sizes, tileDestOperands);
  }
