/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Definitions                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

::mlir::DiagnosedSilenceableFailure mlir::transform::TransformOpInterface::apply(::mlir::transform::TransformResults & transformResults, ::mlir::transform::TransformState & state) {
      return getImpl()->apply(getImpl(), getOperation(), transformResults, state);
  }
