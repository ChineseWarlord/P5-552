/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

bool mlir::bufferization::BufferizableOpInterface::bufferizesToAllocation(OpResult opResult) {
      return getImpl()->bufferizesToAllocation(getImpl(), getOperation(), opResult);
  }
bool mlir::bufferization::BufferizableOpInterface::bufferizesToMemoryRead(OpOperand & opOperand, const AnalysisState & state) {
      return getImpl()->bufferizesToMemoryRead(getImpl(), getOperation(), opOperand, state);
  }
bool mlir::bufferization::BufferizableOpInterface::bufferizesToMemoryWrite(OpOperand & opOperand, const AnalysisState & state) {
      return getImpl()->bufferizesToMemoryWrite(getImpl(), getOperation(), opOperand, state);
  }
bool mlir::bufferization::BufferizableOpInterface::isMemoryWrite(OpResult opResult, const AnalysisState & state) {
      return getImpl()->isMemoryWrite(getImpl(), getOperation(), opResult, state);
  }
bool mlir::bufferization::BufferizableOpInterface::mustBufferizeInPlace(OpOperand & opOperand, const AnalysisState & state) {
      return getImpl()->mustBufferizeInPlace(getImpl(), getOperation(), opOperand, state);
  }
SmallVector<OpResult> mlir::bufferization::BufferizableOpInterface::getAliasingOpResult(OpOperand & opOperand, const AnalysisState & state) {
      return getImpl()->getAliasingOpResult(getImpl(), getOperation(), opOperand, state);
  }
SmallVector<OpOperand *> mlir::bufferization::BufferizableOpInterface::getAliasingOpOperand(OpResult opResult, const AnalysisState & state) {
      return getImpl()->getAliasingOpOperand(getImpl(), getOperation(), opResult, state);
  }
BufferRelation mlir::bufferization::BufferizableOpInterface::bufferRelation(OpResult opResult, const AnalysisState & state) {
      return getImpl()->bufferRelation(getImpl(), getOperation(), opResult, state);
  }
LogicalResult mlir::bufferization::BufferizableOpInterface::resolveConflicts(RewriterBase & rewriter, const AnalysisState & state) {
      return getImpl()->resolveConflicts(getImpl(), getOperation(), rewriter, state);
  }
LogicalResult mlir::bufferization::BufferizableOpInterface::bufferize(RewriterBase & rewriter, const BufferizationOptions & options) {
      return getImpl()->bufferize(getImpl(), getOperation(), rewriter, options);
  }
bool mlir::bufferization::BufferizableOpInterface::isWritable(Value value, const AnalysisState & state) {
      return getImpl()->isWritable(getImpl(), getOperation(), value, state);
  }
bool mlir::bufferization::BufferizableOpInterface::isNotConflicting(OpOperand * uRead, OpOperand * uWrite, const AnalysisState & state) {
      return getImpl()->isNotConflicting(getImpl(), getOperation(), uRead, uWrite, state);
  }
LogicalResult mlir::bufferization::BufferizableOpInterface::verifyAnalysis(const AnalysisState & state) {
      return getImpl()->verifyAnalysis(getImpl(), getOperation(), state);
  }
FailureOr<BaseMemRefType> mlir::bufferization::BufferizableOpInterface::getBufferType(BlockArgument bbArg, const BufferizationOptions & options) {
      return getImpl()->getBufferType(getImpl(), getOperation(), bbArg, options);
  }
FailureOr<unsigned> mlir::bufferization::BufferizableOpInterface::getMemorySpace(OpResult opResult) {
      return getImpl()->getMemorySpace(getImpl(), getOperation(), opResult);
  }
