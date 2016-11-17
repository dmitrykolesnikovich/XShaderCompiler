/*
 * ASTEnums.h
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef XSC_AST_ENUMS_H
#define XSC_AST_ENUMS_H


#include <string>


namespace Xsc
{


/* ----- AssignOp Enum ----- */

// Assignment operator enumeration:
// =, +=, -=, *=, /=, %=, <<=, >>=, |= , &=, ^=
enum class AssignOp
{
    Undefined,

    Set,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    LShift,
    RShift,
    Or,
    And,
    Xor,
};

std::string AssignOpToString(const AssignOp o);
AssignOp StringToAssignOp(const std::string& s);

bool IsBitwiseOp(const AssignOp o);


/* ----- BinaryOp Enum ----- */

// Binary operator enumeration:
// &&, ||, |, ^, &, <<, >>, +, -, *, /, %, ==, !=, <, >, <=, >=
enum class BinaryOp
{
    Undefined,

    LogicalAnd,
    LogicalOr,
    Or,
    Xor,
    And,
    LShift,
    RShift,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    Equal,
    NotEqual,
    Less,
    Greater,
    LessEqual,
    GreaterEqual,
};

std::string BinaryOpToString(const BinaryOp o);
BinaryOp StringToBinaryOp(const std::string& s);

bool IsBitwiseOp(const BinaryOp o);


/* ----- UnaryOp Enum ----- */

// Unary operator enumeration:
// !, ~, +, -, ++, --
enum class UnaryOp
{
    Undefined,

    LogicalNot, // Logical not (e.g. !x)
    Not,        // Bitwise not (e.g. ~x)
    Nop,        // No-op (e.g. +x is equal to x)
    Negate,     // Negate (e.g. -x)
    Inc,        // Increment (e.g. ++x)
    Dec,        // Decrement (e.g. --x)
};

std::string UnaryOpToString(const UnaryOp o);
UnaryOp StringToUnaryOp(const std::string& s);

bool IsBitwiseOp(const UnaryOp o);


/* ----- CtrlTransfer Enum ----- */

// Control transfer enumeration:
// break, continue, discard
enum class CtrlTransfer
{
    Undefined,

    Break,
    Continue,
    Discard,
};

std::string CtrlTransformToString(const CtrlTransfer ct);
CtrlTransfer StringToCtrlTransfer(const std::string& s);


/* ----- DataType Enum ----- */

// Base data type enumeration.
enum class DataType
{
    Undefined,

    // String types,
    String,

    // Scalar types
    Bool,
    Int,
    UInt,
    Half,
    Float,
    Double,
    
    // Vector types
    Bool2,
    Bool3,
    Bool4,
    Int2,
    Int3,
    Int4,
    UInt2,
    UInt3,
    UInt4,
    Half2,
    Half3,
    Half4,
    Float2,
    Float3,
    Float4,
    Double2,
    Double3,
    Double4,

    // Matrix types
    Bool2x2,
    Bool2x3,
    Bool2x4,
    Bool3x2,
    Bool3x3,
    Bool3x4,
    Bool4x2,
    Bool4x3,
    Bool4x4,
    Int2x2,
    Int2x3,
    Int2x4,
    Int3x2,
    Int3x3,
    Int3x4,
    Int4x2,
    Int4x3,
    Int4x4,
    UInt2x2,
    UInt2x3,
    UInt2x4,
    UInt3x2,
    UInt3x3,
    UInt3x4,
    UInt4x2,
    UInt4x3,
    UInt4x4,
    Half2x2,
    Half2x3,
    Half2x4,
    Half3x2,
    Half3x3,
    Half3x4,
    Half4x2,
    Half4x3,
    Half4x4,
    Float2x2,
    Float2x3,
    Float2x4,
    Float3x2,
    Float3x3,
    Float3x4,
    Float4x2,
    Float4x3,
    Float4x4,
    Double2x2,
    Double2x3,
    Double2x4,
    Double3x2,
    Double3x3,
    Double3x4,
    Double4x2,
    Double4x3,
    Double4x4,
};

// Returns a descriptive string of the specified data type.
std::string DataTypeToString(const DataType t, bool useTemplateSyntax = false);

// Returns true if the specified data type is a scalar type.
bool IsScalarType(const DataType t);

// Returns true if the specified data type is a vector type.
bool IsVectorType(const DataType t);

// Returns true if the specified data type is a matrix type.
bool IsMatrixType(const DataType t);

