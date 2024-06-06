! (C) Prologic SA --- Report Initial Inputs
INPUT  $L_UNAME   'UNAME '
INPUT  $L_X1      'X1 '
INPUT  $L_X2      'X1 '
INPUT  $L_X3      'X1 '
INPUT  $L_G1      'G1 '
INPUT  $L_G2      'G2 '
INPUT  $L_G3      'G3 '
! (v) Modification for windows SQRINTERFACE :
! INPUT  $L_G4      'G4 '
! INPUT  $L_G5      'G5 '
! In Windows Version of SQRINTERFACE variables $L_G4 and $L_G5 changed
! to $L_REPORTPATH and $L_REPORTNAME
INPUT $L_REPORTPATH  'REPORTPATH '
INPUT $L_REPORTNAME  'REPORTNAME'
! (^)
INPUT  $L_UESH    'UESH '
INPUT  $L_UEID    'UEID '
! (v) Modification for windows SQRINTERFACE :
!  Since 5/7/99 in the Windows Version of SQRINTERFACE variable
!  $L_UID Changed to $L_XRHSH
! INPUT  $L_UID     'UID '
INPUT  $L_XRHSH     'L_XRHSH '
! (^)
INPUT  $L_CID     'CID '
INPUT  $SQLCMD    'SQL CMD '
INPUT  $SQLORD    'ORD CMD '
if $SQLORD = '_'
    move '' to $SQLORD
end-if

display '(c) by Prologic Computer Applications 1987-2000'
display 'Windows SQRINTERFACE Version 4.00'
display '-(v)---------------------------------- info ---'
display 'SQLCMD :' noline
display $SQLCMD
display 'SQLORD :' noline
display $SQLORD
display 'REPORTPATH :' noline
display $L_REPORTPATH
display 'REPORTNAME :' noline
display $L_REPORTNAME
display 'CID :' noline
display $L_CID
display 'XRHSH :' noline
display $L_XRHSH
display '-(^)---------------------------------- info ---'

#INCLUDE "{$L_GDATA}/pc{$L_CLASS}.inc"
