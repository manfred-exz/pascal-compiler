; ---------------------------------------------------
; paslib.inc Copyright © The MASM32 Project 1998-2006
; ---------------------------------------------------

IFNDEF PASLIB_INC
PASLIB_INC equ <1>

readInt PROTO C :VARARG
readChar PROTO C :VARARG
writeInt PROTO C :VARARG
writeChar PROTO C :VARARG
writelnInt PROTO C :VARARG
writelnChar PROTO C :VARARG
absInt PROTO C :VARARG
oddInt PROTO C :VARARG
sqrInt PROTO C :VARARG
sqrtInt PROTO C :VARARG

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file paslib.inc
echo -----------------------------------------
ENDIF