/*
Returns the dimension of the specified data type interpreted as vector type.
Values range from 1 to 4, but 0 for matrix types).
*/
int VectorTypeDim(const DataType t);

/*
Returns the dimensions MxN of the specified data type interpreted as matrix type.
Values range from 1x1 to 4x4, but 1x1 to 4x1 for vector and scalar types).
*/
std::pair<int, int> MatrixTypeDim(const DataType t);

// Returns the base data type for the specified type or DataType::Undefined on failure.
DataType BaseDataType(const DataType t);

// Returns the vector data type for the specified type and vector size.
DataType VectorDataType(const DataType baseDataType, int vectorSize);

// Returns the data type for the specified swizzle operator or throws and std::invalid_argument on failure.
DataType VectorSubscriptDataType(const DataType dataType, const std::string& subscript);


/* ----- Intrinsic Enum ----- */

/*
Intrinsics function enumeration (currently only HLSL intrinsics).
see https://msdn.microsoft.com/en-us/library/windows/desktop/ff471376(v=vs.85).aspx
*/
enum class Intrinsic
{
    Undefined,

    Abort,
    Abs,
    ACos,
    All,
    AllMemoryBarrier,
    AllMemoryBarrierWithGroupSync,
    Any,
    AsDouble,
    AsFloat,
    ASin,
    AsInt,
    AsUInt,
    AsUInt_2,
    ATan,
    ATan2,
    Ceil,
    CheckAccessFullyMapped,
    Clamp,
    Clip,
    Cos,
    CosH,
    CountBits,
    Cross,
    D3DCOLORtoUBYTE4,
    DDX,
    DDXCoarse,
    DDXFine,
    DDY,
    DDYCoarse,
    DDYFine,
    Degrees,
    Determinant,
    DeviceMemoryBarrier,
    DeviceMemoryBarrierWithGroupSync,
    Distance,
    Dot,
    Dst,
    ErrorF,
    EvaluateAttributeAtCentroid,
    EvaluateAttributeAtSample,
    EvaluateAttributeSnapped,
    Exp,
    Exp2,
    F16toF32,
    F32toF16,
    FaceForward,
    FirstBitHigh,
    FirstBitLow,
    Floor,
    FMA,
    FMod,
    Frac,
    FrExp,
    FWidth,
    GetRenderTargetSampleCount,
    GetRenderTargetSamplePosition,
    GroupMemoryBarrier,
    GroupMemoryBarrierWithGroupSync,
    InterlockedAdd,
    InterlockedAnd,
    InterlockedCompareExchange,
    InterlockedCompareStore,
    InterlockedExchange,
    InterlockedMax,
    InterlockedMin,
    InterlockedOr,
    InterlockedXor,
    IsFinite,
    IsInf,
    IsNaN,
    LdExp,
    Length,
    Lerp,
    Lit,
    Log,
    Log10,
    Log2,
    MAD,
    Max,
    Min,
    ModF,
    MSAD4,
    Mul,
    Noise,
    Normalize,
    Pow,
    PrintF,
    Process2DQuadTessFactorsAvg,
    Process2DQuadTessFactorsMax,
    Process2DQuadTessFactorsMin,
    ProcessIsolineTessFactors,
    ProcessQuadTessFactorsAvg,
    ProcessQuadTessFactorsMax,
    ProcessQuadTessFactorsMin,
    ProcessTriTessFactorsAvg,
    ProcessTriTessFactorsMax,
    ProcessTriTessFactorsMin,
    Radians,
    Rcp,
    Reflect,
    Refract,
    ReverseBits,
    Round,
    RSqrt,
    Saturate,
    Sign,
    Sin,
    SinCos,
    SinH,
    SmoothStep,
    Sqrt,
    Step,
    Tan,
    TanH,
    Tex1D,
    Tex1D_2,
    Tex1DBias,
    Tex1DGrad,
    Tex1DLod,
    Tex1DProj,
    Tex2D,
    Tex2D_2,
    Tex2DBias,
    Tex2DGrad,
    Tex2DLod,
    Tex2DProj,
    Tex3D,
    Tex3D_2,
    Tex3DBias,
    Tex3DGrad,
    Tex3DLod,
    Tex3DProj,
    TexCube,
    TexCube_2,
    TexCubeBias,
    TexCubeGrad,
    TexCubeLod,
    TexCubeProj,
    Transpose,
    Trunc,
};


} // /namespace Xsc


#endif



// ================================================================================